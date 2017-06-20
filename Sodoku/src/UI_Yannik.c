#include "sudoku.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "UI_Yannik.h"

/******************************************************************************
Name: bigWhiteSpace
Parameter: /
Description: Does nine Tabstops
******************************************************************************/
void bigWhiteSpace()
{
	printf("\t\t\t\t\t\t\t\t\t");// 9 Tabstops
}

/******************************************************************************
Name: whiteSpace
Parameter: /
Description:Does one Tabstop
******************************************************************************/
void whiteSpace()
{
	printf("\t");
}

/******************************************************************************
Name: quadWhiteSpace
Parameter: /
Description:Does four Tabstops
******************************************************************************/
void quadWhiteSpace()
{
	printf("\t\t\t\t");
}

/******************************************************************************
Name: quadWhiteSpace
Parameter: /
Description:Does six Tabstops
******************************************************************************/
void hexaWhiteSpace()
{
	quadWhiteSpace();
	whiteSpace();
	whiteSpace();
}

/******************************************************************************
Name: lineBreaks
Parameter: /
Description:
******************************************************************************/
void lineBreaks()
{
	printf("\n\n");
}

/******************************************************************************
Name: printErrorMessage
Parameter: /
Description:
******************************************************************************/
void printErrorMessage(char error)
{
	lineBreaks();
	bigWhiteSpace();
	whiteSpace();
	printf("Es ist ein Fehler aufgetreten: %c", error);
}

/******************************************************************************
Name: showStartScreen
Parameter: /
Description:
******************************************************************************/
void showStartScreen()
{
	system("cls");
	lineBreaks();
	bigWhiteSpace();
	printf("	Sudoku");
	lineBreaks();
	bigWhiteSpace();
	printf("Schnelles Spiel");
	lineBreaks();
	bigWhiteSpace();
	printf(" Login");
	lineBreaks();
	bigWhiteSpace();
	printf("Registrieren");
	lineBreaks();
	bigWhiteSpace();
	printf("	Beenden");
	lineBreaks();
}

/******************************************************************************
Name: printLogin
Parameter: /
Description:
******************************************************************************/
void printLogin()
{
	system("cls");
	lineBreaks();
	bigWhiteSpace();
	printf("Login");
}

/******************************************************************************
Name: printRegistration
Parameter: /
Description:
******************************************************************************/
void printRegistration()
{
	system("cls");
	lineBreaks();
	bigWhiteSpace();
	printf("Registrierung");
}

/******************************************************************************
Name: printInputUsername
Parameter: /
Description:
******************************************************************************/
void printInputUsername()
{
	lineBreaks();
	bigWhiteSpace();
	printf("Bitte geben sie Ihren Username ein:");
}

/******************************************************************************
Name: printInputPassword
Parameter: /
Description:
******************************************************************************/
void printInputPassword()
{
	lineBreaks();
	bigWhiteSpace();
	printf(" Bitte geben sie Ihr Passwort ein:");
}

/******************************************************************************
Name: printInputPasswordRepeat
Parameter: /
Description:
******************************************************************************/
void printInputPasswordRepeat()
{
	lineBreaks();
	bigWhiteSpace();
	printf("Bitte wiederholen sie das Passwort:");
}

void printSuccessMessage(char username)
{
	lineBreaks();
	bigWhiteSpace();
	whiteSpace();
	printf("Es ist ein Fehler aufgetreten: %c", username);
}

/******************************************************************************
Name: showDifficulty
Parameter: /
Description:
******************************************************************************/
void showDifficulty()
{
	system("cls");
	lineBreaks();
	quadWhiteSpace();
	quadWhiteSpace();
	printf("    Schwierigkeitsgrad");
	lineBreaks();
	bigWhiteSpace();
	printf("  Leicht");
	lineBreaks();
	bigWhiteSpace();
	printf("  Mittel");
	lineBreaks();
	bigWhiteSpace();
	printf("  Schwer");
}

/******************************************************************************
Name: loggedInStartScreen
Parameter: /
Description:
******************************************************************************/
void showLoggedInStartScreen()
{
	system("cls");
	lineBreaks();
	bigWhiteSpace();
	printf("  Sudoku");
	lineBreaks();
	bigWhiteSpace();
	printf("  Spielen");
	lineBreaks();
	bigWhiteSpace();
	printf("Bestenliste");
	lineBreaks();
	bigWhiteSpace();
	printf("  Regeln");
	lineBreaks();
	bigWhiteSpace();
	printf("  Logout");
	lineBreaks();
	bigWhiteSpace();
	printf("  Beenden");
	lineBreaks();
}

/******************************************************************************
Name: printFieldHorizontal
Parameter: /
Description:
******************************************************************************/
void printFieldHorizontal()
{
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
	printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC5\n");
}

/******************************************************************************
Name: printField
Parameter: /
Description:
******************************************************************************/
void printField(sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS])
{

		/*sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];*/
	int i,j;

	for(i = 0; i < SUDOKU_FIELDS_X_AXIS; i++){
		hexaWhiteSpace();
		printFieldHorizontal();
		hexaWhiteSpace();
		for(j = 0; j < SUDOKU_FIELDS_Y_AXIS; j++){
			printf("\xB3  %i   ", sudoku_fields[i][j].value);
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




	// int i = 9; // Zählervariable
	// int j = 9; // Zählervariable

	// lineBreaks();

	// while (i > 0)
	// {
	//   int x = 9;
	//   int y = 28;
	//   bigWhiteSpace();
	//   while (x > 0)
	//   {
	//     printFieldHorizontal();
	//     x--;
	//   }
	//   printf("\xC5\n");
	//   bigWhiteSpace();
	//   while (y > 0)
	//   {
	//     printFieldVertical();

	//     if (y == 10||y == 20)
	//     {
	//       printf("\n");
	//       bigWhiteSpace();
	//     }

	//     y--;

	//   }
	//   printf("\xB3\n");
	//   i--;
	// }
	//bigWhiteSpace();
	// while (j > 0)
	// {
	//   printFieldHorizontal();
	//   j--;
	// }
	// printf("\xC5\n");
}

void showHighscore()
{
	system("cls");
	lineBreaks();
	bigWhiteSpace();
	printf("Bestenliste\n");
}

void showIntro()
{
	//printf(" .----------------.  .----------------.  .----------------.  .--");
	//printf("--------------.  .----------------.  .----------------. \n");
	//printf("| .--------------. || .--------------. || .--------------. || .-");
	//printf("-------------. || .--------------. || .--------------. |\n");
	//printf("| |    _______   | || | _____  _____ | || |  ________    | || | ");
	//printf("____     | || |  ___  ____   | || | _____  _____ | |\n");
	//printf("| |   /  ___  |  | || ||_   _||_   _|| || | |_   ___ `.  | || | ");
	//printf(".'    `.   | || | |_  ||_  _|  | || ||_   _||_   _|| |\n");
	//printf("| |  |  (__ \_|  | || |  | |    | |  | || |   | |   `. \ | || | ");
	//printf("/  .--.  \  | || |   | |_/ /    | || |  | |    | |  | |\n");
	//printf("| |   '.___`-.   | || |  | '    ' |  | || |   | |    | | | || | ");
	//printf("| |    | |  | || |   |  __'.    | || |  | '    ' |  | |");
}


