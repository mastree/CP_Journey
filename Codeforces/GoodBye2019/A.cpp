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

int q;
int n, k1, k2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k1 >> k2;

        bool yes = 0;
        for (int i=0;i<k1;i++){
            int a;
            cin >> a;
            if (a==n){
                yes = 1;
            }
        }
        for (int i=0;i<k2;i++){
            int a;
            cin >> a;
        }

        if (yes){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}