#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char operand[10];
char oprnd[10];
int flag;
void strfun()
{
flag=1;
 int i;
 char temp[10];
 for(i=0;i<strlen(operand);i++)
 {
  temp[i]=operand[i];
 }
 for(i=0;i<strlen(operand);i++)
 {
  if(temp[i]!=',')
  {
   operand[i]=temp[i];
  }
  else
  break;
 }
 operand[i]='\0';
}

void main()
{
 char a[10],ad[10],label[10],opcode[10],mneumonic[10],symbol[10];
 int i,len,actual_len,l1;
 unsigned int code,address,add,p;
 FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
 fp1=fopen("assmlist.txt","w");
 fp3=fopen("intermediate.txt","r");
   fp6=fopen("text.txt","w");
 fscanf(fp3,"%X%s%s%s",&address,label,opcode,operand);
 fprintf(fp6,"\nT^00%s^  ^",operand);
 if(strcmp(opcode,"START")==0)
 {
  fprintf(fp1,"%X\t%s\t\t%s\t%s\n",address,label,opcode,operand);
  fscanf(fp3,"%X%s%s%s",&address,label,opcode,operand);
 }
 while(strcmp(opcode,"END")!=0)
 {
  if(strcmp(opcode,"BYTE")==0)
  {
   fprintf(fp1,"%X\t%s\t\t%s\t%s\t",address,label,opcode,operand);
   fprintf(fp1,"\t\t0000");
   len=strlen(operand);
   actual_len=len-3;
   for(i=2;i<(actual_len+2);i++)
   {
    fprintf(fp1,"%c",operand[i]);
     fprintf(fp6,"00000%c^",operand[i]);
   }
   fprintf(fp1,"\n");
  }
  else if(strcmp(opcode,"WORD")==0)
  {
   fprintf(fp1,"%X\t%s\t\t%s\t%s\t\t%s0000%s\n",address,label,opcode,operand,operand,operand);
   fprintf(fp6,"%s0000^",operand);
  }
  else if((strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0))
  {
   fprintf(fp1,"%X\t%s\t\t%s\t%s\n",address,label,opcode,operand);
  }
  else
  {
   fp4=fopen("optab.txt","r");
   fscanf(fp4,"%s%X",mneumonic,&code);
   while((strcmp(opcode,mneumonic)!=0)&&!feof(fp4))
   {
    fscanf(fp4,"%s%X",mneumonic,&code);
   }
   fclose(fp4);
 if(strcmp(operand,"**")==0)
   {
    fprintf(fp1,"%X\t%s\t%s\t%s\t%X0000\n",address,label,opcode,operand,code);
   }
   else
   {
    fp2=fopen("symtab.txt","r");
    fscanf(fp2,"%X%s",&add,symbol);
    while((strcmp(operand,symbol)!=0)&&!feof(fp2))
    {
     fscanf(fp2,"%X%s",&add,symbol);
    }
     if(flag==1)
     {
     p=32768;
      printf("%X",add+p);
 	add=add+p;
     }
    fclose(fp2);
    fprintf(fp1,"%X\t%s\t\t%s\t\t%s\t%X%X\n",address,label,opcode,oprnd,code,add);
    fprintf(fp6,"%X%X^",code,add);
    }
    }
  fscanf(fp3,"%X%s%s%s",&address,label,opcode,operand);
  strcpy(oprnd,operand);
  int l=strlen(operand);
  flag=0;
  for(i=0;i<l;i++)
  {
   if(operand[i]==',')
   {
    strfun();
    break;
   }
  }
 }
 fprintf(fp1,"%X\t%s\t\t%s\t%s\n",address,label,opcode,operand);
 printf("\nASSEMBLED...");
 fclose(fp1);
 fclose(fp3);
  fp5=fopen("head.txt","w");
  fp7=fopen("end.txt","w");
  fp1=fopen("assmlist.txt","r");
  fp8=fopen("length.txt","r");
  fscanf(fp8,"%X",&l1);
  fscanf(fp1,"%X%s%s%s",&address,label,opcode,operand);
  fprintf(fp5,"\nH^%s^00%s^%X",label,operand,l1);
  fprintf(fp7,"\nE^00%s",operand);
  fclose(fp5);
  fclose(fp6);
  fclose(fp7);
}
