#include <bits/stdc++.h>
using namespace std;

long long gcd(int p, int q){
    if(q == 0) return p;
    return gcd(q, p % q);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp, first, last;
    cin >> n >> temp;
    first = temp;
    vector<int> v;
    for (int i=1; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a-temp);
        temp = a;
        if(i==n-1)
            last = a;
    }
    long long temp2 = gcd(v[0], v[1]);
    for (int i=2; i<v.size(); i++)
        temp2 = gcd(temp2, v[i]);
    cout << (last - first)/temp2 +1 - n;
}