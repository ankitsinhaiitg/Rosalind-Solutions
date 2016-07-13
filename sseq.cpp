# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");
	ofstream result("results.txt");
	string fasta[2]; long int al[2], j=0,i=0,count=0;char s[2][1000],ch;
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
	fileone<<"no. of sequence"<<count<<endl;j=0;
	for(i=0;i<al[1];i++)
        for(j;j<al[0];j++)
    {
        if(s[1][i]==s[0][j])
        {
            result<<j+1<<" ";
            cout<<j+1<<" ";j++;
            break;
        }
    }
	inputfile.close();
	result.close();
	fileone.close();

	return 0;
}
