#include<conio.h> //Header file for the kbhit command
#include<stdio.h>
#include<stdlib.h> 


void navigation(char keypressed[])
{
	int ch;
	int loop = 0;

	while (loop != 1) //Looping while none of the important keys is pressed
	{
		if (kbhit()) //Waiting for pressing a Key
		{
			ch=getch();
			if (ch==224 || ch==0) //Filtering 0 and 224, 
								  //because they cause problems
			{
				ch=getch(); //Second getch to get the right key
			}
			switch (ch) //Giving "keypressed" the right content
			{
			case 72: strcpy(keypressed, "UP"); loop=1; break; //Setting "loop" on to 1
			case 80: strcpy(keypressed, "DOWN"); loop=1; break;//to brake the while loop
			case 75: strcpy(keypressed, "LEFT"); loop=1; break;
			case 77: strcpy(keypressed, "RIGHT"); loop=1; break;
			case 8: strcpy(keypressed, "RETURN"); loop=1; break;
			case 27: strcpy(keypressed, "ESCAPE"); loop=1; break;
			case 13: strcpy(keypressed, "ENTER"); loop=1; break;
			default:
				break;
			}
		}
	}
}
