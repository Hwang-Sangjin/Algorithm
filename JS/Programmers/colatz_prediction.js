function solution(num) {
    var answer = 0;
    
    while(num!=1 && answer < 500){
        (num%2===0 ? (num = num/2): (num = num*3 +1))
        answer++
    }
    answer===500? answer = -1: answer;
    
    return answer;
}