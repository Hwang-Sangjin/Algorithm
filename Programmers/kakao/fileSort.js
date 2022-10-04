function solution(files) {
  let answer = [];

  let res = [];

  files.map((e, index) => {
    const element = e.toUpperCase();

    const head = element.match(/^\D+/)[0];
    const number = Number(element.match(/\d+/)[0]);
    res.push([head, number, index]);
  });

  answer = res
    .sort((a, b) => {
      if (a[0] < b[0]) return -1;
      else if (a[0] > b[0]) return 1;
      else return a[1] - b[1];
    })
    .map((e) => {
      return files[e[2]];
    });

  return answer;
}
