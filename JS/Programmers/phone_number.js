function solution(phone_number) {
    let answer = ""
    answer = phone_number.split("").map((number,index)=> {
        return(index < phone_number.length-4? '*' : number)
    }).join("")
    return answer;
}