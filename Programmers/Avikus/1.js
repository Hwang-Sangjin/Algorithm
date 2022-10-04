function solution(stats) {
  let answer = 0;

  let team = [];
  let index =0;

  stats.map(e => {
      let available = false;
      for(let i=0;i<index;i++){
          if(team[i]<=e){
              team[i] = e;
              available = true;
              break;
          }
      }

      if(available === false){
          team.push(e);
          index++;
      }

  })


  return team.length;
}