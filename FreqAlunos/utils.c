#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "utils.h"

int lePalavra(FILE *fp, char *s)
{
    int i = 0;
    int c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
            break;
    }
    if (c == EOF)
        return 0;
    else
        s[i++] = c;
    while (i < NPAL - 1 && (c = fgetc(fp)) != EOF && isalpha(c))
        s[i++] = c;
    s[i] = '\0';
    return 1;
}
