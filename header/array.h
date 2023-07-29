#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class arrayOperation {

	public:
		void getElements(int *&, int );
		void showElements(int *&, int);
		void insertElement(int *&, int, int, int);
		void deleteElement(int *&, int, int);
};

void arrayOperation::getElements(int *&array, int size) {
		
	array = (int *)malloc(size * sizeof(int));

	cout<<"Enter elements for the array: ";
	for(int i =0; i<size; i++){

		cin>>array[i];
	}
}

void arrayOperation::showElements(int *&array, int size) {

	cout<<"New Array: ";

	for(int i=0; i<size; i++){

		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void arrayOperation::insertElement(int *&array, int size, int position, int item) {

	size++;
	int *array2 = (int *)realloc(array, size*sizeof(int));


	int j=size;
	
	while(j>position) {
		array2[j-1] = array2[j-2];
		j--;
	}

	array2[position-1] = item ;

	array = array2;


}
void arrayOperation::deleteElement(int  *&array, int size, int position){

	int j= size;

	position--;
	while (j>position) {
		array[position]=array[position+1];

		position++;
	}

	array[size -1] =0;
}

#endif 
