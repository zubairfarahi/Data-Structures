#ifndef __SOLVE_H__
#define __SOLVE_H__
#include <stdlib.h>

typedef struct {
  int nn; // Number of nodes
  int **Ma; // Adjacent matrix
} TGraphM;

typedef struct node {
  int v; // Destination node index
  int c; // Cost associated with the arc
  struct node *next;
} TNode, *ATNode;

typedef struct {
  int nn; // Number of nodes
  ATNode *adl; // Vector pointers assigned dynamically to the neighbors
} TGraphL;


int find_min(int arr[],int n)
{
    int i,min,idx;
    min = arr[0];
    idx = 0;
    for(i=0;i<n;i++){

    if(arr[i]<min){
            min = arr[i];
            idx = i;
    	}
    }
    return idx;
}


int solve(char *testInputFileName) {

	
    freopen(testInputFileName,"r",stdin);
    int i,j,sum,idx,k,l,*aux,**temp,m;
    TGraphM graph;
    scanf("%d",&graph.nn);
    graph.Ma = (int **)malloc(graph.nn * sizeof(int *));
    for (i=0; i<graph.nn; i++)
         graph.Ma[i] = (int *)malloc(graph.nn * sizeof(int));

    for (i=0;i<graph.nn;i++)
    {
        for(j=0;j<graph.nn;j++)
            scanf("%d",&(graph.Ma[i][j]));
    }

    sum = 0;
    for(i=0;i<graph.nn;i++)
    {

        aux = (int*)malloc((graph.nn) * sizeof(int));
        for(l=0;l<graph.nn-i;l++)aux[l] = 0;
        k = 0;
        for(j = 0;j<graph.nn;j++)
        {
            temp = (int **)malloc((graph.nn) * sizeof(int *));
            for (m=0; m<graph.nn; m++)
                temp[m] = (int *)malloc(graph.nn * sizeof(int));
            for(l=0;l<graph.nn;l++)
                for(m=0;m<graph.nn;m++)temp[l][m] = graph.Ma[l][m];


            aux[k] = temp[i][j];
            for(l=i+1;l<graph.nn;l++)temp[l][j]=100000;
            for(l = i+1;l<graph.nn;l++)
                {
                    idx = find_min(temp[l],graph.nn);
                    for(m = l+1;m<graph.nn;m++)temp[m][idx] = 100000;
                    aux[k] += temp[l][idx];
                }
            k++;
        }

        idx = find_min(aux,graph.nn);
        sum += graph.Ma[i][idx];
        for(l=i+1;l<graph.nn;l++)graph.Ma[l][idx] = 10000;
        free(aux);
    }
   return sum;
 
}

#endif
