'use strict';

const THRESHOLD_A = 80; //閾値(成績 優)
const THRESHOLD_B = 70; //閾値(成績 良)
const THRESHOLD_C = 60; //閾値(成績 可)

const point = 60; //変更して試してみよう
let message = ``;

if(point >= THRESHOLD_A){
    message = `優`;
}else if(point >= THRESHOLD_B && point < THRESHOLD_A){
    message = `良`;
}else if(point >= THRESHOLD_C && point < THRESHOLD_B){
    message = `可`;
}else if(point < THRESHOLD_C){
    message = `不可`;
}

console.log(`あなたの成績は${message}です。`);