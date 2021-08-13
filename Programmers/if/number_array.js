function solution(s) {
    var answer = "";
    let n = s.length;
    
    for(let i=0;i<n;i++){
        if(s[i] >=0 && s[i] <=9){
            answer+=s[i];
        }
        else if(s[i] === 'z'){
            answer+=0;
            i+=3;
        }
        else if(s[i] === 'o'){
            answer+=1;
            i+=2;
        }
        else if(s[i] === 't'){
            if(s[i + 1] === 'w'){
                answer+=2;
                i+=2;
            }
            else{
                answer+=3;
                i+=4;
            }
        }
        else if(s[i] === 'f'){
            if(s[i + 1] === 'o'){
                answer+=4;
                i+=3;
            }
            else{
                answer+=5;
                i+=3;
            }
        }
        else if(s[i] === 's'){
            if(s[i + 1] === 'i'){
                answer+=6;
                i+=2;
            }
            else{
                answer+=7;
                i+=4;
            }
        }
        else if(s[i] === 'e'){
            answer+=8;
            i+=4;
        }
        else if(s[i] === 'n'){
            answer+=9;
            i+=3;
        }
    }
    answer = Number(answer)
    return answer;
}