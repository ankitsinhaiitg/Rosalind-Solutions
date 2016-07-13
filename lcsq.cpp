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
    long int** tab1 = (long int**)malloc(1000 * sizeof(long int*));

for (long int i=0;i<1000;++i)
{
    tab1[i] = (long int*)malloc(1000 * sizeof(long int));
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
	   fileone<<tab1[i][j]<<" ";
	   fileone<<endl;}  */
	   for (int i=0; i<=al[0]; i++)         //matrix
{
	for (int j=0; j<=al[1]; j++)
	{
	if (i == 0 || j == 0)
		tab1[i][j] = 0;
	else if (s[0][i-1] == s[1][j-1])
		tab1[i][j] = tab1[i-1][j-1] + 1;
	else
		tab1[i][j] = max(tab1[i-1][j], tab1[i][j-1]);
	}
}  
 long int m=al[0],n=al[1];
long int index = tab1[m][n],just=tab1[m][n];
char lcs[index+1];
 i = al[0]; j = al[1];
while (i > 0 && j > 0)      //tracking
{
	if (s[0][i-1] == s[1][j-1])
	{
		lcs[index-1]=s[0][i-1];
		i--; j--; index--;
			}

	else if (tab1[i-1][j] > tab1[i][j-1])
		i--;
	else
		j--;
}
for(i=0;i<=al[1];i++)
	{for(j=0;j<=al[0];j++)
	   cout<<tab1[j][i]<<" ";
	   cout<<endl;} 

for(i=0;i<just;i++)
{
		result<<lcs[i];cout<<lcs[i];
		
} 

	inputfile.close();
	result.close();
	fileone.close();

return 0;
}
