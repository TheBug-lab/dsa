#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* members;
	int top;
	int max;
}Stack;

Stack* createStack(int);
void push(Stack*, int);
void pop(Stack*);
void peek(Stack);
void show(Stack);
int isfull(Stack);
int isempty(Stack);

int main () {

	int temp, userInput;

	int max=5;
	Stack* mystack = createStack(max);

	while(1) {
		printf("\n1 push\n2 pop\n3 peek\n4 show\n9 Exit\n");
		scanf("%d", &userInput);
		switch ((int)userInput) {
			case 1:
				printf("enter value for the element: ");
				scanf("%d", &temp);
				push(mystack, temp);
				break;
			case 2:
				pop(mystack);
				break;
			case 3:
				peek(*mystack);
				break;
				
			case 4:
				show(*mystack);
				break;
			case 9:
				return 0;
			default:
				printf("invalid Input");
		}
		
		system("clear");
		printf("\nenter any key to continue\n");
	}
	return 0;
}

Stack* createStack( int _max) {
	Stack* newStack= (Stack *)malloc(sizeof(Stack));
	newStack->members=(int *)malloc(sizeof(int));
	newStack->top=-1;
	newStack->max=_max;
	
	return newStack;
}

void push (Stack* _mystack, int _value) {
	if(!isfull(*_mystack)) {
		_mystack->top++;
		_mystack->members[_mystack->top]=_value;
		printf("Item pushed\n");
		show(*_mystack);
	}
	else
		printf("stack overflow");
}

void pop(Stack* _mystack) {
	if(!isempty(*_mystack)){
		_mystack->top--;
		printf("item poped\n");
		show(*_mystack);
	}
	else
		printf("Emptied stack");
}

void peek(Stack _mystack){
	if(!isempty(_mystack)){
		printf("Element on the top of the Stack:  %d", _mystack.members[_mystack.top]);
	}
	else
		printf("Empty Stack\n");
}

void show(Stack _mystack) {
	if(!isempty(_mystack)) {
		printf("Elements at Stack: ");
		for(int i=_mystack.top;i>=0;--i){
			printf("%d ", _mystack.members[i]);
		}
	}
	else 
		printf("Empty stack");
}

int isfull(Stack _mystack) {
	if(_mystack.top==_mystack.max){
		return 1;
	}
	else 
		return 0;
}

int isempty(Stack _mystack) {
	if(_mystack.top==-1){
		return 1;
	}
	else 
		return 0;

}
