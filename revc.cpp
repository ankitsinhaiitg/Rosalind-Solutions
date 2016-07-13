#include <stdlib.h>
#include <iostream>
using namespace std;
 
int main()
{
   char ch, file_name[25],data[1000];
   FILE *fp;
 
   printf("Enter the name of input file\n");
   gets(file_name);
 
   fp = fopen(file_name,"r"); // read mode
   FILE *fp1;
   
      fp1 = fopen("results.txt", "w"); //write mode
   
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   int i=0;
   while( ( ch = fgetc(fp) ) != EOF )
      {
	  data[i]=ch;
      i++;}
	  
	  for(i;i>=0;i--)
	  {
		if(data[i]=='A')
      	fprintf(fp1, "%c", 'T');
      	else if(data[i]=='C')
      	fprintf(fp1, "%c", 'G');
      	else if(data[i]=='G')
      	fprintf(fp1, "%c", 'C');
      	else if(data[i]=='T')
      	fprintf(fp1, "%c", 'A');
      }

   fclose(fp);
   fclose(fp1);
   return 0;
}
