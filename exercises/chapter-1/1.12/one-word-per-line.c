#include <stdio.h>

#define IN 0
#define OUT 1

int main () {
	int c = getchar();
	int status = OUT;

	while (c != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			status = OUT;
		else if (status == OUT) {
			status = IN;
			putchar('\n');
			putchar(c);
		}
		else
			putchar(c);

		c = getchar();
	}

	printf('\n');
}
	
		
		

