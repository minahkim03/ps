#include <bits/stdc++.h>
using namespace std;

long long arr[36] = {1, 1, 2, 5,};

long long dp(int n){
    if(arr[n]!=0)
        return arr[n];
    else {
        if (n%2 == 0){
            for (int i=0; i<n/2; i++)
                 arr[n] += dp(i) * dp(n-i-1);
            return arr[n] *= 2;
        } else {
            for (int i=0; i<n/2; i++){
                arr[n] += dp(i) * dp(n-i-1);
            }
            arr[n] *= 2;
            arr[n] += dp(n/2) * dp(n/2);
        }
        
        return arr[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    dp(n);
    cout << arr[n];
}