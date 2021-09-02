using namespace std;

//유클리드 호제법
long long gcd(long long a, long long b){
    long long c;
    
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long W = w;
    long long H = h;
    long long g = gcd(w,h);
    long long lw = W/g;
    long long lh = H/g;
    answer = W*H -g* (lw+lh -1);
    return answer;
}