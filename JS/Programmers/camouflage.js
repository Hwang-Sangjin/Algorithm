function solution(clothes) {
    var answer = 1;
    
    const map = new Map()
    
    clothes.map(e => {
        const name = e[0]
        const kind = e[1]
        
        if(map.has(kind)){
            let temp = map.get(kind)
            map.set(kind,temp+1)
        }
        else{
            map.set(kind,1)
        }

    })
    
    for(let t of map.values()){

        answer*=t+1
    }
    
    return answer-1;
}