#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int partiton(int arr[],int low,int high)
{
    int piovet=arr[high];

    int i=low-1;
    for(int j=low;j<high;++j)
    {
        if(arr[j]<=piovet)
        {
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {

    int pi=partiton(arr,low,high);

    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
    }
}
int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    quicksort(arr,0,9);
    for(int i=0;i<10;++i)cout<<arr[i]<<" ";
    return 0;
}
