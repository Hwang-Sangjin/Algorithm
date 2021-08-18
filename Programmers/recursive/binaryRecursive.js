var answer = [];
function binary(C){
    let t = [];
    
    while(true){
        if(C === 1) break;
        t.push(C%2);
        C= Math.floor(C/2);
    }
    t.push(1);
    
    t.reverse();
    return t.join('');
}

function go(s, level, zeroDelCnt){
    console.log(s,level, zeroDelCnt);
    if(s=== '1'){
        answer.push(level);
        answer.push(zeroDelCnt);
        return
    }
    
    let n = s.length;
    let temp =0;
    let temps="";
    for(let i=0;i<n;i++){
        if(s[i] === '0') zeroDelCnt++;
        else temp++;
    }
    temps = binary(temp);
    
    //console.log(temps);
    return go(temps,level+1,zeroDelCnt);
}

function solution(s) {
    
    
    go(s,0,0)
    
    return answer;
}