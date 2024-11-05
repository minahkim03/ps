#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt[13], arr[13][13];
    
    for(int i=0; i<13; i++){
        cnt[i] = 0;
        for(int j=0; j<13; j++)
            arr[i][j] = 0;
    }
    
    for(int i=0; i<12; i++){
        int x, y;
        cin >> x >> y;
        
        arr[x][y] = 1;
        arr[y][x] = 1;
        cnt[x]++;
        cnt[y]++;
    }
    
    for(int i=1; i<=12; i++){
        if(cnt[i] == 3){
            vector<int> v;
            int temp = 0;
            for(int j=1; j<=12; j++){
                if(arr[i][j])
                    temp+=cnt[j];
            }
            if(temp == 6)
                cout << i;
        }
    }
}