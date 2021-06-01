#include "InventoryItem.h"
#include "FoodItem.h"
#include "ClothingItem.h"
#include "SportingItem.h"
#include "MakeUpItem.h"
#include "ToyItem.h"

/*
Name: Cullen Wenzlick
Instructor: Josh Woods
Course: C++ Programming
Date: May 1st, 2021
*/

enum ITEMTYPES {Food, Clothing, Sporting, MakeUp, Toy};

ITEMTYPES askForItemType()
{
	int itemType = ITEMTYPES::Food;
	cout << "Press 0 for Food, Press 1 for Clothing, Press 2 for Sporting\n"
		<< "Press 3 for MakeUp, Press 4 for Toy: ";
	cin >> itemType;
	while (itemType < 0 || itemType > 4)
	{
		cout << "Value must be between 0 and 4! Try again! ";
		cin >> itemType;
	}
	return (ITEMTYPES)itemType;
}

bool isNumberOfItemsValid(int numOfItems)
{
	return numOfItems > 0;
}

bool isIdValid(int id)
{
	return id > 0;
}

bool isPriceValid(float price)
{
	return price > 0;
}

void displayError()
{
	cout << "The value entered must be greater than 0. Please try again.\n";
}

int askForNumberOfItems()
{
	int numOfItems = 0;
	while (!isNumberOfItemsValid(numOfItems))
	{
		cout << "Please enter the number of items in your inventory: ";
		cin >> numOfItems;
		if(!isNumberOfItemsValid(numOfItems))
		{
			displayError();
		}
	}
	return numOfItems;
}

int askForId()
{
	int id = 0;
	while (!isIdValid(id))
	{
		cout << "Please enter an ID greater than 0: ";
		cin >> id;
		if (!isIdValid(id))
		{
			displayError();
		}
	}
	return id;
}

float askForPrice()
{
	float price = 0.0;
	while (!isPriceValid(price))
	{
		cout << "Please enter an Item Price greater than $0.00: $";
		cin >> price;
		if (!isPriceValid(price))
		{
			displayError();
		}
	}
	return price;
}

int main()
{
	int numOfItems = askForNumberOfItems();
	InventoryItem** items = new InventoryItem*[numOfItems];

	for (int i = 0; i < numOfItems; i++)
	{
		ITEMTYPES itemType = askForItemType();
		int id = askForId();
		float price = askForPrice();

		switch (itemType)
		{
		case ITEMTYPES::Food:
			items[i] = new FoodItem(id, price);
			break;
		case ITEMTYPES::Clothing:
			items[i] = new ClothingItem(id, price);
			break;
		case ITEMTYPES::Sporting:
			items[i] = new SportingItem(id, price);
			break;
		case ITEMTYPES::MakeUp:
			items[i] = new MakeUpItem(id, price);
			break;
		case ITEMTYPES::Toy:
			items[i] = new ToyItem(id, price);
			break;
		}
		if (i < numOfItems - 1)
		{
			cout << "\nNext Item\n";
		}
	}

	cout << "\n-----INVENTORY INFORMATION-----\n\n";
	for (int i = 0; i < numOfItems; i++)
	{
		items[i]->display();
	}
	for (int i = 0; i < numOfItems; i++)
	{
		delete items[i];
	}

	delete[] items;
	system("pause");
	return 0;
}