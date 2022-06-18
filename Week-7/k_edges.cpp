#include<bits/stdc++.h>
using namespace std;

#define N 4

int shortest_path(int graph[][N],int u,int v,int k)
{
    if(k==0 && u==v)
    return 0;
    if(k==1 && graph[u][v]!=0)
    return graph[u][v];
    if(k<0)
    return INT_MAX;
    int res=INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(graph[u][i]!=INT_MAX && u!=i && v!=i)
        {
            int rec_res=shortest_path(graph,i,v,k-1);
            if(rec_res!=INT_MAX)
            res=min(res,graph[u][i]+rec_res);
        }
    }
    return res;
}


int main()
{
    int n;
    cin>>n;
    int graph[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            graph[i][j]=num;
        }
    }
    int u,v,k;
    cin>>u>>v>>k;
    int result=shortest_path(graph,u-1,v-1,k);
    cout<<"weight of shortest path from ("<<u<<","<<v<<") with "<<k<<" edges : "<<result<<endl;
    return 0;
}
