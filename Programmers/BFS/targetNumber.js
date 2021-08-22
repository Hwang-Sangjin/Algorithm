
function solution(numbers, target) {
    var answer = 0;
    
    function dfs(index, res){
        if(index === numbers.length){
            if(res === target){
                answer++;
            }
            return;
        }
        
        dfs(index+1, res + numbers[index]);
        dfs(index+1, res - numbers[index]);
    }
    
    dfs(0,0);
    
    
    
    return answer;
}