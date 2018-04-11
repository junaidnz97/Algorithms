#include<bits/stdc++.h>
using namespace std;

int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
vector<int>tree(100);

int compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) 
        return p1.second > p2.second;
    return p1.first < p2.first;
}
int find_q(int node,int start,int end,int low,int high)
{
	if(start>high || end<low)
		return 0;

	if(start>=low && end<=high)
		return tree[node];
	int mid=(start+end)/2;
	return max(find_q(2*node+1,start,mid,low,high),find_q(2*node+2,mid+1,end,low,high));
}

int buildtree(int node,int start,int end,int high,int val)
{
	if(start>high || high>end)
	{
		return 0;

	}
	if(start==end)
	{
		tree[node]=val;
		return 0;
	}
	int mid=(start+end)/2;
	buildtree(2*node+1,start,mid,high,val);
	buildtree(2*node+2,mid+1,end,high,val);
	tree[node]=max(tree[2*node+1],tree[2*node+2]);
}

int main()
{
	vector< pair <int,int> > a(8);

	for(int i=0;i<8;i++)
	{
		a[i].first=arr[i];
		a[i].second=i;
	}
	sort(a.begin(),a.end(),compare);
	for(int i=0;i<8;i++)
		buildtree(0,0,7,a[i].second,find_q(0,0,7,0,a[i].second-1)+1);
	cout<<tree[0];	
}