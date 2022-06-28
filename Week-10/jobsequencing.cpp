#include<bits/stdc++.h>
using namespace std;
struct jobs
{
    int time,deadline,index;
};
void job_sequencing(jobs job[],int n)
{
    bool slot[n+1];
    int result[n+1];
    int count=0;
    for(int i=0;i<n;i++)
    slot[i] = false;
    for(int i=0;i<n;i++)
    {
        int x = job[i].time;
        if(slot[job[i].deadline - 1]==false)
        {
            int y = job[i].deadline-1;
            while(x != 0)
            {
                result[y] = i;
                slot[y] = true;;
                y--;
                x--;
            }
            if(x==0)
            count++;
        }
    }
    cout<<"Number of activities selected: "<<count<<endl;
    for(int i=0;i<=n;i++)
    {
        if(i==n) {
        cout<<job[result[i]].index+1<<" ";
        break; }
        if(result[i] == result[i+1])
        continue;
        cout<<job[result[i]].index+1<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    jobs job[n];
    for(int i=0;i<n;i++)
    job[i].index = i;
    for(int i=0;i<n;i++)
    cin>>job[i].time;
    for(int i=0;i<n;i++)
    cin >> job[i].deadline;
    job_sequencing(job,n);
    return 0;
}
