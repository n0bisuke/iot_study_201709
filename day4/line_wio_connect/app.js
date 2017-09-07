'use strict';

const WebSocket = require('ws');
const axios = require('axios');
const qs = require('querystring');
const BASE_URL = 'https://notify-api.line.me';
const PATH =  '/api/notify';
const LINE_TOKEN = `トークンを指定`; //ここにLINE Notifyのトークンを指定
const WIO_TOKEN = `トークンを指定`; //ここにWioNodeのトークンを指定
const MESSAGE = `不在通知があった模様です。`;
const ws = new WebSocket('wss://us.wio.seeed.io/v1/node/event');

const CONFIG = {
    baseURL: BASE_URL,
    url: PATH,
    method: 'post',
    headers: {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Authorization': `Bearer ${LINE_TOKEN}`
    },
    data: qs.stringify({message: MESSAGE})
};

ws.onopen = () => {
    ws.send(WIO_TOKEN);
    console.log(`WebSocket Connect`);
}

ws.onmessage = (evt) => {
    const msg = JSON.parse(evt.data).msg;
    if('input_rise' in msg){
        console.log(`------${evt.data}-反応あり------`);
        axios.request(CONFIG)
        .then((res) => console.log(`ステータス${res.status}、送信成功`))
        .catch((err) => console.log(err));
    }
}

