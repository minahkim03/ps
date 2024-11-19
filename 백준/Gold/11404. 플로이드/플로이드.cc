#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int INF = 987654321;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1,vector<int> (n+1));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (i==j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(graph[a][b]>c)
            graph[a][b] = c;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                graph[start][end] = min(graph[start][end], graph[start][k] + graph[k][end]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j]>=INF)
                cout << 0 << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}