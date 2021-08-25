#include<iostream>
using namespace std;

void print(int ar[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ar[i];
	}
	return;
}

void divisionxor(int ar1[],int n1,int ar2[],int n2,int ar3[])
{
	int div[n1];
	for(int i=0;i<n1;i++)
	{
		div[i]= ar2[i];
	}
	for(int i=n1;i<=n2;i++)
	{
		if(div[0]==1)
		{
			for(int k=0;k<n1;k++)
			{
				div[k]=div[k]^ar1[k];
			}
			for(int j=1;j<n1;j++)
			{
				if(j==n1)
				{
					if(i!=n2)
					div[n1-1]=ar2[i+1];
					else
					div[n1-1]=0;
				}
				else
				{
					div[j-1]=div[j];
				}
			}
		}
		else
		{
			for(int j=1;j<n1;j++)
			{
				if(j==n1)
				{
					if(i!=n2)
					div[n1-1]=ar2[i+1];
					else
					div[n1-1]=0;
				}
				else
				{
					div[j-1]=div[j];
				}
			}
		}
	}
	for(int i=0;i<n1;i++)
	{
		ar3[i]=div[i];
	}		
}

int main()
{
	int n,a;
	cout<<"Enter the degree of the polynomial: ";
	cin>>n;
	int pol[n];
	for(int i=n,j=0;i>=0;i--,j++)
	{
		cout<<"Enter the co-efficient of x^"<<i<<": ";
		cin>>pol[j];
	}
	print(pol,n+1);
	cout<<endl<<"Enter the number of bits of Data Word: ";
    cin>>a;
    int data[a];
    int code[a+n];
    cout<<"Enter the code word: ";
    for(int i=0;i<a+n;i++)
	{
		if(i>=a)
		{
			code[i]=0;
		}
		else
		{
			cin>>data[i];
			code[i]=data[i];			
		}		
	}
	print(data,a);
	print(code,a+n);
	
	int div[n+1];
	divisionxor(pol,(n+1),code,a+n,div);
	print(div,n+1);
	for(int i=a,j=0;i<a+n;i++,j++)
	{
		code[i]=div[j];
	}
	print(code,a+n);
    
	
	
}
