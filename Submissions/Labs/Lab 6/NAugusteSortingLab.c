// Naseem Auguste Professor Ahmed COP3502

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVAL 100000

long timediff(clock_t t1, clock_t t2);
void selectionSort(int arr[], int n);
void swap(int * xp, int * yp);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int is_sorted(int values[], int length);
int partition(int * vals, int low, int high);
void quickSort(int* numbers, int low, int high);
void arrayCopy(int giver[], int receiver[], int size);
void RandomArray(int Array[], int size, int maxval);


int main()
{

    int i = 0;

    int sizes[]={10000,20000,30000,40000,50000,100000};
    int length = sizeof(sizes)/ sizeof(sizes[0]);

    int * originalArray;
    int * sortedArray;

    clock_t t_start, t_end;

    for(i = 0; i < length; i ++)
    {
        originalArray = (int*)malloc(sizeof(int)*sizes[i]);
        sortedArray = (int*)malloc(sizeof(int)*sizes[i]);

        RandomArray(originalArray, sizes[i], MAXVAL);

        arrayCopy(originalArray, sortedArray, sizes[i]);
        t_start = clock();
        bubbleSort(sortedArray, sizes[i]);
        t_end = clock();
        printf("\nsorting %d values takes %ld milli seconds for Bubble sort\n",sizes[i],timediff(t_start, t_end));

        arrayCopy(originalArray, sortedArray, sizes[i]);
        t_start = clock();
        selectionSort(sortedArray, sizes[i]);
        t_end = clock();
        printf("\nsorting %d values takes %ld milli seconds for Selection sort\n",sizes[i],timediff(t_start, t_end));

        arrayCopy(originalArray, sortedArray, sizes[i]);
        t_start = clock();
        mergeSort(sortedArray, 0, sizes[i]-1);
        t_end = clock();
        printf("\nsorting %d values takes %ld milli seconds for Merge sort\n",sizes[i],timediff(t_start, t_end));

        arrayCopy(originalArray, sortedArray, sizes[i]);
        t_start = clock();
        quickSort(sortedArray, 0, sizes[i]-1);
        t_end = clock();
        printf("\nsorting %d values takes %ld milli seconds for Quick sort\n",sizes[i],timediff(t_start, t_end));

        arrayCopy(originalArray, sortedArray, sizes[i]);
        t_start = clock();
        insertionSort(sortedArray, sizes[i]);
        t_end = clock();
        printf("\nsorting %d values takes %ld milli seconds for Insertion sort\n",sizes[i],timediff(t_start, t_end));

        printf("===============================================================\n");

        free(originalArray);
        free(sortedArray);
    }

    return 0;
}

void arrayCopy(int giver[], int receiver[], int size)
{
    int j;
    for(j = 0; j < size; j++)
        receiver[j] = giver[j];
}


void RandomArray(int Array[], int size, int maxval)
{
    for(int i = 0; i < size; i++)
        Array[i]= rand()%maxval + 1;
}


long timediff(clock_t t1, clock_t t2)
{
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}










void selectionSort(int arr[], int n)
{
	int i, j, min_idx, temp;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
	    //printf("\nIteration# %d\n",i+1);
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;

		// printArray(arr, n);
	}
}









void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
  //printf("\nUsing Bubble sort\n\n");

   int i, j,temp;
   for (i = 0; i < n-1; i++)
   {
        //printf("Iteration# %d\n",i+1);
        for (j = 0; j < n-i-1; j++)
        {

           if (arr[j] > arr[j+1])
           {
             //then swap
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
           }
           //printArray(arr, n);
        }

    }
}









void insertionSort(int arr[], int n)
{
    int i, item, j;
    for (i = 1; i < n; i++)
    {
         item = arr[i];

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
          for(j=i-1; j>=0; j--)
          {
              if(arr[j]>item)
                arr[j+1] = arr[j];
              else
                break;

          }
          arr[j+1] = item;
    }
}











void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2]; //if your compiler does not support this, create them dynamically.

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // get the mid point
        int m = (l+r)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

       // printf("Testing l=%d r=%d m=%d\n", l, r, m);

        merge(arr, l, m, r);
    }
}











int is_sorted(int values[], int length) {

    int i;

    // Return false if any adjacent pair is out of order.
    for (i=0; i<length-1; i++)
        if (values[i] > values[i+1])
            return 0;

    return 1;
}


/*
// Swaps the values pointed to by a and b.
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
*/

int partition(int *vals, int low, int high)
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

// Pre-condition: s and f are value indexes into numbers.
// Post-condition: The values in numbers will be sorted in between indexes s
//                 and f.
void quickSort(int* numbers, int low, int high) {

    // Only have to sort if we are sorting more than one number
    if (low < high) {
        int split = partition(numbers,low,high);
        quickSort(numbers,low,split-1);
        quickSort(numbers,split+1,high);
    }
}
