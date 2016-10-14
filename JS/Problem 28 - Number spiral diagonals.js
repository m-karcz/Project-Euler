'use strict';
var sum=1, num=1;
for(let layer=1; layer<=500; layer++){
  for(let corner=0; corner<4; corner++){
    sum+=num+=layer*2;
  }
}
console.log(sum);
