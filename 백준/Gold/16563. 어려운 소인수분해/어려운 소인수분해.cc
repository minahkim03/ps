#include <bits/stdc++.h>
using namespace std;

int N = 5000000;
int minFactor[5000001];

void sieve_of_Eratosthenes2(int N) {
    minFactor[0] = -1;
    minFactor[1] = -1;
    
    for (int i = 2; i <= N; i++)
        minFactor[i] = i;

    int sqrtn = int(sqrt(N));

    for (int i = 2; i <= sqrtn; i++) {
        if (minFactor[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (minFactor[j] == j) {
                    minFactor[j] = i;
                }
            }
        }
    }
}

vector<int> factor(int N) {
    vector<int> ret;

    while (N > 1) {
        ret.push_back(minFactor[N]);
        N /= minFactor[N];
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    sieve_of_Eratosthenes2(N);
    while(t--){
        int n;
        cin >> n;
        vector<int> v = factor(n);
        for(auto elem: v)
            printf("%d ", elem);
        printf("\n");
    }
}