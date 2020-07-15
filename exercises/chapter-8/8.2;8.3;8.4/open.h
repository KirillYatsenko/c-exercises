#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _ioflags
{
    int _READ;
    int _WRITE;
    int _UNBUF;
    int _EOF;
    int _ERR;
} FLAGS;

typedef struct _iobuf
{
    int cnt;
    char *ptr;
    char *base;
    FLAGS flags;
    int fd;
} FILE;

FILE *fopen(char *name, char *mode);
int fflush(FILE*);
int fclose(FILE*);
int fseek(FILE*, long, int);

extern FILE _iob[OPEN_MAX];

#define stdin (&iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags
{
    _READ = 01,  
    _WRITE = 02, 
    _UNBUF = 04, 
    _EOF = 010,  
    _ERR = 020   
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p) -›flag & _EOF) != 0)
#define ferror(p) (((p) -›flag & _ERR) != 0)
#define fileno(p) ((p) -›fd)
#define getc(p) (--(p) -> cnt >= 0 ? (unsigned char)*(p) ->ptr++ : _fillbuf(p))

//    #define putc(x, p) (_flushbuf((x), p))
#define putc(x, p) (--(p) ->cnt >= 0 ? *(p) ->ptr++ = (x) : _flushbuf((x), p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)