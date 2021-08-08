function solution(absolutes, signs) {
    var answer = 0;
    
    let n = signs.length;
    
    for(let i=0;i<n;i++){
        if(signs[i]){
            answer+=absolutes[i];
        }
        else{
            answer-=absolutes[i];
        }
    }
    
    return answer;
}