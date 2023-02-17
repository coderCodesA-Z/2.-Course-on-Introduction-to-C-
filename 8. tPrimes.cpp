#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;


void file_i_o() {
  	std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    clock_t begin = clock();
    file_i_o();


    long long int n;
    cin>>n;

    long long int *a = new long long int(n);
    for(long long int i = 0; i < n; i++) cin>>a[i];


    long long int size = 1000001;
	bool primes[size+1];
	memset(primes, 1, sizeof(primes));

	primes[0] = primes[1] = 0;

	for(int j = 2; j <= size; j+=2) primes[j] = 0;

	for(int i = 3; i * i <= size; ++i) {
		if(primes[i]) {
			for(int j = i * i; j <= size; j+=(2*i)) {
				primes[j] = 0;
			}
		}
	}

    for(long long int i = 0; i < n; ++i) {

    	// 1 is not a t-prime
    	if(a[i] == 1) {
    		cout<<"NO"<<"\n";
    		continue;
    	}

    	// if perfect square, find sqrt
    	// since the root of the max x(10^12) value will be around 10^6, high can be set to some value
    	// around 10^7 
    	// long long int sqrtNum = -1, low = 1, high = a[i];
    	long long int sqrtNum = -1, low = 1, high = 10000005;

    	while(low<=high) {
    		long long int mid = low + ((high-low)>>1);
    		if(mid * mid == a[i]) {
    			// mid * mid overflow if hi set to a[i]
    			sqrtNum = mid;
    			break;
    		} else if(mid * mid > a[i]) {
    			high = mid - 1;
    		} else {
    			low = mid + 1;
    			// sqrtNum = mid;
    		}
    	}

    	if(sqrtNum == -1) {
    		cout<<"NO"<<"\n";
    		continue;
    	}

    	// if perfect square primality check

    	// O(n^1/4)
    	// bool isSqrtNumPrime = 1;
    	// for(long long int div = 2; div * div <= sqrtNum; div++) {
    	// 	if(sqrtNum % div == 0) {
    	// 		isSqrtNumPrime = 0;
    	// 		cout<<"NO"<<"\n";
    	// 		break;
    	// 	}
    	// }

    	// if(isSqrtNumPrime) cout<<"YES"<<"\n";

    	if(primes[sqrtNum]) cout<<"YES"<<"\n";
    	else cout<<"NO"<<"\n";
    }


    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}