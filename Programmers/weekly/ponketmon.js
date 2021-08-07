function solution(nums) {
    let answer = [];
    let n = nums.length/2;
    
    for(let i=0;i<nums.length;i++){
        if(answer.length < n){
            if(answer.includes(nums[i])) continue;
            else{
                answer.push(nums[i]);
            }
        }
    }
    
    return answer.length;
}