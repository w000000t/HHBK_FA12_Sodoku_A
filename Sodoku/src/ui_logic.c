#include "../inc/ui_logic.h"
#include "../inc/sudoku.h"
#include "../inc/login.h"

/*
 * =============================================================================
 *  ****help()****
 *  Parameter:  int xPosition, int yPosition, sudoku_field field
 *  Rückgabewert: -
 *  Beschreibung:    Setzt den Cursor auf die Position unter das Sudokufeld
 *                    Schreibt den text "moegliche loesungen":
 *                    Setzt den Cursor dann unter diesen Text und ruft die
 *                    Funktion auf, die die möglichen nummern für das
 *                    aktuelle Feld errechnet
 *  ============================================================================
 */
void help(int xPosition,
          int yPosition,
          sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){

   COORD coords; //COORDS for the cursor in the console
   coords.X = 48;
   coords.Y = 22;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
   //sets cursor position in the console

   printf("Moegliche Loesungen:");

   coords.Y = 23;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
   //sets cursor to under the text
   getPossibleNumbersForField(xPosition, yPosition, field);
   //calls function that calculates and prints the possible numbers
}

/*
 * =============================================================================
 *  ****pauseMenuHandler()****
 *  Parameter:       -
 *  Rückgabewert:    int iChoice
 *  Beschreibung:    Die Funktion behandelt die Benutzereingaben im Pausemenü
 *                    dazu wird erst die Funktion für die Darstellung aufgerufen
 *                    und anschließend auf eine Benutzereingabe gewartet
 *  ============================================================================
 */
int pauseMenuHandler(){

   char cKeyPressed[10];
   int iChoice=-1;
   int iSelector=0;

   do{

      showPauseMenu(iSelector); //shows pause menu
      navigation(cKeyPressed); //awaits keypress

      if(strcmp(cKeyPressed, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=2; //moves selector to the last entry
			}
		}

		if(strcmp(cKeyPressed, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<2){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

		if(strcmp(cKeyPressed, "ENTER")==0){
       iChoice=iSelector;
       return iChoice;
		}

   }while((strcmp(cKeyPressed, "ESC")!=0
           &&strcmp(cKeyPressed, "RETURN")!=0)
           &&iChoice!=0);

   return iChoice;

}



/*
 * =============================================================================
 *  ****sudokuControls()****
 *  Parameter:       -
 *  Rückgabewert:    -
 *  Beschreibung:    Die Funktion ist für die gesamte Sudokusteuerung zuständig.
 *                    Benutzereingaben werden behandelt und der Cursor auf dem
 *                     Spielfeld bewegt. Werte werden in das Sudokufield-array
 *                     geschrieben und nach jeder nutzereingabe wird das
 *                     Spiel validiert.
 *  ============================================================================
 */
void sudokuControls(){
   int redraw = 1; //to figure out whether the screen has to be redrawn
   int xOffset = 51; //The initial offset where the cursor should be to be at
                     //the top left sudoku field
   int yOffset = 1;
   int xPosition = 0; //the x Position of the cursor
   int yPosition = 0; //the y position of the cursor
   int xStep=7; //how far the next sudoku fields are apart on the x axis
   int yStep=2; // '' on the y axis

   int iMenuChoice=0; //what the user entered in the pause menu

   char cKeyboardInput[10]; //the chararray that stores the userinput

   COORD coords; //Coords for the Cursor Position

   sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];

   int iDifficulty =  difficulty(); //saves the difficulty in a variable

   if(iDifficulty==-1){ //if the user hasn't chosen a difficulty, exit game
      return 1;
   }
   system("cls"); //clear screen

   printField(field); //draws field

   //coordinate = the offset of the sudoku + (distance between cells*position)
   coords.Y=yOffset+(yPosition*yStep);
   coords.X=xOffset+(xPosition*xStep);

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);

   do{

      navigation(cKeyboardInput); //awaits user input

      if(redraw==1){ //checks if field needs to be redrawn
         printField(field); //draws field
         redraw=0;


         coords.Y=yOffset+(yPosition*yStep);
         coords.X=xOffset+(xPosition*xStep);

         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
         //set cursor position
      }

      //if user pressed "up" and position isn't at the very top
      if(strcmp(cKeyboardInput, "UP")==0&&yPosition>0){
         yPosition--; //move position up by 1
      }
      else if(strcmp(cKeyboardInput, "DOWN")==0&&yPosition<8){
         yPosition++; //move position down by 1
      }
      else if(strcmp(cKeyboardInput, "LEFT")==0&&xPosition>0){
         xPosition--; //move position left by one
      }
      else if(strcmp(cKeyboardInput, "RIGHT")==0&&xPosition<8){
         xPosition++; //move position right by one
      }
      else if(strcmp(cKeyboardInput, "RETURN")==0
              &&field[xPosition][yPosition].disabled!=1){
         printf("%c",' '); //empty the field
         field[yPosition][xPosition].value=0;
      }
      else if(strcmp(cKeyboardInput, "F1")==0){
         help(yPosition, xPosition, field); //prints the help
         redraw = 1; //tells that the sudoku needs to be redrawn
      }
      else if(strcmp(cKeyboardInput, "ESC")==0){
         iMenuChoice = pauseMenuHandler();

         if(iMenuChoice==1){
            solveSudoku(); //loest das Sudoku
         }
         else if(iMenuChoice==2){
            return; //bricht das spiel ab
         }

         printField(field); //das feld wird geschrieben
      }
      else if(cKeyboardInput[0]>48
              &&cKeyboardInput[0]<59
              &&field[xPosition][yPosition].disabled!=1){
         //schreibt die Nutzereingabe in die Konsole
         printf("%c",cKeyboardInput[0]);
         field[yPosition][xPosition].value=cKeyboardInput[0]-48;

         if(validateSudoku(field)==1)
         {
            //Victory fanfare
            Beep(523, 200);
            Beep(523, 110);
            Beep(523, 110);
            Beep(723, 500);
         }
      }

      //Check if sudoku is solved & validate
      //if validated, check if user is logged in

      coords.Y=yOffset+(yPosition*yStep);
      coords.X=xOffset+(xPosition*xStep);

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
   }while(0==0);
}

/*
 * =============================================================================
 *  ****mainMenu()****
 *  Parameter:       -
 *  Rückgabewert:    -
 *  Beschreibung:    Die Funktion überprüft Nutzereingaben, setzt den Cursor,
 *                    ruft die Funktion auf, die das Hauptmenü darstellt
 *                    und ruft beim drücken der Enter-Taste die entsprechende
 *                    Funktion auf.
 *  ============================================================================
 */

int mainMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char cKeyboardInput[10]; //The Array for what the user has pressed
	do{

		showStartScreen(iSelector); //shows the start screen


		navigation(cKeyboardInput); //handles keyboard input


		if(strcmp(cKeyboardInput, "ENTER")==0){ //checks if user selected an entry
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
				case 3: return; //exits program
				default:
				   //printErrorMessage("Error! Incorrect Input!");
				   break;
			}
		}

		if(strcmp(cKeyboardInput, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=3; //moves selector to the last entry
			}
		}

		if(strcmp(cKeyboardInput, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<3){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while((strcmp(cKeyboardInput, "RETURN")!=0&&
         strcmp(cKeyboardInput, "ESC")!=0)&&
		!(iSelector==4&&strcmp(cKeyboardInput, "ENTER")==0));
	//while the user hasn't pressed return or enter on the last entry
}

/*
 * =============================================================================
 *  ****mainMenu()****
 *  Parameter:       -
 *  Rückgabewert:    -
 *  Beschreibung:    Die Funktion überprüft Nutzereingaben, setzt den Cursor,
 *                    ruft die Funktion auf, die das Hauptmenü für
 *                    eingeloggte Benutzer darstellt
 *                    und ruft beim drücken der Enter-Taste die entsprechende
 *                    Funktion auf.
 *  ============================================================================
 */
int loggedInMenu(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char cKeyboardInput[10];

	do{
		//shows start screen for logged in users
		showLoggedInStartScreen(iSelector);

		navigation(cKeyboardInput); //handles keyboard input

		if(strcmp(cKeyboardInput, "ENTER")==0){ //checks if user pressed enter
			switch(iSelector){
				case 0: sudokuControls(); break;//Game(); break; //starts game
				case 1: system("cls");
                     getHighscoreTable();
                     navigation(cKeyboardInput);
                     break;//Highscores(); break; //shows highscore
				case 2: printSudokuRules(); break;//Rules(); break; //shows rules
				case 3: iUserId = -1; return 1; //Logout(); break; //logs out
				case 4: exit(0); //exits program
				default: //printErrorMessage("Error! Incorrect Input!"); break;
				   break;
			}
		}

		if(strcmp(cKeyboardInput, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=4; //moves selector to the last entry
			}
		}

		if(strcmp(cKeyboardInput, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<4){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(!(iSelector==4&&strcmp(cKeyboardInput, "ENTER")==0));
}


/*
 * =============================================================================
 *  ****difficulty()****
 *  Parameter:       -
 *  Rückgabewert:    int iSelector
 *  Beschreibung:    Die Funktion überprüft Nutzereingaben, setzt den Cursor,
 *                    ruft die Funktion auf, die die Auswahl der Schwierigkeit
 *                    darstellt. Die Funktion gibt dann einen int zurück, der
 *                    einen Schwierigkeitsgrad darstellt.
 *  ============================================================================
 */
int difficulty(){
	int iSelector=0; //The Selector where the "cursor" currently is
	char cKeyboardInput[10];
	int iCorrectInput = 0;

	do{
		//shows start screen for logged in users
		showDifficulty(iSelector);
      navigation(cKeyboardInput); //handles keyboard input

      if(strcmp(cKeyboardInput, "ENTER")==0){ //checks if user pressed enter
         switch(iSelector){
            case 0:
               return 1;
               iCorrectInput++;
               break;
            case 1:
               return 2;
               iCorrectInput++;
               break;
            case 2:
               return 3;
               iCorrectInput++;
               break;
            default: return -1;//printErrorMessage("Error! Incorrect Input!");
               break;
         }
      }


		if(strcmp(cKeyboardInput, "UP")==0){ //cehcks if the user pressed "up"
			if(iSelector>0){ //checks is the selector is not on first item
				iSelector--; //moves selector one up
			}
			else{
				iSelector=2; //moves selector to the last entry
			}
		}

		if(strcmp(cKeyboardInput, "DOWN")==0){ //cehcks if the user pressed "down"
			if(iSelector<2){//checks is the selector is not on last item
				iSelector++; //moves selector one down
			}
			else{
				iSelector=0; //moves selector to first entry
			}
		}

	}while(strcmp(cKeyboardInput, "RETURN")!=0&&
        strcmp(cKeyboardInput, "ESC")!=0&&
		iCorrectInput<=0);

		return -1;
}

//===============================Functions===============================
/*
-------------------------------------------------------------------------
Function readUsername()
given Parameters: -
return Value: -
Description: Reads the input of the user and returns it (to save it in
			 a variable)
-------------------------------------------------------------------------
*/
char readUsername(char *cUsername)
{
	char *cUsernamePtr = cUsername;
	int iError;
	do
	{
		fflush(stdin);
		iError = scanf("%s", &cUsername[0]);
	}while(iError == 0 || strcmp(cUsername,"") == 0);

	return *cUsernamePtr;
}

/*
-------------------------------------------------------------------------
Function readPassword()
given Parameters: -
return Value: -
Description: Reads the input of the user and returns it (to save it in
			 a variable)
-------------------------------------------------------------------------
*/
void readPassword(char *cPassword) //readPasswordRepeat?
{
	int iError;
	do
	{
		fflush(stdin);
		iError = scanf("%s", &cPassword[0]);
	}while(iError == 0 || strcmp(cPassword,"") == 0);
}

/*
-------------------------------------------------------------------------
Function handleLogin()
given Parameters: -
return Value: -
Description: Goes through the task of logging in (console
			 as well as the logic behind it)
-------------------------------------------------------------------------
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

		iUserId = 2;

		iStayInMethod=1;

		loggedInMenu();

		/*Database Query Method

		if (Query found something)
		{
			showLoggedInStartScreen();
		}

		else
		{
			printErrorMessage("Benutzername oder Passwort ist falsch.
			Wenn du es erneut versuchen möchtest, drücke Enter.");

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
	*/
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
void handleRegistration()
{
	char cUsername[50], cPassword[50], cPasswordRepeat[50];
	char cKeyPressed[10];
	int iStayInMethod;

	do
	{
		printRegistration();
		printInputUsername();
		readUsername(cUsername);
		printInputPassword();
		readPassword(cPassword);
		printInputPasswordRepeat();
		readPassword(cPasswordRepeat);

		if (strcmp(cPassword, cPasswordRepeat) == 0) //if equal
		{
			/*Database Query

			if userDoesNotExist
			{
				printSuccessMessage("Dein Benutzer wurde erfolgreich
				angelegt.");
				showStartScreen();
			}

			else
			{
				printErrorMessage("Dieser Benutzer existiert bereits.
				Wenn Sie es mit einem anderen Benutzernamen erneut
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
			*/
		}

		else
		{
			printErrorMessage("Passwörter stimmen nicht überein. Wenn Sie es erneut "\
							 "versuche möchten, drücken Sie Enter.");


			/*navigation(cKeyPressed);

			if (strcmp(cKeyPressed, "ENTER") == 0)
			{
				iStayInMethod = 0;
			}

			else
			{
				iStayInMethod = 1;
			}*/

		}
	} while (iStayInMethod == 0);
}

/*
-------------------------------------------------------------------------
Function getHighscore()
given Parameters: int user_id
return Value: -
Description: Gets the Highscores out of the database and also the best
			 score of the user with the given user_id and puts them into
			 an array.
			 This array then will be used to build up the Highscore page
-------------------------------------------------------------------------
*/
void getHighscore(int user_id)
{
	/*
	if loggedin
	{
		Database Query to get Highscore and personal Highscore of
		loggedinUser

		//Logic to change difficulty and played time to points ->
		to sort the Highscore
		//Logic to prevent bad display
		(e.g. 1. place | 2. place | ... | you at 3. place)

		showHighscores(Array);
	}

	else
	{
		printErrorMessage("Sie müssen eingeloggt sein, um diesen Bereich sehen zu können.");
	}
	*/
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
        case 27: {strcpy(cKeyPressed, "ESC"); loop=1; break;};
        case 13: {strcpy(cKeyPressed, "ENTER"); loop=1; break;};
        case 59: {strcpy(cKeyPressed, "F1"); loop=1; break;};
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
