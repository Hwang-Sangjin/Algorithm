#include <string>
#include <iostream>
#include <map>
using namespace std;

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
int ci=10, cj=10;
int ni,nj;
int m[22][22];

map<char,int> com;


int solution(string dirs) {
    int answer = 0;
    com['U'] = 0;
    com['R'] = 1;
    com['D'] = 2;
    com['L'] = 3;
    
    for(int i=0;i<dirs.length();i++){
        
        /*for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                cout<<m[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';*/
        
        int temp = com[dirs[i]];
        ni = ci + di[temp];
        nj = cj + dj[temp];
        if(ni<0 || nj<0 || ni>20 ||nj>20) continue;
        if(m[ni][nj]==0){
            m[ni][nj] = 1;
            answer++;
        }
        ci = ni;
        cj = nj;
        
        ni = ci + di[temp];
        nj = cj + dj[temp];
        if(ni<0 || nj<0 || ni>20 ||nj>20) continue;
        if(m[ni][nj]==0){
            m[ni][nj] = 1;
            //answer++;
        }
        ci = ni;
        cj = nj;
    }
    return answer;
}