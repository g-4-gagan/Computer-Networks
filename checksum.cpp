#include<iostream>
#include<stdlib.h>
using namespace std;

void print(int ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<ar[i];
	}
	cout<<endl;
}

void dectobin(int ar[],int size,int dec)
{
	for(int j=size;j>0 && dec!=0;j--)
	{
		ar[j-1]=dec%2;
		dec=dec/2;
	}
	return;
}

int main()
{
	int n,m;
	cout<<"Enter the size of the checksum Bit: ";
	cin>>n;
	cout<<"Enter the size of Data Word: ";
	cin>>m;
	int data[m/n][n];
	cout<<"Enter the Data Word: ";
	for(int i=0;i<m/n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>data[i][j];
		}
	}
	
	int temp[n+1];
	temp[0]=0;
	for(int i=0;i<n+1;i++)
	{
		temp[i]=0;
	}
	for(int i=0;i<m/n;i++)
	{
		int carry=0;
		for(int j=n;j>0;j--)
		{
			carry=temp[j]+data[i][j-1]+carry;
			switch (carry)
			{
				case 0: temp[j]=0;
				    carry=0;
				    break;
				case 1: temp[j]=1;
				    carry=0;  
					break;
				case 2: temp[j]=0;
				    carry=1;
				    break;
				case 3: temp[j]=1;
				    carry=1;
				    break;
			}
		}
		temp[0]=temp[0]+carry;
	}
	int cary[n];
	for(int i=0;i<n;i++)
	{
		cary[i]=0;
	}
	dectobin(cary,n,temp[0]);
	int a =0; 
	for(int j=n;j>0;j--)
		{
			a=temp[j]+cary[j-1]+a;
			switch (a)
			{
				case 0: temp[j]=0;
				    a=0;
				    break;
				case 1: temp[j]=1;
				    a=0;  
					break;
				case 2: temp[j]=0;
				    a=1;
				    break;
				case 3: temp[j]=1;
				    a=1;
				    break;
			}
		}
		temp[0]=a;
		for(int i=0;i<n+1;i++)
		{
			if(temp[i]==0)
			  temp[i]=1;
			else
			  temp[i]=0;
		}
		cout<<"Check-sum bit is: \n";
		print(temp,n+1);
		int codeword[m/n+1][n];
		for(int i=0;i<m/n;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    codeword[i][j]=data[i][j];
		    }
	    }
	    for(int i=0;i<n;i++)
	    {
	    	codeword[m/n][i]=temp[i+1];
		}
		cout<<"Code Word is:\n";
		for(int i=0;i<m/n+1;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    cout<<codeword[i][j];
		    }
	    }
	    cout<<endl;
		int copycodeword[m/n+1][n];
		bool flag= true;
		while(flag)
		{
	      for(int i=0;i<m/n+1;i++)
	      {
		    for(int j=0;j<n;j++)
		    {
			    copycodeword[i][j]=codeword[i][j];
		    }
	       }
			cout<<"Sending code word to Receiver:\n";
		    int x=rand()%(m+n+10);
		    int row = x/n;
			if(x<m+n)
			{
				if(copycodeword[row][x-(row*n)]==0)
					copycodeword[row][x-(row*n)]=1;
				else
					copycodeword[row][x-(row*n)]=0;
			}
			cout<<"\n\nCode word Received by receiver:\n";
			for(int i=0,k=0;i<m/n+1;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    cout<<copycodeword[i][j];
		    }
	    }			
	        cout<<"\nReceiver Checking the code word:\n";
		for(int i=0;i<n+1;i++)
	{
		temp[i]=0;
	}
	for(int i=0;i<m/n+1;i++)
	{
		int carry=0;
		for(int j=n;j>0;j--)
		{
			carry=temp[j]+copycodeword[i][j-1]+carry;
			switch (carry)
			{
				case 0: temp[j]=0;
				    carry=0;
				    break;
				case 1: temp[j]=1;
				    carry=0;  
					break;
				case 2: temp[j]=0;
				    carry=1;
				    break;
				case 3: temp[j]=1;
				    carry=1;
				    break;
			}
		}
		temp[0]=temp[0]+carry;
	}
	cary[n];
	for(int i=0;i<n;i++)
	{
		cary[i]=0;
	}
	dectobin(cary,n,temp[0]);
	a =0; 
	for(int j=n;j>0;j--)
		{
			a=temp[j]+cary[j-1]+a;
			switch (a)
			{
				case 0: temp[j]=0;
				    a=0;
				    break;
				case 1: temp[j]=1;
				    a=0;  
					break;
				case 2: temp[j]=0;
				    a=1;
				    break;
				case 3: temp[j]=1;
				    a=1;
				    break;
			}
		}
		temp[0]=a;
		for(int i=0;i<n+1;i++)
		{
			if(temp[i]==0)
			  temp[i]=1;
			else
			  temp[i]=0;
		}
		cout<<"Check bit after Checking\n";
		print(temp,n+1);
		flag=false;
		for(int i=1;i<n+1;i++)
		{
			if(temp[i]!=0)
			{
				cout<<"Error Detected in code word...\nRequesting to resend...\n\n\n";
				cout<<"Again...";
				flag=true;
				break;
			}
		}
	}
	cout<<"Receiver received the code successfully";
}



	
