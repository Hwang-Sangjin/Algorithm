function solution(N, stages) {
  var answer = [];

  for (let i = 1; i <= N; i++) {
    let pass = stages.filter((x) => x >= i).length;

    let fail = stages.filter((x) => x === i).length;

    answer.push([i, fail / pass]);
  }

  answer = answer.sort((a, b) => b[1] - a[1]).map((e) => e[0]);

  return answer;
}
