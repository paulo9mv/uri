#include <stdio.h>
#include<string.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 1000
#define oo 1000000000


int n;  // number of nodes
int e;  // number of edges
int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
int flow[MAX_NODES][MAX_NODES];     // flow matrix
int color[MAX_NODES]; // needed for breadth-first search
int pred[MAX_NODES];  // array to store augmenting path

int min (int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}
int indice(char camisa[]){
    if(strcmp(camisa, "XS") == 0)
        return 1;
        if(strcmp(camisa, "S") == 0)
            return 2;
            if(strcmp(camisa, "M") == 0)
                return 3;
                if(strcmp(camisa, "L") == 0)
                    return 4;
                    if(strcmp(camisa, "XL") == 0)
                        return 5;
                        if(strcmp(camisa, "XXL") == 0)
                            return 6;
}

int head,tail;
int q[MAX_NODES+2];

void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}


int bfs (int start, int target) {
    int u,v;
    for (u=0; u<n; u++) {
	color[u] = WHITE;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
	u = dequeue();
        // Search all adjacent white nodes v. If the capacity
        // from u to v in the residual network is positive,
        // enqueue v.
	for (v=0; v<n; v++) {
	    if (color[v]==WHITE && capacity[u][v]-flow[u][v]>0) {
		enqueue(v);
		pred[v] = u;
	    }
	}
    }
    // If the color of the target node is black now,
    // it means that we reached it.
    return color[target]==BLACK;
}

int max_flow (int source, int sink) {
    int i,j,u;
    // Initialize empty flow.
    int max_flow = 0;
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    flow[i][j] = 0;
	}
    }
    // While there exists an augmenting path,
    // increment the flow along this path.
    while (bfs(source,sink)) {
        // Determine the amount by which we can increment the flow.
	int increment = oo;
	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    increment = min(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
	}
        // Now increment the flow.
	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    flow[pred[u]][u] += increment;
	    flow[u][pred[u]] -= increment;
	}
	max_flow += increment;
    }
    // No augmenting path anymore. We are done.
    return max_flow;
}


int read_input_file() {
    int a,b,c,i,j;
    char camisa1[5], camisa2[5];
    // read number of nodes and edges
    //scanf("%d %d",&n,&e);
    int camisetas, e;
    scanf("%d %d", &camisetas, &e);
    n = 8 + e;
    // initialize empty capacity matrix
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    capacity[i][j] = 0;
	}
    }
    for(i = 1; i < 7; i++){
        capacity[0][i] = camisetas/6;
    }
    for(i = 7 ; i < n-1;i++){
        capacity[i][n-1] = 1;
    }
    // read edge capacities
    for (i=7; i<(n-1); i++) {
        scanf("%s %s", camisa1, camisa2);
	     //scanf("%d %d",&a,&b,&c);
	      capacity[indice(camisa1)][i] = 1;
        capacity[indice(camisa2)][i] = 1;
    }

        return e;
}

int main () {
    int casos, flow;
    scanf("%d",&casos);
    while(casos > 0){
      int a = read_input_file();
      flow = max_flow(0, n-1);
      if(flow < a){

        printf("NO\n");
    }
    else
    printf("YES\n");
    
    casos--;
  }
    return 0;
}