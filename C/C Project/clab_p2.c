//ID:300139010
//postfix calculation

#include<stdio.h>
#include<stdlib.h> /*Malloc*/
#include<ctype.h>
#include<string.h>
#define Node_Size sizeof(StackNode)

struct stackNode {
int data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

int evaluatePostfixExpression( char *expr );
//Evaluate the postfix expression.
int calculate( int op1, int op2, char operator );
//Evaluate the expression op1 operator op2.
void push( StackNodePtr *topPtr, int value );
//Push a value on the stack.
int pop( StackNodePtr *topPtr );
//Pop a value off the stack.
int isEmpty( StackNodePtr topPtr );
//Determine if the stack is empty.
void printStack( StackNodePtr topPtr );
//Print the stack.

int main(void){
    int size = 500;
    char postfix[size];
    printf("Enter a postfix expression:\n");
    scanf("%s", postfix);

    int l = strlen(postfix);
    postfix[l] = '\0'; //last index value is null

    printf("The value of the expression is: %d", evaluatePostfixExpression(postfix));
    printf("\n");

}

//evaluate the solution for postfix expression
int evaluatePostfixExpression( char *expr ){
    int i=0;
    StackNodePtr p = NULL;
    while(expr[i] != '\0'){
        if(isdigit(expr[i])){ //[0-9]
            push(&p, (expr[i]-'0')); // digit value = char value - '0' value
            printStack(p);    //push and print
        }
        if(expr[i]=='+' || expr[i]=='-'|| expr[i]=='*' ||
         expr[i]=='/' || expr[i]=='^' || expr[i] =='%'){
         int first = pop(&p);
        printStack(p);          //pop value out,right side will be out first
        int second = pop(&p);   // use second value as op1,
         printStack(p);         //second value has lower index as inside the array
         int ans = calculate(second, first, expr[i]);
         push(&p, ans);
         printStack(p);
         }
         i++;
    }
    return pop(&p);
}
int calculate( int op1, int op2, char operator ){
    if(operator == '+'){return op1+op2;}
    if(operator == '-'){return op1-op2;}
    if(operator == '*'){return op1*op2;}
    if(operator == '/'){return op1/op2;}
    if(operator == '%'){return op1%op2;}
    if(operator == '^'){
    int ans = 1;
    for(int i=0; i<op2; i++){ //power itself by op2/value times
        ans = ans*op1;
    }
    return ans;
    }

}

//push value into stack
void push( StackNodePtr *topPtr, int value ){
StackNodePtr temp = malloc(Node_Size);
    if(temp != NULL)
    {
		temp->data = value;
		temp->nextPtr = *topPtr;
		*topPtr = temp;
    }

}

// pop the last char put into the stack
int pop( StackNodePtr *topPtr ){
StackNodePtr temp = *topPtr;
    int c;
    c = temp->data;
    *topPtr = temp->nextPtr;

    return c;
}

//check stack is empty or not
int isEmpty( StackNodePtr topPtr ){
if(topPtr == NULL){return 1;}
return -1;
}

//print correct information match with handout
void printStack( StackNodePtr topPtr ){
    if(topPtr == NULL){
    printf("NULL \n");
    }
    else{
        while(topPtr != NULL){
        printf("%d      ", topPtr->data);
        topPtr = topPtr->nextPtr;
        }
        printf("NULL \n");
    }
}
