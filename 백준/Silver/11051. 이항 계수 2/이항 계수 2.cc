#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(1001, vector<int> (1001,-1));

int bino(int n, int k) {
    if (k==0 || k==n) return 1;
    if (arr[n][k] != -1) return arr[n][k];
    else {
        arr[n][k] = (bino(n-1, k-1) + bino(n-1, k))%10007;
        return arr[n][k];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    cout << bino(n,k);
}
