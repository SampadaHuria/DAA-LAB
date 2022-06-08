#include<iostream>
using namespace std;
void insertion_sort(int a[],int n,int &cmp,int &shifts)
{
    int i,j,temp;
    for(int i=0;i<n;i++)
    {
        temp = a[i];
        j=i-1;
        ++cmp;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
            ++shifts;
        }
        a[j+1] = temp;
        
      
    }
}
void print (int a[],int n,int&c,int&shifts)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<c<<endl;
    cout<<"Shifts "<<shifts<<endl;
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
    int n,a[100],cmp=0,shifts=0;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    insertion_sort(a,n,cmp,shifts);
    print(a,n,cmp,shifts);
    }
    return 0;
}
