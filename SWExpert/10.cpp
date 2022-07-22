#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N; cin>>N;
        
        int index ,left,right;
        char ch;
        int res=1;
        for(int i=1;i<=N;i++){
            cin>>index>>ch;
            
            if(index<=N/2){
            	if (i == N / 2 && N % 2 == 0) cin >> left;
               else cin >> left >> right;
                if(ch>='0' && ch<='9') {
                	res =0;
                }
            }
            else{
            	if (!(ch >= '0' && ch <= '9')) res = 0;
            }
            
        }
        cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}