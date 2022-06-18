#include<bits/stdc++.h>
using namespace std;
struct edges{
    int src,dest,wt;
};
int v,e;
void bellmanford(vector<edges> &edge)
{
    int parent[v];
    int cost_parent[v];
    vector<int> value(v,INT_MAX);
    parent[0] = -1;
    value[0] = 0;
    bool updated;
    for(int i=0;i<v-1;i++)
    {
        updated= false;
        for(int j=0;j<e;j++)
        {
          int u = edge[j].src;
          int v1 = edge[j].dest;
          int w = edge[j].wt;
          if(value[u]!=INT_MAX && value[u]+w < value[v1])
          {
            value[v1] = value[u] + w;
            parent[v1] = u;
            cost_parent[v1] = value[v1]; 
            updated = true;
          }
        }
        if(updated==false)
        break;
    }
    for(int j=0; j<e && updated==true;j++)
    {
        int u = edge[j].src;
          int v1 = edge[j].dest;
          int w = edge[j].wt;
          if(value[u]!=INT_MAX && value[u]+w < value[v1])
          { 
            cout<<"Graph has -ve edge cycle ";
            return; }
    } 
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<" "<<i<<" = "<<value[i]<<endl;
    }
}
int main()
{
    
    cin>>v>>e;
    vector<edges> edge(e);
    int src,dest,wt;
    for(int i=0;i<e;i++)
    {
        cin>>src>>dest>>wt;
        edge[i].src = src;
        edge[i].dest = dest;
        edge[i].wt = wt;
    }
    bellmanford(edge);
    return 0;
}
