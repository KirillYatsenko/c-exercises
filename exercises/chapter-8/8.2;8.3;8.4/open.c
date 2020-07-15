#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "open.h"

#define PERMS 0666

FILE _iob[OPEN_MAX] = {
    {0, (char *)0, (char *)0, {1, 0, 0, 0, 0}, 0},
    {0, (char *)0, (char *)0, {0, 1, 0, 0, 0}, 1},
    {0, (char *)0, (char *)0, {0, 1, 1, 0, 0}, 2}};

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flags._READ == 0 && fp->flags._WRITE == 0)
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;

    if (*mode == 'r')
        fp->flags._READ = 1;
    else
        fp->flags._WRITE = 1;

    return fp;
}

int fflush(FILE *fp)
{
    if(!fp->flags._WRITE)
        return _ERR;

    int flushed = write(fp->fd, fp->base, fp->ptr - fp->base);
    
    fp->ptr = fp->base;
    fp->cnt = 0;

    return flushed;
}

int fclose(FILE *fp)
{
    if(fp->flags._ERR)
        return _ERR;

    int flushed = 0;
    if(fp->flags._WRITE)
        flushed = fflush(fp);
    
    fp->cnt = 0;
    fp->ptr = fp->base;
    free(fp->base);
    
    close(fp->fd);

    return flushed;
}

int fseek(FILE *fp, long offset, int origin)
{
    if(fp->flags._ERR)
        return 1;

    lseek(fp->fd, offset, origin);

    fp->ptr = fp->base;
    fp->cnt = 0;
    free(fp->base);

    return 0;
}

int _fillbuf(FILE *fp)
{
    int bufsize;
    if (fp->flags._EOF || fp->flags._ERR || !fp->flags._READ)
        return EOF;

    bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0)
    {
        if (fp->cnt == -1)
            fp->flags._EOF = 1;
        else
            fp->flags._ERR = 1;

        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char)*fp->ptr++;
}

int _flushbuf(int c, FILE *fp)
{
    if (!fp->flags._WRITE)
        return _ERR;

    int bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;

    fp->cnt = write(fp->fd, fp->base, bufsize) - 1;

    fp->ptr = fp->base;
    *(fp->base) = c;

    return c;
}