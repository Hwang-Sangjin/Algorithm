function solution(x) {
    var answer = true;
    let tempString ="";
    tempString+=x;
    let hashad = 0;
    tempString.split("").map(number => {
        hashad+=Number(number)
    })
    
    answer = (x%hashad===0? true: false)
    
    return answer;
}