#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&dp,int low,int high,int s)
{
	//cout<<"low ="<<low<<" high= "<<high<<" s="<<s<<endl;
	while (low<high) {
    int m = (low+high)/2;
    if (dp[m] >= s)
    {
    	//cout<<"he;"<<endl;
        high = m-1;
    }
    else
        low=m+1;

    }
    //cout<<endl<<"high= "<<high<<endl;
 
    return high;
}

int bsearch(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}

int lis(vector<int> &a,int n)
{
	vector<int> dp(n,0);
	dp[0]=a[0];
	int i,j,length=1;
	for(i=1;i<n;i++)
	{
		if(a[i]<dp[0])
		{
			dp[0]=a[i];
		}
		else if(dp[length-1]<a[i])
		{
			dp[length++]=a[i];
		}
		else
		{
			//dp[bsearch(dp,0,length,a[i])]=a[i];
			dp[upper_bound(dp.begin(),dp.begin()+length,a[i])-dp.begin()]=a[i];
		}
		for(j=0;j<n;j++)
		{
			cout<<dp[j]<<" ";
		}
		cout<<endl;
	}
	return length;
}

int main()
{
	vector <int> a;
    int i;
	for(i=0;i<10;i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	cout<<lis(a,10)<<endl;
}