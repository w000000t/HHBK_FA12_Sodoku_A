#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "../inc/ui.h"

void printSudokuRules() {

   char cKeyPressed[10];

   system("cls");

    center("Spielregeln");
    lineBreaks();
    center("In jeder Zeile duerfen die Ziffern von 1 bis 9 nur einmal "
                   "vorkommen");
   lineBreaks();
    center("In jeder Spalte duerfen die Ziffern von 1 bis 9 nur einmal "
                   "vorkommen");
   lineBreaks();
    center("In jedem Block duerfen die Ziffern von 1 bis 9 nur einmal"
            " vorkommen");

    navigation(cKeyPressed);
}

void center(char message[]){
   int iWidth = 157;
   int i = 0;
   char* cNewString[300];

   int iOldStringLength = (int)strlen(message);

   char cSpaces[((iWidth/2)-(iOldStringLength/2))+1];

   for(i=0;i<((iWidth/2)-(iOldStringLength/2));i++){
      cSpaces[i] = ' ';
   }
   cSpaces[i]= '\0';
   /*for(i=(int)strlen(cSpaces);i>0;i--){
      if(cSpaces[i]!=' '){
         cSpaces[i]='\0';
      }
   }*/

   sprintf(cNewString,"%s %s", cSpaces, message);

   printf("%s", cNewString);
}

//*****************************************************************************
//Name: whiteSpace
//Parameter: /
//Description:Does one Tabstop
//*****************************************************************************
void whiteSpace()
{
    printf("\t");
}

//*****************************************************************************
//Name: bigWhiteSpace
//Parameter: /
//Description: Does nine Tabstops
//*****************************************************************************
void bigWhiteSpace()
{
    printf("\t\t\t\t\t\t\t\t\t");// 9 Tabstops
}

//*****************************************************************************
//Name: quadWhiteSpace
//Parameter: /
//Description:Does four Tabstops
//*****************************************************************************
void quadWhiteSpace()
{
	printf("\t\t\t\t");
}

//*****************************************************************************
//Name: quadWhiteSpace
//Parameter: /
//Description:Does six Tabstops
//*****************************************************************************
void hexaWhiteSpace()
{
	quadWhiteSpace();
	whiteSpace();
	whiteSpace();
}

//*****************************************************************************
//Name: lineBreaks
//Parameter: /
//Description:
//*****************************************************************************
void lineBreaks()
{
	printf("\n\n");
}

//*****************************************************************************
//Name: printErrorMessage
//Parameter: char cError Error string
//Description:
//*****************************************************************************
void printErrorMessage(char *cError)
{
	lineBreaks();
	quadWhiteSpace();
	quadWhiteSpace();
	printf("Es ist ein Fehler aufgetreten: %c", cError);
}

//*****************************************************************************
//Name: showStartScreen
//Parameter: /
//Description:
//*****************************************************************************
void showStartScreen(int iSelector)
{
	system("cls");
	lineBreaks();
   center("Sudoku");
	lineBreaks();
	center("Schnelles Spiel");
	printSelector(1, iSelector);
	lineBreaks();
	center("Login");
	printSelector(2, iSelector);
	lineBreaks();
	center("Registrieren");
	printSelector(3, iSelector);
	lineBreaks();
	center("Beenden");
	printSelector(4, iSelector);
	lineBreaks();
}

//*****************************************************************************
//Name: printLogin
//Parameter: /
//Description:
//*****************************************************************************
void printLogin()
{
	system("cls");
	lineBreaks();
	center("Login");
}

//*****************************************************************************
//Name: printRegistration
//Parameter: /
//Description:
//*****************************************************************************
void printRegistration()
{
	system("cls");
	lineBreaks();
	center("Registrierung");
}

//*****************************************************************************
//Name: printInputUsername
//Parameter: /
//Description:
//*****************************************************************************
void printInputUsername()
{
	lineBreaks();
	center("Bitte geben Sie Ihren Usernamen ein:");
	lineBreaks();
	bigWhiteSpace();
}

//*****************************************************************************
//Name: printInputPassword
//Parameter: /
//Description:
//*****************************************************************************
void printInputPassword()
{
	lineBreaks();
	center("Bitte geben Sie Ihr Passwort ein:");
	lineBreaks();
	bigWhiteSpace();
}

//*****************************************************************************
//Name: printInputPasswordRepeat
//Parameter: /
//Description:
//*****************************************************************************
void printInputPasswordRepeat()
{
	lineBreaks();
	center("Bitte wiederholen Sie das Passwort:");
	lineBreaks();
	bigWhiteSpace();
}

void printSuccessMessage(char* cUsername)
{
   char* cMessage;
   cMessage = strcat("Ihr Username ist: ", cUsername);
	lineBreaks();

	center(cMessage);
}

//*****************************************************************************
//Name: showDifficulty
//Parameter: /
//Description:
//*****************************************************************************
void showDifficulty(int iSelector)
{
	system("cls");
	lineBreaks();
	center("Schwierigkeitsgrad");
	lineBreaks();
	center("Leicht");
	printSelector(1, iSelector);
	lineBreaks();
	center("Mittel");
	printSelector(2, iSelector);
	lineBreaks();
	center("Schwer");
	printSelector(3, iSelector);
}

//*****************************************************************************
//Name: loggedInStartScreen
//Parameter: /
//Description:
//*****************************************************************************
void showLoggedInStartScreen(int iSelector)
{
	system("cls");
	lineBreaks();
	center("Sudoku");
	lineBreaks();
	center("Spielen");
	printSelector(1, iSelector);
	lineBreaks();
	center("Bestenliste");
	printSelector(2, iSelector);
	lineBreaks();
	center("Regeln");
	printSelector(3, iSelector);
	lineBreaks();
	center("Logout");
	printSelector(4, iSelector);
	lineBreaks();
	center("Beenden");
	printSelector(5, iSelector);
	lineBreaks();
}

//*****************************************************************************
//Name: printFieldHorizontal
//Parameter: /
//Description:
//*****************************************************************************
void printFieldHorizontal()
{
	int iCounter = 9;
	while(iCounter > 0)
	{
		printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
    iCounter--;
	}

	printf("\xC5\n");
}

void showPauseMenu(iSelector)
{
   system("cls");
   lineBreaks();
   center("Pause");
   lineBreaks();
   lineBreaks();
	center("Zurueck zum Spiel");
   printSelector(1, iSelector);
	lineBreaks();
	center("Zeige Loesung");
   printSelector(2, iSelector);
	lineBreaks();
	center("Spiel Beenden");
   printSelector(3, iSelector);
}

//*****************************************************************************
//Name: printField
//Parameter: /
//Description:
//*****************************************************************************
void printField(sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS])
{
   system("cls");
	/*sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];*/
	int i,j;

	for(i = 0; i < SUDOKU_FIELDS_X_AXIS; i++){
		hexaWhiteSpace();
		printFieldHorizontal();
		hexaWhiteSpace();
		for(j = 0; j < SUDOKU_FIELDS_Y_AXIS; j++){

			if ( sudoku_fields[i][j].value == 0)
			{
				printf("\xB3      ");
			}
			else
			{
				printf("\xB3  %i   ", sudoku_fields[i][j].value);
			}
		}
		printf("\xB3\n");
	}

	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("Hilfe");
	hexaWhiteSpace();
	whiteSpace();
	printf("  Beenden\n");
	hexaWhiteSpace();
	printf("F1");
	hexaWhiteSpace();
	whiteSpace();
	printf("  ESC\n");

}

void showHighscore(){
    lineBreaks();
    quadWhiteSpace();
    quadWhiteSpace();
    printf("Bestenliste\n");
    lineBreaks();
    quadWhiteSpace();
    quadWhiteSpace();
    printf("Punkte");
    printf("\t\t\t");
    printf("Name");
    lineBreaks();
}

void printSelector(int iPosition, int iSelector)
{
	if (iPosition - 1 == iSelector)
	{
		printf("\t<-");
	}
}

void showIntro()
{
   /*char cKeyPressed[10];
	system("cls");
	printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("| |    _______   | || | _____  _____ | || |  ________    | || |     ____     | || |  ___  ____   | || | _____  _____ | |\n");
	printf("| |   /  ___  |  | || ||_   _||_   _|| || | |_   ___ `.  | || |   .'    `.   | || | |_  ||_  _|  | || ||_   _||_   _|| |\n");
	printf("| |  |  (__ \_|  | || |  | |    | |  | || |   | |   `. \ | || |  /  .--.  \  | || |   | |_/ /    | || |  | |    | |  | |\n");
	printf("| |   '.___`-.   | || |  | '    ' |  | || |   | |    | | | || |  | |    | |  | || |   |  __'.    | || |  | '    ' |  | |\n");
	printf("| |  |`\____) |  | || |   \ `--' /   | || |  _| |___.' / | || |  \  `--'  /  | || |  _| |  \ \_  | || |   \ `--' /   | |\n");
	printf("| |  |_______.'  | || |    `.__.'    | || | |________.'  | || |   `.____.'   | || | |____||____| | || |    `.__.'    | |\n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
   navigation(cKeyPressed);*/

   mainMenu();
}


