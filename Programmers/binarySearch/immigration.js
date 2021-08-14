function solution(n, times) {
    var answer = -1;
    times.sort((a,b) => a-b);
    let left = 1;
    let right = n * times[times.length-1];
    
    while(left <= right){
        let mid = Math.floor((left+ right) /2);
        let count=0;
        
        times.forEach(value => {
            count += Math.floor(mid / value); // 한 사람당 몇명 할 수 있는지
            if(count >= n) {
                if(answer === -1){
                    answer = mid;
                }
                else{
                    answer = Math.min(mid, answer); // 최솟값
                }
                
                return;
            };
        });
        console.log(mid, count);
        if(count >= n){
            right = mid- 1;
        }
        else if(count < n){
            left = mid + 1;
        }
    }
    return answer;
}