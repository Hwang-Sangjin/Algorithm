function solution(record) {
    var answer = [];
    
    const map = new Map()
    
    record.map(e => {
        const[com,uid,id] = e.split(' ')
        
        if(com==="Enter"){
            answer.push([uid,"님이 들어왔습니다."])
        }
        else if(com==="Leave"){
            answer.push([uid,"님이 나갔습니다."])
            return
        }
        map.set(uid,id)
    })
    
    

    return answer.map(e => map.get(e[0]) + e[1]);
}