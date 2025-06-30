#include <stdio.h>
int max, min;
int arr[100];
void maxmin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = arr[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (arr[i] < arr[j])
            {
                max = arr[j];
                min = arr[i];
            }
            else
            {
                max = arr[i];
                min = arr[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("The input array is:\t");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
    min = arr[0];
    max = arr[0];
    maxmin(1, n);
    printf("\nMinimum element in the array is: %d", min);
    printf("\nMaximum element in the array is: %d", max);
    return 0;
}