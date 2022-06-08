#include<iostream>
using namespace std;
int binary_search(int a[],int i,int j ,int key)
{
    while(i<=j) {
    int mid = (i+j)/2;
    if(a[mid]==key)
      return mid+1;
    if(a[mid]>key)
       return binary_search(a,i,mid-1,key);
      else
      return binary_search(a,mid+1,j,key);
    }
    return -1;
}
int main()
{
  int i,n,key,v,a[100];
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cin>>key;
  v = binary_search(a,0,n,key);
  if(v==-1)
  cout<<"Not Present "<<n<<endl;
  else cout<<"Present "<<v<<endl;
}
