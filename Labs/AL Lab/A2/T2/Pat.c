#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int a[1000000],c[1000000];

int binary_search(int n,int key){
    int m;
    int l=-1,r=n-1;
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        if(c[m]>=key)
            r=m;
        else
            l=m;
    }
 
    return r;
}

int main() {
    int n,i,j;
    int max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int size=1;
    c[0]=a[0];
    for(i=1;i<n;i++){
        if(a[i]<c[0]){
            c[0]=a[i];
        }
        else if(a[i]>c[size-1]){
            c[size]=a[i];
            size++;
        }
        else{
            c[binary_search(size,a[i])]=a[i];
        }
    }
    printf("The Length is:  %d",size);
    printf("\n");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
