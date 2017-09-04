'use strict';

const THRESHOLD = 60; //閾値(合格ライン)
const point = 70; //変更して試してみよう
let message = ``;

if(point >= THRESHOLD){
    message = `合格`;
}else{
    message = `不合格`;
}

console.log(message);