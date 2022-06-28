#include<bits/stdc++.h>
using namespace std;
#define v 5
#define inf INT_MAX
void floyd_warshall(int graph[v][v])
{
    int dist[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<v;k++)
       for(int i=0;i<v;i++)
       for(int j=0;j<v;j++)
       {
        if(dist[i][k]==inf || dist[k][j]==inf)
        continue;
        else if(dist[i][k] + dist[k][j] < dist[i][j])
        dist[i][j] = dist[i][k] + dist[k][j];
        }
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    cout<<dist[i][j]<<" ";
    cout<<endl;
  }
}
int main()
{
    int graph[v][v] = {{0,10,5,5,inf},
                       {inf,0,5,5,5},
                       {inf,inf,0,inf,10},
                       {inf,inf,inf,0,20},
                       {inf,inf,inf,5,0}};
    floyd_warshall(graph);
    return 0;
}
