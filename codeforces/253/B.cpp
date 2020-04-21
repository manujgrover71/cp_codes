#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll mod=1e9+7;
 
             
        
int main() {
			   fast
            //    #ifndef ONLINE_JUDGE
               freopen("input.txt","r",stdin);
               freopen("output.txt","w",stdout);
            //    #endif
                
               
                ll prefix[50002]={0};
                 ll n;
                cin>>n;
                for(ll i=0;i<n;i++)
                {
                    ll x;
                    cin>>x;
                    prefix[x]+=1;
                    // prefix[x+1]-=1;
                }
                ll ans=LLONG_MAX;
                for(ll i=2;i<50002;i++)
                {
                    prefix[i]=prefix[i]+prefix[i-1];
                   //cout<<prefix[i]<<" ";
                }
                for(ll i=1;i<50002;i++)
                {
                    if(2*i<=5000)
                    {
                        ans=min(ans,prefix[i-1]+n-prefix[2*i]);
 
                    }
                    else
                    ans=min(ans,prefix[i]);
                }
                cout<<ans<<endl;
 
 
                return 0;
}