/* Program to convert text in a file to lowercase */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <infile> <outfile>\n", argv[0]);
        return 1;
    }

    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Error: cannot access '%s'\n", argv[1]);
        return 2;
    }

    FILE* outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error: cannot access '%s'\n", argv[2]);
        return 3;
    }

    int character;
    while ((character = fgetc(infile)) != EOF) {
        int lower_char = tolower(character);
        fputc(lower_char, outfile);
    }

    fclose(outfile);
    fclose(infile);

    return 0;
}
