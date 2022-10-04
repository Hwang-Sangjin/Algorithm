function solution(s) {
  let answer = 0;

  let isUp = (s[0] < s[1]) ? true : false;
  let first = isUp;
  let group=1;

  for(let i=0;i<s.length-1;i++){
      const a = s[i];
      const b = s[i+1];

      if(isUp){
          if(a >= b) {
              group++;
          }
          else{
              isUp = !isUp;
          }
      }
      else{
          if(a<=b) {
              group++;
          }
          else{
              isUp = !isUp;
          }
      }

  }

  answer = group-1 + !first;

  return answer;
}