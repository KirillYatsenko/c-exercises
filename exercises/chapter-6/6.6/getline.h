#ifndef GETWORD_H_INCLUDED
#define GETWORD_H_INCLUDED
#define MAX_LINE 1000
#define MAX_WORD 1000

int _getline(char s[], int lim);
int getword(char *line, char *word, int lim, int indx);

#endif