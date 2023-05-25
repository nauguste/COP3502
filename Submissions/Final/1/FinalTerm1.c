// Naseem Auguste Midterm Assignment 2

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct points
{

	int X;
    int Y;

} points;

int fcoords;
//int Left[999], Right[999];

points * ReaData(points * origin, int * radius, int * coords);
points * FilterData(points * data, points  origin, int  radius, int * coords);
void mergeSort(points * data, int l, int r);
void merge(points * data, int l, int m, int r);
void binarySearch(points * data, points inputs, int fcoords);
void SearchPhase(points * data, int fcoords);


int main()
{

    int i;
    int radius;
    int coords;

    points * data;
    points * filter;
    points origin;


    data = ReaData(&origin, &radius, &coords);

    filter = FilterData(data, origin, radius, &coords);

    mergeSort(filter, 0, fcoords -1);

    //for (i = 0; i < fcoords; i++)
        //printf("X  %d\tY  %d\n", filter[i].X, filter[i].Y);

    //printf("\n----------------------------------------------------------\n");

    FILE * OFP = fopen("out.txt", "w");

    for (i = 0; i < fcoords; i++)
        fprintf(OFP,"X  %d\tY  %d\n", filter[i].X, filter[i].Y);

    fclose(OFP);

    printf("Filtered and Sorted Data has been written to out.txt");

    SearchPhase(filter, fcoords);

    return 0;
}

points * ReaData(points * origin, int * radius, int * coords)
{
    int i, PoI;
    points * ptr;

    FILE * IFP;
    IFP = fopen("in.txt", "r");

    fscanf(IFP, "%d%d%d%d", &origin->X, &origin->Y, radius, coords);

    PoI = *coords;
    ptr = (points *)malloc(sizeof(points)* PoI);

    for(i = 0; i < PoI; i++)
        fscanf(IFP, "%d%d", &ptr[i].X, &ptr[i].Y);

    fclose(IFP);

    /*
    printf("X's origin point is %d.\nY's origin point is %d.\n", origin->X, origin->Y);
    printf("The radius of this circle is %d.\n", *radius);
    printf("There are %d points of interest.\n", PoI);

    for(i = 0; i < PoI; i++)
    printf("X  %d\tY  %d\n", ptr[i].X, ptr[i].Y);
    */

    return ptr;
}


points * FilterData(points * data, points origin, int  radius, int * coords)
{
    int i, j = 0, x, y, loc;
    int PoI = *coords;
    double distance;

    int * num = (int *)malloc(sizeof(int)*PoI);

    points * pure;


    //pure = (points *)malloc(sizeof(points)* PoI);

    //printf("Points of Interest : %d\n", PoI);
    //printf("Radius : %d\n", radius);
    //printf("X's origin point is %d.\nY's origin point is %d.\n", origin->X, origin->Y);

    //for (i = 0, j = 0; i < PoI; i++)
    //printf("X  %d\tY  %d\n", data[i].X, data[i].Y);

    //printf("X  %d\tY  %d\n", x, y);


    for(i = 0; i < PoI; i++)
    {
        distance = sqrt(pow(data[i].X - origin.X, 2)+ pow(data[i].Y - origin.Y, 2));

    //printf("Distance : %.2lf\n", distance);

        if(distance <= radius)
        {
            num[j] = i;
            j++;
        }
    }

    fcoords = j;
    //printf("\n\n%d\n\n", fcoords);

    pure = (points *)malloc(sizeof(points)* j);

    for(i = 0; i < j; i++)
    {
        loc = num[i];
        pure[i] = data[loc];
    }

    /*
    for(i = 0; i < j; i++)
    printf("%d\n", num[i]);

    printf("\n\n======================================================================================\n\n");

    for(i = 0; i < j; i++)
    printf("%d\t%d\n", pure[i].X, pure[i].Y);
    */

    return pure;
}

void merge(points * data, int l, int m, int r)
{

    int i, j, k;

    int n1 = m - l + 1;
    int n2 =  r - m;

    //printf("%d\t%d\n", n1, n2);



    //points Left[n1], Right[n2];
    points * Left = malloc(sizeof(points)* n1);
    points * Right = malloc(sizeof(points)* n2);


    for (int i = 0; i < n1; i++)
    {
        Left[i].X = data[l + i].X;
        Left[i].Y = data[l + i].Y;
    }

    for (int j = 0; j < n2; j++)
    {
        Right[j].X = data[m + 1 + j].X;
        Right[j].Y = data[m + 1 + j].Y;
    }

    //for (int i = 0; i < n1; i++)
      //  printf("%d\n", data[l + i]);

    //for (int i = 0; i < n1; i++)
      //  printf("%d\t%d\n", Left[i].X, Left[i].Y);

    //for (int j = 0; j < n2; j++)
      //  printf("%d\t%d\n", Right[j].X, Right[j].Y);

    //for (j = 0; j < n2; j++)
       // Right[j] = data[m + 1 + j];

    //for (int i = 0; i < n2; i++)
        //printf("%d\n", data[m + 1 + j]);

    //for (int i = 0; i < n2; i++)
       // printf("%d\n", Right[i]);

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    //printf("i:%d\tj:%d\tn1:%d\tn2:%d\n",i, j, n1, n2);

    while (i < n1 && j < n2)
    {         //printf("i:%d\tj:%d\tn1: %d\tn2: %d\n",i, j, n1, n2);
        if (Left[i].X <= Right[j].X)
        {
            if( Left[i].X == Right[j].X)
            {
                if(Left[i].Y < Right[j].Y)
                {
                    data[k].X = Left[i].X;
                    data[k].Y = Left[i].Y;
                    i++;
                }
                else
                {
                    data[k].X = Right[j].X;
                    data[k].Y = Right[j].Y;
                    j++;
                }
            }
            else
            {
                data[k].X = Left[i].X;
                data[k].Y = Left[i].Y;
                i++;
            }
        }
        else
        {
            data[k].X = Right[j].X;
            data[k].Y = Right[j].Y;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        data[k].X = Left[i].X;
        data[k].Y = Left[i].Y;
        i++;
        k++;
    }

    while (j < n2)
    {
        data[k].X = Right[j].X;
        data[k].Y = Right[j].Y;
        j++;
        k++;
    }
}


void mergeSort(points * data, int l, int r)
{
    if (l < r)
    {
        // get the mid point
        int m = (l + r) / 2;

        // Sort first and second halves
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);

        //printf("Testing l=%d r=%d m=%d\n", l, r, m);

        merge(data, l, m, r);
    }
}

void binarySearch(points * data, points inputs, int fcoords)
{
    int mid = 0;
    int hit = 0, l = 0, h = fcoords;

    //for(int i = 0; i < fcoords; i++)
    //printf("\n\nX is : %d\tY is : %d",data[i].X,data[i].Y);

    while (l < h)
    {
        mid = (l+h) / 2;

           // for(int i = 0; i < fcoords; i++)
               // printf("\n\nX is : %d\tY is : %d\tIX is : %d\tIY is : %d",data[i].X,data[i].Y,inputs.X,inputs.Y);

            //printf("\n=====================\n\nBEFORE mid:%d\tl: %d\th:%d\t\n", mid,l,h);

        if (data[mid].X == inputs.X && data[mid].Y == inputs.Y)
        {
            hit = 1;
            break;
        }
        else if (data[mid-1].X == inputs.X && data[mid-1].Y == inputs.Y)
        {
            mid--;
            hit = 1;
            break;
        }
        else if (data[mid].X <= inputs.X && data[mid].Y <= inputs.Y)
        {
            l = mid + 1;
            //break;
        }
        else
        {
            h = mid - 1;
            //break;
        }
        if (l == 0 && h == 0)
        {
            mid = 0;

            if (data[mid].X == inputs.X && data[mid].Y == inputs.Y)
                hit = 1;

            if(hit == 1)
            {
                printf("Executing lowest case scenario.\n");
            }
            break;
        }

        if (hit == 0)
        {
            mid = fcoords-1;
            if (data[mid].X == inputs.X && data[mid].Y == inputs.Y)
            {
                hit = 1;
                break;
            }
        }
            //printf("\n=====================\n\nAFTER mid:%d\tl: %d\th:%d\t\n", mid,l,h);
    }
            //printf("\n=====================\nhit:%d\n", hit);

    if(hit == 1)
        printf("Found at record %d", mid+1);
    else
        printf("Not Found.");

}

void SearchPhase(points * data, int fcoords)
{

	points inputs;

	while(1)
	{
		printf("\nSearch input (x y): ");
		scanf("%d%d", &inputs.X, &inputs.Y);

		if (inputs.X == -999 || inputs.Y == -999)
		{
			printf("Exiting Program.\n");
			break;
		}
		binarySearch (data, inputs, fcoords);
	}
}


