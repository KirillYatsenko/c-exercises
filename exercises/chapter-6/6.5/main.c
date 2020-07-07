#include <stdio.h>
#include "table.h"

int main()
{
    struct nlist *prev;

    install("MIN_VALUE", "20");
    install("MAX_VALUE", "100");
    struct nlist *x = lookup("MAX_VALUE", &prev);
    undef("MAX_VALUE");
    x = lookup("MAX_VALUE", &prev);

    if(x == NULL)
        printf("\n\n'%s' cannot be found\n\n", "MAX_VALUE");
    else
        printf("\n\nfrom table = %s\n\n", x->defn);
}