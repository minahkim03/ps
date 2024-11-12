#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> m;
int cnt = 0;

pair<int, int> find(int s) {
    auto temp = m.find(s);
    if (temp==m.end()){
        m.insert({s,{s,1}});
        return {s,1};
    };
    if (temp->second.first == s) return temp->second;
    return temp->second = find(temp->second.first);
}

void merge(int x, int y) {
    x = find(x).first;
    y = find(y).first;
    if (x == y) return;
    m.find(y)->second.first = x;
    m.find(m.find(x)->second.first)->second.second += m.find(y)->second.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cnt ++;
        m.clear();
        int n, k, m;
        cin >> n >> k;
        for(int i=0; i<k; i++){
            int s1, s2;
            cin >> s1 >> s2;
            find(s1);
            find(s2);
            merge(s1, s2);
        }
        cout << "Scenario " << cnt << ":\n";
        cin >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            if(find(a)==find(b))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        cout << '\n';
    }
}