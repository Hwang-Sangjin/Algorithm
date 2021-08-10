function solution(nums) {
    var answer = 0;
    let n = nums.length;
    
    //3000까지 소수들 구하기
    //brute force로 모든 경우의 수 다 구하기
    
    let sosu = Array.from({length: 3000}, () => false);
    
    sosu[1] = true;
    for(let i=2;i<= 3000; i++){
        for(let j = 2;j*i<=3000;j++){
            sosu[i*j] = true;
        }
    }
    
    for(let i=0;i<n-2;i++){
        for(let j=i+1;j<n-1;j++){
            for(let k = j+1;k<n;k++){
                let temp = nums[i] + nums[j] + nums[k];
                
                if(sosu[temp]) continue;
                else{
                    answer++;
                }
            }
        }
    }
    
    return answer;
}