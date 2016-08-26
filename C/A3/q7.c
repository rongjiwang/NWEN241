/*
Name:Rongji Wang
ID:300139010
*/
/*
swap pointer address
*/
#include <stdio.h>

/* function prototypes */
void swap_ptr(int **, int **);

int main(void)
{ int p = 11, q = 22;
 int *ptrp = &p, *ptrq = &q;
 int **ppp = &ptrp, **ppq = &ptrq;

printf("%d%d\n",**ppp,**ppq);  //print out current order

 swap_ptr(ppp,ppq); /* &ptrp, &ptrq passed */
 /* to swap_ptr() */

 return 0;
} 
void swap_ptr(int **ppp, int **ppq){
	int *temp = *ppp;
	*ppp = *ppq;
	*ppq = temp;

printf("%d%d\n",**ppp,**ppq);  // print out after swap order
}

