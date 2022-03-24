#include <iostream>

using namespace std;

void merge(int arr[],int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int tmp_arr[100];
    
    while(i<=mid && j<= high)
    {
        if(arr[i]<arr[j])
        {
            tmp_arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tmp_arr[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while(i <= mid)
    {
            tmp_arr[k] = arr[i];
            i++;
            k++;        
    }
    
    while(j <= high)
    {
            tmp_arr[k] = arr[j];
            k++;
            j++;       
    }
    
    for(i=low;i<=high;i++)
    {
        arr[i] = tmp_arr[i];
    }
}
void merge_sort(int arr[],int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main()
{
    int arr[] = {5,7,2,3,9,1,55,87,98,20,11,43,54,65,76,98,9};
    merge_sort(arr,0,16);
    for(int i=0;i<17;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
