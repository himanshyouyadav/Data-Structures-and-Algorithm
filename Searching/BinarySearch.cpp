#include <iostream>

using namespace std;

int Bsearch(int arr[], int n, int item)
{
    int beg = 0;
    int end = n-1;
    
    while(beg <= end)
    {
        int mid = (beg+end)/2;
        
        if(arr[mid] == item)
        {
            cout<<"\n "<<arr[mid]<<" found!"<<endl;
            return mid;
        }
        else if(arr[mid] > item)
        {
            end = mid-1;
        }
        else
        {
            beg = mid+1;
        }
    }
        cout<<"\n "<<item<<" not found !"<<endl;
        return -1;
}


int main()
{
    int arr[] = {-867989,87,100,523,869,1000,6898,INT32_MAX};
    int key = Bsearch(arr,8,INT32_MAX);
    return 0;
}
