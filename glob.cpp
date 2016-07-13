# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
char ch1[500],ch2[500]; double score[500];
double score_blosum(char a, char b)
{	
	
	for(int i=0;i<400;i++)
	if(a==ch1[i] && b==ch2[i])
	return score[i];
	return 0;
	
}
int main()
{
	double score_blosum(char a, char b);
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ifstream blosum62("BLOSUM62.txt");
	ofstream fileone("one.txt");      //for checking.
	ofstream result("results.txt");
	long int i;
    double** tab1 = (double**)malloc(1001 * sizeof(double*));

	for (long int i=0;i<1001;++i)
	{
    	tab1[i] = (double*)malloc(1001 * sizeof(double));
	}

	string fasta[2]; long int  j=0,k=0,al[2],count=0,max1=0;char s[2][1000],ch;
	
	i=0;
	inputfile>>ch;
	while(!blosum62.eof())
		{
			blosum62>>ch1[i]>>ch2[i]>>score[i];
			i++;
		}
	blosum62.close();
	i=0;
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
	fileone<<"no. of sequence"<<count<<endl; 
	 for (int i=0; i<=al[0]; i++)      //scoring matrix
    {
        for (int j=0; j<=al[1]; j++)
        {
           
            if (i==0)
                tab1[i][j] = j*(-5);      // 5 is gap penalty   
 
            
            else if (j==0)
                tab1[i][j] = i*(-5);      // 5 is gap penalty
 
           
            else 
                {
                	count=score_blosum(s[0][i-1],s[1][j-1]);
                	tab1[i][j] = max(tab1[i][j-1]-5,max(tab1[i-1][j]-5,tab1[i-1][j-1]+count)); 
				}
 
        }}
        cout<<tab1[al[0]][al[1]];
	inputfile.close();
	result.close();
	fileone.close();	
	
	return 0;
}


