/*!
 * LxExt v0.0.1
 * LxExt 是LxExt JS框架的核心文件
 * http://intelomo.com/
 * Author: Colin3dmax
 * Date: 2012-02-06
 */
 
LxExt=new Object();
LxExt.Transition=function(){};
function setConfig( value,defaultValue ){
	if(typeof(value)=="undefined"){
		if(typeof(defaultValue)=="undefined"){
			throw("配置属性没有默认值，需要js客户端程序员指定该参数！"); 
		}
		return defaultValue;
	}
	return value;	
}


/*!
	LxExt.Dialog
	对话框类
*/
LxExt.Dialog = function(){};
LxExt.Dialog.canDragBorder=false;//窗体边框是否可以拖拽

//设置窗口初始大小
LxExt.Dialog.initWndWH = function(width,height){
	LxDialog.setDialogWH(width,height);
	LxDialog.width = width;
	LxDialog.height = height;
};
//设置边框是否可以拖动
LxExt.Dialog.setBorderDrag= function( drag ){
	if(drag!=undefined){
		LxExt.Dialog.canDragBorder=drag;
	}
	return LxExt.Dialog.canDragBorder;
};
//标题栏的的可拖着区域
//obj设置拖动区域的对象
LxExt.Dialog.dragRegion = function( obj ){
	//解决LxDialog.move();的Bug，替换LxDialog.move();
	function Point( x,y){
		this.x=x;
		this.y=y;
	}
	var oldPoint=new Point(0,0);
	var currPoint=new Point(0,0);
	var topleftPoint=new Point(0,0);
	var canMoveWindow=false;
	function getWindowPos(){
		topleftPoint.x=LxDialog.getTopLeftX();
		topleftPoint.y=LxDialog.getTopLeftY();
	}
	obj.bind("mousedown",function(e){
		oldPoint.x=e.pageX;
		oldPoint.y=e.pageY;
		getWindowPos();
		canMoveWindow=true;
		if(window.captureEvents){
			window.captureEvents(Event.MOUSEMOVE|Event.MOUSEUP);  
		}
		else{ 
			obj.setCapture(); 
		}
	});
	$(document).bind("mousemove",function(e){
		if(canMoveWindow){
			currPoint.x=e.pageX;
			currPoint.y=e.pageY;
			LxDialog.move( topleftPoint.x+currPoint.x-oldPoint.x, topleftPoint.y+currPoint.y-oldPoint.y);
			getWindowPos();
		}
	})
	$(document).bind("mouseup",function(){
		canMoveWindow=false;
		if(window.captureEvents)window.releaseEvents(Event.MOUSEMOVE|Event.MOUSEUP);  
		else obj.releaseCapture();  
	});
};

//移动窗口至x,y坐标处
LxExt.Dialog.moveWnd = function(x,y){
	LxDialog.move(x,y);
};

//最大化窗口
LxExt.Dialog.showMaximized = function(){
	LxDialog.showMaximized();
};

//最小化窗口
LxExt.Dialog.showMinimized = function(){
	LxDialog.showMinimized();
};

//关闭当前窗口
LxExt.Dialog.closeWnd = function(){
	LxDialog.close();
};

//显示窗口
LxExt.Dialog.showNormal = function(){
	LxDialog.showNormal();
};

//当前窗口是否最小化
LxExt.Dialog.isMinimized = function(){
	return LxDialog.isMinimized();
};

//当前窗口是否最大化
LxExt.Dialog.isMaximized = function(){
	return LxDialog.isMaximized();
};

//当前窗口是否全屏
LxExt.Dialog.isMaximized = function(){
	return LxDialog.isMaximized();
};

//取得当前窗口限制的最小宽度
LxExt.Dialog.getMinWidth = function(){
	return LxDialog.minimumWidth();
};

//取得当前窗口限制的最大宽度
LxExt.Dialog.getMaxWidth = function(){
	return LxDialog.maximumWidth();
};

//取得当前窗口限制的最小高度
LxExt.Dialog.getMinHeight = function(){
	return LxDialog.minimumHeight();
};

//取得当前窗口限制的最大高度
LxExt.Dialog.getMaxHeight = function(){
	return LxDialog.maximumHeight();
};

//限制当前窗口最小宽度和最小高度
LxExt.Dialog.setMinimumSize = function(w,h){
	LxDialog.setMinimumSize(w,h);
};

//限制当前窗口最大宽度和最大高度
LxExt.Dialog.setMaximumSize = function(w,h){
	LxDialog.setMaximumSize(w,h);
};

//限制当前窗口最小宽度
LxExt.Dialog.setMinimumWidth = function(w){
	LxDialog.setMinimumWidth(w);
};

//限制当前窗口最小高度
LxExt.Dialog.setMinimumHeight= function(h){
	LxDialog.setMinimumWidth(h);
};

//限制当前窗口最大宽度和最大高度
LxExt.Dialog.setMaximumSize = function(h){
	LxDialog.setMaximumSize(w,h);
};

//限制当前窗口最大宽度
LxExt.Dialog.setMaximumWidth = function(w){
	LxDialog.setMaximumWidth(w);
};

//限制当前窗口最大高度
LxExt.Dialog.setMaximumHeight = function(h){
	LxDialog.setMaximumHeight(h);
};

//屏幕宽
LxExt.Dialog.getScreenWidth = function(){
	return window.screen.width;
};

//屏幕高
LxExt.Dialog.getScreenHeight = function(){
	return window.screen.height;
};

//窗口屏幕居中
LxExt.Dialog.centerWnd = function(){
	LxExt.Dialog.moveWnd((LxExt.Dialog.getScreenWidth() - window.innerWidth)/2,(LxExt.Dialog.getScreenHeight() - window.innerHeight)/2);
};

//显示窗口
LxExt.Dialog.showWnd = function(){
	LxDialog.show();
};

//隐藏窗口
LxExt.Dialog.hideWnd = function(){
	//
};

//重新加载UI资源
LxExt.Dialog.Reload = function(){
	LxDialog.reload();
};
//默认浏览器打开网址
LxExt.Dialog.openURL = function(addr){
	LxDialog.openUrl(addr);
};
//启动程序
LxExt.Dialog.exec = function(exeName){
	LxDialog.openUrl(exeName);
};

LxExt.Dialog.updateClientSize = function( objClient,offset ){
	objClient.height( document.documentElement.clientHeight - objClient.position().top - offset );
} 

/*
 功能:默认对最外层Div实现边框拖拽功能
  param:obj  		添加拖拽功能的对象
  pargm:int size	拖动感应区域 默认5 px;
*/
LxExt.Dialog.borderDrag=function(objBody,obj,size){
	var size= typeof(size)=="undefined"?10:size;
	var canMoveWindow =false;
	function Point(x,y){
		this.x=x;
		this.y=y;
	}
	function isMouseInBorder( obj,point ){
		var offset=obj.offset();
		if(point.x<=offset.left+size && point.y<=offset.top+size ){
				//左上角
				return true;
			}else if(point.x>=offset.left && point.x>offset.left+size && point.x<= obj.outerWidth(true)+offset.left-size && point.y<=offset.top+size){
				//上边
				return true;
			}else if(point.x>=offset.left && point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y<=offset.top+size ){
				//右上角
				return true;
			}else if(point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y>offset.top+size && point.y<= obj.outerHeight(true)+offset.top - size ){
				//右边
				return true;
			}else if(point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//右下角
				return true;
			}else if( point.x>offset.left+size && point.x<= obj.outerWidth(true)+offset.left-size && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//下角
				return true;
			}else if(point.x>=offset.left && point.x<=offset.left+size && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//左下角
				return true;
			}else if(point.x>=offset.left && point.x<=offset.left+size && point.y>offset.top+size && point.y<= obj.outerHeight(true)+offset.top ){
				return true;
			}
			return false;
	}
	var oldPoint;
	var pointFlag=-1;
	var windowWidth=0;
	var windowHeight=0;
	//绑定边框拖动的事件
	if(obj){
		//鼠标按下
		obj.bind("mousedown",function(e){
			if(LxExt.Dialog.canDragBorder){
				
				oldPoint=new Point( e.pageX,e.pageY);
				canMoveWindow = isMouseInBorder( obj,oldPoint );
				windowWidth=document.documentElement.clientWidth;
				windowHeight=document.documentElement.clientHeight;				
			}
			if(window.captureEvents){
				window.captureEvents(Event.MOUSEMOVE|Event.MOUSEUP);  
			}
			else{ 
				obj.setCapture(); 
			}
		});
		//鼠标移动
		$(document).bind("mousemove",function(e){
			//如果启动边框拖动，改变窗体大小
			if(LxExt.Dialog.canDragBorder){
				//获取当前窗体坐标
				var newPoint=new Point( e.pageX,e.pageY);
				var offset = obj.offset();
				
				//设置鼠标在对应区域中的样式
				//判断鼠标位置
				if(!canMoveWindow){
					if(newPoint.x<=offset.left+size && newPoint.y<=offset.top+size ){
						//左上角
						pointFlag=0;
						obj.css("cursor","nw-resize");
					}else if(newPoint.x>=offset.left && newPoint.x>offset.left+size && newPoint.x<= obj.outerWidth(true)+offset.left-size && newPoint.y<=offset.top+size){
						//上边
						pointFlag=1;
						obj.css("cursor","n-resize");
					}else if(newPoint.x>=offset.left && newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y<=offset.top+size ){
						//右上角
						pointFlag=2;
						obj.css("cursor","ne-resize");
					}else if(newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y>offset.top+size && newPoint.y<= obj.outerHeight(true)+offset.top - size ){
						//右边
						pointFlag=3;
						obj.css("cursor","e-resize");
					}else if(newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//右下角
						pointFlag=4;
						obj.css("cursor","se-resize");
					}else if( newPoint.x>offset.left+size && newPoint.x<= obj.outerWidth(true)+offset.left-size && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//下角
						pointFlag=5;
						obj.css("cursor","s-resize");
					}else if(newPoint.x>=offset.left && newPoint.x<=offset.left+size && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//左下角
						pointFlag=6;
						obj.css("cursor","sw-resize");
					}else if(newPoint.x>=offset.left && newPoint.x<=offset.left+size && newPoint.y>offset.top+size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//左边
						pointFlag=7;
						obj.css("cursor","w-resize");
					}
					else{
						//恢复默认
						obj.css("cursor","default");
					}
				}
				//1.左上角，右下角图标
				

				//调整窗体大小
				if(canMoveWindow){
					//获取当前窗体大小
					switch(pointFlag){
						case 0:
						//左上角
							//设置TopLeft位置到当前
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowWidth=windowWidth- offsetX;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX()+offsetX,LxDialog.getTopLeftY()+offsetY);
							break;
						case 1:
						//上边
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX(),LxDialog.getTopLeftY()+offsetY);
							break;
						case 2:
						//右上角
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth + offsetX ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX(),LxDialog.getTopLeftY()+offsetY);
							break;
						case 3:
						//右边
							LxExt.Dialog.initWndWH(windowWidth+ (newPoint.x - oldPoint.x) ,windowHeight );
							break;
						case 4:
						//右下角
							LxExt.Dialog.initWndWH(windowWidth+ (newPoint.x - oldPoint.x) ,windowHeight+ (newPoint.y - oldPoint.y) );
							break;
						case 5:
						//下边
							LxExt.Dialog.initWndWH(windowWidth,windowHeight+ (newPoint.y - oldPoint.y) );
							break;
						case 6:
						//左下角
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowWidth=windowWidth- offsetX;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight+offsetY );
							LxDialog.move(LxDialog.getTopLeftX()+offsetX,LxDialog.getTopLeftY());
							break;
						case 7:
						//左边
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowWidth=windowWidth- offsetX;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX()+offsetX,LxDialog.getTopLeftY());
							break;
						case -1:
							break;
					}
					LxExt.Dialog.updateClientSize( objBody,12 );
				}
				
			}
		});
		//鼠标抬起
		$(document).bind("mouseup",function(){
			if(LxExt.Dialog.canDragBorder){
				canMoveWindow=false;
				obj.css("cursor","default");
				pointFlag=-1;
			}
			if(window.captureEvents){
				window.releaseEvents(Event.MOUSEMOVE|Event.MOUSEUP); 
			}else{ 
				obj.releaseCapture();
			} 		
		});
		
	}
};

/*!
	LxExt.Transition.Button
	特效->动画按钮类
*/
/*
	Class
	按钮类构造函数
	param:JQueryObject obj要维护的对象
*/

/*	
	Public:
	功能:图片按钮的过渡动画
	Config:{
		string	eventName 			事件类型名称 默认为 "mouseenter"
		object	eventTarget 	*	事件触发对象 必须指定
		object	animTarget 			动画显示对象 默认为eventTarget
		string 	image	 		*	用作过渡效果的图片路径 必须指定 
		string  className			类样式名称
		int 	width				首个图片元素的宽 默认为32
		int 	height				首个图片元素的高 默认为32
		int 	frames 				图片元素帧数	 默认为1帧
		int 	x 					首个图片元素的x坐标 默认为0
		int 	y 					首个图片元素的y坐标 默认为0
		bool 	pos 				动画正向播放或逆向播放，默认为true正向播放  			pos[itive]简写
		bool 	hori 				按钮图片元素集水平或垂直方向 [true|false] 默认为true   	hori[zontale]简写
		bool 	stop 				图集播放结束是否停留在最后一帧 [true|false] 默认为true 
		int     speed				动画延时  默认为 50毫秒
		int     space    			图集元素间隔 默认为0 
	}
	注意：为了方便使用一个Button类的实例 内部只维护一组Config,但支持多个事件同时绑定在这个实例，如果需要每个事件对应的Config配置不同，需要实例多个对象
*/
LxExt.Transition.Button=function(config){
	//内置Button配置对象
	function ButtonConfig(config){
		this.eventName=setConfig(config.eventName,"mouseenter");
		this.eventTarget=setConfig(config.eventTarget);
		this.animTarget=setConfig(config.animTarget,config.eventTarget);
		this.image=setConfig(config.image);
		this.className=config.className;//如果没有this.className=undefined;
		this.width=setConfig(config.width,32);
		this.height=setConfig(config.height,32);
		this.frames=setConfig(config.frames,1);
		this.x = setConfig(config.x,0);
		this.y = setConfig(config.y,0);
		this.pos = setConfig(config.pos,true);		//动画播放方向
		this.hori = setConfig(config.hori,true);
		this.stop=setConfig(config.stop,true);
		this.speed = setConfig(config.speed,50);
		this.space = setConfig(config.space,0);
	}
	//默认配置项
	this.defaultConfig =new ButtonConfig( config );
	//配置config
	this.eventArray=[];	//用于存放对应的事件配置
	
	var buttonscope=this;	//保持当前的作用域
	/*
		Public:
		功能:按钮添加新的事件支持
		需要配置
			config{
				string configId 事件标示，同一个对象中configId不能重复
			}
	*/
	this.addEvent=function( configAdd ){
		var newConfig= {};
		newConfig.configId=configAdd.configId;
		newConfig.eventName=setConfig(configAdd.eventName,buttonscope.defaultConfig.eventName);
		newConfig.eventTarget=setConfig(configAdd.eventTarget,buttonscope.defaultConfig.eventTarget);
		newConfig.animTarget=setConfig(configAdd.animTarget,buttonscope.defaultConfig.animTarget);
		newConfig.image=setConfig(configAdd.image,buttonscope.defaultConfig.image);
		newConfig.className=configAdd.className;//如果没有this.className=undefined;
		newConfig.width=setConfig(configAdd.width,buttonscope.defaultConfig.width);
		newConfig.height=setConfig(configAdd.height,buttonscope.defaultConfig.height);
		newConfig.frames=setConfig(configAdd.frames,buttonscope.defaultConfig.frames);
		newConfig.x = setConfig(configAdd.x,buttonscope.defaultConfig.x);
		newConfig.y = setConfig(configAdd.y,buttonscope.defaultConfig.y);
		newConfig.pos = setConfig(configAdd.pos,buttonscope.defaultConfig.pos);		//动画播放方向
		newConfig.hori = setConfig(configAdd.hori,buttonscope.defaultConfig.hori);
		newConfig.stop=setConfig(configAdd.stop,buttonscope.defaultConfig.stop);
		newConfig.speed = setConfig(configAdd.speed,buttonscope.defaultConfig.speed);
		newConfig.space = setConfig(configAdd.space,buttonscope.defaultConfig.space);
		for( var i=0; i<buttonscope.eventArray.length;i++ ){
			if(buttonscope.eventArray[i].configId==configAdd.configId){
				return false; //添加事件失败存在重复的configId
			}
		}
		//--------------------------------------------------------------------------
		
		buttonscope.eventArray.push( newConfig );  
		var currFrame = 0;							//当前显示的动画帧
		var oldStyle={};
		//根据播放方向调整参数
		function InitParams(){
			if(!newConfig.pos){
				currFrame = newConfig.frames - 1;
			}else{
				currFrame = 0;
			}
		}
		//记录冲突的样式
		function recordStyle(){
			oldStyle.backgroundImage=newConfig.animTarget.css("background-image");
			oldStyle.backgroundRepeat=newConfig.animTarget.css("background-repeat");
			oldStyle.backgroundPosition=newConfig.animTarget.css("background-position");
			//如果存在className样式，添加
			if(newConfig.className){
				newConfig.animTarget.addClass( newConfig.className );
			}
		}
		//回复样式表
		function resetStyle(){
			newConfig.animTarget.css("background-image",oldStyle.backgroundImage);
			newConfig.animTarget.css("background-repeat",oldStyle.backgroundRepeat);
			newConfig.animTarget.css("background-position",oldStyle.backgroundPosition);
			//移除className样式
			if(newConfig.className){
				newConfig.animTarget.removeClass( newConfig.className );
			}
		}
		//更新样式
		function updateStyle(){
			newConfig.animTarget.css("background-image","url("+newConfig.image+")");
			newConfig.animTarget.css("background-repeat","no-repeat");
			var tmpX=-newConfig.x;
			var tmpY=-newConfig.y;
			if(newConfig.hori){
				tmpX= newConfig.x-(newConfig.width+newConfig.space)*currFrame;
			}else{
				tmpY= newConfig.y-(newConfig.heigth+newConfig.space)*currFrame;
			}
			newConfig.animTarget.css("background-position",""+tmpX+"px "+tmpY+"px " );
		}
		//调整参数
		InitParams();
		//记录冲突样式
		recordStyle();
		
		if( newConfig.pos ){
			newConfig.eventTarget.bind(newConfig.eventName,function(){
				function playPos(){
					updateStyle.apply(buttonscope);
					//计算下一次的样式
					if(currFrame<newConfig.frames){
						currFrame++;
						setTimeout(callPlayPos,newConfig.speed);
					}else{
						InitParams.apply(buttonscope);
						if(!newConfig.stop){
							resetStyle.apply(buttonscope);
						}
					}
				}
				function callPlayPos(){
					playPos.apply(buttonscope);
				}
				callPlayPos();
			});
		}else{
			newConfig.eventTarget.bind(newConfig.eventName,function(){
				function playUnPos(){
					updateStyle.apply(buttonscope);
					//计算下一次的样式
					if(currFrame>0){
						currFrame--;
						setTimeout(callPlayUnPos,newConfig.speed);
					}
					else{
						InitParams.apply(buttonscope);
						if(!newConfig.stop){
							resetStyle.apply(buttonscope);
						}
					}
				}
				function callPlayUnPos(){
					playUnPos.apply(buttonscope);
				}
				callPlayUnPos();
				
			});
		}
		return buttonscope;
	}
	/*
		Public:
		功能:移除事件支持
		string configId  事件id
		string eventName 事件名称
		return 删除是否成功
	*/
	this.removeEvent=function( configId ){
		for( var i=0; i<buttonscope.eventArray.length;i++ ){
			if(buttonscope.eventArray[i].configId==configId){
				buttonscope.eventArray[i].eventTarget.unbind( buttonscope.eventArray[i].eventName );
				return buttonscope; //添加事件失败存在重复的configId
			}
		}
		return false;
	};
	
	return buttonscope;
};

