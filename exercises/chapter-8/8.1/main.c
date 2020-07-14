#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 200
int buf[BUFSIZE];

int main(int argc, char *argv[])
{
    int i = 0;

    int fd;
    void filecopy(int fd, char *, int);

    if (argc == 1)
        filecopy(0, "stdin", 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fd, *argv, 1);
                close(fd);
            }
    return 0;
}

void filecopy(int fd, char *filename, int fo)
{
    int n;

    while ((n = read(fd, buf, BUFSIZE)) > 0)
        if (write(fo, buf, n) != n)
            printf("\nerror: while reading '%s' file", filename);
}