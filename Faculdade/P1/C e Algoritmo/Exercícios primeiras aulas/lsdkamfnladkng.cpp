#include <stdio.h>
#include <windows.h>

int main () {
	char barrinha [] = {'-', '\\', '|', '/', '-'};
	printf ("\n\n\t\t\t");
	
	printf("%d, %d", sizeof(barrinha), sizeof(char));
	/*	while (1) {
		for (int i=0; i < (sizeof(barrinha)/sizeof(char)); i++) {
			printf ("%c\b", barrinha [i]);
			Sleep (150);
		}
	}
	*/
}
