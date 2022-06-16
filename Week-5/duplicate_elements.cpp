#include<bits/stdc++.h>
using namespace std;

void intersection(int a[],int m,int b[],int n)
{
    int i=0,j=0;
    int flag=0;
    while(i<m && j<n)
    {
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            flag=1;
            i++;
            j++;
        }
        else if(a[i]>b[j])
        j++;
        else
        i++;
    }
    if(flag==0)
    cout<<"No common element";
}

int main()
{
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)
    cin>>a[i];
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    intersection(a,m,b,n);
    return 0;
}
