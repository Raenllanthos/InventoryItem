#pragma once
#include<iostream>
#include<string>
using namespace std;

class InventoryItem
{
protected:
	int id;
	float price;

public:
	InventoryItem()
	{
		this->id = 0;
		this->price = 0.0;
	}

	InventoryItem(int id, float price)
	{
		this->id = id;
		this->price = price;
	}

	virtual ~InventoryItem()
	{
		cout << "destructed\n";
	}

	int getId() const
	{
		return this->id;
	}

	float getPrice() const
	{
		return this->price;
	}

	virtual void display() const = 0;
};