function solution(n, arr1, arr2) {
  var answer = [];
  
  for(let i=0;i<arr1.length;i++){
      let temp = (arr1[i]| arr2[i]).toString(2).split('').map(e => {
          if(e==='0'){
              return ' '
          }
          else{
              return '#'
          }
      });
     
      while(temp.length <n){
          temp.unshift(' ')
      }
      answer.push(temp.join(''))
  }
  
  return answer;
}