'use strict';

const TOKEN = `トークンを指定`;
const URL = `http://cors-allow.azurewebsites.net/?url=https://us.wio.seeed.io/v1/node/GroveDigitalLightI2C0/lux?access_token=${TOKEN}`;
const $bulb = document.querySelector('.bulb');
const INTERVAL_TIME = 3000;

const addClass = (color) => {
    $bulb.style.background = color;
    $bulb.style.boxShadow = `0 -10px 100px ${color}`;
    $bulb.classList.add("light_up");
}

const removeClass = () => {
    $bulb.style.background = '#bbb';
    $bulb.style.boxShadow = '';
    $bulb.classList.remove("light_up");
}

const changeOpacity = async () => {
   const res = await axios.get(URL);
   const light = res.data.lux;
   let opacity = light / 1000;
   if(opacity == NaN) opacity = 0.9
   $bulb.style.opacity = opacity;
   if(opacity <= 0.5) {
       removeClass();
    }else{
        addClass(`red`);
    }
    
    return opacity;
}

setInterval(() => {
    console.log(`ping`);
    changeOpacity().catch((err) => console.log(err));
},INTERVAL_TIME);