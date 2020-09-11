#include <iostream>
#include <string>
using namespace std;
int lapa(string);
string sorti(string,int,int);
int main()
{
    string str;
    cout<<"Enter string";
    cin>>str;
    if(lapa(str))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

int lapa(string s)
{
    int n,mid,i=0,j;
    n=s.length();
    mid=n/2;
    s=sorti(s,0,mid);
    if(n%2==0)
    {
        s=sorti(s,mid,n);
        j=mid;
    }
    else
     {
         s=sorti(s,mid+1,n);
         j=mid+1;
     }

    while(j<n)
    {
        if(s[i]!=s[j])
            return 0;
        else
        {
            i++;
            j++;
        }
    }
    return(1);
}
string sorti(string st,int low,int high)
{
   int j,i;
   char key;
   for(i=low+1;i<high;i++)
   {
       key=st[i];
       j=i-1;
       while(j>=low && st[j]>key)
       {
           st[j+1]=st[j];
           j=j-1;
       }
       st[j+1]=key;
   }
   return(st);
  // cout<<st<<endl;
}
