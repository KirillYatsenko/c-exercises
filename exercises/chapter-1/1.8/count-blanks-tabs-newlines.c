#include <stdio.h>

int main() {
	int c, nl, tb, bl;
	nl = 0;
	tb = 0;
	bl = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++tb;
		else if (c == ' ')
			++bl;
	}

	printf("\n\nnew lines count = %d\n", nl);
	printf("tabs count = %d\n", tb);
	printf("blank count = %d\n", bl);
}
