#pragma once
#include  "InventoryItem.h"

class ClothingItem : public InventoryItem
{
protected:
	int clothItem = 0;
	string clothString;
public:
	ClothingItem(int id, float price) : InventoryItem(id, price)
	{
		int clothItem = 0;
		cout << "\nYou have selected a Clothing Item. For the Category,\nPress 0 for Shirt, Press 1 for Dress, Press 2 for Pants, Press 3 for Shoes: ";
		cin >> clothItem;
		while (clothItem < 0 || clothItem > 3)
		{
			cout << "Value must be between 0 and 3! Try again! ";
			cin >> clothItem;
		}
		if (clothItem == 0) { clothString = "Shirt"; }
		if (clothItem == 1) { clothString = "Dress"; }
		if (clothItem == 2) { clothString = "Pants"; }
		if (clothItem == 3) { clothString = "Shoes"; }
	}

	void display() const
	{
		cout << "The CLOTHING ITEM in Category: '" << this->clothString << "', with id: " << this->id << ", costs: $" << this->price << endl;
	}

	int getClothType()
	{
		return this->clothItem;
	}
	string getClothString()
	{
		return this->clothString;
	}
};
