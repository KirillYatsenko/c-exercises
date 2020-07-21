#ifndef MALLOC_H_INCLUDED
#define MALLOC_H_INCLUDED

typedef long Align; 
union header {      
    struct
    {
        union header *ptr;
        unsigned size;     
    } s;
    Align x; 
};
typedef union header Header;

void *malloc(unsigned nbytes);
void free(void *ap);
void *calloc(unsigned nbytes, unsigned size);

#endif