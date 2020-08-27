#include <stdio.h>
#include <stdlib.h>
void linearS(int array[], int size, int ele);
int main()
{
    int n, elem;
    system("cls");
    printf("ENTER ARRAY SIZE : ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("ELEMENT[%d] IS : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\nENTER ELEMENT TO SEARCH : ");
    scanf("%d", &elem);
    linearS(arr, n, elem);
    return 0;
}
void linearS(int array[], int size, int ele)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ele == array[i])
        {
            printf("FOUND AT POSITION %d\n", i);
            count++;
        }
        else
            continue;
    }
    if (count > 0)
        if (count == 1)
        {
            printf("%d FOUND %d TIME\n", ele, count);
        }
        else
        {
            printf("%d FOUND %d TIMES\n", ele, count);
        }
    else
        printf("%d NOT FOUND\n", ele);
}