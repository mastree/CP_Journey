#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n,e;
vector <int> adlist[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;

    for (int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adlist[a].pb(b);
    } 

    

    return 0;
}