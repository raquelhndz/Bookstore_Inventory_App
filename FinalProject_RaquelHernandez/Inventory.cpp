//Inventory.CPP File

#include "Inventory.h"

void Inventory::menuPrompt()// shows main menu options 
{
	cout <<endl<< " MAIN MENU: " << endl;
	cout << " 1) To Enter a New item, Enter 1 " << endl;
	cout << " 2) To Enter an Order, Enter 2 " << endl;
	cout << " 3) For Sale, Enter 3 " << endl;
	cout << " 4) To Complete Report, Enter 4 " << endl;
	cout << " 5) To Quit, Enter 5 " << endl;

}

void Inventory::itemPrompt()//shows item creation options 
{
	cout <<endl<< " NEW ITEM: " <<endl;
	cout << " B) To add a new Book, enter B " <<endl;
	cout << " C) To add a new CD, enter C " << endl;
	cout << " D) To add a new DVD, enter D " << endl;
	cout << " M) To return to the main menu, enter M " << endl;

}

void Inventory::mainMenu()//gets and directs user to correct function 
{
	int menuChoice; //to hold user choice 
	menuPrompt();	//show prompt
	cin >> menuChoice; 
	cin.ignore();
	switch (menuChoice)//switch to different cases
	{
	case 1: 
	{
		itemMenu(); //function with second switch 
	}
	break;
	case 2:
	{
		enterOrder();
		mainMenu();
	}
	break;
	case 3: 
	{
		makeSale();
		mainMenu();
	}
	case 4: 
	{
		report();//loads full report
		mainMenu();//takes back to mainmenu
	}
	break;
	case 5:
	{
		exit(0);
	}
	default: 
		cout<<" NOT a Valid Choice. Please input a value AMONG choices: 1, 2, 3, 4, M or 5 to Quit: "; 
	}
}

void Inventory::itemMenu()//gets user to create correct item 
{
	char itemChoice; //to hold user choice 
	itemPrompt();	//show prompt
	cin >> itemChoice; 
	cin.ignore();
	itemChoice = toupper(itemChoice); //in case of lower case 
	switch (itemChoice)
	{
	case 'B': 
	{
		addBook(); //direct to create book
		mainMenu(); //back to menu
	}
	break;
	case 'C':
	{
		addCD(); //direct to create CD
		mainMenu();
	}
	break;
	case 'D':
	{
		addDVD(); //direct to create DVD
		mainMenu();
	}
	break;
	case 'M':
	{
		mainMenu(); //direct back to main menu
	}
	default: 
		cout << " NOT a Valid Choice. Please input a value AMONG choices: B, C, D, and M: "; //make sure user chooses a letter
		itemMenu();//take back to menu
	}

}

void Inventory::addBook()// function to add book 
{
	string bookTitle, bookAuthor, shortDescrip; //variables 
	double bookCost; 
	int bookOnHand; 
	cout << " Enter Book Title: "; //prompt for all inputs 
	getline(cin, bookTitle);
	cout << " Enter Author: ";
	getline(cin, bookAuthor);
	cout << " Enter Description: ";
	getline(cin, shortDescrip); 
	cout << " Enter Book Cost: ";
	cin >> bookCost; 
	cin.ignore();
	cout << " Enter # On Hand (0 if none): "; // add stock along with new item 
	cin >> bookOnHand; 
	cin.ignore();
	itemPtr[counter] = new Book(bookTitle, bookAuthor, shortDescrip, bookCost, bookOnHand); //create object
	cout << endl << " The Book " << itemPtr[counter]->getTitle() << " has been saved. The SKU is: " << itemPtr[counter]->getSKU() << ".  # On Hand:" << itemPtr[counter]->getOnHand() << endl;;
	counter++;
	
}
void Inventory::addCD()// function to add CD
{
	string CDTitle, CDArtistName, CDGenre;// variables 
	int numTracks, playTime, CDOnHand;
	double CDcost; 
	cout << " Enter CD Title: ";//prompt for all inputs 
	getline(cin, CDTitle);
	cout << " Enter Artist Name: ";
	getline(cin, CDArtistName);
	cout << " Enter Number of Tracks: "; 
	cin >> numTracks;
	cin.ignore();
	cout << " Enter Length of Playing Time: ";
	cin >> playTime;
	cin.ignore();
	cout << " Enter Genre: ";
	getline(cin, CDGenre);
	cout << " Enter Cost: ";
	cin >> CDcost;
	cin.ignore();
	cout << " Enter # On Hand (0 if none): "; // add stock 
	cin >> CDOnHand;
	itemPtr[counter] = new CD(CDTitle, CDArtistName, CDGenre, CDOnHand, numTracks, playTime, CDcost);// create new object --item 
	cout << endl << " The CD " << itemPtr[counter]->getTitle() << " has been saved.  The SKU is: " << itemPtr[counter]->getSKU() << ".  # On Hand: " << itemPtr[counter]->getOnHand() << endl;;
	counter++;//continue count in array
}

void Inventory::addDVD()// function to add DVD
{
	string DVDTitle, DVDdirector, DVDLeadActor, DVDGenre;//variables 
	int DVDPlayTime, DVDOnHand;
	double DVDCost; 
	cout << " Enter DVD Title: "; //prompt for all inputs 
	getline(cin, DVDTitle);
	cout << " Enter Director Name: ";
	getline(cin, DVDdirector);
	cout << " Enter Lead Actor Name: ";
	getline(cin, DVDLeadActor);
	cout << " Enter DVD Playing Time: ";
	cin >> DVDPlayTime;
	cin.ignore();
	cout << " Enter DVD Genre: ";
	getline(cin, DVDGenre);
	cout << " Enter DVD Cost: ";
	cin >>DVDCost;
	cin.ignore();
	cout << " Enter # On Hand (0 if none): ";//add dvd stock
	cin >> DVDOnHand;
	itemPtr[counter] = new DVD(DVDTitle, DVDdirector, DVDLeadActor, DVDGenre, DVDOnHand, DVDPlayTime, DVDCost);//create new object - DVD
	cout << endl << " The DVD " << itemPtr[counter]->getTitle() << " has been saved. The SKU is: " << itemPtr[counter]->getSKU() << ".  # On Hand:" <<itemPtr[counter]->getOnHand()<< endl;
	counter++;
}

///*
int Inventory::verifySKU(int skuEntered)// check if Sku number exists 
{
	while (skuEntered > itemPtr[counter]->getObjectCount() + SKU_INCREASE || skuEntered < MIN_SKU)// if sku is greater then current getSKU or less than 1000 it cannot exist
	{
		cout << " That SKU Number does not exist. Please enter a valid SKU Number: ";
		cin >> skuEntered;
	}
	return skuEntered;
}
//*/

void Inventory::enterOrder()
{
	int skuEntered = 0, newQuantity, index;
	double newCost; 

	cout << endl << " ORDER : " << endl; //prompt for order 
	cout << " Enter SKU for new order: ";
	cin >> skuEntered;
	skuEntered = verifySKU(skuEntered);
	skuEntered = abs(skuEntered); //error checking 
	cout << " Enter quantity recieved: "; //new quantity
	cin >> newQuantity;
	newQuantity = abs(newQuantity);
	cout << " Enter Cost: "; //new cost 
	cin >> newCost; 
	newCost = abs(newCost);
	index = skuEntered - MIN_SKU; //get to correct array index 

	itemPtr[index]->updateOnHand(newQuantity); //get back to correct index and update onHand
	itemPtr[index]->updateCost(newCost);
	cout<<endl<<" On Hand has been updated to:  "<<itemPtr[index]->getOnHand();
	cout <<endl<< " Cost has been updated to: $" << itemPtr[index]->getCost();
	cout <<endl<< " Thank you for entering the order... you are being redirected to Main Menu " << endl << endl;
	
}

void Inventory::makeSale()
{
	//Variables 
	const int FORMAT = 15; //const for formatting
	const int LONGER = 34;
	char choice; 
	Item* tempPtr[SIZE]; //array to point at all relevant Item class informaiton 
	int soldItems[SIZE]; //array to keep track of sold items 
	int tempCount = 0, skuEntered, index;// saleQuantity;
	double total = 0;

	cout << " SALE : " << endl;

	do {
		cout << " Enter SKU of desired product: ";//prompt for SKU
		cin >> skuEntered;
		skuEntered = abs(skuEntered);
		skuEntered = verifySKU(skuEntered);
		index = skuEntered - MIN_SKU; //get to correct index
		tempPtr[tempCount] = itemPtr[index]; //set tempPtr to correct index 
		cout << " Enter a quantity for sale: "; //prompt for sale
		cin >> soldItems[tempCount];
		if (soldItems[tempCount] > itemPtr[index]->getOnHand()) //error check on hand 
		{
			cout <<endl<< " NOTICE: We only have " << itemPtr[index]->getOnHand() << " of that item in stock. " << endl;
			cout << " The sale will be made for that amount. " << endl;
			soldItems[tempCount] = itemPtr[index]->getOnHand(); //limits sold items to only those on hand
		}
		tempPtr[tempCount]->sellOnHand(soldItems[tempCount]); //update on hand 
		cout <<endl<< " The New # On Hand is: " << tempPtr[tempCount]->getOnHand() << endl; //print outputs
		cout << " The Number sold is: " << soldItems[tempCount] << endl;
		tempCount++; //incrememnt count for next loo[
		//index++; --didnt use 
		cout << " Enter Y to purchase another item or R to go to receipt: ";
		cin>> choice; //choice to end or complete other sale 
		cout<<endl;
	} while (choice == 'Y' || choice == 'y');

	cout << endl << " RECEIPT: " << endl;
	for (int i = 0; i < tempCount; i++)//loop to print out contents of different arrays which hold the sale info
	{
		cout << setprecision(2) << fixed;
		cout <<" "<< tempPtr[i]->getSKU() << "   " <<soldItems[i]<<setw(FORMAT)<< "$" << tempPtr[i]->getPrice() << setw(FORMAT) << "$" << tempPtr[i]->getPrice() * soldItems[i];
		if (soldItems[i] > itemPtr[index]->getOnHand()) //only if we sold more than we had on hand 
		{
			cout << " (Sold only amount in stock) ";
		}
		cout << endl;
		total += tempPtr[i]->getPrice() * soldItems[i]; //total sold
	}
	//print rest of receipt 
	cout <<endl<<" Total:   "<<setw(LONGER)<<"$"<< total << endl;
	cout << " Tax:     " << setw(LONGER)<<"$"<<(total * TAX_RATE) << endl;
	cout << " Subtotal:" << setw(LONGER)<<"$"<< total + (total * TAX_RATE) << endl;
	cout << endl << " Thank you for your sale. You are being redirected to Main Menu " << endl;
	}
	

void Inventory::report()//to create full current report 
{
	for (int i = 0; i < counter; i++)//goes through entire print function of array of pointers 
	{
		itemPtr[i]->print();//virtual print function 
		cout << "------------------------------------------------------------------" << endl;
	}
}