#pragma once
#include  "InventoryItem.h"

class ToyItem : public InventoryItem
{
protected: 
	string name;
public:
	ToyItem(int id, float price) : InventoryItem(id, price)
	{
		cout << "Name of the TOY: ";
		cin.ignore();
		getline(cin, name);
	}

	void display() const
	{
		cout << "The TOY ITEM with name of: '" << this->name << "', with id: " << this->id << ", costs: $" << this->price << endl;
	}
	// name of toy
	string getName()
	{
		return this->name;
	}
};