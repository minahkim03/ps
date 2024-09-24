#include <bits/stdc++.h>
using namespace std;

long long arr[10001] = {0,1, 2, 3, 4, };
int flag = 4;

void f(int n){
    int temp=0;
    for(int i=0; i<=n/3; i++){
        if(n%2==0 && i%2==0){
            if((n-3*i)%2==0)
                temp++;
        }
        if(n%2==1 && i%2==1){
            if((n-3*i)%2==0)
                temp++;
        }
    }
    arr[n] = arr[n-1] + temp;
    if (flag<n)
        flag = n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(arr[n] !=0)
            cout << arr[n] << '\n';
        else {
            for(int i=flag+1; i<=n; i++)
                f(i);
            cout << arr[n] <<'\n';
        }
    }
}