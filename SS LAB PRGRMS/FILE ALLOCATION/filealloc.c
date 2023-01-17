#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int spaces[50];

struct file
{
 char name[20];
 int index;
 int len;
 int status;
 int block[20];
}f[20];

struct fall
{
 char name[20];
 int start;
 int len;
 int status;
}f1[20];

int search(int start, int len)
{
 int i,flag=1;
 for(i=start;i<start+len;i++)
 {
  if(spaces[i]==1)
  {
  flag=0;
  break;
  }
 }
 return flag;
}


int searchi(int b)
{
 int flag=1;
  if(spaces[b]==1)
  flag=0;
 return flag;
}

//Sequential File Allocation
void seq()
{
 int i,j,n,flag,s,l;
 for(i=0;i<50;i++)
 {
  spaces[i]=0;
 }
 printf("\n Enter the no: of files you wish to insert:");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  printf("\n Enter the file name: ");
  scanf("%s",f1[i].name);
  printf("\n Enter the starting address: ");
  scanf("%d",&f1[i].start);
  printf("\n Enter the file length (in Bytes) ");
  scanf("%d",&f1[i].len);
  flag=search(f1[i].start,f1[i].len);
  if(flag==1)
  {
   for(j=f1[i].start;j<(f1[i].start+f1[i].len);j++)
   spaces[j]=1;
   printf("\n File %s successfully allocated ",f1[i].name);
   f1[i].status=1;
  }
  else
  {
   printf("\n File not allocated ");
   f1[i].status=0; 
   }
 }
 printf("\n \n DETAILS: \n");
 for(int i=0;i<n;i++)
 {
 if(f1[i].status==1)
 {
 printf("\n File Name:  %s",f1[i].name);
 printf("\n File Starting Address: %d",f1[i].start);
 printf("\n File Length: %d",f1[i].len);
 }
 }
}

//Indexed File Allocation
void ind()
{
 int i,j,n,b;
 for(i=0;i<50;i++)
 {
  spaces[i]=0;
 }
 printf("\n Enter the no: of files you wish to insert:");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  printf("\n Enter the file name: ");
  scanf("%s",f[i].name);
  do{
  printf("\n Enter the index block: of file %s",f[i].name);
  scanf("%d",&f[i].index);
  }while(searchi(f[i].index)==0);
  printf("\n Enter the length of file ");
  scanf("%d",&f[i].len);
  for(j=0;j<f[i].len;j++)
  {
   do{
    b=rand()%50;
   }while(searchi(b)!=1);
   f[i].block[j]=b;
   spaces[b]=1;
  }
  }
 printf("\n \n DETAILS: \n");
 for(int i=0;i<n;i++)
 {
 printf("\n File Name:  %s",f[i].name);
 printf("\n File Index Block: %d",f[i].index);
 printf("\n File Length: %d",f[i].len);
  printf("\n File Blocks:");
 for(j=0;j<f[i].len;j++)
 {
  printf("%d  ",f[i].block[j]);
 }
 }
}

//Linked File Allocation
void lin()
{
 int i,j,n,b;
 for(i=0;i<50;i++)
 {
  spaces[i]=0;
 }
 printf("\n Enter the no: of files you wish to insert:");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  printf("\n Enter the file name: ");
  scanf("%s",f[i].name);
  do{
  printf("\n Enter the starting block: of file %s",f[i].name);
  scanf("%d",&f[i].index);
  }while(searchi(f[i].index)==0);
  printf("\n Enter the length of file ");
  scanf("%d",&f[i].len);
  for(j=0;j<f[i].len-1;j++)
  {
   do{
    b=rand()%50;
   }while(searchi(b)!=1);
   f[i].block[j]=b;
   spaces[b]=1;
  }
  }
 printf("\n \n DETAILS: \n");
 for(int i=0;i<n;i++)
 {
 printf("\n File Name:  %s",f[i].name);
 printf("\n File Length: %d",f[i].len);
  printf("\n File Blocks:");
  printf("%d-->",f[i].index);
 for(j=0;j<f[i].len-1;j++)
 {
  printf("%d-->",f[i].block[j]);
 }
 }
}

int main()
{
 int o,p;
 do{
 printf("\n Enter the file allocation to implement");
 printf("\n 1. Sequential File Allocation ");
 printf("\n 2. Indexed File Allocation ");
 printf("\n 3. Linked File Allocation ");
 scanf("%d",&o);
 switch(o)
 {
  case 1:seq();
  	 break;
  case 2:ind();
  	 break;
  case 3:lin();
  	 break;
  default:printf("\n Invalid Option!!! \n");
 }
 printf("\n Do you want to continue? 1.Yes 2.No");
 scanf("%d",&p);
 }while(p!=2);
 return 0;
}
