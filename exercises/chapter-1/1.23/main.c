#include <stdio.h>

#define MAXLINE 1000
#define IN_COMMENT 1
#define OUT_COMMENT 0

int getLine(char line[], int maxline);
int removeComments(char lineWithComments[], char lineWithoutComments[], int length, int status);

int main()
{
	int len;
	int max;
	int status = OUT_COMMENT;
	char line[MAXLINE];
	char lineWithoutComments[MAXLINE];

	max = 0;

	while ((len = getLine(line, MAXLINE)) > 0)
	{
		printf("before removing comments: %s\n", lineWithoutComments);
		status = removeComments(line, lineWithoutComments, len, status);
		printf("after removing comments: %s\n", lineWithoutComments);
	}

	return 0;
}

int removeComments(char lineWithComments[], char lineWithoutComments[], int length, int status)
{
	int multiLine = status;
	int i, current, next, counter;
	for (i = 0, counter = 0; i < length; i++)
	{
		current = lineWithComments[i];
		if (i + 1 == length)
			next = '\0';
		else
			next = lineWithComments[i+1];

		if (current == '/' && (next == '/' || next == '*'))
		{
			++i;
			if(next == '*')
				multiLine = IN_COMMENT;

			status = IN_COMMENT;
		}
		else if (status == IN_COMMENT &&  current == '*' && next == '/')
		{
			++i;
			multiLine = OUT_COMMENT;
			status = OUT_COMMENT;
		}
		else if (status == OUT_COMMENT)
		{
			lineWithoutComments[counter] = lineWithComments[i];
			++counter;
		}

		lineWithoutComments[counter + 1] = '\0';
	}

	return multiLine;
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


