// Merge sort in C
// todo optimise merge sort or shorten the code
#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int low, int mid, int high)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];

    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {

        // mid is the point where the array is divided into two subarrays
        int mid = (low + high) / 2;
        //for left half sub array
        mergeSort(arr, low, mid);
        //for right half sub array
        mergeSort(arr, mid + 1, high);
        // Merge the sorted subarrays
        merge(arr, low, mid, high);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program
int main()
{
    int size;

    printf("ENTER SIZE : ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("YOUR ARRAY : \n");
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("SORTED ARRAY : \n");
    printArray(arr, size);
}
