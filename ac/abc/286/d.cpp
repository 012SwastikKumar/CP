
#include <bits/stdc++.h>
using namespace std;
#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
#define  pb              push_back
#define  ppb             pop_back
#define  sz(v)           int((v).size())
#define  all(v)          (v).begin(), (v).end()
#define  allr(v)         (v).rbegin(), (v).rend()
#define  endl            "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < sz(nums) - 1; i++)cout << nums[i] << " "; if (sz(nums))cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums){for(int i = 0; i < nums.size(); i++){print1D(nums[i]);cout << endl;}}
long long power(long long x, long long n) {x = x % MOD; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % MOD; n = n >> 1; x = (x * x) % MOD;} return result;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

void get(vll &v, ll n) {rep(i, 0, n)cin >> v[i];}
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
	// cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}



void solve()
{
	ll n,x;
	cin>>n>>x;
	vll a(n),b(n);
	rep(i,0,n)cin>>a[i]>>b[i];

    vector<vector<int>> dp(x+1,vector<int>(n+1));

    for(int i=0; i<=x; i++){
    	for(int j=0;j<=n; j++){
	        if(i == 0){
	            dp[i][j] = 0;
	            continue;
	        }
	        else if (j == 0){
	            dp[i][j] = INT_MAX;
	            continue;
	        }
	        
	        dp[i][j] = dp[i][j-1];
        	for(int k=1; k<=1000; k++){
	            if(i< k*a[j-1])
	                break;
	            
	            if(dp[i-k*a[j-1]][j-1] != INT_MAX)
	            dp[i][j] = min(dp[i][j], k+dp[i-k*a[j-1]][j-1]);
	        }
    	}
	}

	// int k=1000;
	// int i=x;
	// int j=n;
	// vector<int> values;
	// while(i>0)
	// {
	//     for(int val=1;val<=1000;val++)
	//     {
	//         if(val*a[j-1] > i || dp[i][j] == INT_MAX)
	//                 break;
	        
	//         if(dp[i-val*a[j-1]][j-1] == dp[i][j] - val)
	//         {    
	//             for(int iter=1; iter<=val; iter++)
	//             {
	//                 values.push_back(a[j-1]);
	//             }
	            
	//              i-=val*a[j-1];
	//             break;
	//         }
	//     }
	    
	//     j--;
	// }

    if(dp[x][n]>0){
    	cout<<"Yes\n";
    }else{
    	cout<<"No\n";
    }

	// vector<vector<ll>>dp(n+1,vector<ll>(x+1));

	// rep(i,0,n+1){
		// rep(j,0,n+1){
		// 	if(j==0)dp[i][j]=1;
		// 	if(i==0)dp[i][j]=0;
		// }
	// }

	// rep(i,1,n+1){
		// rep(j,1,x+1){
		// 	if(a[i]<=j && b[i]>0){
		// 		dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
		// 		b[i]--;
		// 	}else{
		// 		dp[i][j] = dp[i-1][j];
		// 	}
		// }
	// }

	// dp[n][x]>0 ? cout<<"Yes\n" : cout<<"No\n";
}
