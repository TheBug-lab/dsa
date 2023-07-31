#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct Queue {
	node* front;
	node* rear;
}Queue;

Queue* createQueue();
int isEmpty(Queue);
void enQueue(Queue*,int);
int deQueue(Queue*);
void showQueue(Queue);

int main () {
	int userInput, tempValue;
	Queue* myQueue = createQueue();
	while(1) {
		printf("\n1 enqueue\n2 dequeue\n3 show\n4 exit\n");
		scanf("%d", &userInput);
		switch(userInput) {
			case 1:
				printf("\nEnter any number to insert inside queue: ");
				scanf("%d", &tempValue);
				enQueue(myQueue, tempValue);
				break;
			case 2:
				if(!deQueue(myQueue))
					printf("\nempty");
				else
					printf("\nremoved %d", deQueue(myQueue));
				break;
			case 3:
				showQueue(*myQueue);
				getchar();
				break;

			case 4:
				return 0;
		}
		system("clear");
		printf("\nEnter any option or press 4 to exit");
	}

	free(myQueue);
	return 0;
}


Queue* createQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->front = NULL;
	newQueue->rear = NULL;

	return newQueue;
}

int isEmpty(Queue _myQueue){
	return _myQueue.front==NULL;
}

void enQueue(Queue* _myQueue, int _value) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data=_value;
	newNode->next=NULL;

	if(isEmpty(*_myQueue)){
		_myQueue->front = newNode;
		_myQueue->rear = newNode;
	}
	else {
		_myQueue->rear->next=newNode;
		_myQueue->rear=newNode;
	}

}

int deQueue(Queue* _myQueue) {

	if(!isEmpty(*_myQueue)){

		node* current = (node*)malloc(sizeof(node));
		current=_myQueue->front;
		int temp=current->data;
		_myQueue->front=_myQueue->front->next;
		free(current);
		return temp;
	}
	else 
		return 0;
	
}

void showQueue(Queue _myQueue) {
	if(!isEmpty(_myQueue)){
		node* current = _myQueue.front;
		while(current != NULL){
			printf("%d ", current->data);
			current=current->next;

		}
	}
	else 
		printf("EMPTY");
	
}
	
