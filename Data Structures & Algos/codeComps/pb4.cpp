// Count Occurances of element X in an array
// Complexity : O(logn + count)

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
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
            return binarySearch(array, low, mid - 1, search);
        }
        if (array[mid] < search)
        {
            return binarySearch(array, mid + 1, high, search);
        }
    }
    return -1;
}
int countOcc(int arr[], int size, int ele)
{
    int index = binarySearch(arr, 0, size - 1, ele);
    int count = 0;

    if (index == -1)
    {
        return count;
    }
    else
    {
        int left = index - 1;
        int right = index + 1;

        while ((left >= 0) && (arr[left] == ele))
        {
            count++;
            left--;
        }
        while ((right <= size - 1) && (arr[right] == ele))
        {
            count++;
            right++;
        }
        return count + 1;
    }
}
void sort_array(int array[], int n)
{
    sort(array, array + n);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "] : " << arr[i] << endl;
    }
}
void inputit(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ENTER AT " << i << " :: ";
        cin >> arr[i];
        cout << endl;
    }
}
int main()
{
    int n, element;

    cout << "ENTER ARRAY SIZE : \n";
    cin >> n;

    int arr[n];

    //input the array
    inputit(arr, n);
    //sort the array if not sorted
    sort_array(arr, n);

    //print the sorted array
    cout << "SORTED ARRAY : \n";
    printArray(arr, n);

    //ask the element to search
    cout << "ENTER ELEMENT TO SEARCH : " << endl;
    cin >> element;

    cout << " :: -> " << countOcc(arr, n, element);
    return 0;
}
