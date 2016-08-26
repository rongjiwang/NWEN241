/*
Case:       NWEN241 - Assignment1 - Q3
Author:	    Rongji Wang
Student ID: 300139010
	 
Programme Description: Return the smallest the integer that User entered;

*/
#include<stdio.h>


int main(void){
	 int number;   /* number of integers to be entered */
         int value;    /* value input by user */
         int smallest; /* smallest number */
         int i;        /* counter */
  

	printf("Please enter the integers that you are going to compare: ");
	scanf("%d", &number);  /* User input */

	printf("Enter an number: ");
  	scanf("%d", &smallest);    /* set the first input as smallest value */

	for(i=1; i<number; i++){
		printf("Enter the number: ");
		scanf("%d", &value);         /* set user input as value */
		if(value < smallest){ 
			smallest = value;      /* reset the smallest value after the compare */
		}	
	}

	printf("Your smallest number is %d\n", smallest);
	return 0;

}
