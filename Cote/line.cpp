#include <string>
#include <vector>
#include <iostream>

using namespace std;

string logFormat[4] = {"team_name : ","application_name : ", "error_level : ", "message : "};

bool check(string s){
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if((c>=65 &&c<=90) || (c>=97 && c<=122))continue;
        return false;
    }
    return true;
}

int solution(vector<string> logs) {
    int answer = 0;

    for(auto t: logs){
        string temp=t;
        string checkString="";
        int length = t.length();
        bool available= true;
        if(length>=100){
            available = false;
        }
        else{
            for(int k=0;k<4;k++){
                int flength = logFormat[k].length();
                        

                if(temp.substr(0,flength)==logFormat[k]){
                    temp = temp.substr(flength);
                    cout<<temp<<'\n';

                    for(int i=0;i<temp.length();i++){
                        if(temp[i]==' '){
                            checkString = temp.substr(0,i);
                            if(check(checkString)){
                                temp = temp.substr(i+1);
                                break;
                            }
                        else {
                            available = false;
                            break;
                        }
                    }
                }
                if(available == false){
                    break;
                        } 
                }
                else{
                    available = false;
                        break;
                    }
                }
        }
        if(check(temp) == false){
            available = false;
        }
       
        if(available == false){
            answer++;
            cout<<"!\n";
            continue;
        } 
        cout<<"?";
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;
set<char> se;
bool existChar[123];

char lowerC(char c){
    if(c>=65 && c<=90){
        return c+32;
    }
    return c;
}

int solution(vector<string> sentences, int n) {
    int answer = 0;

    for(auto t: sentences){
        for(int i=0;i<t.length();i++){
            if(t[i]!=' '){
                se.insert(lowerC(t[i]));
            }
        }
    }
    vector<char> arr;
    for(auto t: se){
        arr.push_back(t);
    }
    arr.push_back('!');

    vector<int> mask(arr.size(),0);
    for(int i=0;i<n;i++){
        mask[i] = 1;
    }
    sort(mask.begin(),mask.end());
    
    do{
        int tempScore=0;
        memset(existChar,false,sizeof(existChar));
        for(int i=0;i<mask.size();i++){
            if(mask[i]==1){

                existChar[arr[i]] = true;
            }
        }

        int senScore=0; 
        for(auto t: sentences){
            senScore=0;
            int l = t.length();
            bool available = true;
            for(int i=0;i<l;i++){
                if(t[i]==' '){
                    senScore++;
                    continue;
                }
                else if(t[i]>=65 && t[i]<=90){
                    if(existChar[33]==true){
                        if(existChar[lowerC(t[i])]){
                            senScore+=2;
                        }
                        else{
                            available= false;
                            break;
                        }
                    }
                    else{
                        available= false;
                        break;
                    }                
                }
                else if(t[i]>=97 && t[i]<=122){
                    if(existChar[t[i]]){
                        senScore++;
                    }
                    else{
                        available = false;
                        break;
                    }
                }
                else {
                    available = false;
                    break;
                }
            }
            if(available){
                tempScore +=senScore;
            }
            else{
                continue;
            }
        }
        // for(int i=97;i<=122;i++){
        //     if(existChar[i]){
        //         cout<<i<<' ';
        //     }
        // }
        answer = max(answer,tempScore);
        
    }while(next_permutation(mask.begin(),mask.end()));

    

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<vector<string>> v(102);
vector<vector<int>> group(12);
map<string,bool> officeT;
bool isOffice[102];

vector<int> solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
    vector<int> answer;

    for(int i=0;i<office_tasks.size();i++){
        officeT[office_tasks[i]] = true;
    }
    
    for(int index =0;index<employees.size();index++){
        vector<string> temp;
        string t=employees[index];
        int l = t.length();
        for(int i=0;i<l;i++){
            if(t[i]==' '){
                temp.push_back(t.substr(0,i));
                t= t.substr(i);
            }
        }
        temp.push_back(t);
        
        int tgroup = stoi(temp[0]);
        group[tgroup].push_back(index+1);
        for(int i=1;i<temp.size();i++){
            string twork = temp[i].substr(1);

            if(officeT[twork] == true){
                isOffice[index+1] = true;
            }
        }
    }

    for(int i=1;i<=num_teams;i++){
        bool oneOfThem = false;
        for(auto t: group[i]){
            if(isOffice[t]){
                oneOfThem = true;
                break;
            }
        }
        if(oneOfThem){
            for(auto t: group[i]){
                if(!isOffice[t]){
                    answer.push_back(t);
                }
            }
        }
        else{
            for(int j=1;j<group[i].size();j++){
                if(!isOffice[group[i][j]]){
                    answer.push_back(group[i][j]);
                }
            }
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
long long answer = 0;
vector<pair<long long, int>> m;

long long solution(vector<int> abilities, int k) {
    

    long long a=0;
    long long b=0;

    int length = abilities.size();
    if(length %2!=0){
        abilities.push_back(0);
        length++;
    }
    sort(abilities.begin(),abilities.end());

    for(int i=0;i<length/2;i++){
        long long ta = abilities[i*2];
        long long tb = abilities[i*2+1];
        m.push_back({tb-ta,i});
        a+=ta;
        b+=tb;
    }
    cout<<a<<' '<<b<<'\n';
    sort(m.begin(),m.end(),greater<>());
    for(int i=0;i<k;i++){
        a+=m[i].first;
    }
    answer = a;
    return answer;
}