function solution(dartResult) {
  var answer = [];

  let table = {
    S: 1,
    D: 2,
    T: 3,
  };

  let darts = dartResult.match(/\d.?\D/g);

  darts.map((e) => {
    let split = e.match(/(^\d{1,})(S|D|T)(\*|#)?/);

    let temp = split[1] ** table[split[2]];

    if (split[3] === "*") {
      if (answer.length !== 0) {
        answer[answer.length - 1] *= 2;
      }
      temp *= 2;
      answer.push(temp);
    } else if (split[3] === "#") {
      temp *= -1;
      answer.push(temp);
    } else {
      answer.push(temp);
    }
  });
  let res = 0;
  answer.map((e) => {
    res += e;
  });

  return res;
}
