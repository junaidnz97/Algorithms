#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}


int lcsbt(char s1[10000],char s2[10000],int m,int n)
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



 int k=dp[m][n]+1;
 char temp[100000];
 temp[k-1]='\0';
 k--;


  i=m,j=n;
  while(1)
  {
    if(i==0 || j==0) break;
    
    else if(s1[i-1]==s2[j-1])
    {

      temp[k-1]=s1[i-1];
      i--,j--,k--;
      //arr2[j]=0;
      //arr1[i]=0;
    }
    
    else if(dp[i-1][j]>dp[i][j-1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }

 cout<<temp<<endl;

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
   	lcsbt(s1,s2,strlen(s1),strlen(s2));
  }
  
}
