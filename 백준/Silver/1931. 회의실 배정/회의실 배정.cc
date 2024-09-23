#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second!=b.second)
        return a.second<b.second;
    else{
        return a.first<b.first;
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, ans=0, curr=0;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        if(curr<=v[i].first){
            ans++;
            curr=v[i].second;
        }
    }
    cout << ans;
}