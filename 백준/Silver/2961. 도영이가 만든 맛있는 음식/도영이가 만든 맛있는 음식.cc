#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, ans = 1000000000;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    for (int i=1; i<(1<<n); i++){
        int sour = 1, bitter = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                sour *= v[j].first;
                bitter += v[j].second;
            }
        }
        ans = min(ans, abs(sour-bitter));
    }
    cout << ans;
}
