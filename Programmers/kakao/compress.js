function solution(msg) {
  var answer = [];

  let dic = {};

  for (let i = 0; i < 26; i++) {
    let t = String.fromCharCode("A".charCodeAt(0) + i);
    let tt = { [`${t}`]: i + 1 };
    Object.assign(dic, tt);
  }

  let num = 27;
  let index = 0;
  let continous = 1;
  let prev = "";
  let flag = false;
  while (index < msg.length) {
    let t = msg.substr(index, continous);
    if (t === prev) {
      answer.push(dic[prev]);
      break;
    }

    if (dic[t] === undefined) {
      Object.assign(dic, { [`${t}`]: num++ });
      answer.push(dic[prev]);
      index = index + continous - 1;
      continous = 1;
      prev = "";
    } else {
      continous++;
      prev = t;
    }
  }

  return answer;
}
