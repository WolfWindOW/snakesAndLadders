//Dice Roller Xd6
//Noah Wyborny
//9/2/2020

#include <iostream>
#include <cstdlib>
#include <ctime>

int diceRoller(int howManyDice) {
	srand(time(nullptr)); //Initializing the random seed for the number generator

	int diceRollerD6, totalRoll, howManyDice;
	for (int i = 0; i < howManyDice; i++) {
		diceRollerD6 = 0;
		diceRollerD6 = rand() % 6 + 1;
		totalRoll = +diceRollerD6;
	}
	return totalRoll;
}
