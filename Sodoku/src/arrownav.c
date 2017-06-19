#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


void navigation(char keypressed[])
{
	int ch;

	while (1)
	{
		if (kbhit())
		{
			ch=getch();
			if (ch==224 || ch==0)
			{
				ch=getch();
			}
			switch (ch)
			{
			case 72: keypressed="UP"; break;
			case 80: keypressed="DOWN"; break;
			case 75: keypressed="LEFT"; break;
			case 77: keypressed="RIGHT"; break;
			case 8: keypressed="RETURN"; break;
			case 27: keypressed="ESCAPE"; break;
			case 13: keypressed="ENTER"; break;
			default:
				break;
			}
		}
	}
}