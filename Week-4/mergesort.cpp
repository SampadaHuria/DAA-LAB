#include<iostream>
using namespace std;
int inversion(int a[],int n)
{
  int c=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(a[i] > a[j])
      ++c;
    }
  }
  return c;
}
void merge(int[],int,int,int,int&);
void mergesort(int a[],int l,int r,int&cmp)
{
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a,l,mid,cmp);
        mergesort(a,mid+1,r,cmp);
        merge(a,l,mid,r,cmp);
    }
}
void merge(int a[],int l,int mid,int r,int &cmp)
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
      ++cmp;
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
void print (int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,t,a[100],c;
    cin>>t;
    while(t--){
    int cmp=0;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    c = inversion(a,n);
    mergesort(a,0,n-1,cmp);
    print(a,n);
    cout<<"Comparisons: "<<cmp<<endl;
    cout<<"Inversions: "<<c<<endl;
    }
    return 0;
}
