#include <stdio.h>
// binary search
int binarySearch(int array[], int low, int high, int search)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (array[mid] == search)
        {
            return mid;
        }
        if (array[mid] > search)
        {
            return binarySearch(array, 0, mid - 1, search);
        }
        if (array[mid] < search)
        {
            return binarySearch(array, mid + 1, high, search);
        }
    }
    return -1;
}
void sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (array[j] > array[j + 1])
            {
                int swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] : %d ", i, arr[i]);
    }
}
void inputit(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("ENTER AT [%d] : ", i);
        scanf("%d", &arr[i]);
    }
}
int main()
{
    int n, element;

    printf("ENTER ARRAY SIZE : ");
    scanf("%d", &n);

    int arr[n];

    //input the array
    inputit(arr, n);
    //sort the array if not sorted
    sort(arr, n);

    //print the sorted array
    printf("SORTED ARRAY : \n");
    printArray(arr, n);

    //ask the element to search
    printf("\nENTER ELEMENT TO SEARCH : ");
    scanf("%d", &element);

    //binarySearch starts
    int pos = binarySearch(arr, 0, n - 1, element);

    if (pos == -1)
    {
        printf("ELEMENT NOT FOUND");
    }
    else
    {
        printf("AT %d \n", pos);
        printf("SUCCESS\n");
    }

    return 0;
}
