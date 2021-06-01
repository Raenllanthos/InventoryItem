#pragma once
#include  "InventoryItem.h"

class FoodItem : public InventoryItem
{
protected:
	int calories = 0;
public:
	FoodItem(int id, float price) : InventoryItem(id, price)
	{
		cout << "Amount of calories in food item?: ";
		cin >> calories;
		while (calories <= 0)
		{
			cout << "Calories must be greater than 0!: ";
			cin >> calories;
		}
	}

	void display() const
	{
		cout << "The FOOD ITEM with calories: " << this->calories << ", with id: " << this->id << ", costs: $" << this->price << endl;
	}

	int getCalories()
	{
		return this->calories;
	}

	// 
};