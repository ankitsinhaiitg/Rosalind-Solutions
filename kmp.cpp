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
	string fasta; long int al, j=0,i=0,count=0,k=0;char s[100000],ch;
	inputfile>>ch;
	while(!inputfile.eof())  // reading sequence
	{	inputfile>>fasta; fileone<<fasta<<endl;
		for(j=0;j<100000;j++)
		{inputfile>>s[j]; fileone<<s[j];
			if (s[j]=='>')break;
			if(inputfile.eof()) break;		}
		count++;      // no. of sequence
		ch='a';
		al=j; fileone<<al<<endl;     // length of each sequence
		i++;
	}
	fileone<<"no. of sequence"<<count<<endl;j=0;
    long f[100000]={0};
    for(i=0;i<al;i++)
    {   if(al-i-1>0)
        {for(j=0,k=al-i-1;j<i+1,k<al;j++,k++)
        if(s[j]==s[k])
        f[k]=f[k-1]+1;
        else
            break;
        }
    }

    for(i=0;i<al;i++){
        result<<f[i]<<" ";


    }
	inputfile.close();
	result.close();
	fileone.close();
return 0;

}
