# include <iostream>
#include <fstream>

using namespace std;
char amino(char ch1, char ch2, char ch3)
{

	string codons[64] = {"UUU","UUC","UUA","UUG","UCU","UCC","UCA","UCG","UAU","UAC","UAA","UAG","UGU","UGC","UGA","UGG",
						 "CUU","CUC","CUA","CUG","CCU","CCC","CCA","CCG","CAU","CAC","CAA","CAG","CGU","CGC","CGA","CGG",
						 "AUU","AUC","AUA","AUG","ACU","ACC","ACA","ACG","AAU","AAC","AAA","AAG","AGU","AGC","AGA","AGG",
						 "GUU","GUC","GUA","GUG","GCU","GCC","GCA","GCG","GAU","GAC","GAA","GAG","GGU","GGC","GGA","GGG"};
	char aminoAcids[64]={'F','F','L','L','S','S','S','S','Y','Y','Z','Z','C','C','Z','W',
						 'L','L','L','L','P','P','P','P','H','H','Q','Q','R','R','R','R',
						 'I','I','I','M','T','T','T','T','N','N','K','K','S','S','R','R',
						 'V','V','V','V','A','A','A','A','D','D','E','E','G','G','G','G'};
    char a;
   
	for(int i =0; i<64;i++)
	{	a=aminoAcids[i];

        if(ch1==codons[i][0] && ch2==codons[i][1] && ch3==codons[i][2])
        {
            
         return a;

        }
		}

}




int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream result("results.txt");
	char ch1,ch2,ch3,am; string Codon;

	while(1)
	{
		
    inputfile>>ch1; Codon[0]=ch1;
	inputfile>>ch2; Codon[1]=ch2;
	inputfile>>ch3; Codon[2]=ch3;
	
	am=amino(ch1,ch2,ch3);

	if(am=='Z')
	break;
	else
	result<<am;

	}
inputfile.close();
result.close();
return 0;
}
