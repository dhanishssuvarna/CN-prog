#include<stdio.h>
#include<stdlib.h>

struct node{
	int dist[20];
	int from[20];
}rt[10];

void main(){
	int i, j, k, n, dmat[20][20];

	printf("Enter the no. of Nodes : ");
	scanf("%d",&n);

	printf("Enter the Cost Matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d", &dmat[i][j]);
			dmat[i][i]=0;
			rt[i].dist[j]=dmat[i][j];
			rt[i].from[j]=i;
		}

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(rt[i].dist[j]>rt[i].dist[k]+rt[k].dist[j]){
						rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j] = k;
					}

		for(i=1;i<=n;i++){
			printf("Distace table for Router %c is \n",i+64);
			for(j=1;j<=n;j++)
				printf("\tNode %c to Node %c via %c, Distance : %d\n",i+64, j+64,rt[i].from[j] +64,rt[i].dist[j]);
		}
}