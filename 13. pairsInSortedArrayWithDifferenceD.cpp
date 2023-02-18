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

int bs(int *a, int el, int start, int end) {
	int res = end;
	int lo = start, hi = end - 1;

	while(lo <= hi) {
		int mid = lo + ((hi-lo)>>1);

		if(a[mid] >= el) {
			res = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	return res;
}

int pairsWithDDiff(int *a, int n, int d) {

	sort(a, a+n); 
	int count = 0;

	// sol1 : two pointers approach
	// int lo = 0, hi = 1;
    // set<pair<int, int>> pr;
	    
    // while(hi < n) {
    //     if(a[hi] - a[lo] == d) {
    //         pr.insert({a[hi], a[lo]});
    //         lo++;
    //         hi++;
    //     } else if(a[hi] - a[lo] < d) {
    //         hi++;
    //     } else {
    //         lo++;
    //     }
    // }
    // count = pr.size();
    // for(auto it:pr) {
    // 	cout<<it.first<<" "<<it.second<<"\n";
    // }

	// sol2 : binary search approach
	for(int i = 0; i < n; i++) {
		// if(i!= 0 and a[i] == a[i - 1]) continue; // avoiding duplicates

		int X = bs(a, a[i] + d, i + 1, n);

		if(X != n) {
			int Y = bs(a, a[i] + d + 1, i + 1, n);
			count+=(Y - X);
		}
	}


    
	return count;
}

int main() {
    clock_t begin = clock();
    file_i_o();

    int n, d;
    cin>>n>>d;

    int *a = new int[n];
    for(int i = 0; i < n; i++) {
    	cin>>a[i];
    }

    cout<<pairsWithDDiff(a, n, d);


    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}