let m = new Map();

function recursive(str, temp, index, res){
    if(res===temp.length){
        if(!m.has(temp)){
            m.set(temp,1);
        }
        else{
            m.set(temp, m.get(temp)+1);
        }
        return;
    }
    for(let i=index;i<str.length;i++){
        let next=temp;
        next+=str[i];
        recursive(str, next, i+1,res);
    }
}

function solution(orders, course) {
    let answer = [];
    
    course.map(e => {
        m.clear();
        
        orders.map(o => {
            const sorted = o.split('').sort();
            recursive(sorted,"",0,e)
        })
        
        let sup=0;
            
        for(let [k,v] of m.entries()){
            sup = (sup > v)? sup: v;
        }
        for(let [k,v] of m.entries()){
            if(sup>=2 && v===sup) answer.push(k);
        }
    })
    answer.sort()
    
    return answer;
}