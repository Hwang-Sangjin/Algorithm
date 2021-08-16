function solution(numbers, hand) {
    var answer = '';
    let n = numbers.length;
    let left = [3,0];
    let right = [3,2];
    
    for(let i=0;i<n;i++){
        console.log(left, right)
        let ni = Math.floor(numbers[i]/3);
        if(numbers[i] === 0) {
            ni = 3;
        }
        
        if(numbers[i] === 1 || numbers[i] === 4 || numbers[i] === 7){
            answer+='L';
            left = [ni , 0];
        }
        else if(numbers[i] === 3 || numbers[i] === 6 || numbers[i] === 9){
            answer+='R';
            right = [ni -1 , 2];
        }
        else{
            let ldist=0;
            let rdist=0;
            ldist = Math.abs(left[0] - ni) + Math.abs(left[1] - 1);
            rdist = Math.abs(right[0] - ni) + Math.abs(right[1] - 1);
            console.log(ldist, rdist)
            
            if(ldist === rdist){
                if(hand === 'left'){
                    answer+='L';
                    left = [ni , 1];
                }
                else{
                    answer+='R';
                    right = [ni  , 1];
                }
            }
            else if(ldist > rdist){
                answer+='R';
                right = [ni , 1];
            }
            else if(ldist < rdist){
                answer+='L';
                left = [ni , 1];
            }
        }
    }
    
    return answer;
}