//Item.cpp File

#include "Item.h"

int Item::objectCount = 0; //initialize object count

//Set Function Implementation
void Item::setOnHand(int myOnHand)
{
	myOnHand = onHand;
	fixItem();
}

void Item::setTitle(string myTitle)
{
	myTitle = title; 
}

void Item::setCost(double myCost)
{
	myCost = cost; 
	fixItem();
}

void Item::setMarkup(double myMarkup)
{
	myMarkup = markup; 
}


//Get Function Implementation 
int Item::getOnHand()const
{
	return onHand; 
}

string Item::getTitle()const
{
	return title; 
}

double Item::getCost()const
{
	return cost; 
}

int Item::getSKU()const
{
	return SKU; 
}

double Item::getPrice()const
{
	return (cost + (cost * markup));
}


//Private Helper Function
void Item::fixItem()
{
	cost = abs(cost);
	onHand = abs(onHand);
}

//Update Funcitons 
void Item::updateOnHand(int newOnHand)
{
	onHand = newOnHand + onHand;
}

void Item::updateCost(double newCost)
{
	cost = newCost;
}

void Item::sellOnHand(int newOnHand)
{
	onHand = (onHand - newOnHand);
	if (onHand < 0)
	{
		onHand = 0;
	}
}


//Print Function 
void Item::print()const
{
	const int SPACE = 10; 
	const int WIDER = 16;

	cout << fixed << setprecision(2);
	cout << " Number on Hand:   " << setw(SPACE) << onHand;
	if (onHand < MIN_STOCK)
	{
		cout << "    (Less than 10 left in Stock) Place an Order " << endl;
	}
	cout <<endl<< " Cost:  " << setw(WIDER) << "$" << cost << endl;
	cout << " Title: " << title << endl;
	cout << " Price: " << setw(WIDER) << "$" << getPrice() << endl;
	cout << " Total Value: " << setw(SPACE) << "$" << (onHand * getPrice()) << endl;
	\
}

