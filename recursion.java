import java.util.*;

public class recursion {
	public static int traingles(int n)
	{
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			sum+=i;
		}
		return sum;
	}
    public static int traingleRec(int n)
    {
    	if(n==1)return 1;
    	if(n<1)return 0;
    	
    	return traingleRec(n-1)+n;
    }
    public static int factorial(int n)
    {
    	if(n==1)return 1;
    	return n*factorial(n-1);
    }
    public static int sum(int[]a,int n)
    {
    	if(n==0)return 0;
    	return a[n-1]+sum(a,n-1);
    }
    public static void reverseArray(int []a,int low,int high)
    {
    	if(low<high)
    	{
    		int data=a[low];
    		a[low]=a[high];
    		a[high]=data;
    		reverseArray(a,low+1,high-1);
    	}
    }
    public static boolean binarySearch(int a[],int target ,int low,int high)
    {
    	if(low>high)return false;
    	else
    	{
    		int mid=(low+high)/2;
    		if(a[mid]==target)return true;
    		else if(a[mid]<target)return binarySearch(a,target,mid+1,high);
    		else return binarySearch(a,target,low,mid-1);
    		
    	}
    }
    public static int binarySum(int a[],int low,int high){
    	if(low>high)return 0;
    	if(low==high)return a[low];
    	return binarySum(a,low,(low+high)/2)+binarySum(a,(low+high)/2+1,high);
    }
    
}
