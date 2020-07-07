#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "table.h"

#define HASHSIZE 1

unsigned hash(char *s);
static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *s, struct nlist **prev)
{
    struct nlist *np;

    int hashed = hash(s);
    *prev = hashtab[hashed];

    for (np = hashtab[hash(s)], *prev = hashtab[hash(s)]; np != NULL; *prev = np, np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    /* found */
    return NULL;
    /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np, *prev;
    unsigned hashval;
    if ((np = lookup(name, &prev)) == NULL)
    { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *)np->defn); /* already there */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

void undef(char *name)
{
    struct nlist *np, *prev;
    if ((np = lookup(name, &prev)) == NULL)
    {
        printf("\nerror: '%s' cannot be found in the table\n", name);
        return;
    }

    prev->next = np->next;
    free((void*)np);
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
