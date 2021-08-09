function grade(score){
    if(score >=90) return 'A';
    else if(score >=80) return 'B';
    else if(score >=70) return 'C';
    else if(score >=50) return 'D';
    else  return 'F';
}

function solution(scores) {
    var answer = [];
    
    let n = scores.length;
    
    for(let i=0;i<n;i++){
        let min =-1;
        let max = -1;
        let temp =0;
        let tempn = n;
        for(let j=0;j<n;j++){
            temp+=scores[j][i];
            if(min === -1 || min > scores[j][i ]) min = scores[j][i];
            if(max === -1 || max < scores[j][i]) max = scores[j][i];
        }
        if(min === scores[i][i] || max === scores[i][i]){
            let newarr =[];
            for(let k = 0;k<n;k++){
                if(k===i) continue;
                newarr.push(scores[k][i]);
            }
            if(!newarr.includes(scores[i][i])){
                console.log(i);
                temp-= scores[i][i];
                tempn--;
            }
        }
        answer += grade(temp/tempn);
    }
    
    return answer;
}