# include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	string fasta; long int al=0, j=0,i=0,count=0;char s[10][1000],ch;
	inputfile>>ch;
	while(!inputfile.eof())
	{
	
		
		
		inputfile>>fasta;
		for(j=0;j<1000;j++)
		{inputfile>>s[i][j];  
			if (s[i][j]=='>')break;
			if(inputfile.eof()) break;
		}
		count++;
		ch='a';
		
		i++;
	}
	     //7
	al=j;
	
	long int profile[4][al],A=0,C=0,G=0,T=0,m=0;
	 //8
	for(long int j=0;j<al;j++)       // counting of ATCG 
	{

	for(i=0;i<count;i++)
	{
		if(s[i][j]=='A')
		A++;
		if(s[i][j]=='C')
		C++;
		if(s[i][j]=='G')
		G++;
		if(s[i][j]=='T')
		T++;
	} 
	m=max(max(A,C),max(G,T));
	if(m==A) result<<"A";else if(m==C) result<<"C";else if(m==G) result<<"G";else if(m==T) result<<"T";	
	profile[0][j]=A ;A=0;profile[1][j]=C;C=0;profile[2][j]=G;G=0;profile[3][j]=T;T=0;
	

	}
	result<<endl;
	for(long int i=0;i<4;i++)
	{ if(i==0) result<<"A: ";if(i==1) result<<"C: ";if(i==2) result<<"G: ";if(i==3) result<<"T: ";
	for(long int j=0;j<al;j++)
	result<<profile[i][j]<<" ";
	result<<endl;}
	inputfile.close();
	result.close();

	return 0;
}
