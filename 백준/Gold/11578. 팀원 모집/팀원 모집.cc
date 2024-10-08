#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, ans = -1;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0; i<m; i++){
        int a, temp=0;
        cin >> a;
        for(int j=0; j<a; j++){
            int b;
            cin >> b;
            temp |= 1<<(b-1);
        }
        v[i] = temp;
    }
    for(int i=1; i<(1<<m); i++){
        long long temp = 0;
        for(int j = 0; j<m; j++){
            if(i & (1<<j))
                temp |= v[j];
        }
        if(temp == pow(2, n)-1){
            bitset<10> binary(i);
            if(ans==-1)
                ans = int(binary.count());
            else
                ans = min(ans, int(binary.count()));
        }
    }
    cout << ans;
}
