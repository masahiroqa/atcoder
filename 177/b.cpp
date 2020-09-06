#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    //答えansを仮置きする。
    //これが十分に大きくないと不正解となるので、
    //この値なら絶対に正しい答えが出る、という値を仮置きすること
    int ans = T.size();

    //Sの何文字目から調べるかを全探索する
    for (int start = 0; start <= S.size() - T.size(); start++)
    {
        int diff = 0;
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] != S[start + i]) {
                diff++;
            }
        }
        ans = min(ans, diff);
    }

    cout << ans << endl;
}
