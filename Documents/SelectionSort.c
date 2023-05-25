#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);
void printArray(int arr[], int n);
int partition(int * vals, int low, int high);
int quickSelect(int arr[], int left, int right, int n);
void swap(int* a, int* b);


int main()
{
    int arr[] = {26, 21, 16, 37, 2,	5, 11, 10, 23, 17, 9, 22, 15, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = 123;

    printf("Unsorted: ");
    printArray(arr, n);

    result = quickSelect(arr,0, n-1,n);
    //selectionSort(arr, n);

    printf("Sorted: ");
    printArray(arr, n);
    printf("\n");
    printf("The result is %d\n", result);

    return 0;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int quickSelect(int arr[], int left, int right, int n)
{
    n = 5;
    if (left == right)
        return arr[left];

    int pivotIndex = partition(arr, left, right);

        if (n-1 == pivotIndex)
            return arr[pivotIndex];
        else if(pivotIndex > n-1)
            quickSelect(arr, left, pivotIndex - 1, n);
        else
            quickSelect(arr, pivotIndex + 1, right, n);
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx, temp;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
	    printf("\nIteration# %d\n",i+1);
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;

		printArray(arr, n);
	}
}

int partition(int * vals, int low, int high)
{
  // Pick a random partition element and swap it into index low.
  int i = low + rand()%(high-low+1);
  swap(&vals[low], &vals[i]);

  int lowpos = low; //here is our pivot located.

  low++; //our starting point is after the pivot.

  // Run the partition so long as the low and high counters don't cross.
  while(low<=high)
  {
    // Move the low pointer until we find a value too large for this side.
    while(low<=high && vals[low]<=vals[lowpos]) low++;

    // Move the high pointer until we find a value too small for this side.
    while(high>=low && vals[high] > vals[lowpos]) high--;

    // Now that we've identified two values on the wrong side, swap them.
    if (low<high)
     swap(&vals[low], &vals[high]);
  }

  // Swap the pivot element element into its correct location.
  swap(&vals[lowpos], &vals[high]);

  return high; //return the partition point
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
