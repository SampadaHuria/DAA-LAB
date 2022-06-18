#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}

int findParent(vector<int> &parent,int node)
{
    if(parent[node]==node)
    return node;

    return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u=findParent(parent,u);
    v=findParent(parent,v);

    if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else if(rank[v]>rank[u])
    {
        parent[u]=v;
    }
    else
    {
    parent[v]=u;
    rank[u]++;
    }
}

int minspanning(vector<vector<int>> &graph,int n)
{
    sort(graph.begin(),graph.end(),cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    } 
    int minweight=0;
    for(auto i : graph)
    {
        int u=findParent(parent,i[0]);
        int v=findParent(parent,i[1]);
        int w=i[2];

        if(u!=v)
        {
            minweight += w;
            unionSet(u,v,parent,rank);
        }
    }
    return minweight;
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                graph.push_back({i+1,j+1,arr[i][j]});
            }
        }
    }
    int result=minspanning(graph,n);
    cout<<"Minimum spanning weight : "<<result;
    return 0;
}
