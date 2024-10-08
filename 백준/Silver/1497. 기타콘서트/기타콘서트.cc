#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, ans = -1;
    long long songnum=0;
    cin >> n >> m;
    vector<pair<string, long long>> v(n);
    for(int i=0; i<n; i++){
        string name, song;
        long long num;
        cin >> name >> song;
        for(int j=0; j<m; j++){
            if (song[j] == 'Y')
                song[j] = '1';
            else
                song[j] = '0';
        }
        num = stoll(song, nullptr, 2);
        v[i] = make_pair(name, num);
    }
    for(int i=1; i<(1<<n); i++){
        long long temp = 0;
        for(int j = 0; j<n; j++){
            if(i & (1<<j))
                temp |= v[j].second;
        }
        if(temp>songnum){
            songnum = temp;
            bitset<10> binary(i);
            ans = int(binary.count());
        } else if (temp == songnum){
            bitset<10> binary(i);
            ans = min(ans, int(binary.count()));
        }
    }
    if(songnum)
        cout << ans;
    else
        cout << -1;
}