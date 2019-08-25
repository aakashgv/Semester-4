#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include"selectionSort.h"
#include"insert.h"
#include"bubble.h"
#include"mergeSort.h"
#include"quickSort.h"

void main(){

long time_start, time_end;
struct timeval tv;


// calculating end time in seconds //convert time in readable and printable precision
// (time_end-time_start)


FILE *fptr, *zptr;
int i, n, a[15000];

fptr= fopen("a1.txt","w");
srand(time(0));
for( i = 0; i<9999; i++){
        fprintf(fptr, "%d ", rand() % (9999 + 1 - 0) + 0);}
fclose(fptr);

zptr= fopen("a1.txt", "r");
for(i=0; i<9999; i++){
fscanf(zptr, "%d", &a[i]);
}
fclose(zptr);

n=9999;

printf("\n Array Entered= ");
for(i=0; i<n; i++)
printf("%d ", a[i]);

//timeINSERTION
gettimeofday(&tv,NULL);
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

insert(a, n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
//time

long time= time_end-time_start;
printf("\n TIME FOR INSERTION SORT WAS= %lu", time);

//timeBUBBLE
zptr= fopen("a1.txt", "r");
for(i=0; i<99; i++){
fscanf(zptr, "%d", &a[i]);
}
fclose(zptr);

gettimeofday(&tv,NULL);
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

bubble(a, n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
//time

time= time_end-time_start;
printf("\n TIME FOR BUBBLE SORT WAS= %lu", time);

//timeMERGE
zptr= fopen("a1.txt", "r");
for(i=0; i<99; i++){
fscanf(zptr, "%d", &a[i]);
}
fclose(zptr);

gettimeofday(&tv,NULL);
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

mergeSort(a, 0, n-1);


gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
//time
time= time_end-time_start;
printf("\n TIME FOR MERGE SORT WAS= %lu", time);

//timeQUICK
zptr= fopen("a1.txt", "r");
for(i=0; i<99; i++){
fscanf(zptr, "%d", &a[i]);
}
fclose(zptr);
gettimeofday(&tv,NULL);
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

quickSort(a,0,n-1);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
//time
time= time_end-time_start;
printf("\n TIME FOR QUICK SORT WAS= %lu", time);

//timeSELECTION
zptr= fopen("a1.txt", "r");
for(i=0; i<99; i++){
fscanf(zptr, "%d", &a[i]);
}
fclose(zptr);
gettimeofday(&tv,NULL);
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

selectionSort(a,n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
//time
time= time_end-time_start;
printf("\n TIME FOR SELECTION SORT WAS= %lu", time);


}
