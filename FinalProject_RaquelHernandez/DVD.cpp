//DVD.cpp File

#include "DVD.h"

//Set Function Implementation
void DVD::setDirector(string myDirector)
{
	myDirector = director;
}

void DVD::setActor(string myActor)
{
	myActor = leadActor;
}

void DVD::setGenre(string myGenre)
{
	myGenre = genre;
}

void DVD::setPlayTime(int myPlay)
{
	myPlay = playTime;
	fixDVD();
}

//Get Function Implementation 
string DVD::getDirector()const
{
	return director;
}

string DVD::getActor()const
{
	return leadActor;
}

string DVD::getGenre()const
{
	return genre;
}

int DVD::getPlayTime()const
{
	return playTime;
}

double DVD::getPrice()const //virtual get price 
{
	return (getCost() + (getCost() * DVD_MARKUP));
}

//Private Helper function 
void DVD::fixDVD()
{
	playTime = abs(playTime);
}

//Print function 
void DVD::print()const
{
	cout << " SKU: " << getSKU() << " (DVD) " << endl;
	Item::print();
	cout << " Director: " << director << endl;
	cout << " Lead Actor: " << leadActor << endl;
	cout << " Genre: " << genre << endl;
	cout << " Length of DVD: " << playTime << " minutes" << endl;

}