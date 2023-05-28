#include <stdio.h>

//swap 2 numbers
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int arr[], int n)
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,n); //function called
    printf("sorted array: ");
    for (int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}