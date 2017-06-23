/*
================================================================================
Autoren: Timo Scheile
Klasse: FA12
Programmname: UILogic.Timo.c
Datum: 23.06.2017
Beschreibung: Kümmert sich um die Logik der einzelnen Interfaces.
			  Abgesehen vom Aufbau der Konsolenausgaben, sowie der Datenbank.
Version: 1.0
Compiler: Visual Studio
===============================================================================
*/

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#include "UILogic_Timo.h"
//Funcionprototypes
/*void readUsername(char cUsername[]);
void readPassword(char cPassword[]);
void Login();
void Register();
void getHighscore(int user_id);*/

//Design-Functionprototypes
void showStartScreen(int iSelector);
void printLogin();
void printRegister();
void printInputUsername();
void printInputPassword();
void printInputPasswordRepeat();

void showDifficulty();
void showLoggedInStartScreen();
void showHighscores(char cHighscore[]);
void printErrorMessage(char cErrorMessage[]);
void printSuccessMessage(char cSuccessMessage[]);

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