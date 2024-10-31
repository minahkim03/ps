#include <bits/stdc++.h>
using namespace std;

int n, isPrime[10000], visited[10000];

void reset(){
    for(int i=0; i<10000; i++)
        visited[i] = 0;
}
void sieve_of_Eratosthenes(int n) {
    memset(isPrime, 1, sizeof(isPrime)); 

    isPrime[0] = false;
    isPrime[1] = false;

    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

void dfs(string s, string ans){
    queue<pair<string, int>> q;
    visited[stoi(s)] = true;
    q.push(make_pair(s, 0));
    while(!q.empty()){
        pair<string, int> temp = q.front();
        q.pop();
        if(temp.first==ans){
            cout << temp.second << '\n';
            return;
        }
        for (int i=0; i<4; i++){
            for (int j=0; j<=9; j++){
                string temps = temp.first;
                temps[i] = j+'0';
                int tempsi = stoi(temps);
                if(isPrime[tempsi]&&!visited[tempsi]&&tempsi>=1000){
                    visited[tempsi] = 1;
                    q.push(make_pair(temps, temp.second+1));
                }
            }
        }
    }
    cout << "Impossible" << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    sieve_of_Eratosthenes(9999);
    while(t--){
        reset();
        string a, b;
        cin >> a >> b;
        dfs(a, b);
    }
}