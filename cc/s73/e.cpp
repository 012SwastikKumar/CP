
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int __ = 1;
	cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()
{
	ll n;
	cin>>n;

	vector<ll>v(n);
	for(ll i=0 ; i<n ; i++){
		cin>>v[i];
	}

	for(ll i=1 ; i<n ; i++){
		v[i]^=v[i-1];
		v[i-1]=0;
	}

	ll sum = accumulate(v.begin(),v.end(),0ll);

	if(sum){
		int c=0;
		for(auto &x : v){
			if(x)c++;
		}

		if(n-c == n-1){
			((n-1)&1) ? cout<<"NO\n" : cout<<"YES\n";
			return ;
		}
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
	}

		
}
	