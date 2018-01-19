#include<bits/stdc++.h>
using namespace std;

int djikstra(vector < vector <int> > &g,int n)
{

	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, 0));

	vector <int> distance(100,INT_MAX);

	distance[0]=0;
	int i,temp;

	while(!pq.empty())
	{
		temp=pq.top().second;
		pq.pop();

		for(i=0;i<n;i++)
		{
			if(g[temp][i]!=0)
			{

				if(distance[i]>distance[temp]+g[temp][i])
				{
                                    distance[i]=distance[temp]+g[temp][i];
                                    pq.push(make_pair(distance[i],i));
				}
			}
		}
	}

	return distance[n-1];


}

int main()
{
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		int m,n;
		cin>>n>>m;
		vector < vector <int> > g(n,vector<int> (n,0));
		int i;
		int a,b,w;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>w;
			g[a-1][b-1]=w;
			g[b-1][a-1]=w;

		}

	g[0][1] =4;
	g[0][7]=8;
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

		cout<<djikstra(g,n)<<endl;

	}
}
