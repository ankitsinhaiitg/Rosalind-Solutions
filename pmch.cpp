# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include<C:\Users\Ankit Kumar Sinha\Desktop\Internship_Data\apping\Washington\Code_Solution\InfInt.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");
	ofstream result("results.txt");
	string fasta; long int al, j=0,i=0,count=0;char s[100],ch;
	inputfile>>ch;
	while(!inputfile.eof())  // reading sequence
	{



		inputfile>>fasta; fileone<<fasta<<endl;
		for(j=0;j<10000;j++)
		{inputfile>>s[j]; fileone<<s[j];
			if (s[j]=='>')break;
			if(inputfile.eof()) break;
		}
		count++;     // no. of sequence
		ch='a';
		al=j; fileone<<al<<endl;     // length of each sequence

	}
	fileone<<"no. of sequence"<<count<<endl;
	long int count1=0,count2=0;
	for(i=0;i<al;i++)
	{if(s[i]=='A')
	count1++;
	if(s[i]=='C')
	count2++;
	}
	fileone<<endl<<"count1 2"<<count1<<count2<<"fac1";
    InfInt C1=count1,C2=count2;
    cout<<C1<<C2<<endl;
    InfInt fac1=1 ,fac2=1;
    for(InfInt i=1;i<=C1;i++)
        fac1=fac1*i;
    for(InfInt i=1;i<=C2;i++)
        fac2=fac2*i;

 	cout<<fac1*fac2;
 	result<<fac1*fac2;
	inputfile.close();
	result.close();
	fileone.close();


	return 0;}
