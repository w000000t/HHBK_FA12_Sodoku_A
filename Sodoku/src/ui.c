 /*
================================================================================
Autoren: Knops, Kamps, Schikora, Scheile, Knapp, Marx
Klasse: FA12
Programmname: Sudoku
Datum: 26.06.2017
Beschreibung: Mit dem Programm ist es möglich Sudoku zu spielen. Das Programm
startet im Startbildschirm. Dort kann man sich Einloggen, Registrieren oder
ein Schnelles Spiel starten. Wenn man sich einloggt, hat man die Möglichkeit,
die Bestenliste einzusehen und ein gewertetes Spiel zu starten. Während des
spielens kann man in das Pausenmenue gehen um das Spiel zu beenden oder um
die Hilfe zu benutzen.
Version:0.2
Compiler: Visual Studio 2012
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "../inc/ui.h"

/*
* =============================================================================
* printSudokuRules
* Parameter: /
* Rückgabewert: /
* Beschreibung: Schreibt die Sudokuregln in das Konsolenfenster. Die Regeln
* die geschrieben werden lauten: "In jeder Zeile duerfen die Ziffern von 
* 1 bis 9 nur einmal vorkommen", "In jeder Spalte duerfen die Ziffern von 
* 1 bis 9 nur einmal vorkommen" und "In jedem Block duerfen die Ziffern von 
* 1 bis 9 nur einmal vorkommen".
* ============================================================================
*/
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


/*
* =============================================================================
* center
* Parameter: char message Array
* Rückgabewert: /
* Beschreibung: Zentriert die Nachricht und gibt sie im Konsolenfenster aus.
* ============================================================================
*/
void center(char message[]){
   int iWidth = 157, iNeededSpace;
   int i = 0;
   char* cNewString[300];

   int iOldStringLength = (int)strlen(message);

   char *cSpaces;
   iNeededSpace = (iWidth / 2) - (iOldStringLength / 2);
   cSpaces = malloc(iNeededSpace * sizeof(char));

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

/*
* =============================================================================
* whiteSpace
* Parameter: /
* Rückgabewert: /
* Beschreibung: Macht einen Tabstop.
* ============================================================================
*/
void whiteSpace()
{
    printf("\t");
}

/*
* =============================================================================
* bigWhiteSpace
* Parameter: /
* Rückgabewert: /
* Beschreibung: Macht insgesamt neun Tabstopps.
* ============================================================================
*/
void bigWhiteSpace()
{
    printf("\t\t\t\t\t\t\t\t\t");// 9 Tabstops
}

/*
* =============================================================================
* quadWhiteSpace
* Parameter: /
* Rückgabewert: /
* Beschreibung: Macht vier Tabstops.
* ============================================================================
*/
void quadWhiteSpace()
{
	printf("\t\t\t\t");
}

/*
* =============================================================================
* hexaWhiteSpace
* Parameter: /
* Rückgabewert: /
* Beschreibung: Macht sechs Tabstops.
* ============================================================================
*/
void hexaWhiteSpace()
{
	quadWhiteSpace();
	whiteSpace();
	whiteSpace();
}

/*
* =============================================================================
* lineBreaks
* Parameter: /
* Rückgabewert: /
* Beschreibung: Die Methode lässt den Cursor 2 Zeilen nach unten springen.
* ============================================================================
*/
void lineBreaks()
{
	printf("\n\n");
}

/*
* =============================================================================
* printErrorMessage
* Parameter: char cError
* Rückgabewert: /
* Beschreibung: Die methode gibt eine Fehlermeldung aus. Sie fängt an mit
* "Es ist ein Fehler aufgetreten:" und endet mit dem Fehler der als String 
*übergeben wird.
* ============================================================================
*/
void printErrorMessage(char *cError)
{
	lineBreaks();
	quadWhiteSpace();
	quadWhiteSpace();
	printf("Es ist ein Fehler aufgetreten: %s", cError);
}

/*
* =============================================================================
* showStartScreen
* Parameter: int iSelector
* Rückgabewert: /
* Beschreibung: Zeigt den Startbildschirm an, wenn man noch nicht Eingeloggt
* ist. Er zeigt die folgenden Menuepunkte: "Schnelles Spiel", "Login", 
* "Registrieren" und "Beenden".
* ============================================================================
*/
void showStartScreen(int iSelector)
{
	system("cls"); // Leert das Konsolenfenster
	lineBreaks();
   center("Sudoku"); // Zentriert das Wort "Sudoku"
	lineBreaks();
	center("Schnelles Spiel"); // Zentriert das Wort "Schnelles Spiel"
	printSelector(1, iSelector); // Wenn der Selector an der Position 1 ist
	// wird er hier angezeigt
	lineBreaks();
	center("Login"); // Zentriert das Wort "Login"
	printSelector(2, iSelector); // Wenn der Selector an der Position 2 ist
	// wird er hier angezeigt
	lineBreaks();
	center("Registrieren"); // Zentriert das Wort "Registrieren"
	printSelector(3, iSelector); // Wenn der Selector an der Position 3 ist
	// wird er hier angezeigt
	lineBreaks();
	center("Beenden"); // Zentriert das Wort "Beenden"
	printSelector(4, iSelector); // Wenn der Selector an der Position 3 ist
	// wird er hier angezeigt
	lineBreaks();
}

/*
* =============================================================================
* printLogin
* Parameter: /
* Rückgabewert: /
* Beschreibung: Leert das Fenster und schreibt das Wort "Login" 
* in die Konsole.
* ============================================================================
*/
void printLogin()
{
	system("cls"); // Leert das Konsolenfenster
	lineBreaks();
	center("Login"); // Zentriert das Wort "Login" und gibt es aus
}

/*
* =============================================================================
* printRegistration
* Parameter: /
* Rückgabewert: /
* Beschreibung: Leert das Fenster und schreibt das Wort "Registrierung" 
* in die Konsole.
* ============================================================================
*/
void printRegistration()
{
	system("cls"); // Leert das Konsolenfenster
	lineBreaks();
	center("Registrierung"); // Zentriert das Wort "Registrierung" und 
	// gibt es aus
}

/*
* =============================================================================
* printInputUsername
* Parameter: /
* Rückgabewert: /
* Beschreibung: Schreibt zentriert "Bitte geben Sie Ihren Usernamen ein:"
* in die Konsole.
* ============================================================================
*/
void printInputUsername()
{
	lineBreaks();
	center("Bitte geben Sie Ihren Usernamen ein:"); // Gibt den Satz 
	// zentriert aus
	lineBreaks();
	bigWhiteSpace();
}

/*
* =============================================================================
* printInputPassword
* Parameter: /
* Rückgabewert: /
* Beschreibung: Schreibt zentriert "Bitte geben Sie Ihr Passwort ein:"
* in die Konsole.
* ============================================================================
*/
void printInputPassword()
{
	lineBreaks();
	center("Bitte geben Sie Ihr Passwort ein:"); // Gibt den Satz zentrtiert
    // aus
	lineBreaks();
	bigWhiteSpace();
}

/*
* =============================================================================
* printInputPasswordRepeat
* Parameter: /
* Rückgabewert: /
* Beschreibung: Schreibt zentriert "Bitte wiederholen Sie das Passwort:"
* in die Konsole.
* ============================================================================
*/
void printInputPasswordRepeat()
{
	lineBreaks();
	center("Bitte wiederholen Sie das Passwort:"); // Gibt den Satz zentriert
	// aus
	lineBreaks();
	bigWhiteSpace();
}

/*
* =============================================================================
* printSuccessMessage
* Parameter: char Zeiger cUsername
* Rückgabewert: /
* Beschreibung: Zeigt an, dass die Registrierung geklappt hat.
* ============================================================================
*/
void printSuccessMessage(char* cUsername)
{
   char* cMessage;
   cMessage = strcat("Ihr Username ist: ", cUsername); // In cMessage wird
   // die Nachricht "Ihr Username ist: ..." reingeschrieben
	lineBreaks();

	center(cMessage); // Wird zentriert und ausgegeben
}

/*
* =============================================================================
* showDifficulty
* Parameter: int iSelector
* Rückgabewert: /
* Beschreibung: Zeigt die drei verschieden Schwierigkeitsstufen "Leicht", 
* "Mittel" und "Schwer" an.
* ============================================================================
*/
void showDifficulty(int iSelector)
{
	system("cls"); // Leert das Konsolenfenster
	lineBreaks();
	center("Schwierigkeitsgrad"); // Wird zentriert und ausgegeben
	lineBreaks();
	center("Leicht"); // Wird zentriert und ausgegeben
	printSelector(1, iSelector);
	lineBreaks();
	center("Mittel"); // Wird zentriert und ausgegeben
	printSelector(2, iSelector);
	lineBreaks();
	center("Schwer"); // Wird zentriert und ausgegeben
	printSelector(3, iSelector);
}

/*
* =============================================================================
* showLoggedInStartScreen
* Parameter: int iSelector
* Rückgabewert: /
* Beschreibung: Zeigt den Bildschirm für eingeloggte User an mit den Menue-
* punkten "Spielen", "Bestenliste", "Regeln", "Logout" und "Beenden".
* ============================================================================
*/
void showLoggedInStartScreen(int iSelector)
{
	system("cls"); // Konsolenfenster wird geleert
	lineBreaks();
	center("Sudoku"); // Wird zentriert und ausgegeben
	lineBreaks();
	center("Spielen"); // Wird zentriert und ausgegeben
	printSelector(1, iSelector);
	lineBreaks();
	center("Bestenliste"); // Wird zentriert und ausgegeben
	printSelector(2, iSelector);
	lineBreaks();
	center("Regeln"); // Wird zentriert und ausgegeben
	printSelector(3, iSelector);
	lineBreaks();
	center("Logout"); // Wird zentriert und ausgegeben
	printSelector(4, iSelector);
	lineBreaks();
	center("Beenden"); // Wird zentriert und ausgegeben
	printSelector(5, iSelector);
	lineBreaks();
}

/*
* =============================================================================
* printFieldHorizontal
* Parameter: /
* Rückgabewert: /
* Beschreibung: Zeichnet die horizontale Linie des Sudohufeldes.
* ============================================================================
*/
void printFieldHorizontal()
{
	int iCounter = 9;
	while(iCounter > 0) // Solange iCounter größer als Null ist führe 
	//die Schleife aus
	{
		printf("\xC5\xC4\xC4\xC4\xC4\xC4\xC4");
    iCounter--;
	}

	printf("\xC5\n");
}

/*
* =============================================================================
* showPauseMenu
* Parameter: int iSelector
* Rückgabewert: /
* Beschreibung: Zeigt das Pausenmenue an mit den Optionen "Zurueck zum Spiel",
* "Zeige Loesung" und "Spiel Beenden".
* ============================================================================
*/
void showPauseMenu(iSelector)
{
   system("cls"); // Leert das Konsolenfenster
   lineBreaks();
   center("Pause"); // Wird zentriert und ausgegeben
   lineBreaks();
   lineBreaks();
	center("Zurueck zum Spiel"); // Wird zentriert und ausgegeben
   printSelector(1, iSelector);
	lineBreaks();
	center("Zeige Loesung"); // Wird zentriert und ausgegeben
   printSelector(2, iSelector);
	lineBreaks();
	center("Spiel Beenden"); // Wird zentriert und ausgegeben
   printSelector(3, iSelector);
}

/*
* =============================================================================
* printField
* Parameter: sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS]
* [SUDOKU_FIELDS_Y_AXIS]
* Rückgabewert: /
* Beschreibung: Zeichnet das komplette Sudokufeld und zeigt in manchen Feldern
* Ziffern an. Unter dem Feld wird ein kleines Menue angezeigt.
* ============================================================================
*/
void printField(sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS])
{
   system("cls"); // Leert das Konsolenfenster
	int i,j;

	for(i = 0; i < SUDOKU_FIELDS_X_AXIS; i++){
		hexaWhiteSpace();
		printFieldHorizontal(); // Ruft die Methode auf um die horizontale
		// Spielfeldlinie zu zeichnen
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

/*
* =============================================================================
* showHighscore
* Parameter: /
* Rückgabewert: /
* Beschreibung: Zeigt die besten Spieler an mit dem Namen und 
* den erzielten Punkten.
* ============================================================================
*/
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

/*
* =============================================================================
* printSelector
* Parameter: int iPosition, int iSelector
* Rückgabewert: /
* Beschreibung: Zeigt einen Pfeil neben dem ausgewählten Menuepunkt an.
* ============================================================================
*/
void printSelector(int iPosition, int iSelector)
{
	if (iPosition - 1 == iSelector) // Wenn iPosition - 1 gleich ist wie 
	//iSelector dann Zeichne einen Pfeil
	{
		printf("\t<-"); // Zeichnet einen Pfeil
	}
}



