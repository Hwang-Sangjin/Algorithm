let arr =[];
let alpha = ['A', 'E', 'I', 'O', 'U'];
let w;
var answer;

function go(index, str){
    console.log(str)
    if(index===5){
        return;
    }
    else{
        for(let i=0;i<5;i++){
            let temp = str + alpha[i];
            if(w === temp){
                answer = arr.length +1;
            }
            arr.push(temp);
            go(index+1,temp);
        }
    }
}

function solution(word) {
    answer = 0;
    w = word;
    
    let temp='';
    go(0,temp);
    
    return answer;
}