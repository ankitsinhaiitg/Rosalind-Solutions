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
   FILE *fp1;
   fp1 = fopen("results.txt", "w");
   
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
  
   while( ( ch = fgetc(fp) ) != EOF )
      {
		if(ch!='T')
      	fprintf(fp1, "%c", ch);
      	else if(ch=='T')
      	fprintf(fp1, "%c", 'U');
      }

   fclose(fp);
   fclose(fp1);
   return 0;
}
