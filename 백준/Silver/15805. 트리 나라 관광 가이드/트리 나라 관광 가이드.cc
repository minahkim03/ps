#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, maxn=0;
    cin >> n;
    vector<int> input(n);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        input[i] = a;
        if(a>maxn)
            maxn = a;
    }
    cout << maxn +1 <<'\n';
    vector<int> v(maxn+1), visited(maxn+1);
    for(int i=0; i<v.size(); i++){
        v[i] = -1;
        visited[i] = 0;
    }
    for(int i=0; i<n-1; i++){
        if(!visited[input[i+1]]){
            v[input[i+1]] = input[i];
            visited[input[i+1]] = 1;
            visited[input[i]] = 1;
        }
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
}