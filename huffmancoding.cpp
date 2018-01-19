#include<bits/stdc++.h>
using namespace std;

struct NODE
{
	int value;
	NODE *left;
	NODE *right;
};

struct compare
{
	bool operator() (NODE * const &p1,NODE * const &p2)
	{
		return p1->value > p2->value;
	}
};

NODE *createnode(int value)
{

   NODE *node=new NODE;
   node->value=value;
   node->left=NULL;
   node->right=NULL;
   return node;
}

NODE *buildhuffman(char c[100],int a[100],int n)
{
  
  priority_queue<NODE *, vector<NODE *>, compare> pq;
  NODE *temp;
  int i;
  for(i=0;i<n;i++)
  {
     temp=createnode(a[i]);
     pq.push(temp);
  }

  //cout<<pq.size();
  NODE *temp1,*temp2;

  while(pq.size()>1)
  {
    temp1=pq.top();
    pq.pop();
    temp2=pq.top();
    pq.pop();
    temp=createnode(temp1->value+temp2->value);
    if(temp1->value>temp2->value)
    {
    	temp->left=temp2;
    	temp->right=temp1;
    }
    else
    {
    	temp->left=temp1;
    	temp->right=temp2;
    }
    pq.push(temp);

  }

  return pq.top();


}

void bfs(NODE *head)
{

   NODE *temp;
   queue <NODE *> q;

   q.push(head);

   while(!q.empty())
   {

   	  temp=q.front();
   	  q.pop();
   	  cout<<temp->value<<endl;
   	  if(temp->left)
   	  {
   	  	q.push(temp->left);
   	  }
   	  if(temp->right)
   	  {
   	  	q.push(temp->right);
   	  }
   }


}
int printflag=0;

void printcode(NODE *head,char s[],int value,int pos)
{
	if(head==NULL || printflag==1)return;

	if(head->value==value && printflag==0 &&head->left==NULL && head->right==NULL)
	{
       printflag=1;
       s[pos]='\0';
       
       return;
	}
	 if(head->left!=NULL && printflag==0)
	{
        s[pos]='0';
        printcode(head->left,s,value,pos+1);
	}
	if(head->right!=NULL && printflag==0)
	{
		s[pos]='1';
		printcode(head->right,s,value,pos+1);
	}
}

int main()
{

  int it,test;
  cin>>test;
  for(it=0;it<test;it++)
  {
  	int n;
  	cin>>n;
  	char c[100];
  	int a[100],i;
  	for(i=0;i<n;i++)
  	{
  		cin>>c[i]>>a[i];
  	}

  	NODE *head=buildhuffman(c,a,n);

  	//bfs(head);

  	for(i=0;i<n;i++)
  	{
  	    char s[100];
  	    printflag=0;
  		printcode(head,s,a[i],0);
  		cout<<s<<endl;
  		
  	}

  }
  
}