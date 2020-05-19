#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll solve(ll n){
    ll b = n;
    for(ll i=2;;i++){
        if(i*i > b){
            return b;
        }
        if(n%i == 0){
            return max(i, solve(n/i));
        }
    }
}
int main() {
    int t;cin>>t;
    while(t--){
        ll n; cin >> n;
        ll m = solve(n);
        cout<<m<<endl;
    }
    return 0;
}
