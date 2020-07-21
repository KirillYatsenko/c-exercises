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

void *_malloc(unsigned nbytes);
void _free(void *ap);
void _bfree(void *ap, unsigned n);
void *_calloc(unsigned nbytes, unsigned size);

#endif