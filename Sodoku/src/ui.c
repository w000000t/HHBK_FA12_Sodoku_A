#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "../inc/ui.h"

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
//Name: whiteSpace
//Parameter: /
//Description:Does one Tabstop
//*****************************************************************************
void whiteSpace()
{
    printf("\t");
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
    bigWhiteSpace();
    printf("	Sudoku");
    lineBreaks();
    bigWhiteSpace();
    printf("    Schnelles Spiel");
    printSelector(1, iSelector);
    lineBreaks();
    bigWhiteSpace();
    whiteSpace();
    printf(" Login");
    printSelector(2, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("     Registrieren");
    printSelector(3, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("	Beenden");
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
    bigWhiteSpace();
    printf("     Login");
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
    bigWhiteSpace();
    printf("Registrierung");
}

//*****************************************************************************
//Name: printInputUsername
//Parameter: /
//Description:
//*****************************************************************************
void printInputUsername()
{
    lineBreaks();
    quadWhiteSpace();
    quadWhiteSpace();
    printf("Bitte geben sie Ihren Username ein:\n");
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
    quadWhiteSpace();
    quadWhiteSpace();
    printf(" Bitte geben sie Ihr Passwort ein:\n");
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
    quadWhiteSpace();
    quadWhiteSpace();
    printf("Bitte wiederholen sie das Passwort:\n");
    bigWhiteSpace();
}

void printSuccessMessage(char cUsername)
{
    lineBreaks();
    bigWhiteSpace();
    whiteSpace();
    printf("Ihr Username ist: %c", cUsername);
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
    quadWhiteSpace();
    quadWhiteSpace();
    printf("    Schwierigkeitsgrad");
    lineBreaks();
    bigWhiteSpace();
    printf("  Leicht");
    printSelector(1, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("  Mittel");
    printSelector(2, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("  Schwer");
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
    bigWhiteSpace();
    printf("  Sudoku");
    lineBreaks();
    bigWhiteSpace();
    printf("  Spielen");
    printSelector(1, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("Bestenliste");
    printSelector(2, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("  Regeln");
    printSelector(3, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("  Logout");
    printSelector(4, iSelector);
    lineBreaks();
    bigWhiteSpace();
    printf("  Beenden");
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

void showPauseMenu()
{
    bigWhiteSpace();
    printf("Back to game");
    bigWhiteSpace();
    printf("Show solution");
    bigWhiteSpace();
    printf("Exit");
}

//*****************************************************************************
//Name: printField
//Parameter: /
//Description:
//*****************************************************************************
void printField(sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS])
{
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
    Sleep(5000);
}


void printSudokuRules() {

    printf("\t\t\t\t Spielregeln\n\n");
    printf("In jeder Zeile duerfen die Ziffern von 1 bis 9 nur einmal "
                   "vorkommen\n");
    printf("In jeder Spalte duerfen die Ziffern von 1 bis 9 nur einmal "
                   "vorkommen\n");
    printf("In jedem Block duerfen die Ziffern von 1 bis 9 nur einmal"
            " vorkommen\n");
}
