#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
// binary search
int binarySearch(int array[], int low, int high, int search)
{
    cout << "INSIDE\n";
    if (high >= low)
    {
        int mid = (low + high) / 2;
        cout << "ELEMID :: " << array[mid] << endl;
        cout << "MID    :: " << mid << endl;
        cout << "LOW    :: " << low << endl;
        cout << "HIGH   :: " << high << endl;
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

    if (binarySearch(arr, 0, n - 1, element) != -1)
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
    return 0;
}
