#include "bubble.h"

void swap(int *xp, int *yp){
int temp= *xp;
*xp = *yp;
*yp= temp;
}

void bubble(int arr[], int n){
int i, j;

for(i=0; i<n-1; i++){
 for(j=0; j<n-1; j++){
	if(arr[j]>arr[j+1])
	swap(&arr[j], &arr[j+1]);

	}

 }
}
