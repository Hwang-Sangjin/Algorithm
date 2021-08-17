function solution(board, moves) {
    var answer = 0;
    let st = [];
    let n = board.length;
    let m = moves.length;
    
    for(let i=0;i<m;i++){
        let t = moves[i]-1;
        let pick =0;
        for(let j=0;j<n;j++){
            if(board[j][t] !==0){
                pick = board[j][t];
                board[j][t] = 0;
                break;
            }
        }
        
        if(st[st.length-1] === pick){
            answer+=2;
            st.pop();
        }
        else if(pick !==0){
            st.push(pick)
        }
        
        //console.log(st)
    }
    
    return answer;
}