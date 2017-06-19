#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void BigWhiteSpace()
{
  printf("                                                         ");
}

void whiteSpace()
{
  printf("  ");
}

void quadWhiteSpace()
{
  printf("    ");
}

void lineBreaks()
{
  printf("\n\n");
}

void printErrorMessage(char fehler)
{
  lineBreaks();
  BigWhiteSpace();
  whiteSpace();
  printf("Es ist ein Fehler aufgetreten: %c", fehler);
}

void showStartScreen()
{
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Sudoku");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  printf("Schnelles Spiel");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf(" Login");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Registrieren");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Beenden");
  lineBreaks();
}

void printLogin()
{
   lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Login");
}

void printRegistration()
{
   lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Registrierung");
}

void printInputUsername()
{
  lineBreaks();
  BigWhiteSpace();
  whiteSpace();
  printf("Bitte geben sie Ihren Username ein:");
}

void printInputPassword()
{
  lineBreaks();
  BigWhiteSpace();
  whiteSpace();
  printf(" Bitte geben sie Ihr Passwort ein:");
}

void printInputPasswordRepeat()
{
  lineBreaks();
  BigWhiteSpace();
  whiteSpace();
  printf("Bitte wiederholen sie das Passwort:");
}

void showDifficulty()
{
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Schwierigkeitsgrad");
   lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Leicht");
   lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Mittel");
   lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Schwer");
}

void loggedInStartScreen()
{
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Sudoku");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Spielen");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  printf("Bestenliste");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Regeln");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Logout");
  lineBreaks();
  BigWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  quadWhiteSpace();
  whiteSpace();
  whiteSpace();
  printf("Beenden");
  lineBreaks();
}

void printFieldHorizontal()
{
   printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
}

void printFieldVertical()
{
    printf("\xB3      ");
    
}

void printField()
{
  int i = 9;
  int j = 9;

  lineBreaks();

  while (i > 0)
  {
    int x = 9;
    int y = 28;
    BigWhiteSpace();
    while (x > 0)
    {
      printFieldHorizontal();
      x--;
    }
    printf("\xC5\n");
    BigWhiteSpace();
    while (y > 0)
    {
      printFieldVertical();

        if (y == 10||y == 20)
        {
          printf("\n");
          BigWhiteSpace();
        }

        y--;

    }
    printf("\xB3\n");
    i--;
  }
  BigWhiteSpace();
  while (j > 0)
  {
    printFieldHorizontal();
    j--;
  }
  printf("\xC5\n");
}

int main()
{
  printField();

  system("pause");
  return 0;
}

