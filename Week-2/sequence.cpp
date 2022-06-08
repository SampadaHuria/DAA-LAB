#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
{
    int n;
    cin>>n;
    int a[20],flag=0;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-2;i++)
    {
        if(flag==1)
        break;
        for(int j=1;j<n-1;j++)
        {
            for(int k=2;k<n;k++)
            {
                if(a[i]+a[j]==a[k]){
                    cout<<i+1<<","<<j+1<<","<<k+1<<endl;
                    flag=1;
                    break;
                }
            }
        } 
    }
    if(flag==0)
    cout<<"No sequence found.";
}
}
