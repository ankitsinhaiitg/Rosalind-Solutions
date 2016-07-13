# include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of the input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	char m; string fasta[10]; long double total[10]={0},gc[10]={0},per[10];int i=0;
	inputfile>>m;
	while (!inputfile.eof())
	{

		if(m=='>')
		{
			inputfile>>fasta[i];

		}
		inputfile>>m;
		while(m!='>' && !inputfile.eof() )
		{
			(total[i])++; if(m=='G' || m=='C'){(gc[i])++;} inputfile>>m;
		}
			per[i]=gc[i]/total[i];i++;
	}
	long double max1=0 ;int ind;
	i--;
	for(i;i>=0;i--)
	{	if(max1<per[i])
    		{max1=per[i]; ind=i;}
	}
	result<<fasta[ind]<<endl<<per[ind]*100;
	cout<<fasta[ind]<<endl<<per[ind]*100;
	inputfile.close();
	result.close();

return 0;
}
