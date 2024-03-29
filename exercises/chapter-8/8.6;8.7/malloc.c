#include "malloc.h"

#define NULL 0
#define NALLOC 1024

static Header *morecore(unsigned nu);

static Header base;
static Header *freep = NULL;

void *_malloc(unsigned nbytes)
{
    if (nbytes == 0)
        return NULL;

    Header *p, *prevp;
    unsigned nunits;
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr)
    {
        if (p->s.size >= nunits)
        {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if (p == freep)
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

static Header *morecore(unsigned nu)
{
    char *cp, *sbrk(int);
    Header *up;
    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *)-1)
        return NULL;
    up = (Header *)cp;
    up->s.size = nu;
    _free((void *)(up + 1));
    return freep;
}

void *_calloc(unsigned n, unsigned size)
{
    char *malloced = _malloc(n * size);

    for (int i = 0; i < n * size; i++)
        malloced[i] = 0;

    return malloced;
}

void _free(void *ap)
{
    Header *bp, *p;
    bp = (Header *)ap - 1;

    if (bp->s.size == 0)
        return;

    if(freep == NULL)
    {
        freep = bp;
        freep->s.ptr = &base;
        base.s.ptr = freep;
        return;
    }

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    if (bp + bp->s.size == p->s.ptr)
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp)
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
        p->s.ptr = bp;
    freep = p;
}

void _bfree(void *ap, unsigned n)
{
    if (n < sizeof(Header))
        return;

    Header *bp = (Header *)ap;
    bp->s.ptr = NULL;
    bp->s.size = n - sizeof(Header);

    Header *z = (Header *)ap;

    _free(ap+sizeof(Header));
}
