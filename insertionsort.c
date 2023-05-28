#include <stdio.h>

void insertionSort(int n, int arr[])
{
    int i,j,key;
    for (i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j]; // shifting num. that is greater than key to one position ahead
            j--;
        }
        arr[j+1]=key; // if j=-1
    }
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array: ");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionSort(n,arr); //function called
    printf("Sortd array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}