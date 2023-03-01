#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int num,a,b,c,d,n;
	cin>>num;
	n=num;
	if(n==0){
		cout<<"1 3 4 5\n";
		return ;
	}

	vector<int> ans(4);
	ans[0]=ans[1]=ans[2]=0;
	int j=0;
	for(int i=0 ; i<60 ; i++){
		if(!(n&(1ll<<i))){
			ans[j] += (1ll<<i);
			if(j==2){
				ans[3] += (1ll<<i);
			}
			j++;
			j%=3;
		}
	}

	for(int i=0 ; i<4 ; i++){
		assert(ans[i] != 0);
		for(int j=i+1 ; j<4 ; j++){
			assert(ans[i]!=ans[j]);
		}
	}

	int val = ((ans[0] & ans[1]) | ans[2]^ans[3]);
	assert(val==n);

	if(ans[3]==0){
		cout<<"-1\n";
	}else{
		for(auto &x : ans){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}

int32_t main()
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


	// ll i=0;

	// // first unset-bit of num at i
	// while(n>0){
	// 	if(n%2==0){
	// 		break;
	// 	}
	// 	i++;
	// 	n/=2;
	// }
	
	// // set ith bit
	// n=num;
	// ll mask = 1<<i;
	
	// // value of c
	// c = n | mask;

	// // value of d
	// d = mask;

	// // value of b
	// b = n;

	// // value of a
	// a = n;

	// cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";