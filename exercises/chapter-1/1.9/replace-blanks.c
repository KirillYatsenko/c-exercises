#include <stdio.h>

int main() {
	int c;
	int isBlank;

	c = getchar();

	while (c != EOF) {
		
		isBlank = 0;
		while(c == ' ' ) {
			isBlank = 1;
			c = getchar();
		}
		
		if(isBlank == 1)
			putchar(' ');

		if ( c != EOF) {
			putchar(c);
			c = getchar();
		}
	}
}
