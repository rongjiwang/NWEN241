//ID:300139010
//infix -> postfix

#include<stdio.h>
#include<stdlib.h> /*Malloc*/
#include<ctype.h>
#include<string.h>
#define Node_Size sizeof(StackNode)

struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;


void convertToPostfix( char infix[], char postfix[] );
//Convert the infix expression to postfix notation.
int isOperator( char c );
//Determine if c is an operator.
int precedence( char operator1, char operator2 );
//Determine if the precedence of operator1 is less than, equal to, or greater than
//the precedence of operator2. The function returns -1, 0 and 1, respectively.
void push( StackNodePtr *topPtr, char value );
//Push a value on the stack.
char pop( StackNodePtr *topPtr );
//Pop a value off the stack.
char stackTop( StackNodePtr topPtr );
//Return the top value of the stack without popping the stack.
int isEmpty( StackNodePtr topPtr );
//Determine if the stack is empty.
void printStack( StackNodePtr topPtr );
//Print the stack.
int totalIndex;

int main(void){
    int size = 500;
    char infix[size]; //user input array
    char postfix[size];//stack output array

    int iIndex = 0;
    int jIndex = 0;

    printf("Enter the infix expression: \n");
    scanf("%s", infix);

    printf("The original infix expression is: \n");
    while(infix[iIndex] != '\0')
    {
		printf("%c",infix[iIndex]); //show user input on screen
		iIndex++; //get total size of input
    }
    printf("\n");

    convertToPostfix(infix, postfix);
    printf("The expression in postfix notation is: \n");

    while(jIndex < totalIndex)
    {
		printf("%c", postfix[jIndex]); //printout stack post fix version
		jIndex++;
    }
    printf("\n");

    return 0;
}

void convertToPostfix( char infix[], char postfix[] ){
    int size = strlen(infix); //total size of char
    StackNodePtr stackPointer = NULL;
    int iIndex = 0;
    int jIndex = 0;

    push(&stackPointer,'('); //push a '(' into stack
    printStack(stackPointer);
    infix[size] = ')'; //set ')' to last of array infix
    while(isEmpty(stackPointer) != 1){ // not empty
        if(infix[iIndex] == '('){
            push(&stackPointer, infix[iIndex]); //push into stack '('
            printStack(stackPointer);
            iIndex++;
        }
        else if(isdigit(infix[iIndex])){  // [0-9] add to post array
            postfix[jIndex] = infix[iIndex];
            iIndex++;
            jIndex++;
        }
        else if(isOperator(infix[iIndex]) == 1){ // known operator
           if(isOperator(stackTop(stackPointer))==1) //other operator in stack
	    	{
				while(precedence(stackTop(stackPointer), infix[iIndex]) >0)
				{   char temp = pop(&stackPointer);
						printStack(stackPointer);   //swap position
						postfix[jIndex] = temp;
						jIndex++;
		    		}
				push(&stackPointer, infix[iIndex]); //push and print
				printStack(stackPointer);
				iIndex++;
	    	}
	    	else
	    	{
				push(&stackPointer, infix[iIndex]);// not operator on top of stack
				printStack(stackPointer);
				iIndex++;
	    	}
        }
        else if(infix[iIndex] == ')')
		{
	    while(stackTop(stackPointer) != '(')
	   		{
				char temp = pop(&stackPointer); //pop char and store into postfix array
				printStack(stackPointer);       //until find a left parenthesis
				postfix[jIndex] = temp;
				jIndex++;
	    	}
	    	pop(&stackPointer);
	    	printStack(stackPointer); // pop left parenthesis out and print
	    	iIndex++;
		}
    }
    totalIndex = jIndex;  //update the final postfix array size
}

//operator check
int isOperator( char c ){
if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%'){return 1;}
return 0;
}

//compare the power of operator
int precedence( char operator1, char operator2 ){
if(operator1=='^' && operator2!='^'){return 1;}
else if(operator1!='^' || operator2=='^'){return -1;}
else if(operator1==operator2){return 0;}
else if(operator1!='^' && operator2!='^'){
	if(operator1=='*' || operator1=='/' ||operator1=='%'){return 1;}
	else if (operator1=='+' || operator1=='-'){return -1;}
}

}

//push value into stack
void push( StackNodePtr *topPtr, char value ){

 StackNodePtr temp = malloc(Node_Size);
    if(temp != NULL)
    {
		temp->data = value;
		temp->nextPtr = *topPtr;
		*topPtr = temp;
    }
}

// pop the last char put into the stack
char pop( StackNodePtr *topPtr ){
    StackNodePtr temp = *topPtr;
    char c;
    c = temp->data;
    *topPtr = temp->nextPtr;

    return c;
}

//peek the last char put into the stack if array is not empty
char stackTop( StackNodePtr topPtr ){
if(isEmpty(topPtr) == -1){return topPtr->data;}

}

//check stack is empty or not
int isEmpty( StackNodePtr topPtr ){
if(topPtr == NULL){return 1;}
return -1;

}

//print correct information match with handout
void printStack( StackNodePtr topPtr ){
if(topPtr==NULL){printf("The stack is empty.\n");}
else{
    while(topPtr!=NULL){
        printf("%c      ", topPtr->data);
        topPtr = topPtr->nextPtr;
    }
    printf("NULL\n");
}
}
