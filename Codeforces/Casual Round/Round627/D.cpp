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

const int N = 2e5 + 10;

int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }   

    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        ar[i] -= a;
    }

    sort(ar + 1, ar + n + 1);
    ll ans = 0;

    for (int i=1;i<=n;i++){
        ll minim = -ar[i] + 1;

        int id = (int)(lower_bound(ar + 1, ar + n + 1, minim) - ar);
        ans += (ll)(n - id + 1);
        if (minim <= ar[i]) ans--;
    }
    ans /= 2;
    cout << ans << el;

    return 0;
}