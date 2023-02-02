#include <bits/stdc++.h>
using namespace std;
// class of Bonary Heap representation
class MinHeap
{
    int arr[];
    int size;
    int capacity;

public:
// parametrisewd constrcutor
    MinHeap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    // Binary HEap insertion
    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;

        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    // minheapify function for building 
    void minHeapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    // extract min function from the min heap 
    int extractMin()
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);

        return arr[size];
    }

    // decreaese key and delete from the Binary Heap
        void decreaseKey(int i, int x) 
    { 
    arr[i] = x; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }
    
    void deleteKey(int i) 
    { 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    }

    // build heap from array
        void buildHeap()
    {
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }
    
};





/*  Heap sort */ 
//increasin order- max heap
// decreasing order- min heap
#include<bits/stdc++.h>
using namespace std;
//Building max heap form the array
void maxheapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 
// building heap
void buildheap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
}
// function for sortin the array into increasing order
void heapSort(int arr[], int n) 
{  
	buildheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	} 
} 
// printing the array 
void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
 
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
} 
