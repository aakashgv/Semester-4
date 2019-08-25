#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print(int src,int d,int n,int s[n][n]){
	if(src == d) {return;}
	else if(s[src][d] == -200) {printf("%d %d\n",src,d);return;}
	print(src,s[src][d],n,s);
	print(s[src][d],d,n,s);
}

int main(){
	int n,e,x,y,src,d;
	scanf("%d%d",&n,&e);
	float p[n][n],val,maxi = -100000;
	//int p[n][n];
	int i,j,k,s[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			p[i][j] = -100;
			s[i][j] = -1;
			//p[i][j] = 100.0;
		}
	}
	for(i=0;i<e;i++){
		//scanf("%d%d%d",&x,&y,&val);
		scanf("%d%d%f",&x,&y,&val);
		p[x][y] = val;
		p[i][i] = 0.00;
		s[x][y] = -200;
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(p[i][k] >= 0 && p[k][j] >= 0 && p[i][k] <= 1 && p[k][j] <= 1 && p[i][k]*p[k][j] > p[i][j]/*p[i][k] + p[k][j] < p[i][j]*/) {p[i][j] = p[i][k] * p[k][j];s[i][j] = k;}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%12.6f ",p[i][j]);
			//if(p[i][j] > maxi) maxi = p[i][j];
		}
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i != j) printf("%6d ",s[i][j]);
			else printf("%6d",i);
		}
		printf("\n");
	}
	printf("\nEnter s and d\n");
	scanf("%d%d",&src,&d);
	printf("\n%f is the maximum prob. of path from s to d\n",/*maxi*/p[src][d]);
	print(src,d,n,s);
	return 0;
}
	
			
