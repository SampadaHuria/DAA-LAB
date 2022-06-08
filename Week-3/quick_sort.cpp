#include<iostream>
using namespace std;
void duplicates(int a[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        flag=1;
    }
    if(flag==1)
    cout<<"YES\n";
    else cout<<"NO\n";
}
int partition(int[],int,int);
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int partition(int a[],int l,int r)
{
    int pivot = a[r];
    int i= l-1;
    for(int j=l;j<=r-1 ; j++)
    {
        if(a[j]<pivot)
        {
            i++;
           swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return (i+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
    int n,a[100],l=0,r=n-1;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,0,n-1);
    duplicates(a,n);
    }
    return 0;
}
