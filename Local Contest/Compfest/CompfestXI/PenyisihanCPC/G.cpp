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

const int N = 1e5 + 10;

int n, k;
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    bool bisa = 1;
    for (int i=1;i<N;i++){
        if (cnt[i] - n > k){
            bisa = 0;
            break;
        }
    }

    if (bisa){
        cout << "Ya" << el;
    } else{
        cout << "Tidak" << el;
    }

    return 0;
}