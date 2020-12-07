#include<stdio.h>
#include<string.h>
#define max 11
struct sym
{
int adr;
char sm[20];
}s[max];
void hashc(int key, int address, char label[20])
{
int i = 0,count = 0,vacant = 0;
for(i=0;i<max;i++)
{
if(s[i].adr != 0)
{
count++;
}
}
if(count == max)
printf("THE SYMTAB IS FULL.\n");
else
{
for(i=key+1;i<max;i++)
{
if(s[i].adr == 0)
{
s[i].adr = address;
strcpy(s[i].sm,label);
vacant = 1;
break;
}
}
if(!vacant)
{
for(i=0;i<key;i++)
{
if(s[i].adr == 0)
{
s[i].adr = address;
strcpy(s[i].sm,label);
break;
}
}
}
}
}
int key(int n)
{
return(n%11);
}
void hash(int key, int address,char label[20])
{
if(s[key].adr==0)
{s[key].adr = address;strcpy(s[key].sm,label);
}
else
{
hashc(key,address,label);
}
}
void display()
{
int i;
for(i=0;i<max;i++)
{
printf("%d\t%d\t%s\n",i,s[i].adr,s[i].sm);
}
}
void search(char symbol[20])
{
int i;
for(i=0;i<max;i++)
{
if(!strcmp(s[i].sm,symbol))
{
printf("Symbol %s is found at the address. %d\n",symbol,s[i].adr);
break;
}
}
if(i == max)
printf("Symbol not found.\n");
}
void main()
{
int i,a,n,j,ch,keyv;
char l[20];
for(i=0;i<max;i++)
s[i].adr=0;
do
{
printf("\n1:Insert\t2:Search\t3:Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the address : ");
scanf("%d",&n);
printf("Enter the symbol name : ");
scanf("%s",l);
keyv = key(n);
hash(keyv,n,l);
display();
break;
case 2:
printf("Enter the symbol name : ");
scanf("%s",l);
search(l);
break;
case 3:
printf("Program Terminated!!!\n");
break;
default:
printf("Invalid entry.");
break;
}
}while(ch!=3);
}