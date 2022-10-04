function solution(m, n, board) {
  var answer = 0;

  board = board.map((e) => e.split(""));

  while (true) {
    const arr = [];
    for (let i = 0; i < m - 1; i++) {
      for (let j = 0; j < n - 1; j++) {
        if (
          board[i][j] &&
          board[i][j] === board[i + 1][j] &&
          board[i][j] === board[i][j + 1] &&
          board[i][j] === board[i + 1][j + 1]
        ) {
          arr.push([i, j]);
        }
      }
    }

    if (arr.length === 0) {
      return [].concat(...board).filter((e) => e === 0).length;
    }

    for (let i = 0; i < arr.length; i++) {
      const col = arr[i][0];
      const row = arr[i][1];
      board[col][row] = 0;
      board[col][row + 1] = 0;
      board[col + 1][row] = 0;
      board[col + 1][row + 1] = 0;
    }

    for (let i = m - 1; i >= 0; i--) {
      for (let j = 0; j < n; j++) {
        if (board[i][j] === 0) {
          let ni = i - 1;
          while (true) {
            if (ni < 0) break;
            if (board[ni][j] === 0) ni--;
            else {
              board[i][j] = board[ni][j];
              board[ni][j] = 0;
              break;
            }
          }
        }
      }
    }
  }

  return answer;
}
