#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Failsafe
void fail(void)
{
	printf("Memory could not be allocated");
	exit(EXIT_FAILURE);
}

int main()
{
	///Initiates variables
    int i;
	int *player_choice = calloc(3,sizeof(int));
	if (player_choice == NULL) {fail();}
	
    int player_score=0, computer_score=0;
    srand(time(NULL)); ///Creates a random seed based on computer clock
    
	printf("Rock = 1 // Paper = 2 // Scissors = 3\n"); // Prints the values linked to each choice

    for(i=0 ; i<5 ; i++) //Loop that makes the game play 5 rounds
	{
        printf("Pick a number from the options above:");	//Prompt imput from the user
        scanf("%d", player_choice);
        int computer_choice = rand() % 3 + 1; 	//Takes a random number from 1 to 3 using rand()
        if(*player_choice == 1)	//If player picks rock
		{
            if(computer_choice == 1)	//and computer picks rock its draw
			{
                printf("Draw\n");
            }
            else if(computer_choice == 2) //and computer picks paper player loses and gets a point
			{
                printf("Computer wins!\n");
                computer_score += 1;
            }
            else if(computer_choice == 3) //and computer picks scissor player wins and gets a point
			{
                printf("Player wins\n");
                player_score += 1;
            }	
        }
        else if(*player_choice == 2)		//Same process as before but with player picking paper
		{
            if(computer_choice == 2)
			{
                printf("Draw\n");
            }
            else if(computer_choice == 3)
			{
                printf("Player wins!\n");
                player_score += 1;
            }
            else if(computer_choice == 1)
			{
            	printf("Computer wins!\n");
            	computer_score += 1;
			}
        }
        else if(*player_choice == 3)		//Same process as before but with player picking scissors
		{
            if(computer_choice == 3)
			{
                printf("Draw\n");
            }
            else if(computer_choice == 2)
			{
                printf("Computer wins!\n");
                computer_score += 1;
            }
            else if(computer_choice == 1)
			{
                printf("Player wins!\n");
                player_score += 1;

            }
        }
        else
		{
            printf("The input was incorrectly formatted/outside the range // Check your input\n");	//The input was incorrectly formatted/outside the range
        }

    }
    if(computer_score > player_score)
	{
        printf("Computer wins best of 5:\n Final Score: %d to %d\n",computer_score,player_score); //If computer has more points, it wins and displays final score
    }
    else if(computer_score < player_score)
	{
        printf("Player wins best of 5:\n Final Score: %d to %d\n",player_score,computer_score); //If player has more points, it wins and displays final score
    }
    else if(computer_score == player_score) //If they both had the same it's a draw
	{
        printf("No winner it is a draw!\n");
    }
	free(player_choice);
    return 0;
}
