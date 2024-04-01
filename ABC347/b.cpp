#include <iostream>
#include <string>
#include <vector> 
#include <list>
#include <algorithm>

using namespace std;

int main(){
    string S;
    vector<string> ansList;
    cin >> S;

    for(int i=0;i<S.size();i++){
        for(int j=1;j<=S.size()-i;j++){
            string tmp;
            tmp = S.substr(i,j);
            if(find(ansList.begin(), ansList.end(), tmp) == ansList.end()){
                ansList.push_back(tmp);
            }
        }
    }
    cout << ansList.size() << endl;
    return 0;
}
