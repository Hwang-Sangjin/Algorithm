#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>

using namespace std;
int N;
int c[12];
int p[12][12];
bool check[12];

int main() {
   cin >> N;
   int res = 10002;
   vector<int>v;

   int temp;
   for (int i = 1; i <= N; i++) {
      v.push_back(i);
      cin >> temp;
      c[i] = temp;
   }

   for (int i = 1; i <= N; i++) {
      cin >> temp;
      int a, d;
      while (temp--) {
         cin >> a >> d;
         p[i][a] = d;
      }
   }


   do {
      memset(check, false, sizeof(check));
      int tempRes=0;
      for (auto t : v) {
         //cout << t << ' ';
         int originalCost = c[t];
         for (int i = 1; i <= N; i++) {
            if (p[i][t] != 0) {
               if (check[i]) {
                  originalCost -= p[i][t];
                  if (originalCost <= 0) {
                     originalCost = 1;
                     break;
                  }
               }
            }
         }
         check[t] = true;
         tempRes += originalCost;
      }
      //cout << tempRes << '\n';
      res = min(res, tempRes);
   } while (next_permutation(v.begin(), v.end()));

   cout << res;
   
   return 0;
}


#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>

using namespace std;
vector<vector<int>>m(1002);
bool v[1002];
int N, Q;
int A[1002];

int main() {
	cin >> N >> Q;
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		A[i] = temp;
	}
	int n = N - 1;
	int a, b;
	while (n--) {
		cin >> a >> b;
		m[a].push_back(b);
		m[b].push_back(a);
	}


	int s, f,ex=0;
	while (Q--) {
		memset(v, false, sizeof(v));
		cin >> s >> f;
		string tempRes = to_string(A[s]);
		v[s] = true;
		
		while (s != f) {
			//cout << s << '\n';
			int x, y;
			if (m[s].size() == 1) {
				ex = s;
				s = m[s][0];
			}
			else {
				x = m[s][0];
				y = m[s][1];
				if (x==ex) {
					ex = s;
					s = y;
				}
				else {
					ex = s;
					s = x;
				}
			}
			tempRes += to_string(A[s]);
			long long tempL = stoll(tempRes);
			tempRes = to_string(tempL % 1000000007);
			v[s] = true;
		}
		long long tempL = stoll(tempRes);
		tempRes = to_string(tempL % 1000000007);
		cout << tempRes << '\n';
	}

	return 0;
}

