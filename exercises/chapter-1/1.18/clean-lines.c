#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void cleanline(char s[], int length);

int main()
{
	int len;
	int max;
	char line[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		cleanline(line, len);
	}

	return 0;
}

int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}


void cleanline(char s[], int length)
{
	int i;
	for(i = length - 1; s[i] == '\t' || s[i] == " "; --i);
	
	s[i+1] = '\0';
}
