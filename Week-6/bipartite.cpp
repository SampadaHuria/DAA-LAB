#include<bits/stdc++.h>
using namespace std;
bool bipartite(vector<vector<int> > graph,int colArray[])
{
  queue<int> queue;
  queue.push(graph[0][0]);
  colArray[0] = 0;
  while(!queue.empty())
  {
      int u = queue.front();
      queue.pop();
      if(graph[u][u]==1)
      return false;
      for(int v = 0;v<graph[0].size(); v++)
      {
          if(graph[u][v]==1 && colArray[v]==-1){
              colArray[v] = 1 - colArray[u];
              queue.push(v);
          }
        if(graph[u][v]==1 && colArray[v]==colArray[u])
        return false;
      }
  }
  return true;
}
int main()
{
    int v;
    cin>>v;
    vector<vector<int> > graph(v);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            int t;
            cin>>t;
            graph[i].push_back(t);
        }
    }
    int colArray[v];
    for(int i = 0; i < v; i++) colArray[i] = -1;
    bipartite(graph,colArray) ? cout<<"Yes, Bipartite" : cout<<"Not bipartite";

}
