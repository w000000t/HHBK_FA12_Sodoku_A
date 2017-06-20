#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

/******************************************************************************
Name: bigWhiteSpace
Parameter: /
Description:
******************************************************************************/
void bigWhiteSpace()
{
  printf("\t\t\t\t\t\t\t\t\t");// 9 Tabstops
}

/******************************************************************************
Name: whiteSpace
Parameter: /
Description:
******************************************************************************/
void whiteSpace()
{
  printf("\t");
}

/******************************************************************************
Name: quadWhiteSpace
Parameter: /
Description:
******************************************************************************/
void quadWhiteSpace()
{
  printf("\t\t\t\t");
}

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
void printErrorMessage(char fehler)
{
  lineBreaks();
  bigWhiteSpace();
  whiteSpace();
  printf("Es ist ein Fehler aufgetreten: %c", fehler);
}

/******************************************************************************
Name: showStartScreen
Parameter: /
Description:
******************************************************************************/
void showStartScreen()
{
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

void printSuccessMessage()
{

}

/******************************************************************************
Name: showDifficulty
Parameter: /
Description:
******************************************************************************/
void showDifficulty()
{
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
void loggedInStartScreen()
{
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
Name: printFieldVertical
Parameter: /
Description:
******************************************************************************/
void printFieldVertical()
{
  printf("\xB3      "); // Zeigt einen vertikalen Strich an und 6 Leerzeichen

}

/******************************************************************************
Name: printField
Parameter: /
Description:
******************************************************************************/
void printField()
{
	lineBreaks();
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printFieldHorizontal();
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
	hexaWhiteSpace();
	printf("\xB3      \xB3      \xB3      \xB3      \xB3      \xB3      ");
	printf("\xB3      \xB3      \xB3      \xB3\n");
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
	lineBreaks();
	bigWhiteSpace();
	printf("Bestenliste\n");
}
/******************************************************************************
Name: main
Parameter: /
Description:
******************************************************************************/
int main()
{
	showHighscore();

  system("pause");
  return 0;
}

