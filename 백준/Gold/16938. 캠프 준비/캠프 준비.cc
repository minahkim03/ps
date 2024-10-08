#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l, r, x, ans = 0;
    cin >> n >> l >> r >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    for(int i=1; i<(1<<n); i++){
        int lvl = 0, easy = pow(10, 9), hard = 1;
        for(int j = 0; j<n; j++){
            if(i & (1<<j)){
                lvl += v[j];
                easy = min(easy, v[j]);
                hard = max(hard, v[j]);
            }
        }
        if(l<=lvl && lvl<=r && (hard-easy)>=x)
            ans ++;
    }
    cout << ans;
}