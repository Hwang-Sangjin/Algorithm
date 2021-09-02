#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int map[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    //map
    int cnt=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            map[i][j] = cnt;
            cnt++;
        }
    }
    
    int T = queries.size();
    
    for(int tindex = 0;tindex<T;tindex++){
        int x1 = queries[tindex][0];
        int y1 = queries[tindex][1];
        int x2 = queries[tindex][2];
        int y2 = queries[tindex][3];
        
        //22 54
        //14 8 9 10 16 22 28 27 26 20 
        deque <int> q;
        int tempRes =-1;
        
        for(int j=0;j<=y2-y1;j++){
            q.push_back(map[x1][y1 + j]);
            if(tempRes ==-1 || tempRes > map[x1][y1 + j]) tempRes = map[x1][y1 + j];
        }
        for(int i=1;i<=x2-x1;i++){
            q.push_back(map[x1+i][y2]);
            if(tempRes > map[x1+i][y2]) tempRes = map[x1+i][y2];
        }
        for(int j=1;j<=y2-y1;j++){
            q.push_back(map[x2][y2 - j]);
            if(tempRes > map[x2][y2 - j]) tempRes = map[x2][y2 - j];
        }
        for(int i=1;i<x2-x1;i++){
            q.push_back(map[x2-i][y1]);
            if(tempRes > map[x2-i][y1]) tempRes = map[x2-i][y1];
        }
        
        int lastOne = q.back();
        q.pop_back();
        q.push_front(lastOne);
        
        answer.push_back(tempRes);
        
        for(int j=0;j<=y2-y1;j++){
            map[x1][y1 + j] = q.front();
            q.pop_front();
        }
        for(int i=1;i<=x2-x1;i++){
            map[x1+i][y2] = q.front();
            q.pop_front();
        }
        for(int j=1;j<=y2-y1;j++){
            map[x2][y2 - j] = q.front();
            q.pop_front();
        }
        for(int i=1;i<x2-x1;i++){
            map[x2-i][y1] = q.front();
            q.pop_front();
        }
        
        // for(int i=1;i<=rows;i++){
        //     for(int j=1;j<=columns;j++){
        //         cout<<map[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
    }
    
    return answer;
}