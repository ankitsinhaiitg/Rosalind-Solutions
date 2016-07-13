
#include <stdlib.h>
#include <iostream>
using namespace std;
 
int main()
{
   char ch, file_name[25];
   FILE *fp;
 
   printf("Enter the name of input file\n");
   gets(file_name);
 
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
   int A=0,C=0,G=0,T=0;
 
   while( ( ch = fgetc(fp) ) != EOF )
      {
		if(ch=='A')
      	A++;
      	if(ch=='C')
      	C++;
      	if(ch=='G')
      	G++;
      	if(ch=='T')
      	T++;
      }
	cout<<A<<"\t"<<C<<"\t"<<G<<"\t"<<T; 
    fclose(fp);
    return 0;
}
