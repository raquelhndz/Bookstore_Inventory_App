//DVD.h File

#include "Item.h"

//constant
const double DVD_MARKUP = 0.40;

class DVD : public Item
{
private:
	string director, leadActor, genre; 
	int playTime; 
	//Private Helper function 
	void fixDVD();
public:
	DVD(): Item("N/A", 0, 0), director("N/A"), leadActor("N/A"), genre("N/A"), playTime(0)
	{
		setMarkup(DVD_MARKUP);
		fixDVD();
	}
	DVD(string myTitle, string myDirector, string myActor, string myGenre, int myOnHand, int myTime, double myCost) : Item(myTitle, myCost, myOnHand), director(myDirector), leadActor(myActor), genre(myGenre), playTime(myTime)
	{
		setMarkup(DVD_MARKUP);
		fixDVD();
	}

	virtual ~DVD()//destructor
	{

	}

	//Set Function Prototypes
	void setDirector(string);
	void setActor(string);
	void setGenre(string);
	void setPlayTime(int);

	//Get Function Prototypes 
	string getDirector()const;
	string getActor()const;
	string getGenre()const; 
	int getPlayTime()const;
	virtual double getPrice()const;

	//print function 
	virtual void print()const; 

};

