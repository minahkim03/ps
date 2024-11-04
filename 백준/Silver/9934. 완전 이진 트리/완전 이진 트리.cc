#include <bits/stdc++.h>
using namespace std;

int arr[1024] = {0, };
vector<int> ans[10];

void find(int level, int start, int end){
    if(start>=end)
        return;
    int mid = (start+end)/2;
    ans[level].push_back(arr[mid]);
    find(level+1, start, mid);
    find(level+1, mid+1, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;
    
    for(int i=1; i<pow(2,k); i++)
        cin >> arr[i];
    find(0, 1, int(pow(2,k)));
    for(int i=0; i<k; i++){
        for(auto elem2: ans[i])
            cout << elem2 << ' ';
        cout << '\n';
    }
}