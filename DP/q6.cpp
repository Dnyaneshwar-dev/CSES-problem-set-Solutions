/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); } 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		ll dp[n][n];    // dp[i][j]=number of ways to reach ith row and jth column
		zero(dp);
		for(int i=0;i<n;i++){
			if(s[0][i]=='.'){
				dp[0][i]=1;      // fill first row
			}
			else{
				break;
			}
		}
		for(int i=0;i<n;i++){
			if(s[i][0]=='.'){
				dp[i][0]=1;      // fill first column
			}
			else{
				break;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				if(s[i][j]=='.'){    // update the answer if we can reach (i,j) state
					dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;  // we can only reach from above and left to this state.
				}
			}
		}
		cout<<dp[n-1][n-1]<<endl;
	}
}