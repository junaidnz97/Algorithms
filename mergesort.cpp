
#include<iostream>
using namespace std;

int merge(int a[100],int l,int m,int h)

{
	
	int i,j;
	int n1=m-l+1,n2=h-m;
	int left[n1],right[n2];
	
	for(i=0;i<n1;i++)
	{
		left[i]=a[i+l];
	}
	for(i=0;i<n2;i++)
	{
		right[i]=a[i+m+1];
	}
	
	int k=l;
	i=0,j=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=left[i];
		k++,i++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		k++,j++;
	}
	
}

int mergesort(int a[100],int l,int h)
{
	
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
			merge(a,l,m,h);

	}
	
}

int main()
{
	
	
	int a[100],i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<endl;
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<< " ";
	}
	
	
}
