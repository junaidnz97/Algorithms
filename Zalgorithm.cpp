#include<bits/stdc++.h>
using namespace std;

int genzarray(int z[],int n,string s)
{
   
   int i;
   z[0]=0;
   int l=0,r=0,k;

   for(i=1;i<n;i++)
   {
       
       if(i>r)
       {
       	  l=i;
       	  r=i;

       	  while(r<n && s[r-l]==s[r])
       	  {
       	  	r++;
       	  }
       	  z[i]=r-l;
       	  r--;
       }
       else
       {
          k=l-i;

          if(z[k]<=r+i)
          {
          	z[i]=z[k];
          }
          else
          {
          	l=i;
          	while(r<n && s[r-l]==s[r])
          	{
          		r++;
          	}
          	z[i]=r-l;
          	r--;
          }
       }
   }
}

int main()
{
    while(1)
    {
	string s;
    cin>>s;
	int l=s.length();

	int z[l];

	genzarray(z,l,s);

	for(int i=0;i<l;i++)
		cout<<z[i]<<" ";
	cout<<endl;
}
}