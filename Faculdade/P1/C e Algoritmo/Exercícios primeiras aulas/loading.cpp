#include <stdio.h>
#include <windows.h>

int main () {
	
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Deixar mais perto do centro verticalmente

	 while (1) 
	{
		printf ("\r\t\t\t \\");
		Sleep (200); //O Sleep é pra dar um "delay" entre um comando e outro
		printf ("\r\t\t\t |");
		Sleep (200);
		printf ("\r\t\t\t /");
		Sleep (200);
		printf ("\r\t\t\t -");
		Sleep (200);
	}	
}

