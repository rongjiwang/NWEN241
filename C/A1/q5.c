/*
Case:       NWEN241 - Assignment1 - Q5
Author:	    Rongji Wang
Student ID: 300139010
*/
#include<stdio.h>
#include<ctype.h>

int main(void){

 char grade; /* current grade. */
 int aCount = 0; /* total a grades */
 int bCount = 0; /* total b grades */
 int cCount = 0; /* total c grades */ 
 int dCount = 0; /* total d grades */
 int eCount = 0; /* total e grades */ 

 	printf("Enter the grades (A, B, C, D, E)\n");
	printf("Enter 'X or x' for grade form: \n");

	
	while(grade != 'X'){          
		grade = toupper(getchar());     /* convert user enter char to upper case char */
		switch(grade){             /* count get increased when grade equals to case char */
		case'A':
			aCount++;
			break;
		case'B':
			bCount++;
			break;
		case'C':
			cCount++;
			break;
		case'D':
			dCount++;
			break;
		case'E':
			eCount++;
			break;
		
		}
	}
	printf("Total A grades = %d\n", aCount);   /* print out the out come sheet*/
	printf("Total B grades = %d\n", bCount);
	printf("Total C grades = %d\n", cCount);
	printf("Total D grades = %d\n", dCount);
	printf("Total E grades = %d\n", eCount);
 return 0;
}
