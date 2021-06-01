#pragma once
#include  "InventoryItem.h"

class MakeUpItem : public InventoryItem
{
protected:
	string brand;
public:
	MakeUpItem(int id, float price) : InventoryItem(id, price)
	{
		cout << "Brand of the MAKEUP: ";
		cin.ignore();
		getline(cin, brand);
	}

	void display() const
	{
		cout << "The MAKEUP ITEM with brand of: '" << this->brand << "', with id: " << this->id << ", costs: $" << this->price << endl;
	}
	// brand of makeup
	string getBrand()
	{
		return this->brand;
	}
};