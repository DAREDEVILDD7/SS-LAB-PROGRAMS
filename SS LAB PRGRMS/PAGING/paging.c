#include <stdio.h>
#include <stdlib.h>

int n;

struct pgtbl
{
 int pgno;
 int frno;
}p[20];

struct laddr
{
 int pageno;
 int offset;
}l;

int search(int pn)
{
 int j,flag=0;
 for(j=0;j<n;j++)
 {
  if(pn==p[j].pgno)
  {
   flag=1;
   break;
  }
 }
 return flag;
}

int main()
{
 int i,pgsize,f,q,c;
 printf("\n Enter the page size: ");
 scanf("%d",&pgsize);
 printf("\n Enter the size of page table: ");
 scanf("%d",&n);
 printf("\n Enter the contents of page table: ");
 for(i=0;i<n;i++)
 {
  printf("\n PAGE NO: ");
  scanf("%d",&p[i].pgno);
  printf("\n FRAME NO: ");
  scanf("%d",&p[i].frno);
 }
 printf("\n Enter the logical address: ");
 do
 {
  printf("\n Enter the page no: ");
  scanf("%d",&l.pageno);
  f=search(l.pageno);
  if(f==0)
  printf("\n Page no: not found in page table!!!");
 }while(f!=1);
 do{
  printf("\n Enter the offset value");
  scanf("%d",&l.offset);
  q=l.offset;
  if(q>pgsize-1)
  printf("\n Entered offset not valid");
  }while(q>pgsize);

  for(i=0;i<n;i++)
  {
   if(l.pageno==p[i].pgno)
   {
    c=p[i].frno;
   }
  }
  c=c*pgsize;
  c=c+l.offset;
  printf("\n The corresponding Physical Address is: %d",c);
}

/*
OUTPUT

 Enter the page size: 4

 Enter the size of page table: 5

 Enter the contents of page table: 
 PAGE NO: 0

 FRAME NO: 2

 PAGE NO: 1

 FRAME NO: 4

 PAGE NO: 2

 FRAME NO: 5

 PAGE NO: 3

 FRAME NO: 6

 PAGE NO: 4

 FRAME NO: 9

 Enter the logical address: 
 Enter the page no: 6

 Page no: not found in page table!!!
 Enter the page no: 7

 Page no: not found in page table!!!
 Enter the page no: 3

 Enter the offset value5

 The corresponding Physical Address is: 29
 
 */
