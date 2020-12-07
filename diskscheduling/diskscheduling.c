#include<stdio.h>
#include<stdlib.h>
//fcfs
int fcfs() {
int diskQueue[20], n, i, seekTime=0, diff;
printf("Enter the size of Queue: ");
scanf("%d", &n);
printf("Enter the Queue: ");
for(i=1;i<=n;i++) { /* head element to be read */
scanf("%d",&diskQueue[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &diskQueue[0]); /* head element */
printf("\nMovement of Cylinders\n");
for(i=0;i<n;i++) {
diff= abs(diskQueue[i+1] - diskQueue[i]); /* abs( ) function in C
returns the absolute value of an integer, which is always positive. */
seekTime+= diff;
printf("Move from %d to %d with seek time %d\n", diskQueue[i], diskQueue[i+1],
diff);
}
printf("\nTotal Seek Time: %d", seekTime);
printf("\nAverage Seek Time = %f",(float) seekTime/n);
printf("\n");
return 0;
}
//SCAN
void scan(int Ar[20], int n, int start);
void sort(int Ar[20], int n);
int scanmain() {
int diskQueue[20], n, start, i;
printf("Enter the size of Queue: ");
scanf("%d", &n);
printf("Enter the Queue: ");
for(i=1;i<=n;i++) { /* head element to be read */
scanf("%d",&diskQueue[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &start);
diskQueue[0] = start; /* injecting to the first
position */
++n;
sort(diskQueue, n); /* total of n+1 elements */
scan(diskQueue, n, start);
return 0;
}
void scan(int Ar[20], int n, int start) {
int i, pos, diff, seekTime=0, current;
// position of the disk to start seeking
for(i=0;i<n;i++) {
if(Ar[i]==start) {
pos=i;break;
}
}
// start seeking to the right
printf("\nMovement of Cylinders\n");
for(i=pos;i<n-1;i++) {
diff = abs(Ar[i+1] - Ar[i]);
seekTime += diff;
printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
}
current=i; /* last element position */
// start seeking to the left
for(i=pos-1;i>=0;i--) {
diff = abs(Ar[current] - Ar[i]);
seekTime += diff;
printf("Move from %d to %d with seek time %d\n", Ar[current], Ar[i], diff);
current=i;
}
printf("\nTotal Seek Time: %d", seekTime);
// average of entered elements(n-1) excluding head
printf("\nAverage Seek Time = %f",(float) seekTime/(n-1));
printf("\n");
}
void sort(int Ar[20], int n) {
int i, j, tmp;
for(i=0;i<n-1;i++) {
for(j=0;j<n-1-i;j++) {
if(Ar[j]>Ar[j+1]) {
tmp = Ar[j];
Ar[j] = Ar[j+1];
Ar[j+1] = tmp;
}
}
}
}
//CSCAN
void cscan(int Ar[20], int n, int start);
void csort(int Ar[20], int n);
int cscanmain() {
int diskQueue[20], n, start, i, max;
printf("Enter the size of Queue: ");
scanf("%d", &n);
printf("Enter the Queue: ");
for(i=1;i<=n;i++) { /* head element to be read */
scanf("%d",&diskQueue[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &start);
diskQueue[0] = start; /* injecting to the first
position */
++n;
sort(diskQueue, n); /* total of n+1 elements */
cscan(diskQueue, n, start);
return 0;
}
void cscan(int Ar[20], int n, int start) {
int i, pos, diff, seekTime=0, current;
// position of the disk to start seeking
for(i=0;i<n;i++) {
if(Ar[i]==start) {
pos=i;
break;
}
}
// start seeking to the right
printf("\nMovement of Cylinders\n");
for(i=pos;i<n-1;i++) {
diff = abs(Ar[i+1] - Ar[i]);
seekTime+= diff;
printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
}
current=0; /*
start and end are same as circular, so start state i.e, 0*/
// last element to 0, the first element
printf("Move from %d to %d with seek time %d\n", Ar[i], current, 0); /*
head movement as cylinders are treated as a circular list (C-SCAN always goes back to the
first track) */
// start seeking to the right from 0
for(i=0;i<pos;i++) {
diff = abs(Ar[i] - current);
seekTime+= diff;
printf("Move from %d to %d with seek time %d\n", current, Ar[i], diff);
current = Ar[i];
}
printf("\nTotal Seek Time: %d", seekTime);
// average of entered elements(n-1) excluding head
printf("\nAverage Seek Time = %f",(float) seekTime/(n-1)); /*
Note: Even though six seeks were performed using the C-SCAN algorithm, only five I/Os were
actually done. */
printf("\n");
}
void csort(int Ar[20], int n) {
int i, j, tmp;
for(i=0;i<n-1;i++) {
for(j=0;j<n-1-i;j++) {
if(Ar[j]>Ar[j+1]) {tmp = Ar[j];
Ar[j] = Ar[j+1];
Ar[j+1] = tmp;
}
}
}
}

void main(){
int ch;
do
{
printf("\nDisk Scheduling Simulation\n");
printf("-------------------------------");
printf("\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit\n");
printf("\nEnter choice : ");
scanf("%d",&ch);

switch(ch)
{
case 1:fcfs();break;
case 2:scanmain();break;
case 3:cscanmain();break;
case 4:printf("\nExit.... \n");break;
default:printf("\nInvalid entry");
}
}while(ch!=4);

}