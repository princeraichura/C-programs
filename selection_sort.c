#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

// Function to select the lowest number and bring it to the beginning
void selection(int arr[], int n)
{
    int min;
    for (int i=0;i<n-1;i++)
    {
        min=i; // Assuming first element as the minimum
        for (int j=i+1;j<n;j++)
        {
            if (arr[min]>arr[j])
                min=j;
            swap(&arr[min],&arr[i]); // Bringing the minimum element to the beginning of the array
        }
    }
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("enter %d elements: ",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    selection(arr,n); //call selection fun
    printf("sorted array: ");
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
