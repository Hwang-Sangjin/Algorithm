let arr = new Array(3002).fill(true)

function isPrime(){
    arr[0] = false
    arr[1] = false
    for(let i=2;i<=3000;i++){
        for(let j=2;i*j<=3000;j++){
            arr[i*j] = false
        }
    }
}

function solution(nums) {
    var answer = 0;
    
    isPrime()
    let n = nums.length
    for(let i=0;i<n-2;i++){
        for(let j= i+1;j<n-1;j++){
            for(let k = j+1;k<n;k++){
                if(arr[nums[i]+nums[j]+nums[k]]){
                    answer++
                }
            }
        }
    }
    
    return answer;
}