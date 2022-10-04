function solution(n, t, m, p) {
  let answer = "";

  let dic = {};

  for (let i = 0; i < 10; i++) {
    dic[i] = i;
  }
  for (let i = 0; i < 6; i++) {
    const temp = String.fromCharCode(65 + i);
    dic[temp] = 10 + i;
  }

  let res = "";
  for (let i = 0; i < t * m; i++) {
    const temp = i.toString(n).toUpperCase();
    res += temp;
  }

  let arr = [];
  for (let i = 0; i < t; i++) {
    arr.push(m * i + p - 1);
  }

  arr.map((e) => {
    answer += res[e];
  });

  return answer;
}
