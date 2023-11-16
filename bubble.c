#include <stdio.h>

void Bubble_Sort(int a[], int len)
{
    for(int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main(void)
{
    int arr[10] = {5, 3, 1, 7, 2, 4, 8, 10, 9, 6};
    int len= 10;

    Bubble_Sort(arr, len);
    
    for(int i=0; i<10; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}