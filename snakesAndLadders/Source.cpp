//Four player Snakes and Ladders game
//Noah Wyborny
//9/1/2020

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

int diceRoller(int howManyDice);
int snakesAndLaddersSpaces(int temporaryPosition);

using namespace std;

int howManyDice, totalRoll, temporaryPosition = 0;


int main(void) {
	
	cout << "Would you like a short game? (Y/N)\n";
	char shortOrLong;
	cin >> shortOrLong; 
	
	//Getting input from the user on whether or not they want to play a short or long game, then using that to change the number of dice used to roll
	while (!((howManyDice == 1)||(howManyDice == 2)))
		if ((shortOrLong == 'Y')||(shortOrLong == 'y')) {
			howManyDice = 2;
		}
		else if ((shortOrLong == 'N')||(shortOrLong == 'n')) {
			howManyDice = 1;
		}
		else {
			cout << "Please try again.\n";
			cin >> shortOrLong;
		}

	//Getting input from the user on the names of each player
	cout << "Please type the name of all four players, starting with Player 1.\n";
	char playerNameOne[80], playerNameTwo[80], playerNameThree[80], playerNameFour[80]; //Initializes the variables for the names of players for the game.
	string enterTheNameX; enterTheNameX = "Please enter the name of Player "; //Making a variable so I dont have to type the same thing repeatedly
	cin >> playerNameOne; cout << enterTheNameX + "2.\n"; cin >> playerNameTwo; cout << enterTheNameX + "3.\n"; cin >> playerNameThree; cout << enterTheNameX + "4.\n"; cin >> playerNameFour; //Sets the names of players equal to the input that the user gives for each name.
	int playerOnePosition = 0, playerTwoPosition = 0, playerThreePosition = 0, playerFourPosition = 0; //Initializing the player's position and a temporary positional holder

	//Initalizing and declaring a queue for the player order
	queue<string> players;
	players.push(playerNameOne); players.push(playerNameTwo); players.push(playerNameThree); players.push(playerNameFour);
	//Actual game loop. Keeps going until a player's position is at or above 100
	do {
		if (players.front() == playerNameOne) {
			cout << "Your turn " << playerNameOne << "!" << endl;
			system("pause");
			diceRoller(howManyDice);
			playerOnePosition += totalRoll;
			temporaryPosition = playerOnePosition;
			cout << "You moved " << totalRoll << " spaces!" << endl;
			snakesAndLaddersSpaces(temporaryPosition);
			if (temporaryPosition > playerOnePosition) cout << "But, you climbed a ladder!" << endl;
			else if (temporaryPosition < playerOnePosition) cout << "But, you slid down a snake!" << endl;
			playerOnePosition = temporaryPosition;
			cout << "You are now on space " << playerOnePosition << endl;
			players.pop(); players.push(playerNameOne);
		}
		else if (players.front() == playerNameTwo) {
			cout << "Your turn " << playerNameTwo << "!" << endl;
			system("pause");
			diceRoller(howManyDice);
			playerTwoPosition += totalRoll;
			temporaryPosition = playerTwoPosition;
			cout << "You moved " << totalRoll << " spaces!" << endl;
			snakesAndLaddersSpaces(temporaryPosition);
			if (temporaryPosition > playerTwoPosition) cout << "But, you climbed a ladder!" << endl;
			else if (temporaryPosition < playerTwoPosition) cout << "But, you slid down a snake!" << endl;
			playerTwoPosition = temporaryPosition;
			cout << "You are now on space " << playerTwoPosition << endl;
			players.pop(); players.push(playerNameTwo);
		}
		else if (players.front() == playerNameThree) {
			cout << "Your turn " << playerNameThree << "!" << endl;
			system("pause");
			diceRoller(howManyDice);
			playerThreePosition += totalRoll;
			temporaryPosition = playerThreePosition;
			cout << "You moved " << totalRoll << " spaces!" << endl;
			snakesAndLaddersSpaces(temporaryPosition);
			if (temporaryPosition > playerThreePosition) cout << "But, you climbed a ladder!" << endl;
			else if (temporaryPosition < playerThreePosition) cout << "But, you slid down a snake!" << endl;
			playerThreePosition = temporaryPosition;
			cout << "You are now on space " << playerThreePosition << endl;
			players.pop(); players.push(playerNameThree);
		}
		else if (players.front() == playerNameFour) {
			cout << "Your turn " << playerNameFour << "!" << endl;
			system("pause");
			diceRoller(howManyDice);
			playerFourPosition += totalRoll;
			temporaryPosition = playerFourPosition;
			cout << "You moved " << totalRoll << " spaces!" << endl;
			snakesAndLaddersSpaces(temporaryPosition);
			if (temporaryPosition > playerFourPosition) cout << "But, you climbed a ladder!" << endl;
			else if (temporaryPosition < playerFourPosition) cout << "But, you slid down a snake!" << endl;
			playerFourPosition = temporaryPosition;
			cout << "You are now on space " << playerFourPosition << endl;
			players.pop(); players.push(playerNameFour);
		}
	} while (!(playerOnePosition >= 100 || playerTwoPosition >= 100 || playerThreePosition >= 100 || playerFourPosition >= 100));
	//Victory
	if (playerOnePosition >= 100) cout << "Congratulations " << playerNameOne << "! You won!";
	else if (playerTwoPosition >= 100) cout << "Congratulations " << playerNameTwo << "! You won!";
	else if (playerThreePosition >= 100) cout << "Congratulations " << playerNameThree << "! You won!";
	else if (playerFourPosition >= 100) cout << "Congratulations " << playerNameFour << "! You won!";
}

//A dice roller that rolls XD6, where X is based on whether or not the user wants a short or long game
int diceRoller(int howManyDice) {
	srand(time(nullptr)); //Initializing the random seed for the number generator

	int diceRollerD6 = 0;
	for (int i = 0; i < howManyDice; ++i) {
		diceRollerD6 += ((rand() % 6) + 1);
		totalRoll = +diceRollerD6;
	}
	diceRollerD6 = 0;
	return totalRoll;
	totalRoll = 0;
}

//Moves the player to the right position, if they land on a snake or ladder
int snakesAndLaddersSpaces(int temporaryPosition) {
	switch (temporaryPosition) {
	case 8:
		temporaryPosition = 26;
		break;
	case 21:
		temporaryPosition = 82;
		break;
	case 43:
		temporaryPosition = 77;
		break;
	case 46:
		temporaryPosition = 5;
		break;
	case 48:
		temporaryPosition = 9;
		break;
	case 50:
		temporaryPosition = 91;
		break;
	case 52:
		temporaryPosition = 11;
		break;
	case 54:
		temporaryPosition = 93;
		break;
	case 55:
		temporaryPosition = 7;
		break;
	case 59:
		temporaryPosition = 17;
		break;
	case 62:
		temporaryPosition = 96;
		break;
	case 64:
		temporaryPosition = 36;
		break;
	case 66:
		temporaryPosition = 87;
		break;
	case 69:
		temporaryPosition = 33;
		break;
	case 73:
		temporaryPosition = 1;
		break;
	case 80:
		temporaryPosition = 100;
		break;
	case 83:
		temporaryPosition = 19;
		break;
	case 92:
		temporaryPosition = 51;
		break;
	case 95:
		temporaryPosition = 24;
		break;
	case 98:
		temporaryPosition = 28;
		break;
	default:
		break;
	}
	return temporaryPosition;
}