function solution(id_list, report, k) {
  var answer = [];

  let map = new Map();
  let set = new Set();
  report.map((e) => {
    set.add(e);
  });

  let reported = {};

  id_list.map((e) => {
    reported[e] = [];
  });

  set.forEach((e) => {
    let [user_id, reported_id] = e.split(" ");

    if (map.has(reported_id)) {
      map.set(reported_id, map.get(reported_id) + 1);
    } else {
      map.set(reported_id, 1);
    }
    reported[user_id].push(reported_id);
  });

  for (let e in reported) {
    let cnt = 0;
    reported[e].map((ee) => {
      if (map.get(ee) >= k) {
        cnt++;
      }
    });
    answer.push(cnt);
  }
  return answer;
}
