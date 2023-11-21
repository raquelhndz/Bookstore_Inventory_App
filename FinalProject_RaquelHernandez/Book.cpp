//Book.CPP File

#include "Book.h"

//Set Function Implementation 
void Book::setAuthor(string myAuthor)
{
	myAuthor = author; 
}

void Book::setDescription(string myDescription)
{
	myDescription = description; 
}


//Get function implementation 
string Book::getAuthor()const
{
	return author; 
}

string Book::getDescription()const
{
	return description; 
}


double Book::getPrice()const //virtual get price 
{
	return (getCost() + (getCost() * BOOK_MARKUP));
}


//Print Function 
void Book::print()const
{
	cout << " SKU: " << getSKU() <<" (Book) "<< endl;
	Item::print();
	cout << " Author: " << author << endl;
	cout << " Description: " << description << endl << endl;
}
