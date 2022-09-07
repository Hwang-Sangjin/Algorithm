function solution(cacheSize, cities) {
  let answer = 0;

  let cache = [];

  if (cacheSize === 0) return 5 * cities.length;

  cities.map((e) => {
    e = e.toLowerCase();
    if (cache.includes(e)) {
      cache.splice(cache.indexOf(e), 1);
      console.log(cache);
      answer += 1;
    } else {
      answer += 5;
    }
    cache.push(e);
    if (cache.length > cacheSize) cache.shift();
  });

  return answer;
}
