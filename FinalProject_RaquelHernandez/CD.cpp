//CD.CPP File

#include "CD.h"

//Set Function Implementation 
void CD::setArtist(string myArtist)
{
	myArtist = artistName;
}

void CD::setGenre(string myGenre)
{
	myGenre = genre;
}

void CD::setNumTracks(int myTracks)
{
	myTracks = numTracks;
}

void CD::setPlayTime(int myPlay)
{
	myPlay = playTime;
}

//Get Function Implementation 
string CD::getArtist()const
{
	return artistName;
}

string CD::getGenre()const
{
	return genre;
}

int CD::getNumTracks()const
{
	return numTracks;
}

int CD::getPlayTime()const
{
	return playTime;
}

double CD::getPrice()const //virtual get price 
{
	return (getCost() + (getCost() * CD_MARKUP));
}

//Private Helper Function 
void CD::fixCD()
{
	numTracks = abs(numTracks);
	playTime = abs(playTime);
}


//Print Function 
void CD::print()const
{
	cout << " SKU: " << getSKU() << " (CD) " << endl;
	Item::print();
	cout << " Artist: " << artistName << endl;
	cout << " Genre: " << genre << endl;
	cout << " Number of Tracks: " << numTracks << endl;
	cout << " Length of Play Time: " << playTime << " minutes" << endl<<endl;
}
