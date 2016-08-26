/*Name: Rongji Wang
ID: 300139010*/

#include <stdio.h>
/* Note: Program assumes years are in the same century. */
struct date {
 int month, day, year;
};
/* function prototypes */
int compare_dates(struct date *, struct date *);
void put_date(struct date *);

int main(void)
{
 struct date d1, d2;
 printf("Enter first date (mm/dd/yy): ");
/* for you to complete */
scanf("%d/%d/%d",&d1.month, &d1.day, &d1.year);   //store user input
 printf("Enter second date (mm/dd/yy): ");
/* for you to complete */
scanf("%d/%d/%d",&d2.month, &d2.day, &d2.year);

// make sure the date is valid for the most cases, but not all , such as Feb cannot have 30th & 31st
if(d1.day > 31 || d1.day <=0 || d2.day >31 || d2.day <=0){
printf("The date is invalid\n");
return 0;
}
if(d1.month > 12 || d1.month <=0 || d2.month >12 || d2.month <=0){
printf("The date is invalid\n");
return 0;
}
if(d1.year > 10000 || d1.year <=0 || d2.year >10000 || d2.year <=0){
printf("The date is invalid\n");
return 0;
}

 if (compare_dates(&d1, &d2) < 0) {  // point the address
 put_date(&d1);
 printf(" is earlier than ");
 put_date(&d2);
 printf("\n");
 } else if(compare_dates(&d1, &d2) > 0){
 put_date(&d2);
 printf(" is earlier than ");
 put_date(&d1);
 printf("\n");
 }
else{
 put_date(&d2);
printf(" is the same date");   //if it is the same date, advise user
 put_date(&d1);
 printf("\n");
}
 return 0;
}

//find out earlier date between two user input 
int compare_dates(struct date *d1, struct date *d2)
{
/* for you to complete */
if(d1->year < d2->year){
return -1;
}
else if(d1->year > d2->year){
return 1;
}
else{
	if(d1->month < d2->month){
	return -1;
	}
	else if(d1->month > d2->month){
	return 1;
	}
	else{
		if(d1->day < d2->day){
		return -1;
		}
		else if(d1->day > d2->day){
		return 1;
		}
		else{return 0;}   //same date
}
}

}
void put_date(struct date *d)
{
 printf("%d/%d/%.2d", d->month, d->day, d->year);
} 
