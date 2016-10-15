'use strict';
var digits=[];
for(let i=1; digits.length<1000000; i++){
  String(i).split('').forEach(function(digit){
    digits.push(Number(digit));
  })
}
var result=1;
for(let i=0; i<7; i++){
  result*=digits[Math.pow(10,i)-1];
}
console.log(result);
