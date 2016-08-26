#include <stdio.h>

int stringlen( const char *s ){
	int i;
	for(i=0; *s !='\0'; i++){ // count total, till a empty char
	s++;
	}
	return i;	
} /* prototype */

int main( void ){ 
	char string[ 80 ]; /* create char array */

	printf( "Enter a string: ");
 	scanf( "%[^\n]", string );
 		printf( "%d\n", stringlen( string ) );
	return 0;
} 
