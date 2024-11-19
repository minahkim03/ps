#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int visited[100][100], n, m, dx[]={1,0,-1,0},dy[]={0,1,0,-1};
vector<pair<int, int>> v;

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = temp.first+dx[i];
            int ny = temp.second+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&!visited[nx][ny]){
                if(graph[nx][ny]){
                    v.push_back({nx,ny});
                }
                else
                    q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    int hour=0, found=0;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> graph[i][j];
    }
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            if (!graph[i][j]&&!visited[i][j]){
                v.clear();
                bfs(i,j);
                hour++;
                for(int k=0; k<v.size(); k++)
                    graph[v[k].first][v[k].second]=0;
                for(int k=0; k<n; k++){
                    for (int kk=0; kk<m; kk++)
                        visited[k][kk] = 0;
                }
                if(!v.size()){
                    found=1;
                    break;
                }
                ans.push_back(v.size());
            }
        if(found)
            break;
    }
    cout << hour - 1 << '\n' << ans[ans.size()-1];
    return 0;
}