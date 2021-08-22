let v = Array(202).fill(false)
let com;
let m;

function bfs(index){
    let q = [];
    
    q.push(index);
    v[index] = true;
    
    while(q.length){
        let t = q[0];
        q.shift();
        //console.log(t);
        
        for(let i=0;i<m;i++){
            if(v[i] || com[t][i] === 0) continue;
            
            q.push(i);
            v[i] = true;
        }
    }
}

function solution(n, computers) {
    var answer = 0;
    com = computers;
    m =n;
    
    for(let i=0;i<n;i++){
        if(v[i] === false){
            bfs(i);
            answer++;
        }
    }
    
    
    
    return answer;
}