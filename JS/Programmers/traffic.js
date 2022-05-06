function solution(lines) {
    var answer = 0;
    let arr = []
    const logPointArr = []
    
    lines.slice(", ").map( line => {
        const [date,time,sec] = line.split(" ")
        const [h,m,s] = time.split(":")
        const duration = sec.substring(0,sec.length-1)
        
        const edSec = Number(h)*3600 + Number(m)*60 + Number(s)
        const stSec = edSec - Number(duration) + 0.001
        
        arr.push([stSec,edSec])
        logPointArr.push(stSec,edSec)
    })
    
    logPointArr.sort();
    
    for(let i=0; i<logPointArr.length;i++){
        const beginRage = logPointArr[i]
        const endRange = logPointArr[i] + 1;
        let count = 0;
        
        for (let j = 0; j < arr.length; j++) {
          const stPoint = arr[j][0];
          const edPoint = arr[j][1];

          if (
            (stPoint >= beginRage && stPoint < endRange) ||
            (edPoint >= beginRage && edPoint < endRange) ||
            (stPoint <= beginRage && edPoint >= endRange)
          ) {
            count++;
          }
        }

        if (count > answer) {
          answer = count;
        }
    }

    return answer;
}