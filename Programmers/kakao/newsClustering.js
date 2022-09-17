function solution(str1, str2) {
  let answer = 0;
  
  const s1 = str1.toUpperCase();
  const s2 = str2.toUpperCase();
  
  let s1Arr = [], s2Arr=[];
  
  for(let i=0;i<s1.length-1;i++){
      const temp = s1.substring(i,i+2);
      s1Arr.push(temp);
  }
  
  for(let i=0;i<s2.length-1;i++){
      const temp = s2.substring(i,i+2);
      s2Arr.push(temp)
  }
  const reg = /^[A-Z]*$/;
  s1Arr = s1Arr.filter(e => {
      return reg.test(e)
  })
  s2Arr = s2Arr.filter(e => {
      return reg.test(e)
  })
  
  s1Arr.sort()
  s2Arr.sort()
  
  const all = new Set([...s1Arr,...s2Arr])
  
  let uni =0;
  let inter =0;
  all.forEach(e => {
      const a = s1Arr.filter(s1E => s1E===e).length;
      const b = s2Arr.filter(s2E => s2E===e).length;

      inter += Math.min(a,b);
  })
  uni = s1Arr.length + s2Arr.length-inter;
  if(!uni && !inter) return 65536;
  answer = Math.floor(inter/uni * 65536)
  
  return answer;
}