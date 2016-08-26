#include <stdio.h>
#define SIZE 10

void v_exchange_a(int a[]);
void v_exchange_p(int *p); 

int main(void)
{ int i, x[SIZE]; /* x[] has 10 int elements */

 for (i=0; i<SIZE; i++)
 x[i] = i; /* assign i to x[i] */
 v_exchange_a(x); /* call for value exchange */
 for (i=0; i<SIZE; i++)
 printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]);
 v_exchange_p(x); /* call for value exchange */
 for (i=0; i<SIZE; i++)
 printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]);
 return 0;
} 
void v_exchange_a(int a[]){

	int temp;
	for(int i = 0; i<(SIZE/2); i++){  //reverse the value by array location
	temp = a[SIZE-1-i];
	a[SIZE-1-i] = a[i];
	a[i] = temp;
	}
}

void v_exchange_p(int *p){

	int temp;
	for(int i=0; i<(SIZE/2); i++){  //reverse the value by array pointers
	temp = *(p+i);
	*(p+i) = *(p+(SIZE-1-i));
	*(p+(SIZE-1-i)) = temp;
	}
}
