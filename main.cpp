#include <iostream>
#include <chrono>
#include<stdlib.h>
using namespace std;
    void swap(int *x, int *y) 
    {
      int temp = *x;
      *x = *y;
      *y = temp;
    }
    int partition(int array[], int low, int high) 
    {
        int pivot = array[high];
        int i = (low);
        for (int j = low; j < high; j++) {
        if (array[j] <= pivot) { 
        swap(&array[i], &array[j]);
        i++;
    }
    }
      swap(&array[i], &array[high]);
      return (i );
    }
    void iterativequickSort(int arr[], int a, int b)
    {
        int stack[b + 1];
        int top = -1;
        stack[++top] = a;
        stack[++top] = b;
        while (top >= 0)
        {
            a = stack[top--];
            b = stack[top--];
            int i = partition(arr, a, b);
            if (i - 1 > a) 
        {
            stack[++top] = a;
            stack[++top] = i - 1;
        }
        if (i + 1 < b) 
        {
            stack[++top] = i + 1;
            stack[++top] = b;
        }
    }
    } 
    void bubbleshort(int array[],int n)
    {
    	int i,j; 
    	auto begin =chrono::high_resolution_clock::now();
    	for(i=0;i<n-1;i++){
    	for(j=0;j<n-i-1;j++)
	{
		if(array[j]>array[j+1])
		swap(&array[j],&array[j+1]);
	}	
    }
    	auto end =chrono::high_resolution_clock::now();
        auto elapsed =chrono::duration_cast<chrono::nanoseconds>(end - begin);
        printf("Time elapsed for bubble short: %.5f seconds.\n", elapsed.count() * 1e-9);
    }
    void binarysearch(int array[],int length)
    {
	int k=0,n,m=0;
	cout<<"Enter the element to find: ";
	cin>>n;
	auto begin =chrono::high_resolution_clock::now();
    while(k<=length)
    {
        int mid=(k+length)/2;
        if(array[mid]==n)
        {cout<<"Element is present at "<<mid+1<<"th place";
        m=1;
    	break;
    }
	else if(array[mid]>n)
	length=mid-1;
	else if(array[mid]<n)
	k=mid+1;
	}	
	if(m==0)
	cout<<"No match found ";
	auto end =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<chrono::nanoseconds>(end - begin);
    printf("Time elapsed for binary search: %.5f seconds.\n", elapsed.count() * 1e-9);
	}
	void linearsearch(int array[],int length){
	int n,m=0,i;
	cout<<"Enter the element to find: ";
	cin>>n;
	auto begin =chrono::high_resolution_clock::now();
	for(i=0;i<length;i++)
	{
		if(array[i]==n)
		{
			cout<<"Element is present at arr["<<i<<"]";
			m=1;
		}
	}
	if(m==0)
	cout<<"No match found";
	auto end =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<chrono::nanoseconds>(end - begin);
    printf("Time elapsed for linearsearch: %.5f seconds.\n", elapsed.count() * 1e-9);
    }
    int main() {
    int i,max=1000;
    int arr[max];
    for(i=0;i<max;i++)
    {
  	arr[i]=rand()%1000;
    }
	linearsearch(arr,max-1);
    auto begin = std::chrono::high_resolution_clock::now();
    iterativequickSort(arr, 0, max - 1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time elapsed for quickshorting: %.5f seconds.\n", elapsed.count() * 1e-9);
    for(i=0;i<max;i++)
    {
  	    arr[i]=rand()%1000;
    }
      bubbleshort(arr,max);
      binarysearch(arr,max-1);
    return 0;
    }
