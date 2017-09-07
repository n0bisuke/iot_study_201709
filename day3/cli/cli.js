'use strict';

const TOKEN = `トークンを指定`;
const URL = `https://us.wio.seeed.io/v1/node/GroveDigitalLightI2C0/lux?access_token=${TOKEN}`;
const axios = require(`axios`);

axios.get(URL)
.then((res) => console.log(res.data))
.catch((err) => console.log(err.response.data));