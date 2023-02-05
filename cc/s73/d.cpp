
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
	ll n,y;
	cin>>n>>y;

	vector<ll>v(n);
	for(int i=0 ; i<n ; i++){
		cin>>v[i];
	}

	ll bor = v[0];
	for(int i=1 ; i<n ; i++){
		bor |= v[i];
	}

	ll x = y-bor;

	if(bor==y){
		cout<<"0\n";
		return ;
	}else if((y&x)==x){
		cout<<x<<"\n";
	}else{
		cout<<"-1\n";
	}
		
}
