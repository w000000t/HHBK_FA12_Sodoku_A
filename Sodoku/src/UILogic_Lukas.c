#include<stdio.h>
#include<stdlib.h>
#include<string.h>         

int mainMenu(){	
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10]; //The Array for what the user has pressed
	
	do{
	
		showStartscreen(iSelector); //shows the start screen

		navigation(sKeypressed); //handles keyboard input

		if(strcmp(sKeypressed, "ENTER")){ //checks if user selected an entry
			switch(iSelector){
				case 0: quickGame(); break; //starts a quick game
				case 1: Login(); return 1; break; //opens log in screen
				case 2: Register(); break; //opens register screen
				case 3: return 1; //exits program
				default: printErrorMessage("Error! Incorrect Input!"); break;
			}
		}

		if(strcmp(sKeypressed, "UP")){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=3; //moves selector to the last entry
			}
		}

		if(strcmp(sKeypressed, "DOWN")){ //cehcks if the user pressed "down"
			if(iSelector<3){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(!strcmp(sKeypressed, "RETURN")||
		!(iSelector==3&&strcmp(sKeypressed, "ENTER")));
	//while the user hasn't pressed return or enter on the last entry
}

int loggedInMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10];

	do{
		//shows start screen for logged in users
		showLoggedInStartScreen(iSelector); 

		naviagtion(sKeypressed); //handles keyboard input

		if(strcmp(sKeypressed, "ENTER")){ //checks if user pressed enter
			switch(iSelector){
				case 0: Game(); break; //starts game
				case 1: Highscores(); break; //shows highscore
				case 2: Rules(); break; //shows rules
				case 3: Logout(); break; //logs out
				case 4: return 1; //exits program
				default: printErrorMessage("Error! Incorrect Input!"); break;
			}
		}

		if(strcmp(sKeypressed, "UP")){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=4; //moves selector to the last entry
			}
		}

		if(strcmp(sKeypressed, "DOWN")){ //cehcks if the user pressed "down"
			if(iSelector<4){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(!strcmp(sKeypressed, "RETURN")||
		!(iSelector==3&&strcmp(sKeypressed, "ENTER")));
}

int difficulty(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10];
	char sDifficulty[10];

	do{
		//shows start screen for logged in users
		showLoggedInStartScreen(iSelector); 

		while (true)
		{
			naviagtion(sKeypressed); //handles keyboard input

			if(strcmp(sKeypressed, "ENTER")){ //checks if user pressed enter
				switch(iSelector){
					case 0: sDifficulty = "EASY"; break; //starts game
					case 1: sDifficulty = "NORMAL"; break; //shows highscore
					case 2: sDifficulty = "HARD"; break; //shows rules
					default: printErrorMessage("Error! Incorrect Input!"); break;
				}
			startGame(sDifficulty);
			}
		}


		if(strcmp(sKeypressed, "UP")){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=2; //moves selector to the last entry
			}
		}

		if(strcmp(sKeypressed, "DOWN")){ //cehcks if the user pressed "down"
			if(iSelector<2){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(!strcmp(sKeypressed, "RETURN")||
		!(iSelector==3&&strcmp(sKeypressed, "ENTER")));
}