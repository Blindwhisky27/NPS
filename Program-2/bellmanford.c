#include <stdio.h>
#include <stdlib.h>
struct node
{
    int dist[20];
    int from[20];
} rt[20];
int main()
{
    int v, cost[25][25];
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the cost matrix: \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &cost[i][j]);
            cost[i][i] = 0;
            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }
    }

    int count;
    do
    {
        count = 0;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                for (int k = 0; k < v; k++)
                {
                    if (rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (rt[i].dist[j] < 0)
            {
                printf("Negative cycles");
                exit(0);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        printf("\n\n For router %d\n", i + 1);
        for (int j = 0; j < v; j++)
        {
            printf("\t\nnode %d via %d Distance %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
}