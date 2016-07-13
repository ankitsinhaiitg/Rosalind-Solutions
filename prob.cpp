# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");
	ofstream result("results.txt");
	string fasta,s; long int al, j=0,i=0,count=0; long double frac[20];
	inputfile>>s;     // reading sequence
	fileone<<s<<endl;
	do
	{

		inputfile>>frac[i];
		i++;

	}while(!inputfile.eof()) ;

	al=s.size(); count=i-1;
	for(i=0;i<count;i++)
	fileone<<frac[i]<<" ";

	fileone<<endl<<"no. of sequence "<<count<<endl;
	long int A=0,T=0,C=0,G=0;
	for(i=0;i<al;i++)
	{if(s[i]=='A')
	A++;
	if(s[i]=='C')
	C++;
	if(s[i]=='G')
	G++;
	if(s[i]=='T')
	T++;
	}
    long double logc,loga;
	fileone<<endl<<"A="<<A<<"C"<<C<<"G"<<G<<"T"<<T<<"fac1";
	for(i=0;i<count;i++)
    {
        logc=log10l((frac[i])/2);
        loga=log10l((1-frac[i])/2);
        result<<((C+G)*logc)+((A+T)*loga)<<" ";
    }

	inputfile.close();
	result.close();
	fileone.close();


	return 0;
	}
