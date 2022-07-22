#include<iostream>
#include <vector>

using namespace std;

struct Node{
	bool isNum;
    int num;
    int left;
    int right;
};

vector<Node> tree(1002);

double postOrder(int index){
	if(tree[index].isNum) return (double) tree[index].num;
    
    double l = postOrder(tree[index].left);
    double r = postOrder(tree[index].right);
    
    if(tree[index].num=='+') return l+r;
    if(tree[index].num=='-') return l-r;
    if(tree[index].num=='*') return l*r;
    if(tree[index].num=='/') return l/r;
}


int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;cin>>N;
        int index, left, right;
        string s;
        
        for(int i=1;i<=N;i++){
            left=0;
            right=0;
            cin>>index;
            cin>>s;
            
            if(s[0]>='0' && s[0]<='9'){
                tree[index].isNum = true;
                tree[index].num = stoi(s);
            }
            else{
            	tree[index].isNum = false;
                tree[index].num = s[0];
                cin>>left>>right;
                tree[index].left = left;
                tree[index].right =right;
            }
        }
        
        cout << '#' << test_case << ' ' << postOrder(1)<< '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}