function solution(numbers) {
  var answer = [];
  
  numbers.map((e,index) => {
      for(let i=index+1;i<numbers.length;i++){
          answer.push(e+numbers[i])
      } 
  })
  answer = [...new Set(answer)]
  answer.sort((a,b) => a-b)
  
  return answer;
}