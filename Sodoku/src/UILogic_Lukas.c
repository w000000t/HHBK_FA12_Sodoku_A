#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/************ Funktionsprotoypen *************/
int mainMenu();
int loggedInMenu();
int difficulty();


int main(){
   mainMenu();

   return 1;
}

int mainMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10]; //The Array for what the user has pressed
	do{

		//showStartscreen(iSelector); //shows the start screen


		navigation(sKeypressed); //handles keyboard input


		if(strcmp(sKeypressed, "ENTER")==0){ //checks if user selected an entry
            printf("\nPressed Enter\n");
			switch(iSelector){
				case 0:
				   //quickGame();
				   printf("Quick Game Selected\n");
				   break; //starts a quick game
				case 1:
				   //Login();
				   printf("Login Selected\n");
				   break; //opens log in screen
				case 2:
				   //Register();
				   printf("Register Selected\n");
				   break; //opens register screen
				case 3: return 1; //exits program
				default:
				   //printErrorMessage("Error! Incorrect Input!");
				   break;
			}
		}

		if(strcmp(sKeypressed, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=3; //moves selector to the last entry
			}
		}
		if(strcmp(sKeypressed, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<3){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}


		printf("\nKey: %s\n", sKeypressed);
		printf("\nSelector: %i\n", iSelector);

	}while(!strcmp(sKeypressed, "RETURN")==0&&
		!(iSelector==4&&strcmp(sKeypressed, "ENTER")==0));
	//while the user hasn't pressed return or enter on the last entry
}

int loggedInMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10];

	do{
		//shows start screen for logged in users
		//showLoggedInStartScreen(iSelector);

		navigation(sKeypressed); //handles keyboard input

		if(strcmp(sKeypressed, "ENTER")==0){ //checks if user pressed enter
			switch(iSelector){
				case 0: //Game(); break; //starts game
				case 1: //Highscores(); break; //shows highscore
				case 2: //Rules(); break; //shows rules
				case 3: //Logout(); break; //logs out
				case 4: return 1; //exits program
				default: //printErrorMessage("Error! Incorrect Input!"); break;
				   break;
			}
		}

		if(strcmp(sKeypressed, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=4; //moves selector to the last entry
			}
		}

		if(strcmp(sKeypressed, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<4){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
    }
	}while(!strcmp(sKeypressed, "RETURN")==0&&
		!(iSelector==4&&strcmp(sKeypressed, "ENTER")==0));
}

int difficulty(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10];
	int iCorrectInput = 0;

	do{
		//shows start screen for logged in users
		//showLoggedInStartScreen(iSelector);
      navigation(sKeypressed); //handles keyboard input

      if(strcmp(sKeypressed, "ENTER")==0){ //checks if user pressed enter
         switch(iSelector){
            case 0:
               //startGame("EASY");
               iCorrectInput++;
               break; //starts game
            case 1:
               //startGame("NORMAL");
               iCorrectInput++;
               break; //shows highscore
            case 2:
              // startGame("HARD");
               iCorrectInput++;
               break; //shows rules
            default: //printErrorMessage("Error! Incorrect Input!");
               break;
         }
      }


		if(strcmp(sKeypressed, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=2; //moves selector to the last entry
			}
		}

		if(strcmp(sKeypressed, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<2){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(!strcmp(sKeypressed, "RETURN")==0&&
		iCorrectInput<=0);
}
