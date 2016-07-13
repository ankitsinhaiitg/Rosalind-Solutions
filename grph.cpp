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
	string fasta[200]; long int al[200], j=0,i=0,count=0;char s[100][10000],ch;
	inputfile>>ch;
	while(!inputfile.eof())
	{
	
		
		
		inputfile>>fasta[i];
		for(j=0;j<10000;j++)
		{inputfile>>s[i][j];  
			if (s[i][j]=='>')break;
			if(inputfile.eof()) break;
		}
		count++;
		ch='a';
		al[i]=j;
		i++;
	}


	for(i=0;i<count;i++)
	{
		for(j=0;j<count ;j++)
		if(j!=i)
		if(s[i][al[i]-3]==s[j][0] && s[i][al[i]-2]==s[j][1] && s[i][al[i]-1]==s[j][2])
		{
		result<<fasta[i]<<" "<<fasta[j]<<endl;
		}
	}
	inputfile.close();
	result.close();
	return 0;
}

	
