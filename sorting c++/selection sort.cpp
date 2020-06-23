#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swaping(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selection_sort(int arr[],int siz)
{
    for(int i=0;i<siz-1;++i)
    {
        int index=i;
        for(int j=i+1;j<siz;++j)
            if(arr[index]>arr[j])
              index=j;

        swaping(&arr[i],&arr[index]);
    }
}
void printarray(int arr[],int siz)
{
    for(int i=0;i<siz;++i)cout<<arr[i]<<" ";
    cout<<"\n";

    }
int main()
{
    int arr[7]={5,-1,0,2,8,9,-2};
    printarray(arr,7);
    selection_sort(arr,7);
    printarray(arr,7);
    return 0;
}
