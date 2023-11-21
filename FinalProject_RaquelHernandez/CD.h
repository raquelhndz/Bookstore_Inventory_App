//CD.h File

#include "Item.h"

//constant 
const double CD_MARKUP = 0.30;

class CD: public Item
{
private: 
	string artistName, genre; //private variables
	int numTracks, playTime; 
	//Private Helper Function 
	void fixCD();
public:
	CD(): Item(" ", 0,0), artistName("N/A "), genre("N/A "), numTracks(0), playTime(0)//default constructor 
	{
		setMarkup(CD_MARKUP);
		fixCD();
	}

	//non-default constructor
	CD(string myTitle, string myArtName, string myGenre, int myOnHand, int myTracks, int myPlayTime, double myCost) : Item(myTitle, myCost, myOnHand), artistName(myArtName), genre(myGenre), numTracks(myTracks), playTime(myPlayTime)
	{
		setMarkup(CD_MARKUP);
		fixCD();
	}

	virtual ~CD() //destructor
	{

	}

	//setFunction Prototypes 
	void setArtist(string);
	void setGenre(string);
	void setNumTracks(int);
	void setPlayTime(int);

	//getfunction prototypes 
	string getArtist()const;
	string getGenre()const;
	int getNumTracks()const;
	int getPlayTime()const;
	virtual double getPrice()const;

	//print funciton 
	virtual void print()const; 
};

