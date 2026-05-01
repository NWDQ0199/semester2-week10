#include <stdio.h>
#include <string.h>

int main( void )
{

    char buffer[100] = "the quick brown fox jumped over the lazy dog";   // define a string to process

    // call strtok() repeatedly to tokenise the string on whitespace " "
    // print out each token
    char* tok=strtok(buffer," ");
    while(tok!=NULL)
    {
        printf("%s\n",tok);
        tok=strtok(NULL," ");
    }
    
    return 0;
}