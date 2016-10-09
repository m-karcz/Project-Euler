"use strict";
var max=0;
for(let x=100; x<1000; x++){
  for(let y=x; y<1000; y++){
    if(String(x*y)===String(x*y).split('').reverse().join('')){
      max=Math.max(String(x*y),max);
    }
  }
}
console.log(max);
