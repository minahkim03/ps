#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, ans = 0, temp;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    for(int i=0; i<n; i++)
        ans ^= v[i];
    temp = ans;
    for(int i=0; i<n; i++)
        ans = max(ans, temp^v[i]);
    cout << ans << ans;
}