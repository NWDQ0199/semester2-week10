
#include <stdio.h>
#include <stdlib.h>

int add( int i, int j );

/* 
 * main: creating and testing function pointers
 */
int main( void ) {

    int (*operation)(int,int);  // function pointer for function with 2 integer arguments, returning an int

    int num1=2, num2=3; // data for arguments
    // compute the sum using the function - print out the operands and answer
    printf("%i+%i=%i\n",num1,num2,add(num1,num2));
    // compute the sum using the pointer - print out the operands and answer
    operation=&add;
    printf("%i+%i=%i\n",num1,num2,(*operation)(num1,num2));

    return 0;
}

/*
 * integer operation implementations
 */

int add( int i, int j ) {
    return i+j;
}
