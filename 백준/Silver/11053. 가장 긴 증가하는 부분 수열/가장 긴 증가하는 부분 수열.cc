#include <bits/stdc++.h>
using namespace std;

int arr[1001] = {0,}, val[1001] = {0,}, ans=1;
void dp(int n) {
    for(int i=2; i<=n; i++){
        arr[i] = 1;
        for(int j=1; j<i; j++){
            if(val[i]>val[j]) arr[i] = max(arr[i], 1+arr[j]);
        }
        if(arr[i]>ans)
            ans = arr[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    arr[1] = 1;
    int n;
    cin >>n;
    for(int i=1; i<=n; i++)
        cin >> val[i];
    dp(n);
    cout << ans;
}