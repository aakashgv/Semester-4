#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>



void main()
{
long time_start, time_end;
struct timeval tv;

int n=7;
int arr[] = {64, 34, 25, 12, 22, 11, 90};

int t=1,i,j,temp;

if (t=1){goto bubble;}
if (t=2){goto insertion;}
if (t=3){goto selection;}
if (t=4){goto merge;}

bubble:
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+4) + tv.tv_usec;
for(i=0; i<n-1; i++){
 for(j=0; j<n-1; j++){
	if(arr[j]>arr[j+1]){
		temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;
		}
			}}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+4) + tv.tv_usec;
long time_tot=time_end-time_start;
printf("%ld \n",time_tot);
printf("Bubble \n");
for (i=0;i<n;i++){

printf("%d \n",arr[i]);}
t=2;

if (t=2){goto insertion;}
int key;


insertion:
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+4) + tv.tv_usec;
for(i=1; i<n; i++){
  key=arr[i];
  j=i-1;
  while(j>=0 && arr[j]>key)
   {arr[j+1]=arr[j];
   j=j-1;
   }
  arr[j+1]=key;
 }
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+4) + tv.tv_usec;
time_tot=time_end-time_start;
printf("%ld \n",time_tot);
printf("Insertion \n");
for (i=0;i<n;i++){

printf("%d \n",arr[i]);}


t=3;
int min_idx; 
selection:
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+4) + tv.tv_usec;
	for (i = 0; i < n-1; i++) 
	{ 	min_idx = i; 
		for (j = i+1; j < n; j++){ 
		if (arr[j] < arr[min_idx]){ 
			min_idx = j;}} 
		temp=arr[min_idx];
		arr[min_idx]=arr[i];
		arr[i]=temp; 
	} 
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+4) + tv.tv_usec;
time_tot=(time_end-time_start);
printf("%ld \n",time_tot);
printf("Selection \n");
for (i=0;i<n;i++){

printf("%d \n",arr[i]);}

t=4;
merge:
int mid,i1,i2,y,x,k;
void sort(int arr[],int i1,int x,int i2,int y)
{
 int temp[50]; 
 int i,j,k;
 i=i1; 
 j=i2;
 k=0;
 while(i<=x && j<=y)
 {
  if(arr[i]<arr[j])
    temp[k++]=arr[i++];
  else
    temp[k++]=arr[j++];
 }printf("Merge \n");
 while(i<=x)
  temp[k++]=arr[i++];        
 while(j<=y)
  temp[k++]=arr[j++];
 for(i=i1,j=0;i<=y;i++,j++)
   arr[i]=temp[j];
} 
void divide(int arr[],int i,int j){
 int mid;
 if(i<j)
 {
  mid=(i+j)/2;
  divide(a,i,mid);
  divide(a,mid+1,j); divide(a,0,n-1);   
  sort(a,i,mid,mid+1,j); 
 }
}
 

divide(arr,0,n-1); 
printf("Merge \n");
for (i=0;i<n;i++){

printf("%d \n",arr[i]);}





}


