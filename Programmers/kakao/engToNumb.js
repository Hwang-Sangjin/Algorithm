function solution(s) {
  var answer = 0;

  let arr = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];

  arr.map((e, index) => {
    s = s.split(e).join(index);
    console.log(s);
  });
  answer = parseInt(s);

  return answer;
}
