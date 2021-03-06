#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define el '\n'

using namespace std;

using lld = long double;
using ll = long long;

const int N = 100, M = 700, X = 1e5 + 10;

int n, m, x;
vector<pii> adl[N];

struct FlowEdge{
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic{
    const ll INF = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].pb(m);
        adj[u].pb(m + 1);
        m += 2;
    }    

    bool bfs(){
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (int id : adj[v]){
                if (edges[id].cap - edges[id].flow < 1) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed){
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++){
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll ret = 0;
        while (1){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, INF)){
                ret += pushed;
            }
        }
        return ret;
    }
};

void solve(){
    lld low = 1e-5, high = 1e6;
    for (int lup=0;lup<60;lup++){
        lld mid = (low + high) / ((lld)2);

        Dinic dinic(n + 1, 1, n);
        for (int i=1;i<=n;i++){
            for (auto x : adl[i]){
                int v = i, u = x.fi;
                ll cap = (ll)((lld)(x.se) / mid);
                dinic.add_edge(v, u, cap);
            }
        }
        ll flow = dinic.flow();
        if (flow >= x){
            low = mid;
        } else{
            high = mid;
        }
    }
    cout << ((lld)x) * low << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b, w));
    }
    cout << fixed << setprecision(11);
    solve();

    return 0;
}