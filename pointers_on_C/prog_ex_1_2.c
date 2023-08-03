#include <stdio.h>
#include <stdlib.h>


int readbylines(void);

int
main(void)
{
    return readbylines();
}

int readbylines(void)
{
    int i = 0;
    char ch;
    
    putchar(i);
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
        if (ch == '\n')
        {
            i += 1;
            putchar(ch);
        }

    }
    return 1;
}