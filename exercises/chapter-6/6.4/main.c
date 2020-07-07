#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, int count, char *w, int (*cmp)(char *, char *, int, int));
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *_strdup(char *);
struct tnode *sort(struct tnode *newroot, struct tnode *oldroot);
int _strcmp(char *a, char *b, int counta, int countb);
int countcmp(char *a, char *b, int counta, int countb);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, 1, word, _strcmp);

    struct tnode *sortedRoot;  
    sortedRoot = NULL;

    sortedRoot = sort(sortedRoot, root);
    treeprint(sortedRoot);

    return 0;
}

struct tnode *addtree(struct tnode *p, int count, char *w, int (*cmp)(char *, char *, int, int))
{
    int cond;
    if (p == NULL)
    {
        /* a new word has arrived */
        p = talloc();
        /* make a new node */
        p->word = _strdup(w);
        p->count = count;
        p->left = p->right = NULL;
    }
    else if ((cond = cmp(w, p->word, count, p->count)) == 0)
        p->count++;
    /* repeated word */
    else if (cond < 0)
        /* less than into left subtree */
        p->left = addtree(p->left, count, w, cmp);
    else
        /* greater than into right subtree */
        p->right = addtree(p->right, count, w, cmp);
    return p;
}

struct tnode *sort(struct tnode *newroot, struct tnode *oldroot)
{
    if (oldroot == NULL)
        return newroot;

    newroot = addtree(newroot, oldroot->count, oldroot->word, countcmp);
    sort(newroot, oldroot->left);
    sort(newroot, oldroot->right);

    return newroot;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
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

int countcmp(char *a, char *b, int counta, int countb)
{
    int res = countb - counta;
    
    if (res == 0)
        return -1;

    return res;
}

int _strcmp(char *a, char *b, int counta, int countb)
{
    return strcmp(a, b);
}