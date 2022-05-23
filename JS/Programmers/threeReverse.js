function solution(n) {
  var answer = 0;

  let temp =[]
  
  while(n!==0){
      temp.push(n%3)
      n = Math.floor(n/3)
  }
  temp= temp.reverse()
  
  temp.map((e,index) => {
      answer+=e*3**index
  })
  
  
  return answer;
}