#include<stdio.h>
#include<stdlib.h>
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
//fifo
void fifo(int[], int[], int, int);
void fifomain()
{
int i, pCount, fCount, pages[30], frames[20];
printf("Number of Frames : ");
scanf("%d", &fCount);
// create frames array will null value
for (i = 0; i < fCount; ++i) {
frames[i] = -1;
}
printf("Number of Pages : ");
scanf("%d", &pCount);
printf("Enter the reference string\n");
for (i = 0; i < pCount; ++i) {
scanf("%d", &pages[i]);
}
// call the function
fifo(pages, frames, pCount, fCount);
}
void fifo(int pages[], int frames[], int pCount, int fCount) {
printf("\nRef.String |\tFrames\n");
printf("-------------------------------\n");
int i, j, k, flag, faultCount = 0, queue = 0;
for (i = 0; i < pCount; ++i) {
printf(" %d\t|\t", pages[i]);
flag = 0;
for (j = 0; j < fCount; ++j) {
if (frames[j] == pages[i]) { // compare with string in str[]
flag = 1;
printf(" Hit");
break;
}
}
if (flag == 0) { // not present in frames
frames[queue] = pages[i];
faultCount++;
queue = (queue + 1) % fCount; // Queue position in circular way
// display
for (k = 0; k < fCount; ++k) {
printf("%d ", frames[k]);
}
}printf("\n\n");
}
printf("Total Page Faults = %d\n", faultCount);
}
//LRU
void LRU(int[], int[], int[], int, int);
int findLRU(int[], int);
void LRUmain() {
int i, pCount, fCount, pages[30], frames[20], time[20];
printf("Number of Frames : ");
scanf("%d", &fCount);
// create frames array will null values
for (i = 0; i < fCount; ++i) {
frames[i] = -1;
}
printf("Number of Pages : ");
scanf("%d", &pCount);
printf("Enter the reference string\n");
for (i = 0; i < pCount; ++i) {
scanf("%d", &pages[i]);
}
LRU(pages, frames, time, fCount, pCount);
}
void LRU(int pages[], int frames[], int time[], int fCount, int pCount) {
printf("\nRef.String |\tFrames\n");
printf("-------------------------------\n");
int i, j, k, pos, flag, faultCount, counter, queue;
counter = 0, queue = 0, faultCount = 0;
for (i = 0; i < pCount; ++i) {
flag = 0;printf(" %d\t|\t", pages[i]);
// check if already present
for (j = 0; j < fCount; ++j) {
if (frames[j] == pages[i]) {
flag = 1; // this means that the character is already there in one of the frames.
counter++;
time[j] = counter; // update occurance
printf(" Hit\n\n");
break;
}
}
// push if there is free space
if ((flag == 0) && (queue < fCount)) { // empty frames[] spaces
faultCount++;
counter++;
frames[queue] = pages[i];
time[queue] = counter;
queue++; // queue is to keep the count of number of frames which have been filled.
}
// replacement as frames[] is full
else if ((flag == 0) && (queue == fCount)) { // the frames are full now
faultCount++;
counter++;
pos = findLRU(time, fCount);
frames[pos] = pages[i];
time[pos] = counter;
}
// printing
if (flag == 0) {
for (k = 0; k < fCount; ++k) {
printf("%d ", frames[k]);
}
printf("\n\n");
}
}
printf("Total Page Faults = %d\n\n", faultCount);
}
int findLRU(int time[], int fCount) {
int k, min, pos;
pos = 0;
min = time[0];
for (k = 1; k < fCount; ++k) {
if (time[k] < min) {
min = time[k];
pos = k;
}
}
return pos;
}
//LFU
void LFUmain()
{
int total_frames, total_pages, hit = 0;
int pages[25], frame[10], arr[25], time[25];
int m, n, page, flag, k, minimum_time, temp;
printf("Enter Total Number of Pages:\t");
scanf("%d", &total_pages); 
printf("Enter Total Number of Frames:\t");
scanf("%d", &total_frames);
for(m = 0; m < total_frames; m++)
{
 frame[m] = -1;
}
for(m = 0; m < 25; m++)
{
 arr[m] = 0;
}
printf("Enter Values of Reference String\n");
for(m = 0; m < total_pages; m++)
{
 printf("Enter Value No.[%d]:\t", m + 1);
 scanf("%d", &pages[m]);
}
printf("\n");
for(m = 0; m < total_pages; m++)
{
arr[pages[m]]++;
time[pages[m]] = m;
flag = 1;
k = frame[0];
for(n = 0; n < total_frames; n++)
{
if(frame[n] == -1 || frame[n] == pages[m])
{
if(frame[n] != -1)
{
hit++;
}
flag = 0;
frame[n] = pages[m];
break;
}
if(arr[k] > arr[frame[n]])
{
k = frame[n];
}
}
if(flag)
{
minimum_time = 25;
for(n = 0; n < total_frames; n++)
{
if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
{
temp = n;
minimum_time = time[frame[n]];
}
}
arr[frame[temp]] = 0;
frame[temp] = pages[m];
}
for(n = 0; n < total_frames; n++)
{
printf("%d\t", frame[n]);
}
printf("\n");
}
printf("Page Hit:\t%d\n", hit);
}
void main(){
int ch;
do
{
printf("\n Page Replacement Simulation\n");
printf("-------------------------------");
printf("\n1.FIFO\n2.LRU\n3.LFU\n4.Exit\n");
printf("\nEnter choice : ");
scanf("%d",&ch);

switch(ch)
{
case 1:fifomain();break;
case 2:LRUmain();break;
case 3:LFUmain();break;
case 4:printf("\nExit.... \n");break;
default:printf("\nInvalid entry");
}
}while(ch!=4);

}