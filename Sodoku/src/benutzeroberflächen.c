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
  printf("                                                         ");
}

/******************************************************************************
Name: whiteSpace
Parameter: /
Description:
******************************************************************************/
void whiteSpace()
{
  printf("  ");
}

/******************************************************************************
Name: quadWhiteSpace
Parameter: /
Description:
******************************************************************************/
void quadWhiteSpace()
{
  printf("    ");
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
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Sudoku");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  printf("Schnelles Spiel");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf(" Login");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Registrieren");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Beenden");
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
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
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
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
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
  whiteSpace();
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
  whiteSpace();
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
  whiteSpace();
  printf("Bitte wiederholen sie das Passwort:");
}

/******************************************************************************
Name: showDifficulty
Parameter: /
Description:
******************************************************************************/
void showDifficulty()
{
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Schwierigkeitsgrad");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Leicht");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Mittel");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Schwer");
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
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Sudoku");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Spielen");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Bestenliste");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Regeln");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Logout");
  lineBreaks();
  bigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Beenden");
  lineBreaks();
}

/******************************************************************************
Name: printFieldHorizontal
Parameter: /
Description:
******************************************************************************/
void printFieldHorizontal()
{
  printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4"); // Zeigt ein Kreuz an und 6 horizontale Striche
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
  int i = 9; // Zählervariable
  int j = 9; // Zählervariable

  lineBreaks();

  while (i > 0)
  {
    int x = 9;
    int y = 28;
    bigWhiteSpace();
    while (x > 0)
    {
      printFieldHorizontal();
      x--;
    }
    printf("\xC5\n");
    bigWhiteSpace();
    while (y > 0)
    {
      printFieldVertical();

      if (y == 10||y == 20)
      {
        printf("\n");
        bigWhiteSpace();
      }

      y--;

    }
    printf("\xB3\n");
    i--;
  }
  bigWhiteSpace();
  while (j > 0)
  {
    printFieldHorizontal();
    j--;
  }
  printf("\xC5\n");
}

/******************************************************************************
Name: main
Parameter: /
Description:
******************************************************************************/
int main()
{
  printField();

  system("pause");
  return 0;
}

