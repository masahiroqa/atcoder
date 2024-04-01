#include <iostream>
#include <string>
#include <vector> 
#include <list>
#include <algorithm>

using namespace std;

int main(){
    int N, K, ans;
    vector<int> ansList;
    cin >> N >> K;
    for(int i=0;i < N;i++){
        int input;
        cin >> input;
        if(input % K == 0){
            ans = input / K;
            ansList.push_back(ans);
        }
    }
    for(int i=0;i<ansList.size();i++){
        cout << ansList[i] << " ";
    }
    cout << endl;

    return 0;
}