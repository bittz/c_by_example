// Print CSV file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Format: %s filename\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open the file %s. %s\n", filename, strerror(errno));
        exit(1);
    }

    int c, in_word = 0;

    while ((c = getc(fp)) != EOF)
    {
        if (c == '"')
            in_word = !in_word;
        else if (!in_word && c == ',')
            putchar('\t');
        else if (in_word || c == '\n')
            putchar(c);
    }

    if (ferror(fp))
    {
        puts("I/O while reading");
        exit(1);
    }
    else if (feof(fp))
        puts("End of file reached");

    fclose(fp);

    return 0;
}