#include <stdio.h>

int main() {
	int c = getchar();

	while(c != EOF) {
		if(c == '\t') {
			putchar('\\t');
		}
		else if (c == '\b') {
			putchar('\\b');
		}
		else if (c == '\\') {
			putchar('\\');
		}
		else {
			putchar(c);
		}

		c = getchar();
	}
}
