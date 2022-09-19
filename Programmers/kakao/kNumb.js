function isPrime(x) {
  if (x <= 1) return false;

  for (let i = 2; i <= Math.floor(Math.sqrt(x)); i++) {
    if (x % i === 0) return false;
  }
  return true;
}

function solution(n, k) {
  let answer = 0;

  const arr = n.toString(k).split(0);

  answer = arr.filter((e) => {
    if (isPrime(e)) return e;
  }).length;

  return answer;
}
