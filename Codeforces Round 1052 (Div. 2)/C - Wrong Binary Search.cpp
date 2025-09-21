//Mohd Fahad >_<
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#ifndef ONLINE_JUDGE
#define deb1(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x,y,z) cout<< #x << "="<< x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#else
#define deb1(x)
#define deb2(x,y)
#define deb3(x,y,z)
#endif
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define al(a)           a.begin(),a.end()
#define alg(a)          a.rbegin(),a.rend()
#define getunique(v)    {sort(al(v)); v.erase(unique(al(v)),v.end());}
#define input(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define print(a)        for(auto it:a){cout<<it<<" ";}cout<<endl
#define sll             set<long long>
#define msll            multiset<long long>
#define inmap(x,mymap)  mymap.find(x)!=mymap.end()
#define mll             map<ll,ll>
#define mmll            multimap<ll,ll>
#define uset            unordered_set<ll>
#define lb              lower_bound
#define ub              upper_bound
#define Inf             1e18
#define YES             cout << "YES" << endl;
#define NO              cout << "NO" << endl;
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define nl_              cout << endl;
#define dsort(x)        sort(x.begin(),x.end(),greater<ll>())
#define asort(x)        sort(x.begin(),x.end())
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

typedef pair<int,int>     pii;
typedef pair<ll,ll>       pl;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;

//bit-stuff
#define setbits(a)      (__builtin_popcountll(a))  // to count 1 bits
#define right(a)        (__builtin_ctzll(a))       // to count trailing 0s
#define left(a)         (__builtin_clzll(a))       // to count leading 0s
#define parity(a)       (__builtin_parityll(a))    // to check even odd

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

ll modInverse(ll A, ll M);
int mpow(int base, int exp); 

void ipgraph(int n, int m);
void dfs(int u, int par);

void prnt(vector<ll> a);
void prnt(vector<vector<ll>> a);
void prnt(vector<pair<ll,ll>> a);

ll GCD(ll a,ll b);
ll nCr(ll n,ll r, ll M);

const int mod = 1000000007;
const int mod1 = 998244353;
const int N = 3e5, M = N;

vi g[N];

//fahad.cpp

void karke_dekhte_hain(){
    ll i=0,j=0,k=0,q=0,n=0,m=0,count=0;
    vector<vector<ll>> v;
    vector<ll> a,b;
    string s,s1,s2;
    cin>>n;
    cin>>s;
    s1="1";
    s1+=s;
    s1+="1";
    ll cnt=1;
    for(int i=2;i<s1.size();i++){
        if(s1[i-2]=='1'&&s1[i-1]=='0'&&s1[i]=='1'){
            cout<<"NO\n";
            return;
        }
    }
    queue<ll> qt;
    stack<ll> st;
    vector<ll> ans(n,0);
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            qt.push(i);
            st.push(i+1);
        }
        else{
            ans[i]=i+1;
            while(qt.size()){
                ll pos=qt.front();
                ll val=st.top();
                ans[pos]=val;
                qt.pop();
                st.pop();
            }
        }
    }
    while(qt.size()){
        ll pos=qt.front();
        ll val=st.top();
        ans[pos]=val;
        qt.pop();
        st.pop();
    }
    cout<<"YES\n";
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t=1;
    cin>>t;
    while(t--){
        karke_dekhte_hain();
    }
    return 0;
}

void prnt(vector<ll> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" \n"[i==a.size()-1];
    }
}

void prnt(vector<vector<ll>> a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" \n"[j==a[i].size()-1];
        }
    }
}

void prnt(vector<pair<ll,ll>> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i].F<<" \n"[i==a.size()-1];
    }
    for(int i=0;i<a.size();i++){
        cout<<a[i].S<<" \n"[i==a.size()-1];
    }
}

ll GCD(ll a,ll b){
    while((a>0)&&(b>0)){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
}

ll nCr(ll n,ll r, ll M){
    if(r>n) return 0ll;
    if(r== n || r==0 ) return 1ll;
    ll a1=1,a2=1,a3=1,i;
    for(i=1;i<=n;i++) a1=(a1*i)%M;
    for(i=1;i<=r;i++) a2=(a2*i)%M;
    for(i=1;i<=n-r;i++) a3=(a3*i)%M;
    a2=(a2*(a3))%M;
    a2=modInverse(a2,M);
    a1=(a1*a2)%M;
    return a1;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m){
    int i, u, v;
    while(m--){
        cin>>u>>v;
    u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par){
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}

ll modInverse(ll A, ll M){
    ll m0=M;
    ll y=0, x=1;
    if(M==1) return 0;
    while(A>1){
        int q=A/M;
        int t=M;
        M=A%M,A=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}
