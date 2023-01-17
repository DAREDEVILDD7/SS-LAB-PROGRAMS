#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
 FILE *f1,*f2,*f3,*f4,*f5,*f6;
 int lc,sa,l,op1,o,len;
 char m1[20],la[20],op[20],otp[20];
 f1=fopen("input.txt","r");
 f3=fopen("symtab.txt","w");
 f5=fopen("intermediate.txt","w");
 fscanf(f1,"%s%s%X",la,m1,&op1);
 if(strcmp(m1,"START")==0)
 {
  sa=op1;
  lc=sa;
  //write line to intermediate file
  fprintf(f5,"0000\t%s\t%s\t%X\n",la,m1,op1);
 }
 else
 {
  lc=0;
 }
 fscanf(f1,"%s%s",la,m1);
 while(!feof(f1))
 {
  fscanf(f1,"%s",op);
  fprintf(f5,"%X\t%s\t%s\t%s\n",lc,la,m1,op);
  if(strcmp(la,"**")!=0)
  {
   fprintf(f3,"\n%X\t%s\n",lc,la);
  }
  f2=fopen("optab.txt","r");
  fscanf(f2,"%s%X",otp,&o);
  while(!feof(f2))
  {
   if(strcmp(m1,otp)==0)
   {
    lc=lc+3;
    break;
   }
   fscanf(f2,"%s%X",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
  {
   lc=lc+3;
  }
  else if(strcmp(m1,"RESW")==0)
  {
   op1=atoi(op);
   lc=lc+(3*op1);
  }
    else if(strcmp(m1,"RESB")==0)
  {
   op1=atoi(op);
   lc=lc+op1;
  }
    else if(strcmp(m1,"BYTE")==0)
  {
   if(op[0]=='X')
   {
    lc=lc+1;
   }
   else
   {
    len=strlen(op)-2;
    lc=lc+len;
   }
  }
  fscanf(f1,"%s%s",la,m1);
 }
 if(strcmp(m1,"END")==0)
 {
  printf("\n Program Length= %X",lc-sa);
 }
 f6=fopen("length.txt","w");
 fprintf(f6,"%X",lc-sa);
 fclose(f6);
 fclose(f1);
 fclose(f3);
}
