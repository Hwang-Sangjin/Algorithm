function solution(n, m) {
    var answer = [];
    
    let min=1;
    let max = [];
    
    for(let i=1;i<=m;i++){
        (n%i===0 && m%i===0)? (max.push(i)): 0
    }
    answer.push(Math.max(...max))
    
    for(let i=1;i<=n*m;i++){
        if(i%n===0 && i%m===0) {
            min = i;
            break;
        }
    }
    answer.push(min)
    
    return answer;
}