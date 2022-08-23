function solution(n, arr1, arr2) {
  var answer = [];

  for (let i = 0; i < n; i++) {
    let t = arr1[i] | arr2[i];

    let arr = [];

    for (let j = n - 1; j >= 0; j--) {
      if (t >= 2 ** j) {
        arr.push("#");
        t -= 2 ** j;
      } else {
        arr.push(" ");
      }
    }
    answer.push(arr.join(""));
  }

  return answer;
}
