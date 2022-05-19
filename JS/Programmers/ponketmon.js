function solution(nums) {
  let answer = [];
  
  const n = nums.length/2
  
  const temp = [...new Set(nums)].length
    
  
  return (n < temp)? n : temp;
}