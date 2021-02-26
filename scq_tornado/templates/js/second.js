function inquery(){
  var day=document.getElementsByClassName("day")[0];
  var daylist=day.getElementsByTagName("li");
  var x=new Date(); 
  var year=x.getFullYear();
  var res;
  function is_leap(year){
       if((year%=100)==0)
	   {
	      if((year%400)==0){
		  res=true;
		  }
		  else{
		  res=false;
		  }
	   }else
	   {
		   if((year%=4)==0){
			   res=true;
		   }else{
			   res=false;
		   }
	   }
   }
  is_leap(year);
  var m_day=new Array(31,28,31,30,31,30,31,31,30,31,30,31);
  if(!res){
	 m_day[1]=28; 	     
  }else{
	 m_day[1]=29;
  }
  var month=x.getMonth();
  var thisTime=new Date(year,month,1);
  var firstDay=thisTime.getDay();
  console.log(firstDay);
			 if(firstDay==0){
                  for(var i=0;i<m_day[month];i++){
					 
				      daylist[i+firstDay+6].innerHTML=i+1;
					  }
			 }
			 else{
				  for(var i=0;i<m_day[month];i++){
				      daylist[i+firstDay-1].innerHTML=i+1;
					 
					  }
			 }
  var today=x.getDate();
  daylist[today+firstDay-2].style.color="red";
  var setyear=document.getElementById("year");
  var setmonth=document.getElementById("month");
  setyear.innerHTML=year+'/';
  setmonth.innerHTML=month+1;
  var mon12=month+1;
  var season=document.getElementById("season");
  if(0<mon12&&mon12<4){
  var con=document.getElementById("#con");
  season.innerHTML="´º";
  }
  else if(3<mon12&&mon12<7){
  var con=document.getElementById("#con");
  season.innerHTML="ÏÄ";
  }
  else if(6<mon12&&mon12<10){
  var con=document.getElementById("#con");
  season.innerHTML="Çï";
  }
  else{
  var con=document.getElementById("#con");
  season.innerHTML="¶¬"; 
  }
 }
 $(".footer_a").hover(function(){$(".footer_a").css({color:"red"})},function(){$(".footer_a").css({color:"white"})});
