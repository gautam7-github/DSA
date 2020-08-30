#include <stdio.h>
void printArray(int arr[], int size);
void insertionSort(int arr[], int size)
{
    int i, j, swap;
    printf("SORTING ARRAY....\n");

    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = swap;
            --j;
        }
        printArray(arr, size);
    }
    printf("ARRAY SORTED....\n");
}
void printArray(int arr[], int size)
{
    int i;
    printf("\n\n");
    for (i = 0; i < size; i++)
    {
        printf("[%d] : %d\n", i, arr[i]);
    }
    printf("\n\n");
}
int main()
{
    int n;
    do
    {
        printf("ENTER ARRAY SIZE : ");
        scanf("%d", &n);
    } while (n <= 0);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("ENTER AT [%d] : ", i);
        scanf("%d", &array[i]);
    }
    printArray(array, n);
    insertionSort(array, n);
    printArray(array, n);
    return 0;
}
