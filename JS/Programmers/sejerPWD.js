function solution(s, n) {
    var answer = '';
    
    s.split("").map(e=> {
        if(e===' '){
            answer+=e;
        }
        else{
            let asc = e.charCodeAt();
            
            (e.toUpperCase().charCodeAt()+n > 90)? (answer+=String.fromCharCode(asc-26+n)): (answer+=String.fromCharCode(asc+n))
        }
    })
    
    return answer;
}