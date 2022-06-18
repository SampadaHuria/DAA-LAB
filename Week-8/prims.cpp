#include<bits/stdc++.h>
using namespace std;
#define V 7
int min_vertex(vector<int> &value, vector<bool> &setMst)
{
    int min = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(setMst[i]==false && value[i]<min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}
int findMst(int g[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> setMst(V,false);
    parent[0] =-1;
    value[0] = 0;
    for(int i=0;i<V-1;i++)
    {
        int u = min_vertex(value,setMst);
        setMst[u] = true;
        for(int j=0;j<V;j++)
        {
           if(g[u][j]!=0 && setMst[j]==false && g[u][j] < value[j])
           {
               value[j] = g[u][j];
               parent[j] = u;
           }
        }
    }
    int sum = 0;
    for(int i=1;i<V;i++)
    {
        sum = sum + g[parent[i]][i];
    }
    return sum;
}
int main()
{
    int graph[V][V] = {{0, 0, 7, 5, 0,0 ,0},
                       {0, 0, 8, 5, 0,0 ,0},
                       {7, 8, 0, 9, 7,0, 0},
                       {5, 0, 9, 0, 15, 6, 0},
                       {0, 5, 7, 15,0, 8, 9},
                       {0, 0, 0, 6, 8,0 ,11},
                       {0, 0, 0, 0, 9,11 ,0}};
 int total;
 total = findMst(graph);
 cout<<"Minimum spanning tree: "<<total<<endl;
}
