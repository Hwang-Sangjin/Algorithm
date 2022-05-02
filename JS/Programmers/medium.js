function solution(arr) {
    var answer = 0;
    
    answer = arr.reduce((sum,cur)=> sum+cur)/arr.length
    return answer;
}