#include <iostream>
 
using namespace std;
 
void insertion_sort(int arr[], int n)
{
    
    for(int i=1; i<n; i++)
    {
        int j = i;
        int num = arr[i];
        while(j>0 && num < arr[j-1])
        {
            
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = num;
    }
}
 
 
int main()
{
    int arr[] = {5,8,72,1,3,4,-7,INT32_MIN, INT32_MAX,87,68989,-867989, -8};
    insertion_sort(arr,13);
    for(int i=0;i<13;i++)
    {
        cout<<arr[i]<<" ";
    }
 
    return 0;
}
