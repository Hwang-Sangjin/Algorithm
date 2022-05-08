function solution(salaries, days){
    var answer = 0;

    salaries.map(e => {
        let cnt=0;
        (days%e===0) ? (cnt = days/e[0]) : (cnt = Math.floor(days/e[0]) + 1)

        answer+=cnt*e[1]
    })

    return answer
}

function solutions(scores) {
    var answer = []
    let fsum =0
    let ssum =0

    scores.map((e,index) => {
        scores[index].push(index)
        fsum+=e[0]
        ssum+=e[1]
    })

    scores.sort(function(a,b) {
        let asum = a[0] + a[1]
        let bsum = b[0] + b[1]

        if(asum > bsum) return -1
        else if(asum < bsum) return 1
        else{
            if(fsum< ssum){
                if(a[0] > b[0]) return -1
                else if(a[0] < b[0]) return 1
                else {
                    if(a[2] < b[2]) return -1
                    else return 1
                }
            }
            else if(fsum> ssum) {
                if(a[1] > b[1]) return -1
                else if(a[1] < b[1]) return 1
                else{
                    if(a[2] < b[2]) return -1
                    else return 1
                }
            }
            else{
                return a[2] - b[2]
            }
        }
    })

    scores.map((e,index) => {
        scores[index].push(index+1)
    })

    scores.sort(function(a,b){
        return a[2]-b[2]
    })

    scores.map(e =>{
        answer.push(e[3])
    })

    return answer;
}


//3

let di = [-1,0,1,0]
let dj = [0,1,0,-1]

let v=[]
let n
let b
let group = new Array(2500)

function bfs(i,j,cnt){
    let q = []
    q.push([i,j])
    v[i][j] = cnt
    group[cnt].push([i,j])
    let ch = b[i][j]

    while(!(q.length ===0)){
        let t= q.shift()
        let ti = t[0]
        let tj = t[1]

        for(let k=0;k<4;k++){
            let ni = ti + di[k]
            let nj = tj + dj[k]

            if(ni<0 || nj<0 || ni>=n || nj>=n || v[ni][nj]!==-1) continue
            if(ch === b[ni][nj]){
                q.push([ni,nj])
                v[ni][nj] = cnt
                group[cnt].push([ni,nj])
            }
        }
    }
}

function solution(board){
    var answer =0
    n = board.length
    b = board
    
    for(let i=0;i<n;i++){
        v.push(new Array(n))
        v[i].fill(-1)
    }
    let cnt=0

    for(let i=0;i<n;i++){
        for(let j=0;j<n;j++){
            if(v[i][j]===-1){
                group[cnt] = []
                bfs(i,j,cnt)
                cnt++
            }
        }
    }

    let d = new Array(cnt+1)

    let temp

    for(let i=0;i<n;i++){
        d.fill(false)
        temp =0

        for(let j=0;j<n;j++){
            d[v[i][j]] = true
        }
        d.map((e,index) => {
            if(e){
                temp+=group[index].length
            }
        })
        answer = Math.max(answer,temp)
    }

    
    for(let j=0;j<n;j++){
        d.fill(false)
        temp =0

        for(let i=0;i<n;i++){
            d[v[i][j]] = true
        }
        d.map((e,index) => {
            if(e){
                temp+=group[index].length
            }
        })
        answer = Math.max(answer,temp)
    }

    return answer;
}