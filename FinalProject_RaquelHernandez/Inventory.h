//Inventory.h File

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Book.h"
#include "CD.h"
#include"DVD.h"

//Constants 
const int SIZE = 10000;//array size for suffiecient objects 
const int MIN_SKU = 1001; //starting number for SKUS
const int SKU_INCREASE = 1000; 
const double TAX_RATE = 0.0925;

class Inventory
{
private:
	Item* itemPtr[SIZE];
	int counter = 0; 
public:
	void menuPrompt(); //show menu options
	void mainMenu(); //lead to correct choice case
	void itemMenu(); //leade to correct item case 
	void itemPrompt(); //show item options 
	void addBook(); //will allow user to enter book
	void addCD(); //will allow user to enter CD
	void addDVD(); //Will allow user to enter DVD
	void enterOrder(); //will allow user to enter order
	int verifySKU(int); //checks for correct sku number
	void makeSale();
	void report(); //prints full report of inventory

};
#endif
