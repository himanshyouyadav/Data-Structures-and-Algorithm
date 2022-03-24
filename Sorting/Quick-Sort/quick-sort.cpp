
#include <iostream>

using namespace std;

void swap(int * a,int * b)
{
    int tmp = *a;
    *a= *b;
    *b = tmp;
} 

int partition(int arr[], int start, int end)
{
    int i=start, j=end; 
    int pivot = arr[i];

    while(i<j)
    {
        while(pivot>=arr[i])
        {
            i++;
        }
        while(pivot<arr[j])
        {
            j--;                 // If pivot and j are at same position then don't decrease j because in such case there can be can self swap to preserve data.
            
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }


    swap(&arr[start],&arr[j]);
    return j;
}

void quick_sort(int arr[],int start, int end)
{
    if(start<end)
    {
        int j = partition(arr,start,end);
        quick_sort(arr,start,j);
        quick_sort(arr,j+1,end);

    }

}


int main()
{
    int arr[] = {10,7,72,6,9,4,12,5,1,INT32_MAX};
    quick_sort(arr,0,9);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
