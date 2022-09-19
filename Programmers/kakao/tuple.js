function solution(s) {
  let answer = [];
  
  let temp = s.split('},{');
  
  temp[0] =temp[0].replace('{{','');
  temp[temp.length-1] = temp[temp.length-1].replace('}}','');
  
  temp = temp.map(e => {
      return e.split(',');
  })
  
  
  temp.sort((a,b) => a.length - b.length);
  console.log(temp)
  
  let v = Array(100001).fill(false);
  
  temp.map(arr => {
      for(let e of arr){
          if(v[e]===false){
              v[e] = true;
              answer.push(+e);
              break;
          }
          else{
              continue;
          }
      }
  })
  
  return answer;
}