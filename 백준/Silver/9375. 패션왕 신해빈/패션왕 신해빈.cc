#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--){
        int n, ans=1;
        map<string,vector<string>> m;
        cin >> n;
        while (n--){
            string clothes, type;
            cin >> clothes >> type;
            auto iter = m.find(type);
            if (iter != m.end()){
                iter->second.push_back(clothes);
            } else {
                vector<string> v = {clothes};
                m.insert({type, v});
            }
        }
        for(auto iter = m.begin(); iter!=m.end(); iter++)
            ans *= iter->second.size()+1;
        cout << ans-1 << '\n';
    }
}