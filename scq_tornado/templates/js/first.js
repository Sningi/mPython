$(function(){
$(".show_1").click(function(){
$(".header").animate(
	{top:"0px"},1000);
});
$(".xxx").click(function(){
$(".header").animate({
	top:-130},1000);
});	
});

var header=document.getElementById("header"); 
function scroll() { 	
if(window.scrollY>=400){
   //header.style.background='rgba(0,0,0,0.5)';
   header.style.setProperty('background', 'rgba(0,0,0,0.6)', 'important');
   }
   else{
	   //header.style.setProperty('background', 'rgba(0,0,0,0)', 'important');
	   header.style.background='rgba(0,0,0,0)';
   } 
} 
setInterval(scroll,100);
var car_weixin=document.getElementById("car_weixin");
var weixin=document.getElementById("weixin");
$(weixin).hover(
function(){$(car_weixin).animate({width:220,height:220},"fast")},
function(){$(car_weixin).animate({width:0,height:0},"fast");}
)
var num=5;
function foreach(){
var mymessage=confirm("���ű����Ƿ�Ӱ�쵽���������?");
if(mymessage==true)
{
	num++;
	while(num>10){
	num=5;
	}
	var car_imgsrc=document.getElementById("car_img");
	car_imgsrc.src='images/'+num+".jpg";
}
else
    {
	alert("лл���");
	}
}
function weibo(){
var myname=prompt("������ϵ��ʽ");
if(myname!=null)
  {   alert("лл"+myname+"\n"+"���ź�!���ڻ�����ǰ��̨���"); }
else
  {
  }
}
