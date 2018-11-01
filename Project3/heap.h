#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Heap{

public:
    Heap();
    int parent(int n);
    int left(int n);
    int right(int n);
    T getItem(int n);
    void initializeMaxHeap(vector<T> dict1);
    void buildMaxHeap();
    void maxHeapify(int i);
    void heapSort();
    void printHeap();
    vector<T> getHeap();


private:
    vector<T> myHeap;
    int size;
};
//initializes a blank heap
template <class T>
Heap<T>::Heap(){
	myHeap.clear();
}
//finds parent of node at half of node index
template <class T>
int Heap<T>::parent(int n){
	return (n / 2);
}
//sets left value to twice the index to compare to max
template <class T>
int Heap<T>::left(int n){
	return (2*n);
}
//sets right value to twice the index plus one to compare to max
template <class T>
int Heap<T>::right(int n){
	return (2*n + 1);
}
//takes heap value at index
template <class T>
T Heap<T>::getItem(int n){
    return myHeap.at(n);
}
//moves larger values from end of heap to index
template <class T>
void Heap<T>::maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    //sets index as initial max value
    int max = i;
    //determines if left or right are greater than index
    if(l < size && myHeap[l] > myHeap[max]){
        max = l;
    }
    if(r < size && myHeap[r] > myHeap[max]){
        max = r;
    }
    //if so, the values are swapped, and max heapify is run recursively
    if(max != i){
        swap(myHeap.at(i), myHeap.at(max));

        maxHeapify(max);
    }
}
//runs maxHeapify for entire heap
template<class T>
void Heap<T>::buildMaxHeap(){
    size = myHeap.size();
	for (int i = myHeap.size()/2; i >= 1; i--){
		maxHeapify(i);
	}
}
//initializes heap using the unsorted dictionary vector
template <class T>
void Heap<T>::initializeMaxHeap(vector<T> dict1){
	myHeap.resize(dict1.size() + 1);
	for (int i = 0; i < dict1.size(); i++){
        //leaves index 0 empty for later sorting algorithm
		myHeap.at(i + 1) = (dict1.at(i));
	}
}
//sorts heap by building max heap and heapifying for smaller and smaller heap
template <class T>
void Heap<T>::heapSort(){
	buildMaxHeap();
	for(int i = myHeap.size() - 1; i >= 0; i--){
        swap(myHeap.at(1),myHeap.at(i));
        size--;
		maxHeapify(1);
	}
}
//returns the heap vector
template<class T>
vector<T> Heap<T>::getHeap(){
	return myHeap;
}
//prints the heap vector (for testing)
template<class T>
void Heap<T>::printHeap(){
    for (vector<string>::iterator it = myHeap.begin(); it != myHeap.end(); ++it){
		cout << *it << ' ';
	}
    cout<<"\n";
}
