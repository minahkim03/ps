#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<>> pq;
        cin >> n;
        for (int i=0; i<n; i++){
            int a;
            cin >> a;
            pq.push(a);
        }
        while(pq.size()!=1){
            long long a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+b);
            ans += a+b;
        }
        cout << ans << '\n';
    }
}