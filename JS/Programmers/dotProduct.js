function solution(a, b) {
  var answer = 0;
  
  a.map( (e,index) => {
      answer+=e*b[index]
  })
  
  return answer;
}