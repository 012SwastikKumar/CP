
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
	ll x;
	cin>>x;

	while(x>0){
		if(x%10==7){
			cout<<"YES\n";
			return ;
		}
		x/=10;
	}
	cout<<"NO\n";
		
}
