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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    pii op[m]; // (C,B);
    priority_queue <int,vector<int>,greater<int>> pq;
    for (int i=0;i<n;i++){
        int tm;
        cin >> tm;
        pq.push(tm);
    }

    for (int i=0;i<m;i++){
        int b,c;
        cin >> b >> c;
        op[i]=mp(c,b);
    }

    sort(op,op+m,greater<pii>());

    for (int i=0;i<m;i++){
        int cnt=0;
        while (cnt<op[i].se && op[i].fi>pq.top()){
            pq.pop();
            pq.push(op[i].fi);
            cnt++;
        }
    }

    ll tot=0;
    while (!pq.empty()){
        tot+=(ll)pq.top();
        pq.pop();
    }

    cout << tot << el;

    return 0;
}