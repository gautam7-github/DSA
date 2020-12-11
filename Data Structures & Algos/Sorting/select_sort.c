#include <stdio.h>
void printArray(int arr[], int size);
void selectionSort(int arr[], int size)
{
    int i, j, swap, min_pos;
    printf("SORTING....\n");
    for (i = 0; i < size - 1; i++)
    {
        min_pos = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[min_pos] > arr[j])
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            swap = arr[min_pos];
            arr[min_pos] = arr[i];
            arr[i] = swap;
        }
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
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}
