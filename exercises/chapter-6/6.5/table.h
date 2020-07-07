#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

struct nlist
{
    /* table entry: */
    struct nlist *next;
    /* next entry in chain */
    char *name;
    /* defined name */
    char *defn;
    /* replacement text */
};

struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
unsigned hash(char *s);

#endif