#include <time.h>
#include <stdio.h>


unsigned int sum1(unsigned int from, unsigned int to){
	int total = 0;
	if(from > to){return total;}
	return from + sum1(from+1, to);  //recursion stack adding
} /* recursion */

unsigned int sum2(unsigned int from, unsigned int to){
	int total = 0;
	for(int i = from; i <= to; i++){  /* iteration */
		total += i;
	}
	return total;
}

unsigned int sum3(unsigned int from, unsigned int to){
	int total = to*(to+1)/2;
	if(from != 1){
	total -= sum3(1,from-1);    /* algorithm */
	}
	return total;
} 

/* algorithm: sum(1..n) = n*(n+1)/2, sum(m..n) = sum(1..n) - sum(1..m-1) */
int main(void)
{
 unsigned int s;
 unsigned from, to;
 double t1, t2;
 printf("Enter the fist integer:");
 scanf("%d", &from);
 printf("Enter the second integer:");
 scanf("%d", &to);
 t1 = clock();
 s = sum1(from, to);
 t2 = clock();
 printf("sum1=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
 t1 = clock();
 s = sum2(from, to);
 t2 = clock();
 printf("sum2=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
 t1 = clock();
 s = sum3(from, to);
 t2 = clock();
 printf("sum3=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
 return 0;
}

