#include <iostream>
#include <string>
#include <vector> 
#include <list>
#include <algorithm>

using namespace std;

int main(){
    int N, A, B, Dtmp;
    cin >> N >> A >> B;
    vector<int> DList; 
    for(int i=0;i<N;i++){
        cin >> Dtmp;
        Dtmp = Dtmp % (A + B);
        DList.push_back(Dtmp);
    }
    sort(DList.begin(), DList.end());
    for(int i=0;i<N;i++){
        DList.push_back(DList[i]+(A+B));
    }
    cout << endl;
    for(int i=0;i<N;i++){
        int l = DList[i], r = DList[i+N-1];
        if(r-l+1 <= A){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}