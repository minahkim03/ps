#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++)
        parent[i] = i;
    for(int i=0; i<=m; i++){
        int e, a, b;
        cin >> e >> a >> b;
        if(e==0)
            merge(a,b);
        else {
            if(find(a)==find(b))
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
    }
}
