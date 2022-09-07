function isPrime(x) {
  if (x <= 1) return false;
  for (let i = 2; i <= Math.sqrt(x); i++) {
    if (x % i === 0) return false;
  }
  return true;
}

function solution(n, k) {
  let answer = 0;

  n = n.toString(k);

  answer = n.split(0).filter((e) => e != "" && isPrime(+e)).length;

  return answer;
}
