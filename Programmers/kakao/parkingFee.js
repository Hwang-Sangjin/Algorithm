function solution(fees, records) {
  var answer = [];

  const res = new Map();
  const record = new Map();

  records.map((e) => {
    const [time, num, com] = e.split(" ");
    const [h, m] = time.split(":");

    if (com === "IN") {
      record.set(num, time);
    } else {
      let [th, tm] = record.get(num).split(":");
      let dis = (h - th) * 60 + (m - tm);
      if (res.get(num)) {
        res.set(num, res.get(num) + dis);
      } else {
        res.set(num, dis);
      }

      record.delete(num);
    }
  });

  for (let [key, value] of record.entries()) {
    let [h, m] = value.split(":");
    let th = 23;
    let tm = 59;
    let dis = (th - h) * 60 + (tm - m);

    if (res.get(key)) {
      res.set(key, res.get(key) + dis);
    } else {
      res.set(key, dis);
    }
  }

  let [normalTime, normalFee, min, fee] = fees;
  for (let [key, value] of res.entries()) {
    if (value <= normalTime) {
      answer.push([key, normalFee]);
    } else {
      answer.push([
        key,
        normalFee + Math.ceil((value - normalTime) / min) * fee,
      ]);
    }
  }
  answer.sort((a, b) => a[0] - b[0]);
  answer = answer.map((e) => {
    return e[1];
  });

  return answer;
}
