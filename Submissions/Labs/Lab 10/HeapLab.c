//Naseem Auguste Heap
#include <stdio.h>

int HeapRec(int array[], int i, int x);

int main()
{
    //int array[6] = {12, 110, 14, 15, 13, 115};
    int array[6] = {12, 13, 14, 15, 110, 115};

    if(HeapRec(array, 0, 6))
        printf("Recursively this a min heap!\n");
    else
        printf("Recursively this a not min heap!\n");

    if(HeapRec(array, 0, 6))
        printf("Iteratively this a min heap!\n");
    else
        printf("Iteratively this a not min heap!\n");

}

int HeapRec(int array[], int i, int x)
{
    if (i > (x - 2) / 2)
        return 1;

    int left = (array[i] <= array[2 * i + 1]) && HeapRec(array, 2 * i + 1, x);
    int right = (2 * i + 2 == x) || (array[i] <= array[2 * i + 2]) && HeapRec(array, 2 *i  + 2, x);

    if(left && right == 1)
        return 1;
    else
        return 0;

}

int HeapIter(int array[], int y)
{
    for (int i=0; i <= (y - 2) / 2; i++)
    {
        if (array[2 * i + 1] < array[i])
            return 0;

        if ((2 * i + 2 < y) && (array[2 * i + 2] < array[i]))
            return 0;
    }
    return 1;
}
