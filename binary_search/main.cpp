#include <iostream>
int binary_searccing(int arr[],int siz,int item) // O(log(n))
{
    int low=0;
    int high=siz-1; // low & high keep track which section we search in
    while(low<=high) //While you haven’t narrowed it down  to one element

    {
        int mid=(low+high)/2; //check the middle element
        int guess=arr[mid];
        if(guess==item)return mid; //Found the item
        else if(guess>item) high=mid-1;// guess is too high
        else low=mid+1; //guess is too low
    }
    return -1; // item doesn`t exist

}
using namespace std;
const int length=8;
int main()
{
     int arr[length]={1,2,3,4,5,6,7,8};
     cout<<binary_searccing(arr,length,5)<<"\n";
     cout<<binary_searccing(arr,length,15);
    return 0;
}
