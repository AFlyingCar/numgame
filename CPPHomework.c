/****************************************/
/*To be used for a number guessing game.*/
/*Tyler Robbins				*/
/*12/10/13				*/
/****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]){
	int mystery;
	int choice;
	bool play = true;
	int guess = 10;
	int ok;
	int choiceLog[5]; //keeps a log of the player's numbers
	int win = 0;

	while(play){
		guess = 10;
		choice = 0;
		mystery = 0;

		if(play == true){
			mystery = (rand() % (100 - 1)) + 1; //picks a random number between 1 and 100

			printf("Choose a number between 1 and 100.\n");

			while(choice != mystery && guess != 0){
				printf("You have %d guesses left.", guess);

				printf("\n\nPlease enter your guess. (Integers only): ");
				scanf("%d", &choice);

				if(choice > mystery){
					printf("\nSorry, %d was too high.", choice); //return if guess is too high
				}

				else if(choice < mystery){
					printf("Sorry, but %d was too low.", choice); //return if guess is too low
				}

				guess -= 1;
			}

			if(choice == mystery){

				printf("Congratulations! You guessed the number correctly in %d guesses!",10-guess); //return if player guesses the number in less than 10 guesses
				win++;
			}
			else{
				printf("Too bad. The number was %d.", mystery); //return if player loses
			}
		}

		printf("\n\nYou have won %d games.", win);

		printf("\n\nType 1 to play again, 2 to exit. "); //asks if the player wants to play again
		scanf("%d", &ok);

		if(ok == 1){
			play = true;
		}

		else{
			play = false;
			printf("Alright, play again soon!\n");
		}

	}
	//const char* nuclear = "\u2622";
	return 0;
}
