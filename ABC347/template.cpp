#include <iostream>
#include <string>
#include <vector> 
#include <list>
#include <algorithm>

using namespace std;

int main(){

    return 0;
}

// vector 検索
// if(find(ansList.begin(), ansList.end(), tmp) == ansList.end())

//isNumber
bool isNumber(const string& str) {
  for (char const& c : str) {
    if (std::isdigit(c) == 0) return false;
  }
  return true;
}


// split.cpp
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

// quick sort