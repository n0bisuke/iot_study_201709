'use strict';

const axios = require('axios');
const qs = require('querystring');
const BASE_URL = 'https://notify-api.line.me';
const PATH =  '/api/notify';
const LINE_TOKEN = `トークンを指定`; //ここにトークンを指定
const MESSAGE = `夏も終わりですね〜`;

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

axios.request(CONFIG)
.then((res) => console.log(`ステータス${res.status}、送信成功`))
.catch((err) => console.log(err));