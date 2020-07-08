#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *lookup(char *s, struct nlist **prev);
struct nlist *install(char *name, char *defn);
void undef(char *name);

#endif