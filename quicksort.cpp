#include<iostream>
using namespace std;



int partition(int a[100],int low,int high)
{
	
	int k=a[low];
	a[low]=a[high];
	a[high]=k;
	
	
	int left,right,pivotitem=a[low];
	left=low;
	right=high;
	
	
	
	
	
	while (left<right)
	{
		
		while(a[left]<=pivotitem)
		{
			left++;
		}
		while(a[right]>pivotitem)
		{
			right--;
		}
		if(left<right)
		{
			
			int temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		
		}
		
			int i;
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	}
	a[low]=a[right];
	a[right]=pivotitem;
	
	cout<<right<<endl;
	return right;
	
}


void quicksort(int a[],int low,int high)
{
	
	int pivot;
	
	if(low<high)
	{
		
		pivot=partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
	
}

int main()
{
	int a[100]={2,3,1,4,2};
	quicksort(a,0,4);
	int i;
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
}

