function solution(N, stages) {
  var answer = [];
  let t =[]
  
  let map = new Map()
  
  stages.map(e => {
      (map.has(e)? (map.set(e,map.get(e)+1)) : (map.set(e,1)))
  })
  
  for(let i=1;i<=N+1;i++){
      if(!map.has(i)){
          map.set(i,0)
      }
  }
  for(let i=1;i<=N;i++){
      let temp = map.get(i)
      for(let j=i+1;j<=N+1;j++){
          temp+=map.get(j)
      }
      t.push([map.get(i)/temp,i])
  }
  
  t.sort(function(a,b){
      return b[0] - a[0]
  })
  t.map(e=> {
      answer.push(e[1])
  })
  
  return answer;
}