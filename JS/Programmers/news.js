function solution(str1, str2) {
    var answer = 0;
    const arr1 = []
    const arr2 = []

    const s1 = str1.toUpperCase();
    const s2 = str2.toUpperCase();
    
    function isAlpha(t){
        if(t>='A' && t<='Z'){
            return true;
        }
        return false;
    }
    
    for(let i=2;i<=s1.length;i++){
        const temp =s1.slice(i-2,i)
        if(isAlpha(temp[0]) && isAlpha(temp[1])){
            arr1.push(temp)
        }
    }
    for(let i=2;i<=s2.length;i++){
        const temp =s2.slice(i-2,i)
        if(isAlpha(temp[0]) && isAlpha(temp[1])){
            arr2.push(temp)
        }
       
    }
    
    arr1.sort()
    arr2.sort()
    
    let a=[]
    let b=[]
    
    for (var i = 0; i < arr2.length; i++) {
        if (arr1.indexOf(arr2[i]) >= 0) {
          a.push(arr1.splice(arr1.indexOf(arr2[i]), 1))
        }
        b.push(arr2[i])
    }
    
    arr1.map(e => {
        b.push(e)
    })
    console.log(a)
    console.log(b)
    
    if(b.length===0) answer = 65536
    else if(a.length===0) answer =0
    else{
        answer = Math.floor((a.length/b.length) * 65536)
    }
    
    
    
    return answer;
}