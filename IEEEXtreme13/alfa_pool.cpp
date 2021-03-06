#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 100007;

ll dp[N+N];
int n;

int main() {
    cin >> n;
    
    dp[0]=1;
    
    for (int i=1;i<=N;i++){
        for (int j=1;j<17;j++){
            int id=i-(1 << j)+1;
            if (id>=0){
                dp[i]+=dp[id];
                dp[i]%=MOD;
            }
        }
    }
    
    // for (int i=0;i<40;i++){
    //     cout << "dp[" << i << "] = " << dp[i] * 2 % MOD << el;
    // }
    while (n--){
        int q;
        cin >> q;
        if (q==0){
            cout << 1 << el;
            continue;
        }
        cout << dp[q]*2%MOD << el;
    }
        
    return 0;
}