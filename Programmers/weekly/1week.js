function solution(price, money, count) {
    var answer = 0;
    
    var total = 0;
    for(var i=1;i<=count;i++){
        total+=price*i;
    }
    answer = total - money;
    if(answer >= 0){
        return answer;
    }
    else{
        return 0;
    }
}