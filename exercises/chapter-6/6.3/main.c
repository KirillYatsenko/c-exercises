#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

char *ignore[] =
    {
        "a",
        "an",
        "this",
        "the",
        "is"};

struct tnode
{
    char *word;
    int line;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int line);
void treeprint(struct tnode *);
int getword(char *, int, int *);
struct tnode *talloc(void);
char *_strdup(char *);
int needignore(char *w);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
    int line = 1;
    int linec = 1;
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD, &linec) != EOF)
        if (isalpha(word[0]) && !needignore(word))
        {
            root = addtree(root, word, line);
            line = linec;
        }
    treeprint(root);
    return 0;
}

int needignore(char *w)
{
    for (int i = 0; *(ignore + i); i++)
        if (strcmp(w, *(ignore + i)) == 0)
            return 1;

    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
    int cond;
    if (p == NULL)
    {
        /* a new word has arrived */
        p = talloc();
        /* make a new node */
        p->word = _strdup(w);
        p->line = line;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) < 0)
        /* less than into left subtree */
        p->left = addtree(p->left, w, line);
    else if (cond > 0)
        /* greater than into right subtree */
        p->right = addtree(p->right, w, line);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("line number - %d %s\n", p->line, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *_strdup(char *s)
{
    char *p;
    /* make a duplicate of s */
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim, int *line)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            if (*w == '\n')
                (*line)++;

            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
