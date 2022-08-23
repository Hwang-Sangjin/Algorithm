function solution(board, moves) {
  var answer = 0;

  let tunnel = [];
  let n = board[0].length;

  moves.map((e) => {
    let row = e - 1;

    let pick = false;
    for (let i = 0; i < n; i++) {
      if (board[i][row]) {
        pick = true;
        //console.log(board[i][row], tunnel[tunnel.length-1])

        if (tunnel[tunnel.length - 1] === board[i][row]) {
          answer += 2;
          tunnel.pop();
        } else {
          tunnel.push(board[i][row]);
        }

        board[i][row] = 0;
        break;
      }
    }
  });

  //console.log(tunnel)

  return answer;
}
