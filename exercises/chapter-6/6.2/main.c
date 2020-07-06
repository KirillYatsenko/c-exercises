#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct lnode
{
    struct lnode *next;
    char *word;
};

struct tnode
{
    char *word;
    struct lnode *next;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int indx);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *_strdup(char *);
int _strindx(char *a, char *b);
struct lnode *lalloc(void);
void listprint(struct lnode *l);

char buf[BUFSIZE];
int bufp = 0;

int main(int argc, char **argv)
{
    int indx = 6;
    if(argc > 1)
        indx = atoi(*(++argv));

    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, indx);

    printf("\n\nPrinting tree\n");
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int indx)
{
    int cond;
    if (p == NULL)
    {
        /* a new word has arrived */
        p = talloc();
        /* make a new node */
        p->word = _strdup(w);
        p->left = p->right = NULL;
    }
    else if ((cond = _strindx(w, p->word)) >= indx)
    {
        struct lnode *next = lalloc();
        next->word = _strdup(w);
        p->next = next;
    }
    /* repeated word */
    else if (cond < 0)
        /* less than into left subtree */
        p->left = addtree(p->left, w, indx);
    else
        /* greater than into right subtree */
        p->right = addtree(p->right, w, indx);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%s\n", p->word);
        listprint(p->next);
        treeprint(p->right);
    }
}

void listprint(struct lnode *l)
{
    if (l != NULL)
    {
        printf("%s\n", l->word);
        listprint(l->next);
    }
};

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* lalloc: make a lnode */
struct lnode *lalloc(void)
{
    return (struct lnode *)malloc(sizeof(struct lnode));
};

char *_strdup(char *s)
{
    char *p;
    /* make a duplicate of s */
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim)
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

// return first different char
int _strindx(char *a, char *b)
{
    int i;
    for (i = 0; *(a + i) != '\0' && *(b + i) != '\0' && *(a + i) == *(b + i); i++)
        ;

    return *(a + i) == '\0' && *(b + i) == '\0' ? -1 : i;
}