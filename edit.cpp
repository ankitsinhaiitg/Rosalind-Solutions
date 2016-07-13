# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");
	ofstream result("results.txt");
	long int i;
    long int** tab1 = (long int**)malloc(1001 * sizeof(long int*));

for (long int i=0;i<1001;++i)
{
    tab1[i] = (long int*)malloc(1001 * sizeof(long int));
}

	string fasta[200]; long int al[200], j=0,k=0,count=0,maxtab[100][1000],max1=0;char s[100][1000],ch;
	inputfile>>ch;
	while(!inputfile.eof())  // reading sequence
	{



		inputfile>>fasta[i]; fileone<<fasta[i]<<endl;
		for(j=0;j<10000;j++)
		{inputfile>>s[i][j]; fileone<<s[i][j];
			if (s[i][j]=='>')break;
			if(inputfile.eof()) break;
		}
		count++;      // no. of sequence
		ch='a';
		al[i]=j; fileone<<al[i]<<endl;     // length of each sequence
		i++;
	}
	fileone<<"no. of sequence"<<count<<endl;   //s[][]= sequences , al[]=length, count= no. of sequence.
	/*
	for(i=0;i<=al[0];i++)
	{for(j=0;j<=al[1];j++)
	   cout<<tab1[i][j]<<" ";
	   cout<<endl;}  */
	   
	  
 
    
    for (int i=0; i<=al[0]; i++)      //scoring matrix
    {
        for (int j=0; j<=al[1]; j++)
        {
           
            if (i==0)
                tab1[i][j] = j;  
 
            
            else if (j==0)
                tab1[i][j] = i; 
 
           
            else if (s[0][i-1] == s[1][j-1])
                tab1[i][j] = tab1[i-1][j-1];
 
           
            else
                tab1[i][j] = 1 + min(tab1[i][j-1],min(tab1[i-1][j],tab1[i-1][j-1])); 
        }}
    /* for(i=0;i<=al[0];i++)
	{ for(j=0;j<=al[1];j++)
	   cout<<tab1[i][j]<<" ";
	   cout<<endl;}*/
	   
        result<<tab1[al[0]][al[1]];
        cout<<tab1[al[0]][al[1]];
	inputfile.close();
	result.close();
	fileone.close();

return 0;
}
