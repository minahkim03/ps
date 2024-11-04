#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, int>> m;

pair<string, int> find(string s) {
    auto temp = m.find(s);
    if (temp==m.end()){
        m.insert({s,{s,1}});
        return {s,1};
    };
    if (temp->second.first == s) return temp->second;
    return temp->second = find(temp->second.first);
}

void merge(string x, string y) {
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
        m.clear();
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            string s1, s2;
            cin >> s1 >> s2;
            find(s1);
            find(s2);
            merge(s1, s2);
            cout << find(s1).second << '\n';
        }
    }
}