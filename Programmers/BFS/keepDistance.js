let place;

const di = [-1,0,1,0];
const dj = [0,1,0,-1];

function isCorona(level,i,j){
    let check = false;
    const v = Array.from(Array(5), _ => new Array(5).fill(false));
    let q =[];
    q.push([i,j,0]);
    v[i][j] = true;
    
    while(q.length){
        let t = q[0];
        let ti = t[0];
        let tj = t[1];
        let tcnt = t[2];
        //console.log(t);
        q.shift();
        
        for(let k=0;k<4;k++){
            let ni = ti + di[k];
            let nj = tj + dj[k];
            
            if(ni<0 || nj<0 || ni>=5 || nj>= 5 || v[ni][nj] || place[level][ni][nj] === 'X') continue;
            if(place[level][ni][nj] === 'P' && tcnt <2){
                console.log(ni,nj);
                check = true;
                break;
            }
            else if(place[level][ni][nj] === 'O' && tcnt< 2){
                q.push([ni,nj,tcnt+1]);
                v[ni][nj] = true;
            }
        }
        if(check) break;
    }
    
    if(check) return true;
    else return false
}

function solution(places) {
    var answer = [];
    let n = places.length;
    place = places;
    
    for(let k=0;k<n;k++){
        let check = false;
        for(let i=0;i<5;i++){
            for(let j=0;j<5;j++){
                if(places[k][i][j] === 'P'){
                    check = isCorona(k,i,j);
                    if(check){
                        console.log(k);
                        answer.push(0);
                        break;
                    }
                }
            }
            if(check){
                break;
            }
        }
        if(check === false){
            console.log(k);
            answer.push(1);
        }
    }
    
    return answer;
}