#include <bits/stdc++.h>
using namespace std;

char graph[3][3];
int visited[3][3], dx[]={1,0,-1,0}, dy[]={0,1,0,-1};

void clear(int arr[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            visited[i][j] = 0;
    }
}

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    int cnt=1;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = temp.first+dx[i];
            int ny = temp.second+dy[i];
            if(0<=nx&&nx<3&&0<=ny&&ny<3&&graph[nx][ny]=='O'&&!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = 1;
                cnt ++;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        clear(visited);
        vector<int> v;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++)
                cin >> graph[i][j];
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(graph[i][j]=='O'&&!visited[i][j])
                    v.push_back(bfs(i, j));
            }
        }
        sort(v.begin(), v.end());
        int n;
        cin >> n;
        vector<int> temp(n);
        for(int i=0; i<n; i++)
            cin >> temp[i];
        if(n!=v.size())
            cout << 0 << '\n';
        else {
            bool flag = true;
            for(int i=0; i<v.size(); i++){
                if(temp[i]!=v[i]){
                    flag = false;
                    cout << 0 << '\n';
                    break;
                }
            }
            if(flag)
                cout << 1 << '\n';
        }
            
    }
}