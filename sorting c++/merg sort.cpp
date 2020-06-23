#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void merg(int arr[],int l,int h,int mid)
{
    int i,j,k;
    int siz1=mid-l+1;
    int siz2=h-mid;

   vector<int>v1(siz1);
   vector<int>v2(siz2);


   for(i=0;i<siz1;++i)v1[i]=arr[i+l];
   for(j=0;j<siz2;++j)v2[j]=arr[j+mid+1];

   i=j=0;
   k=0;

   while(i<siz1 && j<siz2)
   {
       if(v1[i]<=v2[j])
       {
           arr[k]=v1[i];
           ++i;
       }
       else
        {
            arr[k]=v2[j];
            ++j;
        }
        ++k;
   }
   while(i<siz1)
   {
       arr[k]=v1[i];
       ++i;
       ++k;
   }
   while(j<siz2)
   {
       arr[k]=v2[j];
       ++j;
       ++k;
   }


}
void merg_sort(int arr[],int l,int h)
{
    while(l<h)
    {
     int mid = l+(h-l)/2; 
    merg_sort(arr,l,mid);
    merg_sort(arr,mid+1,h);
    merg(arr,l,h,mid);
    }
}
void print_array(int arr[],int siz)
{
    for(int i=0;i<siz;++i)
    {
        cout<<arr[i]<<" ";
    }
  cout<<"\n";
}
int main()
{
     int arr[]={1,5,3,2,0};
     print_array(arr,5);
     merg_sort(arr,0,4);
     print_array(arr,5);
	return 0;
}

