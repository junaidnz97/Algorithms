#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}


int lcs(char s1[10000],char s2[10000],int m,int n)
{

 
 vector < vector <int> > dp(m+1, vector<int> (n+1,0));

 int i,j;
 for(i=1;i<=m;i++)
 {
 	for(j=1;j<=n;j++)
 	{
 		
 		
 		if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
 		
 		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	 }
	 
 }

 return dp[m][n];

}

int main()
{
  int it,test;
  cin>>test;
  getchar();
  for(it=0;it<test;it++)
  {
  	char s1[100000],s2[100000];
  	scanf("%[^\n]s",s1);
        getchar();
        scanf("%[^\n]s",s2);
        getchar();
   	cout<<lcs(s1,s2,strlen(s1),strlen(s2))<<endl;
  }
  
}
