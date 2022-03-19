#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

bool v[102];
map<string,int> m;

vector<string> solution(vector<string> goods) {
    vector<string> answer(goods.size());

    int checkLength = 1;
    while(1){
        m.clear();
        vector<vector<string>> word;
        if(checkLength>20)break;

        for(auto t: goods){
            int tlength = t.length();
            
            vector<string>tword;
            string temp;
            for(int i=0;i<tlength-checkLength+1;i++){
                temp = t.substr(i,checkLength);
                if(temp=="")break;
                tword.push_back(temp);
                m[temp]++;
            }
            word.push_back(tword);
        }

        for(int i=0;i<goods.size();i++){
            if(word[i].empty() || v[i]) continue;
            set<string> tanswer;
            for(auto t: word[i]){
                if(m[t]==1){
                    tanswer.insert(t);
                }
                else{
                    string s = goods[i];
                    map<string,int> checkSelf;
                    string cstemp;
                    for(int j=0;j<s.length()-checkLength+1;j++){
                        cstemp= s.substr(j,checkLength);
                        if(cstemp=="")break;
                        checkSelf[cstemp]++;
                    }
                    if(checkSelf[t] == m[t]){
                        tanswer.insert(t);
                    }
                }
            }

            if(tanswer.size()!=0){
                string ta="";
                for(auto t: tanswer){
                    ta+=" ";
                    ta+=t;
                }
                answer[i]= ta.substr(1);
                v[i] = true;
            }
        }

        checkLength++;
    }
    for(int i=0;i<answer.size();i++){
        if(!v[i]){
            answer[i] = "None";
        }
    }

    return answer;
}