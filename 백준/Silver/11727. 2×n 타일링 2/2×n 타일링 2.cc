#include <bits/stdc++.h>
using namespace std;

long long arr[1000] = {1,};

long long dp(long long n){
    if (arr[n-1]==0){
        if(n % 2 == 0){
            return arr[n-1] = (dp(n-1) * 2 +1)%10007;
        } else
            return arr[n-1] = (dp(n-1) * 2 -1)%10007;
    } else
        return arr[n-1];
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << dp(n);
    
}