//Book.h File

#include "Item.h"

const double BOOK_MARKUP = 0.25;

class Book: public Item
{
private:
	string author, description; 
public:
	Book(): Item("N/A", 0, 0), author("N/A"), description("Not available")// defualt constructor 
	{
		setMarkup(BOOK_MARKUP);
	}
	
	//non-default constructor 
	Book(string myTitle, string myAuthor, string myDescription ,  double myCost, int myOnHand ): Item(myTitle, myCost, myOnHand), author(myAuthor), description(myDescription)
	{
		setMarkup(BOOK_MARKUP);
	}

	virtual ~Book()//destructor 
	{

	}
	
	//set function prototypes 
	void setAuthor(string);
	void setDescription(string);

	//getFunction prototypes 
	string getAuthor()const; 
	string getDescription()const; 
	virtual double getPrice()const;
	
	//Print function 
	virtual void print()const;
};

