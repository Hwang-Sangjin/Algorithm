function solution(s) {
    var answer = s.length;
    
    for(let i=1;i<=parseInt(s.length/2);i++){
        let prev = s.substr(0,i)
        let cnt = 1;
        let tempStr = ''
        
        for(let k=i;k<s.length;k+=i){
            const cur = s.substr(k,i)

            if(prev === cur) cnt++
            
            else{
                tempStr +=(cnt>1? String(cnt): '') + prev
                cnt=1
                prev = cur
            }
        }
        tempStr += (cnt>1? String(cnt): '') + prev

        answer = Math.min(answer,tempStr.length)
    }
    
    return answer;
}