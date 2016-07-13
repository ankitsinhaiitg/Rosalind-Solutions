# include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	string s,t;
	inputfile>>s>>t;
	long n=s.size(),mut=0;
	for(long i=0;i<n;i++)
	if(s[i]!=t[i])
	 mut++; 
	result<<mut;
	cout<<mut;
	inputfile.close();
	result.close();

	return 0;
}
