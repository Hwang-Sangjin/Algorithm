function solution(array, commands) {
    var answer = [];
    
    let n = commands.length;
    
    for(let i=0;i<n;i++){
        let si,sj,sk;
        si = commands[i][0];
        sj = commands[i][1];
        sk = commands[i][2];
        let newarr = array.slice(si-1,sj);
        newarr.sort((a,b)=> a - b);
        answer.push(newarr[sk-1]);
    }
    
    return answer;
}