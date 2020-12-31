/*
    Given a sorted array 
    which may be rotated at some pivot element
    find the min element in the array

    SOLN
    Use binary search to check the sorted halves of array and the discard them
    we need the unsorted half and then at end we'll get two elements
    low will be greater than high that means not sorted
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int low, int high, int n)
{
    if (arr[0] <= arr[n - 1])
        return arr[0];
    else
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid + 1] < arr[mid])
                return mid + 1;
            else if (arr[low] <= arr[mid])
            {
                solve(arr, mid + 1, high, n);
            }
            else
            {
                solve(arr, low, mid - 1, n);
            }
        }
    }
}
int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = solve(arr, 0, n, n);
    cout << "min " << arr[res] << " at pos " << res;
}