# include <iostream>
#include <fstream>
using namespace std;
double fact(double n)
{
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

double Com(double n,double r)
{
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (fact(n))/(fact(r)*fact(n-r));
};
int main()

{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");

	double dom,hetro,res,n;


	inputfile>>dom;
	inputfile>>hetro;
	inputfile>>res;

	n=dom+hetro+res;
	double total , totalr ;
	total = 4*Com(n,2);
	totalr = 4*Com(res, 2) + 2*res*hetro + Com(hetro,2);

	float prob;
    prob = (1-((float)totalr/(float)total));
	cout<<total<<" "<<totalr<<" "<<prob;
	result<<prob;

	return 0;

}
