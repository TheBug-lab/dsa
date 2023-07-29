#ifndef STACK_H
#define STACK_H

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

Stack* createStack(int _max) {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->members=(int *)malloc(_max * sizeof(int));
	newStack->top=-1;
	newStack->max = _max;
	return newStack;
}


void push (Stack* _mystack, int _value) {
	if(!isfull(*_mystack)) {
		_mystack->top++;
		_mystack->members[_mystack->top]=_value;
		printf("Item pushed");
	}
	else
		printf("stack overflow");
}

void pop(Stack* _mystack) {
	if(!isempty(*_mystack)){
		_mystack->top--;
		printf("item poped");
	}
	else
		printf("Emptied stack");
}

void peek(Stack _mystack){
	if(!isempty(_mystack)){
		printf("%d", _mystack.members[_mystack.top]);
	}
	else
		printf("Empty Stack");
}

void show(Stack _mystack) {
	if(!isempty(_mystack)) {
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

#endif
