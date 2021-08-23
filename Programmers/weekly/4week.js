//java javascript sql python c# c++ c kotlin php

let lang = ["JAVA", "JAVASCRIPT", "C", "C++" ,"C#" , "SQL", "PYTHON", "KOTLIN", "PHP"];
let job = ["SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"];
let compareTable = [];

function solution(table, languages, preference) {
    for(let i=0;i<5;i++){
        let t = table[i];
        t+=' ';
        let jobCheck = false;
        let temp ="";
        let tempArr =[];
        for(let j=0;j<t.length;j++){
            if(t[j]=== ' '){
                if(jobCheck=== false){
                    jobCheck = true;
                    temp ="";
                }
                else{
                    for(let k=0;k<9;k++){
                        if(lang[k] === temp){
                            tempArr.push(k);
                            break;
                        }
                    }
                    temp ="";
                }
            }
            else{
                temp+=t[j];
            }
        }
        compareTable.push(tempArr);
    }
    let langIndex=[];
    
    for(let i=0;i<languages.length;i++){
        for(let j=0;j<9;j++){
            if(languages[i] === lang[j]){
                langIndex.push(j);
                break;
            }
        }
    }
    console.log(compareTable);
    let answer = [0,0,0,0,0];
    
    for(let i=0;i<langIndex.length;i++){
        let index = langIndex[i];
        
        for(let j=0;j<5;j++){
            for(let k=0;k<5;k++){
                if(compareTable[j][k] === index){
                    answer[j] += (5-k) * preference[i];
                }
            }
        }
    }
    console.log(answer)
    let resIndex = [];
    let resCnt =0;
    for(let i=0;i<5;i++){
        if(resCnt < answer[i]){
            resIndex =[];
            resIndex.push(i);
            resCnt = answer[i];
        }
        else if(resCnt === answer[i]){
            resIndex.push(i);
        }
        
    }
    let s = [1,2,4,3,0];
    let final="";
    let finalArray = [];
    if(resIndex.length === 1){
        final = job[resIndex[0]];
    }
    
    else{
        for(let i=0;i<resIndex.length;i++){
            finalArray.push(job[resIndex[i]]);
        }
        finalArray.sort();
        final = finalArray[0];
    }
    
    
    return final;
}