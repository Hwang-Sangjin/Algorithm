function solution(cacheSize, cities) {
  let answer = 0;
  const HIT = 1, MISS = 5;
  
  if(cacheSize === 0) return MISS * cities.length;
  
  let cache = []
  
  cities.map(e => {
      e = e.toLowerCase();
      
      const idx = cache.indexOf(e);
      
      if(idx === -1){
          if(cache.length === cacheSize) cache.shift();
          answer+=MISS;
      }
      else{
          cache.splice(idx,1)
          answer+=HIT;
      }
      cache.push(e)
  })
  
  return answer;
}