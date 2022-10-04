function solution(total_sp, skills) {
  var answer = [];

  let skill= {}
  let arr = new Array(skills.length+2).fill(false)

  skills.map(e => {
      const up = e[0];
      const down = e[1];
      arr[up]= true;
      
      if(skill[down]===undefined){
          skill[down] = [];
      }
      skill[down].push(up);
  })
  
  let base = [];
  arr.map((e,index) => {
      if(index!==0 && !arr[index]) base.push(index)
  })

  let cnt = new Array(skills.length+2).fill(0);
  let v =  new Array(skills.length+2).fill(false);

  let q = [];
  base.map(e => {
      q.push(e);
      cnt[e]=1;
      v[e] = true;
  })

  while(q.length!==0){
      const e = q[0];
      q.shift();

      if(skill[e]=== undefined) continue;
      skill[e].map(ee => {
          cnt[ee]+=cnt[e];

          if(!v[ee]){
              q.push(ee);
              v[ee] =true;
          }
      })
  }
  
  let total = cnt.reduce((acc,rec) => {
      return acc+=rec
  })
  
  const per = total_sp/total;
  
  cnt.map((e,index) => {
      if(index !==0){
          answer.push(per*e)
      }
  })

  return answer;
}