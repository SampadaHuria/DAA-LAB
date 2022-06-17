#include<bits/stdc++.h>
using namespace std;
#define V 6
int min_vertex(vector<int> value, vector<bool> processed)
{
    int min = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
      if(processed[i]==false && value[i]<min)
      {
        min = value[i];
        vertex = i;
      }
    }
    return vertex;
}
void dijkstra(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> processed(V,false);
    parent[0] = -1;
    value[0] = 0;
    for(int i=0;i<V-1;i++)
    {
        int u = min_vertex(value,processed);
        processed[u] = true;
        for(int j=0;j<V;j++)
        {
            if(graph[u][j]!=0 && processed[j]==false && (value[j]>graph[u][j] + value[u]) 
                           && value[u]!=INT_MAX){
                    value[j] = graph[u][j] + value[u];
                    parent[j] = u;
                           }
        }
    }
    for(int i=0;i<V-1;i++)
    {
        cout<<i<<" ";
        int j = parent[i];
      while(j!=-1)
      {
        cout<<j<<" ";
        j = parent[j];
      }
      cout<<" = "<<value[i]<<endl;
    }
}
int main()
{
    int graph[V][V] ={{0,4,1,0,0},
                      {0,0,0,0,4},
                      {0,2,0,4,0},
                      {0,0,0,0,0}};
    dijkstra(graph);
    return 0;
}
