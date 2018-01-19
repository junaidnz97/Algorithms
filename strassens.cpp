#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int print( vector < vector<long long int> > &a)
{
	int i,j;
	int n=a.size();
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

vector<vector<long long int> > addmatrix(vector<vector<long long int> > a,vector<vector<long long int> > b,int n)
{
    int i,j;
	vector<vector<long long int> > c;
	for(i=0;i<n;i++)
	{
		vector<long long int>temp;
		for(j=0;j<n;j++)
		{
			temp.push_back(a[i][j]+b[i][j]);
		}
		c.push_back(temp);
		temp.clear();
	}
	return c;
}

vector<vector<long long int> > submatrix(vector<vector<long long int> > a,vector<vector<long long int> > b,int n)
{
	int i,j;
	vector<vector<long long int> > c;
	for(i=0;i<n;i++)
	{
		vector<long long int>temp;
		for(j=0;j<n;j++)
		{
			temp.push_back(a[i][j]-b[i][j]);
		}
		c.push_back(temp);
		temp.clear();
	}
	return c;
}

vector<vector <long long int> > strassensalgo(vector<vector<long long int> > &a,vector<vector<long long int> > &b,int n)
{
  if(n==2)
  {
   long long int p1=a[0][0]*(b[0][1]-b[1][1]);
   long long int p2=b[1][1]*(a[0][0]+a[0][1]);
   long long int p3=b[0][0]*(a[1][0]+a[1][1]);
   long long int p4=a[1][1]*(b[1][0]-b[0][0]);
   long long int p5=a[0][0]*(b[0][0]+b[1][1])+a[1][1]*(b[0][0]+b[1][1]);
   long long int p6=a[0][1]*(b[1][0]+b[1][1])-a[1][1]*(b[1][0]+b[1][1]);
   long long int p7=a[0][0]*(b[0][0]+b[0][1])-a[1][0]*(b[0][0]+b[0][1]);
  	
   long long int c11=p5+p4-p2+p6;
  	long long int c12=p1+p2;
  	long long int c21=p3+p4;
  	long long int c22=p5+p1-p3-p7;
  	
	vector<long long int> row;
  	vector< vector<long long int> > final;
  	row.push_back(c11);
  	row.push_back(c12);
  	final.push_back(row);
  	row.clear();
  	row.push_back(c21);
  	row.push_back(c22);
  	final.push_back(row);
  	row.clear();
  	return final;
   }
	
  vector<vector<long long int> > a11,a12,a21,a22,b11,b12,b21,b22;
  
  int i,j;
  vector <long long int> temp1,temp2;
  for(i=0;i<n/2;i++)
  {
    for(j=0;j<n/2;j++)
	 {
	 	temp1.push_back(a[i][j]);
	 	temp2.push_back(b[i][j]);
	 }	
		a11.push_back(temp1);
		b11.push_back(temp2);
		temp1.clear();
		temp2.clear();
  }
  for(i=0;i<n/2;i++)
  {
     for(j=n/2;j<n;j++)
	 {
	 	temp1.push_back(a[i][j]);
	 	temp2.push_back(b[i][j]);
	 }	
		 a12.push_back(temp1);
		 b12.push_back(temp2);
		 temp1.clear();
		 temp2.clear();
  }
  
  for(i=n/2;i<n;i++)
  {
     for(j=0;j<n/2;j++)
	 {
	 	temp1.push_back(a[i][j]);
	 	temp2.push_back(b[i][j]);
	 }	
		 a21.push_back(temp1);
		 b21.push_back(temp2);
		 temp1.clear();
		temp2.clear();
  }
  
  for(i=n/2;i<n;i++)
  {
    for(j=n/2;j<n;j++)
	 {
	 	temp1.push_back(a[i][j]);
	 	temp2.push_back(b[i][j]);
	 	
	 }	
		 
	a22.push_back(temp1);
	b22.push_back(temp2);
	temp1.clear();
	temp2.clear();
  }
 vector<vector<long long int> > s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,p1,p2,p3,p4,p5,p6,p7,c11,c12,c21,c22;
 
 s1=submatrix(b12,b22,n/2);
 s2=addmatrix(a11,a12,n/2);
 s3=addmatrix(a21,a22,n/2);
 s4=submatrix(b21,b11,n/2);
 s5=addmatrix(a11,a22,n/2);
 s6=addmatrix(b11,b22,n/2);
 s7=submatrix(a12,a22,n/2);
 s8=addmatrix(b21,b22,n/2);
 s9=submatrix(a11,a21,n/2);
 s10=addmatrix(b11,b12,n/2);
  
 p1=strassensalgo(a11,s1,n/2);
 p2=strassensalgo(s2,b22,n/2);
 p3=strassensalgo(s3,b11,n/2);
 p4=strassensalgo(a22,s4,n/2);
 p5=strassensalgo(s5,s6,n/2);
 p6=strassensalgo(s7,s8,n/2);
 p7=strassensalgo(s9,s10,n/2);
 
 c11=addmatrix(submatrix(addmatrix(p5,p4,n/2),p2,n/2),p6,n/2);
 c12=addmatrix(p1,p2,n/2);
 c21=addmatrix(p3,p4,n/2);
 c22=submatrix(submatrix(addmatrix(p5,p1,n/2),p3,n/2),p7,n/2); 
 
 vector< vector<long long int> > final;
 temp1.clear();
 for(i=0;i<n/2;i++)
 {
 	for(j=0;j<n/2;j++)
 	{
 		temp1.push_back(c11[i][j]);
	 }
	 
	 for(j=0;j<n/2;j++)
 	{
 		temp1.push_back(c12[i][j]);
	 }
	 
	 final.push_back(temp1);
	 temp1.clear();
  }
  
  temp1.clear();
  for(i=0;i<n/2;i++)
 {
 	for(j=0;j<n/2;j++)
 	{
 		temp1.push_back(c21[i][j]);
	 }
	 
	 for(j=0;j<n/2;j++)
 	{
 		temp1.push_back(c22[i][j]);
	 }
	 
	 final.push_back(temp1);
	 temp1.clear();
  }
  return final;
}

int main()
{
	int it,test;
	
	cin>>test;
	
	for(it=0;it<test;it++)
	{
	
	vector < vector<long long int> > a,b,c;
    int n,i,j;
    cin>>n;
    long long int temp;
    
	for(i=0;i<n;i++)
    {
    	vector <long long int> tempv;
    	for(j=0;j<n;j++)
    	{
    		cin>>temp;
    		tempv.push_back(temp);
		}
		a.push_back(tempv);
		b.push_back(tempv);
		tempv.clear();
	}
	c=strassensalgo(a,b,n);
	print(c);
	a.clear();
	b.clear();
	c.clear();
}
}
