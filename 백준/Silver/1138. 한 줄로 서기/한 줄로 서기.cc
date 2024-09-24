#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int n;
    cin >> n;
    
    int arr[10] = {0,};
    
    for(int i=0; i<n; i++){
        int k, iter=0;
        cin >> k;
        for(int j=0; j<n; j++){
            if(iter==k && arr[j]==0){
                arr[j] = i+1;
                break;
            }
            if(arr[j]==0)
                iter ++;
        }
    }
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
}