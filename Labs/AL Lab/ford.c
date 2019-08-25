#include<stdio.h>
#define MAX 10
#define oo 1000000000

int cap[MAX][MAX]; //Capacity
int flow[MAX][MAX]; //Flow 
int clr[MAX];              
int par[MAX];  

int n,e;
int queue[MAX];

int head,tail;
int q[MAX+2];

void enq (int x) {
    q[tail] = x;
    tail++;
    clr[x] = 1;
}

int deq() {
    int x = q[head];
    head++;
    clr[x] = 2;
    return x;
}


//return min of x and y
int min (int x, int y) { 
    return x<y ? x : y;
}

int bfs (int s, int t) {
    int u,v;
    for (u=0; u<n; u++) {
		clr[u] = 0;
    }   
    head = tail = 0;
    enq(s);
    par[s] = -1;
    while (head!=tail) {
		u = deq(); //search for adjacent nodes. If capacity positive, enqueue	
		for (v=0; v<n; v++) {
	    	if (clr[v]==0 && cap[u][v]-flow[u][v]>0) {
			enq(v);
			par[v] = u;
	    	}
		}
    }
    return clr[t]==2;
}

int max_flow (int src, int sink) {
    int i,j,u;
    int max_flow = 0;
    for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
	    	flow[i][j] = 0;
		}
    } //if augmenting path, increase the flow
    while (bfs(src,sink)) {
	int incr = oo;
	for (u=n-1; par[u]>=0; u=par[u]) {
	    incr = min(incr,cap[par[u]][u]-flow[par[u]][u]);
	} //incr
	for (u=n-1; par[u]>=0; u=par[u]) {
	    flow[par[u]][u] += incr;
	    flow[u][par[u]] -= incr;
	} //tracing the path 
	max_flow += incr;
	printf("Aug path :- \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%6d ",flow[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    }
    return max_flow;
}

int main(){
	int i,j;
	printf("Enter the number of nodes and edges:  ");
	scanf("%d %d",&n,&e);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter edge capacities:  ");
			scanf("%d",&cap[i][j]);}
	}
	printf("\n");
	printf("%d is the max flow\n",max_flow(0,n-1));
	printf("Capacity remaining :- \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%6d ",cap[i][j]-flow[i][j]);
		}
		printf("\n");
	}	
	return 0;
}

