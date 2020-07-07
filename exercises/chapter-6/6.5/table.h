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

struct nlist *lookup(char *s, struct nlist **prev);
struct nlist *install(char *name, char *defn);
void undef(char *name);

#endif