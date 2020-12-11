#include<stdio.h>
#include<string.h>
//pass 1
void pass1main()
{
char macros[20][10], label[20],opcode[20],operand[20];
int i, j, n,m=0;
FILE *fp1, *fp[10];
fp1=fopen("inputm.txt","r");
fscanf(fp1,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
if(!strcmp(opcode,"MACRO"))
{
fp[m]=fopen(operand,"w");
perror(" : ");
m++;
fscanf(fp1,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"MEND")!=0)
{
fprintf(fp[m-1],"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s%s%s",label,opcode,operand);
}
}
fscanf(fp1,"%s%s%s",label,opcode,operand);
}
printf("\n######\nPass one of two pass macro processor algorithm executed!!!\n######\n");
}
//pass 2
void pass2main()
{
char macros[20][10], label[20],opcode[20],operand[20];
int i, j, n, m=0;
FILE *fp1, *fp[10],*fp2;
fp1=fopen("inputm.txt","r");
fp2=fopen("macro_out.txt","w");
fscanf(fp1,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
if(!strcmp(opcode,"CALL"))
{
fp[m]=fopen(operand,"r");
m++;
fscanf(fp[m-1],"%s%s%s",label,opcode,operand);
while(!feof(fp[m-1]))
{
fprintf(fp2,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp[m-1],"%s%s%s",label,opcode,operand);
}
}
else
{
fprintf(fp2,"%s\t%s\t%s\n",label,opcode,operand);
}
fscanf(fp1,"%s%s%s",label,opcode,operand);
}
fprintf(fp2,"%s\t%s\t%s\n",label,opcode,operand);
printf("\n######\nPass two of two pass assembler is executed!!!\n######\n");
}

void main(){
int ch;
do
{
printf("\nTwo Pass Macro Processor\n");
printf("-------------------------------");
printf("\n1.Pass One\n2.Pass Two\n3.Exit\n");
printf("\nEnter choice : ");
scanf("%d",&ch);

switch(ch)
{
case 1:pass1main();break;
case 2:pass2main();break;
case 3:printf("\nExit.... \n");break;
default:printf("\nInvalid entry");
}
}while(ch!=3);

}