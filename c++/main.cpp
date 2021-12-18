#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 
#include <iostream>
#include <math.h>
#include <chrono>
using namespace std::chrono;
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void fillArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
    
}

float timeExecution(int arr[], const int size, int n) {
    float time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillArr(arr, size);
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        time += duration.count() / pow(10, 6);
    }
    time = time / 100;
    return time;
}

int main()
{
    srand(time(NULL));
    const int size = 1000000;
    int arr[size];
    int n = sizeof(arr)/sizeof(arr[0]);
  
    std::cout << "Average time taken by function: " << timeExecution(arr, size, n) << " seconds." << std::endl;    
    
    return 0;
}