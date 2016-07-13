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
	// compare s[0] with s[1] and so on.

        for(i=1;i<count;i++)
        {
            for(j=0;j<al[0];j++)
        {for(k=0;k<al[i];k++)
        {   if(s[i][k]==s[0][j])
                 {if(k>0 && j>0)
                        {tab1[j][k]=tab1[j-1][k-1]+1;

                        }
                   else
                       {tab1[j][k]=1;}}
            else
                {tab1[j][k]=0;}
        }}

    for(long int i1=0;i1<al[0];i1++)
    {
         for(j=0;j<al[i];j++)
        {fileone<<tab1[i1][j];
                if(tab1[i1][j]>=max1)
                max1=tab1[i1][j];

        }
        fileone<<endl;maxtab[i-1][i1]=max1; max1=0;
    } fileone<<endl;

        }
long int resultv[1000];max1=10000;
    for(j=0;j<al[0];j++)
           {
            for(i=0;i<count-1;i++)
            {fileone<<maxtab[i][j];
                if(maxtab[i][j]<max1)
                    max1=maxtab[i][j];

            }
            fileone<<endl;resultv[j]=max1;max1=10000;

            }
            max1=0;
            for(i=0;i<al[0];i++)
            {
              fileone<<resultv[i];
                if(resultv[i]>max1)
                    max1=resultv[i];
            } fileone<<endl<<max1;
            long  int index;
            for(i=0;i<al[0];i++)
            {
                if(max1==resultv[i])
                {
                    index=i;
                    break;
                }
            }
            cout<<"max="<<max1<<"index"<<index<<endl;// max=2 index=4 to print 34  i=index-max+1
            for(i=index-max1+1;i<=index;i++)
                result<<s[0][i];
	inputfile.close();
	result.close();
	fileone.close();


	return 0;
}
