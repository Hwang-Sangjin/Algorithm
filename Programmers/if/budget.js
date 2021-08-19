function solution(d, budget) {
    var answer = 0;
    
    
    d.sort(function(a, b) {
        return a - b;
    });
    
    let n = d.length;
    let sum=0;
    for(let i=0;i<n;i++){
        answer++;
        sum+=d[i];
        if(sum > budget){
            answer--;
            break;
        }
    }
    
    return answer;
}