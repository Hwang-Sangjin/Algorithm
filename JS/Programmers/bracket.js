function check(s){
  let cnt = 0
  let res = true;
  s= s.split('')
  
  s.map(e => {
      if(e==='('){
          cnt++;
      }
      else{
          if(cnt<=0) res = false;
          cnt--;
      }
  })
  return res;
}

function recursive(s){
  if(s==='') return s
  
  let Lcnt=0, Rcnt=0
  let u='', w=''
  
  for(let i=0;i<s.length;i++){
      if(s[i]==='(') Lcnt++;
      else Rcnt++;
      
      if(Lcnt===Rcnt){
          u = s.slice(0,i+1);
          w = s.slice(i+1);
          break;
      }
  }
      
  if(check(u)) return u+ recursive(w)
  
  else{
      let temp ='(';
      temp+=recursive(w)+')';
      u = u.slice(1,u.length-1);
      for(let i=0;i<u.length;i++){
          if(u[i]==='(')   temp+=')';
          else temp+='(';
      }
      return temp;
  }
  
}

function solution(p) {
  var answer = '';
  if(p.length===0) return ''
  
  if(check(p)){
      return p;
  }
  else{
      answer = recursive(p)
  }
  
  
  return answer;
}