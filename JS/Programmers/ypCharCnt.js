function solution(s){
    var answer = true;

    let pCnt=0;
    let yCnt=0;
    
    s.split("").map(e => {
        if(e.toUpperCase()==='P'){
           pCnt++
        }
        else if(e.toUpperCase()==='Y'){
            yCnt++
        }
    });
    (pCnt===yCnt)? (answer = true) : (answer= false)
    
    return answer;
}