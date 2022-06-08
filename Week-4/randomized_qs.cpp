#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int partition(int[],int,int,int&,int&);
int random_p(int[],int,int,int&,int&);
void quicksort(int a[],int l,int r,int&c,int&s)
{
    if(l<r){
    int p = random_p(a,l,r,c,s);
    quicksort(a,l,p-1,c,s);
    quicksort(a,p+1,r,c,s);
    }
}
int random_p(int a[],int l,int r,int &c,int&s)
{
    srand(time(NULL));
    int random = l + rand() % (r - l);
 
    // Swap A[random] with A[high]
    swap(a[random], a[r]);
    ++s;
 
    return partition(a,l,r,c,s);
}
int partition(int a[],int l,int r,int&c,int&s)
{
    int pivot = a[r];
    int i = l-1;
    for(int j=l;j<=r-1;j++)
    {
        ++c;
        if(a[j] <= pivot){
            ++i;
        swap(a[i],a[j]);
        if(i!=j)
        ++s;
        }
    }
    swap(a[i+1],a[r]);
    ++s;
     return(i+1);
}
void print (int a[],int n,int&c ,int&s)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<c<<endl;
    cout<<"Swaps: "<<s<<endl;
}
int main()
{
    int n,a[100],t,c=0,s=0;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,0,n-1,c,s);
    print(a,n,c,s);
    }
    return 0;
}
