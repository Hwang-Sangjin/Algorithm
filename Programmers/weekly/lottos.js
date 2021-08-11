function solution(lottos, win_nums) {
    var answer = [];
    
    let cnt = 0;
    let zerocnt =0;
    
    
    for(let i=0;i<6;i++){
        if(lottos.includes(win_nums[i])) cnt++;
        if(lottos[i] === 0) zerocnt++;
    }
    
    let arr =[];
    let mx = zerocnt + cnt;
    let mn = cnt;
    arr.push(mx);
    arr.push(mn);
    
    for(let i=0;i<2;i++){
        if(arr[i]===6){
            answer.push(1);
        }
        else if(arr[i]===5){
            answer.push(2);
        }
        else if(arr[i]===4){
            answer.push(3);
        }
        else if(arr[i]===3){
            answer.push(4);
        }
        else if(arr[i]===2){
            answer.push(5);
        }
        else {
            answer.push(6);
        }
    }
    

    
    return answer;
}