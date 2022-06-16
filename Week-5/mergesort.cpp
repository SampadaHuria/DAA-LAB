#include<iostream>
using namespace std;
void merge(int*,int,int,int);
void find_pair(int *a,int n,int key)
{
    int flag=0;
    for(int i=0,j=n-1;i<j;)
    {
       if(a[j]==key-a[i])
       {
           cout<<a[i]<<" "<<a[j]<<endl;
           flag=1;
           break;
       }
       else{
           if(a[j] > key-a[i])
           j--;
           else i++;
       }
    }
    if(flag==0)
    cout<<"No such element exist\n";
}
void mergesort(int* a,int l,int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void merge(int*a,int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    L[i] = a[l+i];
    for(int j=0;j<n2;j++)
    R[j] = a[mid+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] < R[j])
        {
            a[k++] = L[i++];
        }
        else{
            a[k++] = R[j++];
        }
    }
    while(i<n1)
    a[k++] = L[i++];
    while(j<n2)
    a[k++] = R[j++];
}
int main()
{
    int t,n,key;
    cin>>t;
    while(t--){
    cin>>n;
    int* a = new int [n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>key;
    mergesort(a,0,n-1);
    find_pair(a,n,key);
    }
    
    return 0;
}
