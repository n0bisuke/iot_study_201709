'use strict';

/**
 * 九九表
 */

const MAX = 9;
let table = ``;

for(let i = 1; i <= MAX; i++){
    for(let j = 1; j <= MAX; j++){
        table += `${i*j} `;
    }
    table += `\n`;
}

console.log(table);
