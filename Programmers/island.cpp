#include <string>
#include <vector>
#include <iostream>

using namespace std;
int map[102][102];

int d[102];
bool v[102];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    int costsn = costs.size();
    
    int x,y,c;
    for(int i=0;i<costsn;i++){
        x = costs[i][0];
        y = costs[i][1];
        c = costs[i][2];
        map[x][y] = c;
        map[y][x] = c;
    }
    //프림, 크루스칼, 다익스트라

    v[0] = true;//0부터 출발
    int res=0;
    
    for(int i=0;i<n-1;i++){
        int min = -1;
        int index =-1;
        int previndex=-1;
        
        for(int j = 0;j<n;j++){
            if(v[j] == false) continue;
            else{
                for(int k=0;k<n;k++){
                    if(v[k] || map[j][k] == 0) continue;
                    if(min == -1 || map[j][k] < min){
                        min = map[j][k];
                        index = k;
                        previndex = j;
                    }
                }
            }
        }
        cout<<previndex<<' '<<index<<' '<<map[previndex][index]<<'\n';
        res +=map[previndex][index];
        v[index] = true;
    }
    
    
    
    return res;
}