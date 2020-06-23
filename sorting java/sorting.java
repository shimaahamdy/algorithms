
public class sorting {
	
	private static void swap(int a[],int i,int j)
	{
		int data=a[i];
		a[i]=a[j];
		a[j]=data;
	}
	public static void print(int a[])
	{
		int n=a.length;
		for(int i=0;i<n;++i)
		System.out.print(a[i]+" ");
		System.out.println();
	}
	public static void bubbleSort(int a[],int n)
	{
		for(int i=0;i<n-1;++i)
		{
			for(int j=0;j<(n-i-1);++j)
			{
				if(a[j]>a[j+1])swap(a,j,j+1);
			}
		}
	}
	public static void selectionSort(int a[],int n)
	{
		for(int i=0;i<n-1;++i)
		{
			int index=i;
			for(int j=i+1;j<n;++j)
			{
				if(a[index]>a[j])
				index=j;
			}
			swap(a,index,i);
		}
	}
	public static void insertionsort(int a[],int n)
	{
		for(int i=1;i<n;++i)
		{
			int data=a[i];
			int j=i-1;
			while(j>=0 && a[j]>data)
			{
				a[j+1]=a[j];
				--j;
			}
			a[j+1]=data;
		}
	}
	public static void mergSort(int a[],int n)
	{
		int workspace[]=new int [n];
		recMergSort(workspace,a,0,n-1);
	}
	private static void recMergSort(int workspace[],int a[],int l,int h)
	{
		if(l<h)
		{
		recMergSort(workspace,a,l,(l+h)/2);
		recMergSort(workspace,a,(l+h)/2+1,h);
		
		merg(workspace,a,l,(l+h)/2,h);
	    }
	}
	private static void merg(int workspace[],int a[],int l,int mid,int h)
	{
		int j=0;
		int l1=l;
		int h1=mid;
		int l2=mid+1;
		int h2=h;
		int n=h-l+1;
		
		while(l1<=h1 && l2<=h2)
		{
			if(a[l1]<a[l2])
				workspace[j++]=a[l1++];
			else workspace[j++]=a[l2++];
		}
		
		while(l1<=h1)
			workspace[j++]=a[l1++];
		
		while(l2<=h2)
			workspace[j++]=a[l2++];
		
		for(j=0;j<n;++j)
			{a[l+j]=workspace[j];
			workspace[j]=0;
			}
	}
	
	

}
