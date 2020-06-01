// ***********************************************************************
// * Assignment 1 Lotterty Numbers                                       *
// * Generate a list of suggested lottery numbers using random           *
// * Number generation techniques                                       *
// * Date: 5/12/2020                                                     *
// * Author: Zachary Mollenhour                                          *
// * References:                                                         *
// ***********************************************************************

//Include statements
#include <iomanip>
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

//Function Prototypes
void Get_Lottery(int numBalls, int largestNumber,int line[]);
bool Duplicate_Ticket(int random, int arr[], int size);
void Print_Results(int line[], int numBalls); 
void Print_Menu(int* numBalls, int* largestNumber, int* numberTickets);

//CONSTANT FOR MINIMUM 
#define MIN 1


//Main Function
int main()
{
	//Variable Declaration
	int numBalls, largestNumber, numberTickets = 0;
	
	//seed for random
	srand(time(0));

	//Print Menu and get input
	Print_Menu(&numBalls, &largestNumber, &numberTickets);	

	//Array to hold each line of numbers
	int line[numBalls];

	//Run Lottery Generator for total number of tickets
	for(int i = 0; i < numberTickets; i++)
	{
		Get_Lottery(numBalls, largestNumber,line);
		Print_Results(line, numBalls);
	}
	
	//Finished print out good luck message
	cout << "\nGOOD LUCK" << endl;
	return 0;
}

//Function to print initial menu and get input from user
void Print_Menu(int* numBalls, int* largestNumber, int* numberTickets)
{
	//Declare variable for the data for each line
	int Balls,Number,Tickets = 0;	
	
	//Variables for caluclating odds of winning
	long double result = 1.0;
	long double a;
	unsigned b;

	//Do while loops to get the input for each one until a correct input is given
	do{
		cout << "Enter in the number of balls or numbers you wish to pick from." << endl;
		cout << endl << "The number must be between 3 and 7: ";
		cin >> Balls;
	}while(Balls < 3 || Balls > 7);
	
	do{
		cout << endl << "Enter in the largest number in the lottery. " << endl;
		cout << endl << "The number must be between 45 - 70: ";
		cin >> Number;
	}while(Number <= 45 || Number >= 70);
	
	do{
		cout << endl << "Enter the number of tickets 1-100 inclusive: ";
		cin >> Tickets;
		cout << endl;
	}while(Tickets < 1 || Tickets > 100);

	//Calculate odds of winning
	for(a = Number, b = Balls; b > 0; a--, b--)
	{
		result = result * a / b;
	}
	//Store odds of winning
	int odds = result; 
	
	//Print out odds of winning
	cout << "You will select " << Balls << " numbers" << endl;
	cout << endl << "The numbers will range from 1 to " << Number << endl;
	cout << endl << "The odds are 1 in " << odds << endl;
	
	//Prepare the lottery selections results
	cout << endl << "\nYOUR LOTTERY SELECTIONS ARE: " << endl;
	cout << endl;

	//Pass back values of input to main
	*numBalls = Balls;
	*largestNumber = Number;
	*numberTickets = Tickets;
}		

//Function to check if the number exists in lottery generated array
bool Duplicate_Ticket(int random, int arr[], int size)
{
	//Check if the random value is duplicate
	for(int i = 0; i < size; i++)
	{
		//If duplicate return true and reprocess
		if(arr[i] == random)
		{
			return true;
		}
		//Else return false
		return false;
	}
}


//Function to get the random lottery numnbers
void Get_Lottery(int numBalls, int largestNumber, int line[])
{
	//Declare int for the random numbers
	int randomNumber = 0;

	//randomNumber Generation
	for(int i = 0; i < numBalls; i++)
	{	
		//Fail safe to ensure randomNumber is zeroed out
		randomNumber = 0;

		//Get random number with MIN being one
		randomNumber = rand() % largestNumber + MIN;

		//Keep getting a random number when its a duplicate value
		while(Duplicate_Ticket(randomNumber, line, i)== true)
		{	
			randomNumber = rand() % largestNumber + 1;
		}

		//Store value into array of values for that line
		line[i] = randomNumber;
	}	
}   

//Print the results
void Print_Results(int line[], int numBalls)
{
	//Print out the results by line
	for(int i = 0; i < numBalls; i++)
	{
		cout << line[i] << " ";
	}
	cout << endl;
}
