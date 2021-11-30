#include <stdio.h>
#define I 9999
#define MAX 10

int n, graph[MAX][MAX], pred[MAX], status[MAX], len[MAX];

struct edge
{
        int u;
        int v;
};

void create_graph()
{
       int i,j;
       printf("\nEnter the number of vertices:");
       scanf("%d",&n);
       printf("\nEnter the matrix:\n");
       for(i=0;i<n;i++) 
       {
               for(j=0;j<n;j++)
                   scanf("%d",&graph[i][j]);
       }
       
}

void maketree(int r, struct edge tree[MAX])
{
        int current, i;
        int count = 0;

        for (i = 0; i < n; i++)
        {
                pred[i] = -1;
                len[i] = I;
                status[i] = 0;
        }

        len[r] = 0;

        while (1)
        {
                current = min_temp();

                if (current == -1)
                {
                        if (count == n - 1)
                                return;
                        else
                        {
                                printf("\nGraph is not connected, No spanning tree possible\n\n");
                                exit(1);
                        }
                }

                status[current] = 1;
                if (current != r)
                {
                        count++;
                        tree[count].u = pred[current];
                        tree[count].v = current;
                }

                for (i = 0; i < n; i++)
                {
                        if (graph[current][i] > 0 && status[i] == 0)
                                if (graph[current][i] < len[i])
                                {
                                        pred[i] = current;
                                        len[i] = graph[current][i];
                                }

                }        
        }
}
int min_temp()
{
        int i;
        int min = I;
        int k = -1;

        for (i = 0; i < n; i++)
        {
                if (status[i] == 0 && len[i] < min)
                {
                        min = len[i];
                        k = i;
                }
        }

        return k;
}
int main()
{
        int wt_tree = 0, i;
        struct edge tree[MAX];
        
        create_graph();

        maketree(0, tree);

        printf("\n Edges to be included in spanning tree are:\n");
        for (i = 1; i <= n - 1; i++)
        
        {       
                printf("%d--->",tree[i].u);
                printf("%d\n",tree[i].v);
                wt_tree += graph[tree[i].u][tree[i].v];
        }
        printf("\nWeight of spanning tree is : %d\n\n", wt_tree);
        return 0;
}