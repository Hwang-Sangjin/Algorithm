function solution(s) {
    var answer = 0;
    let negative = false;
    (s[0] === '-')? (negative = true): (negative = false);
        
    (!negative)? (answer = Number(s)) : (answer = getNegative(s)) 
    return answer;
}

function getNegative(s){
    s = s.substr(1)
    return Number(s) * -1;
}