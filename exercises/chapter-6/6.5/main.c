#include <stdio.h>
#include "table.h"

int main()
{
    install("MAX_VALUE", "100");
    struct nlist *x = lookup("MAX_VALUE");

    printf("\n\nfrom table = %s\n\n", x->defn);
}