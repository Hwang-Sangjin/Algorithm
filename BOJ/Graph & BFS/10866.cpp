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
    int t;
    cin >> t;
    deque<int> q;
    string com;
    int n;
    while (t--) {
        cin >> com;

        if (com == "push_front") {
            cin >> n;
            q.push_front(n);
        }
        else if (com == "push_back") {
            cin >> n;
            q.push_back(n);
        }
        else if (com == "pop_front") {
            if (q.empty()) cout << -1<<'\n';
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if (com == "pop_back") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
                q.pop_back();
            }
        }
        else if (com == "size") {
            cout << q.size()<<'\n';
        }
        else if (com == "empty") {
            if (q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (com == "front") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
            }
        }
        else if (com == "back") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}
