#include<iostream>
using namespace std;
void selection_sort(int a[],int n,int &cmp,int &swap)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min = i;
        ++cmp;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
              min = j; }
        }
        if(min != i){
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            ++swap;
        }
       
    }
}
void print (int a[],int n,int&c,int&s)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<c<<endl;
    cout<<"Swaps: "<<s<<endl;
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,a[100],cmp=0,swap=0;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    selection_sort(a,n,cmp,swap);
    print(a,n,cmp,swap);
    }
    return 0;
}
