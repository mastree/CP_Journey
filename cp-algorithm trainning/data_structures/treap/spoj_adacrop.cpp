#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    int key, prior, cnt;
    item * l, * r;
    item() { }
    item(int key) : key(key), prior(rng32()), cnt(1), l(NULL), r(NULL) { }
    
};
typedef item * pitem;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

void upd(pitem t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

// l gets <= key and r gets > key
void split(pitem t, pitem& l, pitem& r, int key) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->l, l, t->l, key),  r = t;
    else
        split(t->r, t->r, r, key),  l = t;
    upd(t);
}

void merge(pitem& t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r),  t = l;
    else
        merge(r->l, l, r->l),  t = r;
    upd(t);
}

// Zero Indexed
void split_at(pitem t, pitem& l, pitem& r, int pos) {
    if (!t) {
        l = r = NULL;
        return;
    }
    int curpos = cnt(t->l);
    if (pos < curpos)
        split_at(t->l, l, t->l, pos), r = t;
    else
        split_at(t->r, t->r, r, pos - curpos - 1), l = t;
    upd(t);
}

void insert(pitem& t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->l, it->r, it->key),  t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
    upd(t);
}

void erase(pitem& t, int key) {
    if (!t) return;
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
    upd(t);
}

int kth_number(pitem t, int pos) {
    if (!t) return -1;
    int curpos = 1 + cnt(t->l);
    if (curpos == pos)
        return t->key;
    else if (curpos > pos)
        return kth_number(t->l, pos);
    else
        return kth_number(t->r, pos - curpos);
}

int getPos(pitem t, int val) {
    if (!t)
        return 0;
    if (val >= t->key)
        return 1 + cnt(t->l) + getPos(t->r, val);
    else
        return getPos(t->l, val);
}

void output(pitem t) {
    if (!t)  return;
    output(t->l);
    cout << t->key << ' ';
    output(t->r);
}

int n, q;
int ar[N];
pii quer[N];

pitem gtreap[N * 2];
map<int, int> getid;
// int getinput[N * 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;  
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        getid[ar[i]] = 1;
    }
    for (int i=1;i<=q;i++){
        int pos, nval;
        cin >> pos >> nval;
        getid[nval] = 1;
        quer[i] = mp(pos + 1, nval);
    }
    int tempid = 0;
    for (auto x : getid){
        getid[x.fi] = ++tempid; 
    }
    
    for (int i=1;i<=n;i++){
        ar[i] = getid[ar[i]];
        insert(gtreap[ar[i]], new item(i));
    }

    for (int i=1;i<=q;i++){
        int pos, nval;
        pos = quer[i].fi;
        nval = getid[quer[i].se];
        erase(gtreap[ar[pos]], pos);
        ar[pos] = nval;
        insert(gtreap[ar[pos]], new item(pos));
        cout << max(getPos(gtreap[ar[pos]], pos) - 1, 0) << el;
    }

    return 0;
}