#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( void )
{

    char buffer[100] = "the quick brown fox jumped over the lazy dog";
    const int bufLen=100;

    char *argv[10];  // argv is an array of 10 char* pointers
    int argc=0;    // argc max is 10
    
    // iterate through each character of the string
    // every time you find a space ' ' assign a new token to argv[]
    int start=0;
    int end=0;
    bool fail=false;
    for(int i=0;i<100;i++)
    {
        if(buffer[i]=='\0')
        {
            end=i-1;
            int length=end-start+1;
            argv[argc]=NULL;
            char* p=malloc((length+1)*sizeof(char));
            if(!p)
            {
                fail=true;
                break;
            }
            argv[argc]=p;
            for(int j=0;j<length;j++)
            {
                argv[argc][j]=buffer[start+j];
            }
            argv[argc][length]='\0';
            argc++;
            break;
        }
        if(buffer[i]==' '||i==bufLen-1)
        {
            end=i-1;
            if(i==bufLen-1)
            {
                end=i;
            }
            int length=end-start+1;
            argv[argc]=NULL;
            char* p=malloc((length+1)*sizeof(char));
            if(!p)
            {
                fail=true;
                continue;
            }
            argv[argc]=p;
            for(int j=0;j<length;j++)
            {
                argv[argc][j]=buffer[start+j];
            }
            argv[argc][length]='\0';
            argc++;
            start=i+1;
        }
    }

    if(!fail)
    {
        // check output for argc,argv
        printf("argc = %d\n",argc);
        for(int k=0; k<argc; k++)
        {
            printf("argv[%d] = %s\n",k,argv[k]);
        }
    }

    for(int k=0;k<argc;k++)
    {
        free(argv[k]);
    }

    return 0;
}