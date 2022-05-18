let nn

function bin(t){
    let temp = []
    
    for(let i = nn-1;i>=0;i--){
        let j = 2**i
        if(t>= j){
            temp.push(1)
            t-=j
        }
        else{
            temp.push(0)
        }
    }
    return temp
}

function solution(n, arr1, arr2) {
    var answer = [];
    nn =n;
    const temp1 = [];
    arr1.map(e => {
        temp1.push(bin(e))
    })
    
    const temp2 = []
    arr2.map(e => {
        temp2.push(bin(e))
    })
    
    for(let i=0;i<n;i++){
        let temp =""
        for(let j=0;j<n;j++){
            if(temp1[i][j] || temp2[i][j]){
                temp+='#'
            }
            else{
                temp+=' '
            }
        }
        answer.push(temp)
    }
    
    return answer;
}