# include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of file you wish to see\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	string s,t;int index[1000],j=0,c,k=0,i=0;
	inputfile>>s;
	long s1=s.size();
	inputfile>>t;
	long t1=t.size();	
	while(i<s1)
	{	c=i;
		if(s[i]==t[0])
		{ 
		for(i;i<c+t1 && i<s1;i++)
		if(s[i]!=t[j])
		{
				break;
		}
		else j++;}
		
		
		if(i==c+t1){
		
		index[k]=c+1; cout<<index[k]<<" ";result<<index[k]<<" ";k++;}
		
		i=c+1;j=0;
		
	}

	return 0;
}
