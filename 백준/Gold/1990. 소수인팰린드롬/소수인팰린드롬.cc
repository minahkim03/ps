#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n){
    string s = to_string(n);
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s==rs;
}

bool isPrime(int n) {
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
    
    int a, b;
    cin >> a >> b;
    for(int i=a; i<=10000000; i++){
        if(i>b)
            break;
        if (palindrome(i)&&isPrime(i))
            cout << i << '\n';
    }
    cout << -1;
}
