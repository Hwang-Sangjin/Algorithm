#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
//1,000,000,000,000,000
using namespace std;
double n = numeric_limits<double>::max();

pair<double,double>point[1002][1002];


vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int,int>> v;
    double minx=n,miny=n, maxx=-n, maxy=-n;
    
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;j<line.size();j++){
            long long A,B,C,D,E,F;
            A = line[i][0];
            B = line[i][1];
            C = line[j][0];
            D = line[j][1];
            E = line[i][2];
            F = line[j][2];
            long long mod = A*D - B*C;
            if(mod==0) continue;
            
            long long xN = B*F -E*D;
            long long yN = E*C-A*F;
            if(fmod(xN,mod) || fmod(yN,mod)) continue;
            
            double x = xN/mod;
            double y = yN/mod;

            point[i][j] = point[j][i] = {x,y};
            v.push_back({i,j});
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
    }
    
    //cout<<minx<<' '<<miny<<' '<<maxx<<' '<<maxy<<'\n';
    
    double xleng = maxx - minx+1;
    double yleng = maxy - miny+1;
    //cout<<xleng<<' '<<yleng;
    
    for(int i=0;i<yleng;i++){
        string temp="";
        for(int j=0;j<xleng;j++){
            temp+='.';
        }
        answer.push_back(temp);
    }
    
    for(auto t: v){
        double x = point[t.first][t.second].first;
        double y = point[t.first][t.second].second;
        double newx = x - minx;
        double newy = maxy-y;
        //cout<<newx<<' '<<newy<<'\n';
        answer[newy][newx] = '*';
    }
    
    return answer;
}