#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[], int length);

int main()
{
	int len;
	int max;
	char line[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		reverse(line, len);
		printf("%s\n", line);
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

void reverse(char s[], int length)
{	
	int isOdd = 1;
	if(length % 2 == 0)
		isOdd = 0;

	int leftlimit = length/2;
	int rightlimit = leftlimit;

 	if(isOdd == 0)
	{
		leftlimit = length/2;
		rightlimit = leftlimit + 1;
	}

	int left;
	int right;

	for (left=0, right=length-1; left!=leftlimit && right!=rightlimit; ++left, --right)
	{
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;
	}
}
	
