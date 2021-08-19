function solution(distance, rocks, n) {
    var answer = 0;
    rocks.push(distance);
    rocks.sort(function(a,b){
       return a-b;
    });
    
    let low = 1;
    let high = distance;
    
    
    while(low <=high){
        let mid = Math.floor((low + high)/2);
        console.log(mid);
        let removedRock = 0;
        let cur =0;
        let check = true;
        for(let i=0;i<rocks.length;i++){
            if(rocks[i]-cur>=mid){
                cur = rocks[i];
            }
            else{
                removedRock++;
            }
        }
        if(removedRock <=n){
            if(answer < mid) answer = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        
    }
    
    
    return answer;
}