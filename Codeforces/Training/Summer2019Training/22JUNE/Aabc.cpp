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

    string s;
    cin >> s;

    int n=4;
    for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]){
            cout << "Bad" << el;
            return 0;
        }
    }

    cout << "Good" << el;

    return 0;
}