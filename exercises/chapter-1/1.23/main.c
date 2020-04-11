#include <stdio.h>

#define MAXLINE 1000
#define IN_COMMENT 1
#define OUT_COMMENT 0

int getLine(char line[], int maxline);
void removeComments(char lineWithComments[], char lineWithoutComments[], int length);

int main()
{
	int len;
	int max;
	int status = OUT_COMMENT;
	char line[MAXLINE];

	max = 0;

	while ((len = getLine(line, MAXLINE)) > 0)
	{
		char lineWithoutComments[MAXLINE];
		removeComments(line, lineWithoutComments, len);
		printf("%s\n", lineWithoutComments);
	}

	return 0;
}

void removeComments(char lineWithComments[], char lineWithoutComments[], int length)
{
	int status = OUT_COMMENT;
	int i, counter;
	for (i = 0, counter = 0; i < length; i++)
	{	
		if(status == IN_COMMENT || (lineWithComments[i] == '/' && i + 1 < length && lineWithComments[i+1] == '/'))
		{
			status = IN_COMMENT;
		}
		else
		{
			lineWithoutComments[counter] = lineWithComments[i];
			++counter;
		}
	}		
}
int getLine(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
	
