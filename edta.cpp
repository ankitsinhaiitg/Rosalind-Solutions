# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
char ans[2][2000],temp[2000];long int al[2],index=0,index1=0;
int indel(int seq, int i)
{       int j1,k;
    	if(seq==1) //edits in ans[0]
		{
			index++;
			for(j1=0;j1<i;j1++)
			temp[j1]=ans[0][j1];
            temp[j1]='-';
			j1++;
			for(k=i;k<al[0]+index-1;k++)
			{
				temp[j1]=ans[0][k];j1++;
			}
			for(k=0;k<al[0]+index;k++)
			ans[0][k]=temp[k];
		}
	if(seq==2) //edits in ans[1]
		{
			index1++;
			for(j1=0;j1<i;j1++)
			temp[j1]=ans[1][j1];
			temp[j1]='-';
			j1++;
			for(int k=i;k<al[1]+index1-1;k++)
			{
				temp[j1]=ans[1][k];j1++;
			}
			for(k=0;k<al[1]+index1;k++)
			ans[1][k]=temp[k];

		}
	return j1;

}
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");      //for checking.
	ofstream result("results.txt");
	long int i;
    double** tab1 = (double**)malloc(1001 * sizeof(double*));

for (long int i=0;i<1001;++i)
{
    tab1[i] = (double*)malloc(1001 * sizeof(double));
}
    double** track = (double**)malloc(1001 * sizeof(double*));

for (long int i=0;i<1001;++i)
{
    track[i] = (double*)malloc(1001 * sizeof(double));
}

	string fasta[2]; long int  j=0,k=0,count=0,max1=0;char s[2][1000],ch;
	inputfile>>ch;
	while(!inputfile.eof())  // reading sequence
	{



		inputfile>>fasta[i]; fileone<<fasta[i]<<endl;
		for(j=0;j<10000;j++)
		{inputfile>>s[i][j]; fileone<<s[i][j]; ans[i][j]=s[i][j];
			if (s[i][j]=='>')break;
			if(inputfile.eof()) break;
		}
		count++;      // no. of sequence
		ch='a';
		al[i]=j; fileone<<al[i]<<endl;     // length of each sequence
		i++;
	}
	fileone<<"no. of sequence"<<count<<endl;   //s[][]= sequences , al[]=length, count= no. of sequence.
	
/*	for ( i=0; i<=al[0]; i++)
	{
		for ( j=0; j<=al[1]; j++)     // Neddleman Wunsch algorithm
		if (i==0)
                tab1[i][j] = (-2)*j;
        else if (j==0)
                tab1[i][j] = (-2)*i;
        else if (s[0][i-1] == s[1][j-1])
        	tab1[i][j] = max(tab1[i-1][j-1]+1,max(tab1[i-1][j]-2,tab1[i][j-1]-2));
		else
			tab1[i][j] = max(tab1[i-1][j-1]-1,max(tab1[i-1][j]-2,tab1[i][j-1]-2));

		}*/

	 for (int i=0; i<=al[0]; i++)      //scoring matrix
    {
        for (int j=0; j<=al[1]; j++)
        {

            if (i==0)
                tab1[i][j] = j;


            else if (j==0)
                tab1[i][j] = i;


            else if (s[0][i-1] == s[1][j-1])
                {
                	tab1[i][j] = tab1[i-1][j-1];
                	track[i][j]=0;
				}


            else
                {   //add 1
                if(tab1[i][j-1]<tab1[i-1][j])
                	{
                		if(tab1[i][j-1]<tab1[i-1][j-1])
                			{
                				tab1[i][j] = 1+tab1[i][j-1];
								track[i][j]=2;
							}
						else
						    {
						    	tab1[i][j]=1+tab1[i-1][j-1];   //tab1[i][j] =tab1[i][j-1],min(tab1[i-1][j],tab1[i-1][j-1]));
						    	track[i][j]=0;
							}
					}
				else if(tab1[i-1][j]<tab1[i-1][j-1])
                	{
                		tab1[i][j]=1+tab1[i-1][j];
                		track[i][j]=1;
					}
					else
					{
							tab1[i][j]=1+tab1[i-1][j-1];
							track[i][j]=0;
					}
				}
        }}
    int minscore=tab1[al[0]][al[1]];
    result<<minscore<<endl;



	/*	for ( j=0; j<=al[1]; j++)      //to see score matrices

	{
				for ( i=0; i<=al[0]; i++)
			cout<<tab1[i][j]<<"  ";
			cout<<endl;
	}
	cout<<endl;
	for ( j=0; j<=al[1]; j++)

	{
				for ( i=0; i<=al[0]; i++)
			cout<<track[i][j]<<"  ";
			cout<<endl;
	}*/
	i = al[0]; j = al[1];
	while(i>0 && j>0)         //tracking the matrix
	{
		if (track[i][j] == 1)
		{
			i--;
			indel(2,j);
		}
		else if (track[i][j] == 2)
			{
				j--;
			indel(1,i);
			}
		else
			{
				i--;
				j--;
			}
	}
	while(i)
		{
			indel(2,0);
			i--;
		}
	while(j)
		{
			indel(2,0);
			j--;
		}
		
	index=index+al[0];
	
	for(i=0;i<index;i++)
	result<<ans[0][i];
	
	result<<endl;
	for(i=0;i<index;i++)
	result<<ans[1][i];
	inputfile.close();
	result.close();
	fileone.close();




	return 0;
}
