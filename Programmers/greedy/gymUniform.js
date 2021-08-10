function solution(n, lost, reserve) {
    var answer = 0;
    let arr = [];
    for(let i=0;i<=n;i++){
        arr.push(1);
        if(reserve.includes(i)){
            arr[i]++;
        }
        if(lost.includes(i)){
            arr[i]--;
        }
    }
    
    for(let i=1;i<=n;i++){
        if(arr[i] == 0){
            if(i!=n && arr[i+1] ==2){
                arr[i]++;
                arr[i+1]--;
            }
            else if(i!=1 && arr[i-1] == 2){
                arr[i] ++;
                arr[i-1]--;
            }
        }
    }
    answer = n;
    for(let i=1;i<=n;i++){
        if(arr[i] == 0){
            answer--;
        }
    }
    
    return answer;
}