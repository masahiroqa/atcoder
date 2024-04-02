#include <iostream>
#include <string>
#include <vector> 
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    long long int a, b, C, x, y, sum, diff, comNum;
    string tmpX="", tmpY="";

    cin >> a >> b >> C;
    bitset<60> bsC(C);
    sum = bsC.count();
    diff = max(a, b) - min(a, b);
    if((sum + diff) % 2 == 0){
        x = (sum + diff) / 2;
        y = x  - diff;
        comNum = max(a,b) - x;
        for(int i=59, cnt=0;i>=0;i--){
            if(cnt<x && bsC[i] == 1){
                tmpX += "1";
                tmpY += "0";
                cnt += 1;
            }else if(x<=cnt && cnt<(x+y) && bsC[i] == 1){
                tmpX += "0";
                tmpY += "1";
                cnt += 1;
            }else{
                tmpX += "0";
                tmpY += "0";
            }
        }
        bitset<60> ans1(tmpX);
        bitset<60> ans2(tmpY);
        if(comNum > 0){
            for(int i=59, cnt=0;i>=0;i--){
                if(ans1[i] == 0 && ans2[i] == 0){
                    ans1.set(i);
                    ans2.set(i);
                    cnt += 1;
                }
                if(cnt >= comNum) break;
            }
        }
        cout << ans1.to_ullong() << " " << ans2.to_ullong() << endl;
        return 0;
    }
    
    cout << "-1" << endl;
    return 0;
}