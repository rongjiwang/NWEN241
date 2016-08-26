#include <stdio.h>


int stringcmp( const char *s1, const char *s2 ){
	int i,j;
	for(i=0; *s1 != '\0'; i++){
	s1++;
	}
	for(j=0; *s2 != '\0'; j++){  //check both arrays actual size
	s2++;
	}
	if(i!=j){              //if size doesn't match return 0
	return 0;
	}
	while(*s1 != '\0'){    //compare every char between both arrays
	if(*s1 != *s2){          
	return 0;
	}
	}
	return 1;          //duplicate array!

}

int main(void)
{

char string1[ 80 ]; /* create a string */
char string2[ 80 ]; /* create another string */
printf( "Enter two strings: " );
scanf( "%s%s", string1 , string2 );
printf( "The result is %d\n", stringcmp( string1, string2 ) );
return 0;

} 


