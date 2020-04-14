#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int p,q,l,r,i,ar[1001][2],count=0,h[10001]={0};
    
    cin>>p>>q>>l>>r;
    
    for(i=0;i<p;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
    }
    
    
    while(q--)
    {
        int a,b,j;
        
        cin>>a>>b;
        for(j=0;j<p;j++)
        {
             for(i=l;i<=r;i++)
            {
                if(ar[j][0]<=(b+i) && ar[j][1]>=(a+i))
                {
                    h[i]++;
                }
            }
        }
       
    }
    
    for(i=l;i<=r;i++)
    {
        if(h[i]>0)
        {
            count++;
        }
        
    }
    cout<<count<<endl;
    
    return 0;
}
