/*
Case:       NWEN241 - Assignment1 - Q4
Author:	    Rongji Wang
Student ID: 300139010
*/
#include<stdio.h>

int main(){
	int row; /* row counter */
 	int col; /* column counter */
	
	for(row=0; row<4; row++){   /* for loop will run 4times(0,1,2,3)  */
		for(col=0; col<=row; col++){    /* inner loop run time increase while row increase */
			printf("*");
		}
		printf("\n");  /* space out each inner loop */
	}
}
