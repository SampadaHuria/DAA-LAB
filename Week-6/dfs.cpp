#include<bits/stdc++.h>
using namespace std;
bool Ispathexists(vector<vector<int> > graph,vector<int>visited,int s,int d)
{
 visited[s]=true;
 for(int i=s; i<graph[s].size();i++)
 {
     if(visited[d]) return true; 
     else if(graph[s][i]==1 &&  visited[i]==false)
     {
         return Ispathexists(graph,visited,i,d);
     }
 }
 return false;
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
    vector<int> visited(v);
    visited.resize(v,false);
    int s,d;
    cin >> s>> d;
    s--;
    d--;
    if(Ispathexists(graph,visited,s,d))
    {
        cout<<"Yes path exists\n";
    }
    else cout<<"Path doesn't exists\n";
}
