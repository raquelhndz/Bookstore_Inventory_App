//Item.h file

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std; 

//Constants 
const int SKU_ADD = 1000; 
const int MIN_STOCK = 10; 

class Item
{
private: //private variables 
	string title; 
	double cost, markup;
	static int objectCount;
	int onHand, SKU; 
	//Private Helper Function 
	void fixItem();

public:
	Item(): title("N/A"), cost(0), onHand(0) //default constructor 
	{
		markup = 0;	 //initialize markup to zero -- overrided in other classes 
		objectCount++;
		SKU = (SKU_ADD + objectCount);//generate and save sku number 
		fixItem();// no negative values 
	}
	Item(string myTitle, double myCost, int myOnHand) : title(myTitle), cost(myCost), onHand(myOnHand) //non-default constructor; 
	{
		markup = 0; 
		objectCount++; //keep track of objects created 
		SKU = (SKU_ADD + objectCount); //generate sku 
		fixItem(); //no negative values
	}

	static int getObjectCount()// get num of objects created 
	{
		return objectCount; 
	}

	virtual ~Item() //destructor 
	{
		objectCount--; 
	}

	//Function protoypes
	void setTitle(string);
	void setCost(double);
	void setOnHand(int);
	void setMarkup(double);

	//get functions
	string getTitle()const;
	double getCost()const; 
	int getOnHand()const;
	int getSKU()const; 
	virtual double getPrice()const; //virtual function will retrieve the price for each different markup 
	//void getSaleQuantity();

	//Print Function 
	virtual void print()const;

	//Update functions 
	void updateOnHand(int);
	void updateCost(double);
	void sellOnHand(int);
};
#endif












