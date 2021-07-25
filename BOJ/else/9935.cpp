#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int main()
{
    vector<char> st;
    string str;
    string bomb;

    cin >> str >> bomb;
    int strn = str.size();
    int bombn = bomb.size();

    char lastone = bomb[bombn - 1];

    string reverse = "";
    for (int i = 0; i < bombn; i++) {
        reverse += bomb[bombn - 1 - i];
    }

    for (int i = 0; i < strn; i++) {
        


        st.push_back(str[i]);
        if (str[i] == lastone) {
            string temp = "";
            for (int k = 0; k < bombn; k++) {
                char b = st.back();
                st.pop_back();
                temp += b;
            }
            
            if (temp == reverse) {
                //cout << "!!!";
                continue;
            }
            else {
                //cout << "!!!\n";
                string tempReverse="";
                for (int j = 0; j < temp.size(); j++) {
                    st.push_back(temp[temp.size() - 1 - j]);
                }
            }
        }
    }
    if (st.size() == 0) {
        cout << "FRULA";
    }
    else {
        for (auto t : st) {
            cout << t;
        }
    }
    
    
    
    return 0;
}
