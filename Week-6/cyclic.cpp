#include<bits/stdc++.h>
using namespace std;

bool iscycle(int src,vector<vector<int>> &graph,vector<bool> &visited,vector<int> &stack)
{
    stack[src]=true;
        visited[src]=true;
        for(auto i : graph[src])
        {
            if(!visited[i] && iscycle(i,graph,visited,stack))
            {
                return true;
            }
            if(stack[i])
            {
                return true;
            }
        }
    stack[src]=false;
    return false;
}


int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    vector<vector<int>> graph;
    graph.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                graph[i+1].push_back(j+1);
            }
        }
    }
    vector<int> stack;
    stack.resize(n);
    vector<bool> visited;
    visited.resize(n);
    bool result=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && iscycle(i,graph,visited,stack))
        {
            result=true;
        }
    }
    if(result)
    cout<<"Yes Cycle Exists";
    else
    cout<<"No Cycle Exists";
    return 0;
}
