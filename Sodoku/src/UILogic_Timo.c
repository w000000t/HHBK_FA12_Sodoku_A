#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

//Funcionprototypes
char readUsername();
char readPassword();
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
void showHighscores(char Stats[11][11]);
void printErrorMessage(char cErrorMessage[]);
void printSuccessMessage(char cSuccessMessage[]);

//===============================Functions===============================
/*
-------------------------------------------------------------------------
Function readUsername()
given Parameters: -
return Value: cUsername
Description: Reads the input of the user and returns it (to save it in
			 a variable)
-------------------------------------------------------------------------
*/
char readUsername()
{
	char cUsername[] = "";
	char *cUsernamePtr;
	cUsernamePtr = &cUsername[0];
	int iError;
	do
	{
		fflush(stdin);
		iError = scanf("%s", &cUsername);
	}while(iError == 0 || strcmp(cUsername,""));

	return *cUsernamePtr;
}

/*
-------------------------------------------------------------------------
Function readPassword()
given Parameters: -
return Value: *cPasswordPtr
Description: Reads the input of the user and returns it (to save it in
			 a variable)
-------------------------------------------------------------------------
*/
char readPassword() //readPasswordRepeat?
{
	char cPassword[] = "";
	char *cPasswordPtr;
	cPasswordPtr = &cPassword[0];
	int iError;

	do
	{
		fflush(stdin);
		iError = scanf("%s", &cPassword);
	}while(iError == 0 || strcmp(cPassword,"") != 0);

	return *cPasswordPtr;
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
	char cUsername[] = "", cPassword[] = "";

	printLogin();
	printInputUsername();
	cUsername[] = readUsername();
	printInputPassword();
	cPassword[] = readPassword();

	/*Database Query Method
	
	if (Query found something)
	{
		showLoggedInStartScreen();
	}

	else
	{
		printErrorMessage("Benutzername oder Passwort ist falsch. 
		Bitte versuchen Sie es erneut.");
	}
	*/
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
	char cUsername[] = "", char cPassword[] = "", cPasswordRepeat[] = "";

	printRegister();
	printInputUsername();
	cUsername[] = readUsername();
	printInputPassword();
	cPassword[] = readPassword();
	printInputPasswordRepeat();
	cPasswordRepeat[] = readPassword();

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
			Bitte wählen Sie einen anderen Benutzernamen");
		}
		*/
	}

	else
	{
		printErrorMessage("Passwörter stimmen nicht überein. Bitte versuchen Sie es erneut.");
	}
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