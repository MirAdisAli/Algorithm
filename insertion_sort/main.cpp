#include <iostream>

using namespace std;
int main() {
   int t;
   cin>>t; 
   while(t--)
   {
       int n;
       cin>>n;
       int a[n+1];
       for(int i=0;i<n;i++)
       {
           cin>>a[i]; 
       }

       for(int i=1;i<n;i++)
       {
           int k=a[i];
           int j=i-1;
           while((k<a[j])&&(j>=0))
           {
           a[j+1]=a[j];
           j--;
           }
           a[j+1]=k;

       }
       for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
       cout<<endl;
   }
}
