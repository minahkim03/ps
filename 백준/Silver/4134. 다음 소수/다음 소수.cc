#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if (!n || n==1 || n==2){
            cout << 2 << '\n';
            continue;
        }
        if(n%2 == 0)
            n++;
        while(!isPrime(n))
            n +=2 ;
        cout << n << '\n';
    }
}