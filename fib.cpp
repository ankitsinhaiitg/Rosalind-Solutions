# include <iostream>
#include <fstream>
using namespace std;
int main()

{
	char file_name[25];
	printf("Enter the name of file you wish to see\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	long long month,kid,rpair,f0=1,f1=1,temp;
	inputfile>>month;
	inputfile>>kid;
	// f0 =1 , f1= kid,  fn=fn-1 + 3*fn-2

	for ( int c = 0 ; c < month ; c++ )
   {
      if ( c <= 1 )
         temp = c;
      else
      {
         temp = 3*f0 + f1;
         f0 = f1;
         f1 = temp;
      }
      
   }
	result<<temp;
	cout<<temp;
	inputfile.close();
	result.close();
	return 0;
}
	
