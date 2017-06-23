#include "../inc/ui_logic.h"
#include "../inc/sudoku.h"

int sudokuControls(){
   int xOffset = 51;
   int yOffset = 1;
   int xPosition = 0;
   int yPosition = 0;
   int i=0;
   int j=0;
   int xStep=7;
   int yStep=2;
   char cKeyboardInput[10];
   COORD coords;
   sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];

   initSudoku(1, field);

   system("cls");
   printField(field);

   coords.Y=yOffset+(yPosition*yStep);
   coords.X=xOffset+(xPosition*xStep);
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);

   do{
      navigation(cKeyboardInput);
      if(strcmp(cKeyboardInput, "UP")==0&&yPosition>0){
         yPosition--;
      }
      else if(strcmp(cKeyboardInput, "DOWN")==0&&yPosition<8){
         yPosition++;
      }
      else if(strcmp(cKeyboardInput, "LEFT")==0&&xPosition>0){
         xPosition--;
      }
      else if(strcmp(cKeyboardInput, "RIGHT")==0&&xPosition<8){
         xPosition++;
      }
      else if(strcmp(cKeyboardInput, "RETURN")==0&&field[xPosition][yPosition].disabled!=1){
         printf("%c",' ');
         field[xPosition][yPosition].value=0;
      }
      else if(cKeyboardInput[0]>48&&cKeyboardInput[0]<59&&field[xPosition][yPosition].disabled!=1){
         printf("%c",cKeyboardInput[0]);
         field[xPosition][yPosition].value=cKeyboardInput[0]-48;
      }

      coords.Y=yOffset+(yPosition*yStep);
      coords.X=xOffset+(xPosition*xStep);

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
   }while(0==0);
}

int mainMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char sKeypressed[10]; //The Array for what the user has pressed
	do{

		showStartScreen(iSelector); //shows the start screen


		navigation(sKeypressed); //handles keyboard input


		if(strcmp(sKeypressed, "ENTER")==0){ //checks if user selected an entry
            printf("\nPressed Enter\n");
			switch(iSelector){
				case 0:
				   sudokuControls();
				   break; //starts a quick game
				case 1:
				   handleLogin();
				   break; //opens log in screen
				case 2:
				   handleRegistration();
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

//===============================Functions===============================
/*
* =============================================================================
* ****readUsername(char *cUsername)****
* Parameter: char *cUsername
* Rückgabewert: -
* Beschreibung: Liest die Konsoleneingabe aus und speichert sie im 
		char-Array cUsername
* ============================================================================
*/
void readUsername(char *cUsername)
{
	int iError;
	do
	{
		fflush(stdin);
		iError = scanf("%s", &cUsername[0]);
	}while(iError == 0 || strcmp(cUsername,"") == 0);
}

/*
* =============================================================================
* ****readPassword(char *cPassword)****
* Parameter: char *cPassword
* Rückgabewert:
* Beschreibung: Liest die Konsoleneingabe aus und speichert sie im
		char-Array cPassword
* ============================================================================
*/
void readPassword(char *cPassword) //also used to read the password repeat
{
	int iError;
	do
	{
		fflush(stdin);
		iError = scanf("%s", &cPassword[0]);
	}while(iError == 0 || strcmp(cPassword,"") == 0);
}

/*
* =============================================================================
* ****handleLogin()****
* Parameter: -
* Rückgabewert: -
* Beschreibung: Geht durch die einzelnen Aufgaben beim Einloggen.
	        Sowohl das Aufrufen der Konsolenausgaben, das Einlesen der
	        Daten vom Nutzer, sowie die Datenbankabfrage und schließt
	        dies bei Erfolg mit einer neuen 
	        Konsolenausgabe (showLoggedInStartScreen) ab.
* ============================================================================
*/
void handleLogin()
{
	char cUsername[50], cPassword[50];
	char cKeyPressed[10];
	int iStayInMethod;

	do
	{		
		printLogin();
		printInputUsername();
		readUsername(cUsername);
		printInputPassword();
		readPassword(cPassword);

		
		loginUser(cUsername, cPassword);

		if (iUserId != 0)
		{
			showLoggedInStartScreen();
			iStayInMethod = 1;
		}

		else
		{
			printErrorMessage("Benutzername oder Passwort ist falsch.\
			Wenn Sie es erneut versuchen möchten, drücke Enter.");

			navigation(cKeyPressed);

			if (strcmp(cKeyPressed, "ENTER") == 0)
			{
				iStayInMethod = 0;
			}

			else
			{
				iStayInMethod = 1;
			}
		}
	
	} while (iStayInMethod == 0);
}

/*
-------------------------------------------------------------------------
Function handleRegistration()
given Parameters: -
return Value: -
Description: Goes through the task of resgistering (console 
			 as well as the logic behind it)
-------------------------------------------------------------------------
*/
/*
* =============================================================================
* ****handleRegistration()****
* Parameter: -
* Rückgabewert: -
* Beschreibung: Geht durch die einzelnen Aufgaben beim Registrieren.
	        Sowohl das Aufrufen der Konsolenausgaben, das Einlesen der
	        Daten vom Nutzer, sowie die Datenbankabfrage und schließt
	        dies bei Erfolg mit einer neuen 
	        Konsolenausgabe (showStartScreen) ab.
* ============================================================================
*/
void handleRegistration()
{
	char cUsername[50], cPassword[50], cPasswordRepeat[50];
	char cKeyPressed[10];
	int iStayInMethod;	
	int iTestUserExisting;	

	do
	{
		printRegister();
		printInputUsername();
		readUsername(cUsername);
		printInputPassword();
		readPassword(cPassword);
		printInputPasswordRepeat();
		readPassword(cPasswordRepeat);

		if (strcmp(cPassword, cPasswordRepeat) == 0) //if equal
		{
			iTestUserExisting=testIfUserNameExists(cName);
			if(iTestUserExisting==0) {
				insertNewUser(cName, cPasswort);
				iStayInMethod = 1;
				printSuccessMessage("Dein Benutzer wurde erfolgreich\
				angelegt.");
				system("pause");
				showStartScreen();
			}
	
			else if(iTestUserExisting == 1){
				printErrorMessage("Dieser Benutzer existiert bereits.\
				Wenn Sie es mit einem anderen Benutzernamen erneut\
				versuche möchten, drücken Sie Enter.");

				navigation(cKeyPressed);

				if (strcmp(cKeyPressed, "ENTER") == 0)
				{
					iStayInMethod = 0;
				}

				else
				{
					iStayInMethod = 1;
				}
			}
		}

		else
		{
			printErrorMessage("Passwörter stimmen nicht überein. Wenn Sie es erneut\
							  versuchen möchten, drücken Sie Enter.");
		

			navigation(cKeyPressed);

			if (strcmp(cKeyPressed, "ENTER") == 0)
			{
				iStayInMethod = 0;
			}

			else
			{
				iStayInMethod = 1;
			}

		}
	} while (iStayInMethod == 0);
}

void navigation(char cKeyPressed[])
{
	int ch;
	char numinput[2];
	int loop = 0;

	while (loop != 1) //Looping while none of the important keys is pressed
	{
		if (kbhit()) //Waiting for pressing a Key
		{
			ch=getch();
			if (ch==224 || ch==0) //Filtering 0 and 224,
								  //because they cause problems
			{
				ch=getch(); //Second getch to get the right key
			}
			switch (ch) //Giving "cKeyPressed" the right content
			{
        case 72: {strcpy(cKeyPressed, "UP"); loop=1; break;}; //Setting "loop" on to 1
        case 80: {strcpy(cKeyPressed, "DOWN"); loop=1; break;};//to brake the while loop
        case 75: {strcpy(cKeyPressed, "LEFT"); loop=1; break;};
        case 77: {strcpy(cKeyPressed, "RIGHT"); loop=1; break;};
        case 8: {strcpy(cKeyPressed, "RETURN"); loop=1; break;};
        case 27: {strcpy(cKeyPressed, "ESCAPE"); loop=1; break;};
        case 13: {strcpy(cKeyPressed, "ENTER"); loop=1; break;};
			  default:
			     if(ch>48&&59>ch){
                 numinput[0]=ch;
                 numinput[1]='\0';
                 strcpy(cKeyPressed, numinput);
			     }
              loop=1;
				  break;
			}
		}
	}
}
