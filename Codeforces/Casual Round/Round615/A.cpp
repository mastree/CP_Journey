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

int t;
ll a, b, c, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> a >> b >> c >> n;
        ll tot = a + b + c + n;
        if (tot%3==0 && (a<=tot/3) && (b<=tot/3) && (c<=tot/3)){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}