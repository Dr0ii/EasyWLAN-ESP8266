/*
 *  index.h
 *
 *  创建日期: 2022/10/23
 *  作者: Dr0ii
 *
 *  说明：此文件为页面代码，已压缩
 *
 */


#ifndef INDEX_H
#define INDEX_H

String configPage = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible'content='IE=edge'><meta name='viewport'content='width=device-width, initial-scale=1.0'><title>EasyWLAN-配网</title></head><style>*{margin:0;padding:0;font-family:'Microsoft YaHei',微软雅黑;color:#2f3035;user-select:none;-webkit-user-select:none;appearance:none;-webkit-appearance:none}body,html{width:100%;height:100%;overflow:hidden;background:#eff1f5}#body,.body-info,.con,.tips,.typingbox{display:flex;align-items:center;flex-direction:column}.data,.data-dbm{display:flex;align-items:center}body,.body-head,.body-reload>span,.data-lock,#loading,.loading,#typing{display:flex;align-items:center;justify-content:center}hr,button,input{border:0;outline:none}input{-webkit-user-select:auto!important;user-select:auto!important}button{width:85%;height:60px;background:#6181ff;color:#ffffff;font-size:17px;font-weight:bolder;border-radius:10px;margin-top:10px}button:active{background:#d6dbe9}button,.body-reload,.data,.typingbox>input{box-shadow:0px 5px 10px#e4e4e4}.body-reload,.body-reload>span,.body-reload>span>hr:first-of-type,.body-reload>span>hr:last-of-type,.data-dbm>hr,.data-lock>hr:first-of-type::after,.loading-icon>hr,.loading-icon,.con-icon>hr{border-radius:100%}#body,#loading,.loading,.con,.tips,#typing{transition:all.3s;position:absolute;transform:scale(0.001)}::-webkit-scrollbar{width:10px}::-webkit-scrollbar-thumb{background:#d6dbe9;border-radius:10px}::placeholder{color:#dee0e4}#body{width:430px;height:90%;background:#eff1f5;position:relative;overflow:hidden;transform:scale(1)}.body-head{width:100%;padding:20px;margin-top:5px}.body-info{width:100%;height:100%;overflow-x:hidden}.data:first-of-type{margin-top:10px}.data:last-of-type{margin-bottom:10px}.data{width:85%;background:#ffffff;border-radius:10px;position:relative;margin-bottom:10px}.data>p{font-size:17px;font-weight:bolder;margin-left:2px;padding:13px}.data-lock{position:absolute;right:15px;transform:scale(.9);z-index:1;background:#ffffff}.data-lock>hr{width:18px;height:15px;background:#6181ff}.data-lock>hr:first-of-type{border-radius:5px}.data-lock>hr:first-of-type::before{content:'';width:13px;height:10px;position:absolute;top:-3px;left:50%;transform:translate(-50%,0);background:#6181ff;border-radius:5px}.data-lock>hr:first-of-type::after{content:'';width:3px;height:3px;background:#ffffff;position:absolute;top:0px;left:50%;transform:translate(-50%,0)}.data-dbm{position:absolute;right:35px;background:#ffffff;padding:10px}.data-dbm>hr:first-of-type{margin-left:0}.data-dbm>hr{width:9px;height:9px;background:#6181ff;margin-left:5px}.logo{margin:20px;color:#bdc4d4;z-index:1}#loading{width:100%;height:100%;background:#ffffff;z-index:5;visibility:hidden;opacity:0;transform:scale(1)}.loading{flex-direction:column}.loading-icon{width:70px;height:70px;background:#6181ff;margin-bottom:30px}.loading-icon>hr{width:26px;height:26px;background:#c1ceff}@-webkit-keyframes loadingbox{0%{transform:rotate(0deg)}50%{transform:rotate(180deg)}100%{transform:rotate(360deg)}}.loading-text,.tips-text{font-size:17px;font-weight:bolder;color:#adb4c7}.con-icon{display:flex;margin-bottom:40px}.con-icon>hr{width:28px;height:28px;background:#6181ff;margin:0px 4px;position:relative;animation:2.2s conbox infinite}.con-icon>hr:nth-of-type(2){animation-delay:.3s}.con-icon>hr:nth-of-type(3){animation-delay:.6s}.con-icon>hr:nth-of-type(4){animation-delay:.9s}@-webkit-keyframes conbox{50%{top:0px;opacity:0;background:#c1ceff;transform:scale(.5)}}.tips-icon{display:flex;margin-bottom:40px;font-weight:bolder;transform:scale(1.5)}.tips-icon-yes::before{content:'';width:8px;height:20px;position:absolute;background:#6181ff;border-radius:10px;transform:rotate(-45deg)translate(-8px,-3px)}.tips-icon-yes::after{content:'';width:8px;height:40px;position:absolute;border-radius:10px;transform:rotate(45deg)translate(-4px,-15px);background:#6181ff}.tips-icon-no::before{content:'';width:8px;height:40px;position:absolute;top:-15px;left:-3px;background:#ff6b61;border-radius:10px;transform:rotate(-45deg)}.tips-icon-no::after{content:'';width:8px;height:40px;position:absolute;top:-15px;left:-3px;border-radius:10px;transform:rotate(45deg);background:#ff6b61}.tips-text{margin-top:20px}#typing{width:100%;height:100%;z-index:3;background:#eff1f5;visibility:hidden;opacity:0}.typingbox{width:340px;position:relative;top:-40px}.typingbox>input{width:100%;padding:13px;margin:10px;border-radius:10px;font-size:17px;font-weight:bolder}.typingbox>input:first-of-type{margin-top:0}.okey{background:#6181ff;color:#ffffff}.okey:active{background:#d6dbe9}.cancle{background:#bdc4d4;color:#ffffff}.cancle:active{background:#d6dbe9;color:#ffffff}.reload{height:60px}</style><script>init=()=>{document.addEventListener('touchstart',function(){});body=document.querySelector('#body');list=document.querySelector('.body-info');reload=document.querySelector('.reload');messagebox=document.querySelector('#loading');loading=document.querySelector('.loading');loadingicon=document.querySelector('.loading-icon');con=document.querySelector('.con');tips=document.querySelector('.tips');tipsicon_yes=document.querySelector('.tips-icon-yes');tipsicon_no=document.querySelector('.tips-icon-no');tipstext=document.querySelector('.tips-text');typing=document.querySelector('#typing');typingbox=document.querySelector('.typingbox');ssidbox=document.querySelector('.ssid');pwdbox=document.querySelector('.pwd');okey=document.querySelector('.okey');cancle=document.querySelector('.cancle');istyping=false;pwdboxsta=false};window.onload=()=>{init();handle();resize();getdata()};window.onresize=()=>resize();resize=()=>{X=document.body.scrollWidth;if(X>430){ss(typingbox,'width: 330px;');ss(body,null)}else{ss(body,'width: 100%;height:100%');ss(typingbox,'width: 77%;')};ss(okey,`width:${pwdbox.clientWidth}px`);ss(cancle,`width:${pwdbox.clientWidth}px`);console.log()};handle=()=>{list.onmousemove=()=>{for(i=0;i<list.children.length;i++){list.children[i].onclick=function(){ssidbox.value=this.children[0].getAttribute('ssid');pwdbox.value=null;dialog()}}};reload.onclick=()=>message()&getnewdata();okey.onclick=()=>conneting();cancle.onclick=()=>dialog(false)};getnewdata=(type=true)=>{fetch('/getNewData').then(res=>{return res.json()}).then(res=>{if(Boolean(res[0].end))return getnewdata();list.innerHTML=null;create(res)}).catch(()=>{message(3,false,'刷新失败，重试中');getnewdata()})};getdata=()=>{fetch('/getData').then(res=>{return res.json()}).then(res=>{list.innerHTML=null;create(res)}).catch(()=>{message(3,false,'无法获取热点列表')})};conneting=()=>{message(2);setTimeout(()=>dialog(false),250);fetch(`/ssidData?ssid=${ssidbox.value}&pwd=${pwdbox.value}`).then(res=>{return res.json()}).then(res=>{Boolean(res.status)?message(3):message(3,false)}).catch(()=>{message(3,false);getnewdata()})};dialog=(sta=true)=>{if(sta)istyping=true,ss(typing,'visibility: visible;opacity: 1;transform: scale(1);');else istyping=false,ss(typing,'visibility: hidden; opacity: 0;transform: scale(0.01);');};create=(data)=>{data.splice(-1,1);list.innerHTML=null;data.forEach(item=>{let box=document.createElement('div');let name=document.createElement('p');let lockbox=document.createElement('span');let lockicon=document.createElement('hr');let dbmbox=document.createElement('span');let icon1=document.createElement('hr');let icon2=document.createElement('hr');let icon3=document.createElement('hr');box.setAttribute('class','data');name.setAttribute('ssid',item.ssid);item.ssid.length>14?name.innerText=`${item.ssid.substring(14,0)}...`:name.innerText=item.ssid;box.appendChild(name);if(item.type==0)lockbox.setAttribute('class','data-lock'),lockbox.appendChild(lockicon),box.appendChild(lockbox);item.dbm=Math.abs(Number(item.dbm));if(item.dbm>=50)ss(icon3,'background: #d6dbe9;');if(item.dbm>=75)ss(icon3,'background: #d6dbe9;'),ss(icon2,'background: #d6dbe9;');if(item.dbm>=95)ss(icon3,'background: #d6dbe9;'),ss(icon2,'background: #d6dbe9;'),ss(icon1,'background: #d6dbe9;');dbmbox.setAttribute('class','data-dbm');dbmbox.appendChild(icon1);dbmbox.appendChild(icon2);dbmbox.appendChild(icon3);box.appendChild(dbmbox);list.appendChild(box);});message(false);};message=(type=1,sta=true,text='连接失败，请重试')=>{ss(messagebox,null);ss(loading,null);ss(loadingicon,null);ss(con,null);ss(tips,null);timer=null;if(!type)return;if(type==1)ss(loading,'transform: scale(1);'),ss(loadingicon,'animation: 3s loadingbox infinite ;');if(type==2)ss(con,'transform: scale(1);');if(type==3){if(sta){ss(tipsicon_yes,'display: block');ss(tipsicon_no,'display: none');tipstext.innerText='连接成功';}else{ss(tipsicon_yes,'display: none');ss(tipsicon_no,'display: block');tipstext.innerText=text;}ss(tips,'transform: scale(1);');timer=setTimeout(()=>message(false),3500);}ss(messagebox,'visibility: visible;opacity: 1;');};showpwd=()=>{pwdboxsta?pwdbox.setAttribute('type','text'):pwdbox.setAttribute('type','password');pwdboxsta=!pwdboxsta;};ss=(object,style)=>object.style.cssText=style;</script><body><div id='body'><div class='body-head'><h1 style='font-size: 25px;color: #adb4c7;'>附近&nbsp;WLAN</h1></div><div class='body-info'></div><button class='reload'>刷新</button><p class='logo'>-&nbsp;&nbsp;EasyWLAN&nbsp;&nbsp;-</p></div><div id='typing'><div class='typingbox'><p style='margin: 35px;font-size: 25px;font-weight: bolder;color: #adb4c7;'>连接网络</p><input class='ssid'type='text'placeholder='名称'><input class='pwd'type='password'placeholder='密码'><input class='okey'type='button'value='确认'><input class='cancle'type='button'value='取消'></div></div><div id='loading'><span class='loading'><span class='loading-icon'><hr></span><p class='loading-text'>扫描中</p></span><span class='con'><span class='con-icon'><hr><hr><hr><hr></span><p class='loading-text'>连接中</p></span><span class='tips'><span class='tips-icon'><hr class='tips-icon-yes'><hr class='tips-icon-no'></span><p class='tips-text'></p></span></div></body></html>";

#endif
