#include "../inc/ui_logic.h"
#include "../inc/sudoku.h"
#include "../inc/login.h"

void help(int xPosition, int yPosition, sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
   char cPossibilities[30];
   int *iPossibilities=NULL;
   int iSize=0;
   COORD coords;
   coords.X = 48;
   coords.Y = 22;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);

   printf("Moegliche Loesungen:");

   coords.Y = 23;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
   getPossibleNumbersForField(xPosition, yPosition, field);
}

int pauseMenuHandler(){

   char cKeyPressed[10];
   int iChoice=-1;
   int iSelector=0;

   do{

      showPauseMenu(iSelector);
      navigation(cKeyPressed);

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

   }while((strcmp(cKeyPressed, "ESC")!=0&&strcmp(cKeyPressed, "RETURN")!=0)&&iChoice!=0);

   return iChoice;

}

int sudokuControls(){
   int redraw = 1;
   int xOffset = 51;
   int yOffset = 1;
   int xPosition = 0;
   int yPosition = 0;
   int i=0;
   int j=0;
   int xStep=7;
   int yStep=2;
   int iMenuChoice=0;
   char cKeyboardInput[10];
   COORD coords;
   sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];
   int iDifficulty =  difficulty();

   if(iDifficulty==-1){
      return 1;
   }

   for(i=0;i<SUDOKU_FIELDS_X_AXIS;i++){
      for(j=0;j<SUDOKU_FIELDS_Y_AXIS;j++){
         field[i][j].disabled = 0;
         field[i][j].value = 0;
      }
   }
   system("cls");

   printField(field);
   coords.Y=yOffset+(yPosition*yStep);
   coords.X=xOffset+(xPosition*xStep);
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);

   do{

      navigation(cKeyboardInput);

      if(redraw==1){
         printField(field);
         redraw=0;


         coords.Y=yOffset+(yPosition*yStep);
         coords.X=xOffset+(xPosition*xStep);

         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coords);
      }

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
         field[yPosition][xPosition].value=0;
      }
      else if(strcmp(cKeyboardInput, "F1")==0){
         help(yPosition, xPosition, field);
         redraw = 1;
      }
      else if(strcmp(cKeyboardInput, "ESC")==0){
         iMenuChoice = pauseMenuHandler();

         if(iMenuChoice==1){
            solveSudoku();
         }
         else if(iMenuChoice==2){
            return 1;
         }

         printField(field);
      }
      else if(cKeyboardInput[0]>48&&cKeyboardInput[0]<59&&field[xPosition][yPosition].disabled!=1){
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
				case 3: return 1; //exits program
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
				case 1: system("cls"); getHighscoreTable();  navigation(cKeyboardInput); break;//Highscores(); break; //shows highscore
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

/*
* =============================================================================
* ****readUsername(char *cUsername)****
* Parameter: char *cUsername
* RÃ¼ckgabewert: -
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
* RÃ¼ckgabewert:
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
	        Daten vom Nutzer, sowie die Datenbankabfrage und schlieÃt
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
			Wenn Sie es erneut versuchen mÃ¶chten, drÃ¼cke Enter.");

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
* =============================================================================
* ****handleRegistration()****
* Parameter: -
* RÃ¼ckgabewert: -
* Beschreibung: Geht durch die einzelnen Aufgaben beim Registrieren.
	        Sowohl das Aufrufen der Konsolenausgaben, das Einlesen der
	        Daten vom Nutzer, sowie die Datenbankabfrage und schlieÃt
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
				versuche mÃ¶chten, drÃ¼cken Sie Enter.");

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
			printErrorMessage("PasswÃ¶rter stimmen nicht Ã¼berein. Wenn Sie es erneut\
							  versuchen mÃ¶chten, drÃ¼cken Sie Enter.");
		

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
