# include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	char file_name[25];
	printf("Enter the name of input file\n");
    cin>>file_name;
	ifstream inputfile(file_name);
	ofstream fileone("one.txt");
	ofstream result("results.txt");
	string fasta[200]; long int al[200], j=0,i=0,count=0;char s[100][1000],ch;
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
	fileone<<"no. of sequence"<<count<<endl;
	i=0;j=0;long int t=1,c,k,in[200],p=0;
	
	
	
	for(t;t<count;t++)
    { i=0;	while(i<al[0])                   //replace s1 with al[0]
	{	c=i;
	
	
		if(s[0][i]==s[t][0])           //s to s[0]   and  t to s[t]
		{ 
		for(i;i<c+al[t] || i<al[0];i++)      // t1 to al[t]
		if(s[0][i]!=s[t][j])
		{
				break;
		}
		else j++;}
		
		
		if(i==c+al[t]){		
		in[p]=c;fileone<<in[p]<<" "; p++;  in[p]=c+al[t]; fileone<<in[p]<<" "; p++;}		
		i=c+1;j=0;
		
	}}
    char final[1000];j=0;k=0;i=0;
    qsort(in, p, sizeof(long int), compare);
    
    
    for(i=0;i<al[0];i++)
    {
    	if(i<in[j])
    	{
		final[k]=s[0][i];  k++; 
	}
	else if(i==in[j+1]-1) { if(j+2==p) {in[j+1]=al[0]; j=j+1;}  else j=j+2;}
	}
	
	 fileone<<endl<<endl;
	for(j=0;j<k;j++)
	fileone<<final[j];
	j=0;
	while(j<k)
	{
	fileone<<endl<<final[j]<<final[j+1]<<final[j+2]<<endl;
	string codons[64] = {"TTT","TTC","TTA","TTG","TCT","TCC","TCA","TCG","TAT","TAC","TAA","TAG","TGT","TGC","TGA","TGG",
						 "CTT","CTC","CTA","CTG","CCT","CCC","CCA","CCG","CAT","CAC","CAA","CAG","CGT","CGC","CGA","CGG",
						 "ATT","ATC","ATA","ATG","ACT","ACC","ACA","ACG","AAT","AAC","AAA","AAG","AGT","AGC","AGA","AGG",
						 "GTT","GTC","GTA","GTG","GCT","GCC","GCA","GCG","GAT","GAC","GAA","GAG","GGT","GGC","GGA","GGG"
};
	char aminoAcids[64]={'F','F','L','L','S','S','S','S','Y','Y','Z','Z','C','C','Z','W',
						 'L','L','L','L','P','P','P','P','H','H','Q','Q','R','R','R','R',
						 'I','I','I','M','T','T','T','T','N','N','K','K','S','S','R','R',
						 'V','V','V','V','A','A','A','A','D','D','E','E','G','G','G','G'};
    char a;
   
	for(int i =0; i<64;i++)
	{	a=aminoAcids[i];

        if(final[j]==codons[i][0] && final[j+1]==codons[i][1] && final[j+2]==codons[i][2])
        {
         if(a=='Z')
		 return 0;
		    
         result<<a;
         

        }
		}
		j=j+3;
}

	inputfile.close();
	result.close();
	fileone.close();
	
	return 0;
}
