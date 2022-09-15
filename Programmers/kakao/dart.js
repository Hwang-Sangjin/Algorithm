function solution(dartResult) {
  let answer = 0;
  
  let res =[];
  const bonus = {'S':1, 'D':2, 'T':3};
  const options= {'#':-1, '*':2, undefined:1};
  
  let split = dartResult.split(/(10|[0-9])/).slice(1)
  
  for(let i=0;i<3;i++){
      const num = split[i*2];
      const b = split[i*2+1];
      
      res.push(Math.pow(num ,bonus[b[0]]) * options[b[1]]);
      if(b[1]==='*' && i!=0){
          res[i-1]*=2;
      }
  }
  answer = res.reduce((a,b) => a+b)
  
  return answer;
}