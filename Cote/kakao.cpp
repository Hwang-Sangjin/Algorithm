#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

char arr[8] = {'R','T','F','C','M', 'J', 'A','N'};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    map<char,int> m;
    for(int i=0;i<8;i++){
        m[arr[i]]=0;
    }

    int n = survey.size();
    
    for(int i=0;i<n;i++){
        char a = survey[i][0];
        char b = survey[i][1];
        int anum=0;
        int bnum=0;
        if(choices[i]>4){
            bnum = choices[i]-4;
        }
        else if(choices[i]<4){
            anum = 4-choices[i];
        }
        m[a] +=anum;
        m[b] +=bnum;
    }



    for(int i=0;i<4;i++){
        int f = m[arr[i*2]];
        int s = m[arr[i*2+1]];

        if(f==s){
            if(arr[i*2] < arr[i*2+1]){
                answer+=arr[i*2];
            }
            else{
                answer+=arr[i*2+1];
            }
        }
        else if(f>s){
            answer+=arr[i*2];
        }
        else{
            answer+=arr[i*2+1]; 
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;



int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int fs=0, fl = queue1.size();
    int ss=0, sl = queue2.size();

    long long f =0;
    long long s =0;
    long long total =0;
    for(int i=0;i<fl;i++){
        f+=queue1[i];
        total+=queue1[i];
        s+=queue2[i];
        total+=queue2[i];
    }

    long long target = total/2;
    if(total%2==1){
        return -1;
    }

    while(true){
        

        //cout<<f<<' '<<s<<'\n';

        if(f==s) break;
        else if(f> s){
            int t = queue1[fs];
            fs++;
            queue2.push_back(t);
            sl++;
            f-=t;
            s+=t;
        }
        else if(s> f){
            int t= queue2[ss];
            ss++;
            queue1.push_back(t);
            fl++;
            s-=t;
            f+=t;
        }
        answer++;
        if(answer>300000) break;
    }
    if(answer>300000){
        answer = -1;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> R(vector<vector<int>> rc ,int row){
    queue<int> q;
    vector<pair<int,int>> pos;
    int r = rc.size();
    int c = rc[0].size();
    int total = r*2 + (c-2)*2;
    row = row %total;
    if(row ==0) return rc;

    for(int i=0;i<row;i++){
        q.push(-1);
    }
    for(int i=0;i<c;i++){
        q.push(rc[0][i]);
        pos.push_back({0,i});
    }
    for(int i=1;i<r;i++){
        q.push(rc[i][c-1]);
        pos.push_back({i,c-1});
    }
    for(int i=c-2;i>=0;i--){
        q.push(rc[r-1][i]);
        pos.push_back({r-1,i});
    }
    for(int i=r-2;i>=1;i--){
        q.push(rc[i][0]);
        pos.push_back({i,0});
    }

    int index=0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        rc[pos[index%total].first][pos[index%total].second] = t;
        index++;
    }



    return rc;
}

vector<vector<int>> S(vector<vector<int>> rc , int row){
    queue<vector<int>> q;
    int r = rc.size();
    int c = rc[0].size();
    row = row%r;
    if(row == 0) return rc;
    vector<int> temp;

    for(int i=0;i<row;i++){
        q.push(temp);
    }
    for(int i=0;i<r;i++){
        q.push(rc[i]);
    }

    int index=0;
    while(!q.empty()){
        auto t= q.front();
        q.pop();
        rc[index%r] = t;
        index++; 
    }
    


    return rc;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    operations.push_back("X");
    string prev=operations[0];
    int row = 1;
    for(int i=1;i<operations.size();i++){
        auto t = operations[i];
        if(prev == t){
            row++;
        }
        else{
            if(prev== "ShiftRow"){
                rc = S(rc,row);
                prev = "Rotate";
                row = 1;
            }
            else{
                rc = R(rc,row);
                prev = "ShiftRow";
                row = 1;
            }
        }
    }

    return rc;
}