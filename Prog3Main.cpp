/*******************************************************************
*   CS 121 Programming Assignment 3
*   File: Prog3.cpp
*   Author: Kyle Daigle
*   Desc: A game that generates a random number and gives the user 20 tries to guess it
*   Date: 4/3/2017
*
*   I attest that this program is entirely my own work
*******************************************************************/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int SayYouWon(); //Victory messages
int SayYouLost(); //Defeat messages
int CheckGuess(int guess); //Checks user's guess
int GetRandomNumber(); //RNG function
int ContinueOption(); //Asks if user wants to continue

unsigned int rng = 0; //random number
unsigned int rngWin = 0; //Decides victory message
unsigned int rngLose = 0; //decides loss message
bool bStop = false; //bool to decide if program is finished or not
bool bLoop = false; //bool to loop game
int guess = 0; //user's guessed number
int tries = 0;//attempt counter for loss conditions
string reply; //store user's answer for if they want to continue



int main() 
{


	do 
	{

		unsigned int rng = GetRandomNumber(); //generates number. 
			//cout << rng << endl; //Testing line

			bLoop = false;

		do 
		{
			
		
			
				cout << "Please enter a number between 1 and 100" << endl;
				cin >> guess; //retrieves guess
				tries ++;
				CheckGuess(guess);
				
		
				if (tries == 20) 
				{ //checks for loss condition after each try. 
					SayYouLost();
					tries = 0;
					bLoop = true;
				}
			
			
			if (bLoop == true) 
			{
				tries = 0;
			}
		 

		} while (bLoop == false); //continues or ends game

	} while (bStop == false);

}


int SayYouWon() 
{
	
	switch (rngWin) 
	{
			
	case 1:
		cout << "Congratulations, you won! It took you " << tries << " attempts! Play again?" << endl; //tries keeps resetting to 0 when called
		ContinueOption();
		break;

	case 2:
		cout << "You won? It took you " << tries << " attempts, but that was too easy! Play again?" << endl;//tries keeps resetting to 0 when called
		ContinueOption();
		break;

	}
	return 0;
}

int SayYouLost() 
{
	
	switch(rngLose)
	{
			
	case 1:
		cout << "I'm sorry, you are out of tries. Better luck next time! Do you want to try again?" << endl;
		ContinueOption();
		break;
	case 2:
		cout << "Really? 20 tries and you couldn't guess it? You can do better! Play again?" << endl;
		ContinueOption();
		break;
	case 3:
		cout << "You were so close! 1 or 2 more tries you would have had it! Play again?" << endl;
		ContinueOption();
		break;
	}
	return 0;
}

int CheckGuess(int guess) 
{
	
	
	if (guess <= 100 && guess >= 1) 
	{
		if (guess == rng) {
			SayYouWon();
			bLoop = true;
		}
		else if (guess == rng + 1 || guess == rng - 1) 
		{
			cout << "Hot! Hot! Hot!" << endl;
		}
		else  if (guess <= rng + 5 && guess >= rng - 5) 
		{
			cout << "You are getting warmer..." << endl;
		}
		else if (guess <= rng + 10 && guess >= rng - 10) 
		{
			cout << "your guess is still cool" << endl;
		}
		else if (guess > rng + 10 || guess < rng - 10) 
		{
			cout << "Your guess is cold" << endl;
		}
	}
	else 
	{
		cout << "Your guess is invalid. Please enter a guess between 1 and 100." << endl;
	}


	return 0;
}

int GetRandomNumber() 
{
 srand((unsigned int)(time(NULL)));
	rng = rand() % 100 + 1;
	rngWin = rand() % 2 + 1;
	rngLose = rand() % 3 + 1;
	return rng;
	
}

int ContinueOption() 
{
	cout << "Please type yes or no" << endl;
	cin >> reply;
	for (int idx = 0; idx < reply.length(); idx++) //Change reply to uppercase
	{
		reply[idx] = toupper(reply[idx]);
	}
		if (reply == "NO") //stops game. 
		{ 
			bStop = true;
		}
		else if (reply == "YES") //continues game
		{ 
			bStop = false;
		}
		else 
		{
			ContinueOption(); //Recursive until a correct answer is given
		}
	
	return 0;
}
