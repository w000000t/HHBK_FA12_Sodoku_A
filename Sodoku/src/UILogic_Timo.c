#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

//Funcionprototypes
void readUsername(char cUsername[]);
void readPassword(char cPassword[]);
void Login();
void Register();
void getHighscore(int user_id);

//Design-Functionprototypes
void showStartScreen(int iSelector);
void printLogin();
void printRegister();
void printInputUsername();
void printInputPassword();
void printInputPasswordRepeat();

void showDifficulty();
void showLoggedInStartScreen();
void showHighscores(char cHighscorer[]);
void printErrorMessage(char cErrorMessage[]);
void printSuccessMessage(char cSuccessMessage[]);

int main()
{
	Login();

	system("pause");
	return 0;
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
Function Login()
given Parameters: -
return Value: -
Description: Goes through the task of logging in (console 
			 as well as the logic behind it)
-------------------------------------------------------------------------
*/
void Login()
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
Function Register()
given Parameters: -
return Value: -
Description: Goes through the task of resgistering (console 
			 as well as the logic behind it)
-------------------------------------------------------------------------
*/
void Register()
{
	char cUsername[50], cPassword[50], cPasswordRepeat[50];
	char cKeyPressed[10];
	int iStayInMethod;

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
			printErrorMessage("Passwörter stimmen nicht überein. Wenn Sie es erneut\
							  versuche möchten, drücken Sie Enter.");
		

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