#include<bits/stdc++.h>
using namespace std;
int t,n,l[200005],r[200005],a[200005];
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cin>>t;
  while(t--){
    cin>>n;
    long long sum=0,sr=0,s=0;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i],sum+=r[i]-l[i],a[i]=l[i]+r[i],sr+=r[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)s+=a[i];
    if(~n&1)cout<<sum+sr-s<<'\n';
    else{
      long long ans=0;
      for(int i=1;i<=n;i++)ans=max(ans,sr-r[i]-(r[i]+l[i]<=a[n/2]?s-(r[i]+l[i])+a[n/2+1]:s));
      cout<<sum+ans<<'\n';
    }
  }
  return 0;
}