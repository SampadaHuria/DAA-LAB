#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;

int partition(int *a, int low, int high,int *comp, int *swaps)
{
    int i= low-1, j= low;
    int pivot = a[high];

    while(j<high)
    {   
        (*comp)++;
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
            (*swaps)++;

          
        }
        j++;

         
    }
    swap(a[i+1],a[high]);
    (*swaps)++;
  
    return i+1;
}
void quickselect(int *a, int low, int high,int *comp, int *swap,int k)
{   
    
    if(k>0)
    {   
       
        int p = partition(a,low,high,comp,swap);
        
        if(p==k-1)
        {
            cout<<a[p];
            return;
        }
        else if(p>k-1)
        quickselect(a,low,p-1,comp,swap,k);
        else
        {
    
            quickselect(a,p+1,high,comp,swap,k);
}
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {   
        int n;
        cin>>n;
        int *a =  new int [n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int comp=0,swap=0;
        int k;
        cin>>k;
       
        quickselect(a,0,n-1,&comp,&swap,k);

        
      
        cout<<endl;
        

    }
}
