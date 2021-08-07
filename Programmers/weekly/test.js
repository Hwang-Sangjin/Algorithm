function solution(answers) {
    var answer = [];
    let GiveupMath = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]];
    let correct = [];
    
    let n = answers.length;
    let biggest =0;
    for(let i=0;i<3;i++){
        let m = GiveupMath[i].length;
        let temp =0;
        for(let j=0;j<n;j++){
            let jj =j%m;
            //console.log(answers[j]);
            //console.log(GiveupMath[i][jj]);
            if(answers[j] === GiveupMath[i][jj]) temp++;
        }
        if(biggest < temp){
            biggest = temp;
        }
        correct.push(temp);
    }
    
    for(let i=0;i<3;i++){
        if(biggest === correct[i]){
            answer.push(i+1);
        }
    }
    
    return answer;
}