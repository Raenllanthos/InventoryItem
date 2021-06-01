#pragma once
#include  "InventoryItem.h"

class SportingItem : public InventoryItem
{
protected:
	//enum SPORTTYPE {Equipment, Ball, Weights};
	int sportItem = 0;
	string sportString;
public:
	SportingItem(int id, float price) : InventoryItem(id, price)
	{
		int sportItem = 0;
		cout << "\nYou have selected a Sporting Item. For the Category,\nPress 0 for Equipment, Press 1 for Ball, Press 2 for Weights: ";
		cin >> sportItem;
		while (sportItem < 0 || sportItem > 2)
		{
			cout << "Value must be between 0 and 2! Try again! ";
			cin >> sportItem;
		}
		if (sportItem == 0) { sportString = "Equipment"; }
		if (sportItem == 1) { sportString = "Ball"; }
		if (sportItem == 2) { sportString = "Weights"; }
	}

	void display() const
	{
		cout << "The SPORTING ITEM in Category: '" << this->sportString << "', with id: " << this->id << ", costs: $" << this->price << endl;
	}

	int getSportType()
	{
		return this->sportItem;
	}
	string getSportString()
	{
		return this->sportString;
	}

	/*SPORTTYPE askForSportItemType()
	{
		return (SPORTTYPE)sportItem;
	}*/

	// type of sport purchasing
};