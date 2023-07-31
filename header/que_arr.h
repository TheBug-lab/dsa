#ifndef QUE_ARR_H
#define QUE_ARR_H

#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct {
	int member[max];
	int front;
	int rear;
}queue;

queue* createQueue();
void enqueue(queue*, int);
int dequeue(queue*);
void show(queue);
int isfull(queue);
int isempty(queue);

queue* createQueue() {
	queue* new = (queue*)malloc(sizeof(queue));
	new->front=0;
	new->rear=-1;

	return new;
}

int isempty(queue _myqueue) {
	return _myqueue.rear== -1;
}

int isfull(queue _myqueue) {
	return _myqueue.rear== max-1;
}

void enqueue(queue* _myqueue, int _value) {
	if(!isfull(* _myqueue)){
		_myqueue->rear++;
		_myqueue->member[_myqueue->rear]=_value;
	}
	else 
		printf("full");
}

int dequeue(queue* _myqueue){
	if(!isempty(* _myqueue)){
		int temp, i;
		temp =_myqueue->member[_myqueue->front];
		i= 0;
		while(i<=_myqueue->rear){
			_myqueue->member[i]=_myqueue->member[i+1];
			i++;
		}
		_myqueue->rear--;
	return temp;
	}
	else 
		return 0;
}

void show(queue _myqueue){

	if(!isempty(_myqueue)){
		printf("Items at Queue: ");
		for(int i=0;i<=_myqueue.rear;i++){
			printf("%d ",_myqueue.member[i]);
		}
	}
	else 
		printf("Empty");
}

#endif
