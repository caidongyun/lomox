/*!
 * LxExt v0.0.1
 * LxExt ��LxExt JS��ܵĺ����ļ�
 * http://intelomo.com/
 * Author: Colin3dmax
 * Date: 2012-02-06
 */
 
LxExt=new Object();
LxExt.Transition=function(){};
function setConfig( value,defaultValue ){
	if(typeof(value)=="undefined"){
		if(typeof(defaultValue)=="undefined"){
			throw("��������û��Ĭ��ֵ����Ҫjs�ͻ��˳���Աָ���ò�����"); 
		}
		return defaultValue;
	}
	return value;	
}


/*!
	LxExt.Dialog
	�Ի�����
*/
LxExt.Dialog = function(){};
LxExt.Dialog.canDragBorder=false;//����߿��Ƿ������ק

//���ô��ڳ�ʼ��С
LxExt.Dialog.initWndWH = function(width,height){
	LxDialog.setDialogWH(width,height);
	LxDialog.width = width;
	LxDialog.height = height;
};
//���ñ߿��Ƿ�����϶�
LxExt.Dialog.setBorderDrag= function( drag ){
	if(drag!=undefined){
		LxExt.Dialog.canDragBorder=drag;
	}
	return LxExt.Dialog.canDragBorder;
};
//�������ĵĿ���������
//obj�����϶�����Ķ���
LxExt.Dialog.dragRegion = function( obj ){
	//���LxDialog.move();��Bug���滻LxDialog.move();
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

//�ƶ�������x,y���괦
LxExt.Dialog.moveWnd = function(x,y){
	LxDialog.move(x,y);
};

//��󻯴���
LxExt.Dialog.showMaximized = function(){
	LxDialog.showMaximized();
};

//��С������
LxExt.Dialog.showMinimized = function(){
	LxDialog.showMinimized();
};

//�رյ�ǰ����
LxExt.Dialog.closeWnd = function(){
	LxDialog.close();
};

//��ʾ����
LxExt.Dialog.showNormal = function(){
	LxDialog.showNormal();
};

//��ǰ�����Ƿ���С��
LxExt.Dialog.isMinimized = function(){
	return LxDialog.isMinimized();
};

//��ǰ�����Ƿ����
LxExt.Dialog.isMaximized = function(){
	return LxDialog.isMaximized();
};

//��ǰ�����Ƿ�ȫ��
LxExt.Dialog.isMaximized = function(){
	return LxDialog.isMaximized();
};

//ȡ�õ�ǰ�������Ƶ���С���
LxExt.Dialog.getMinWidth = function(){
	return LxDialog.minimumWidth();
};

//ȡ�õ�ǰ�������Ƶ������
LxExt.Dialog.getMaxWidth = function(){
	return LxDialog.maximumWidth();
};

//ȡ�õ�ǰ�������Ƶ���С�߶�
LxExt.Dialog.getMinHeight = function(){
	return LxDialog.minimumHeight();
};

//ȡ�õ�ǰ�������Ƶ����߶�
LxExt.Dialog.getMaxHeight = function(){
	return LxDialog.maximumHeight();
};

//���Ƶ�ǰ������С��Ⱥ���С�߶�
LxExt.Dialog.setMinimumSize = function(w,h){
	LxDialog.setMinimumSize(w,h);
};

//���Ƶ�ǰ��������Ⱥ����߶�
LxExt.Dialog.setMaximumSize = function(w,h){
	LxDialog.setMaximumSize(w,h);
};

//���Ƶ�ǰ������С���
LxExt.Dialog.setMinimumWidth = function(w){
	LxDialog.setMinimumWidth(w);
};

//���Ƶ�ǰ������С�߶�
LxExt.Dialog.setMinimumHeight= function(h){
	LxDialog.setMinimumWidth(h);
};

//���Ƶ�ǰ��������Ⱥ����߶�
LxExt.Dialog.setMaximumSize = function(h){
	LxDialog.setMaximumSize(w,h);
};

//���Ƶ�ǰ���������
LxExt.Dialog.setMaximumWidth = function(w){
	LxDialog.setMaximumWidth(w);
};

//���Ƶ�ǰ�������߶�
LxExt.Dialog.setMaximumHeight = function(h){
	LxDialog.setMaximumHeight(h);
};

//��Ļ��
LxExt.Dialog.getScreenWidth = function(){
	return window.screen.width;
};

//��Ļ��
LxExt.Dialog.getScreenHeight = function(){
	return window.screen.height;
};

//������Ļ����
LxExt.Dialog.centerWnd = function(){
	LxExt.Dialog.moveWnd((LxExt.Dialog.getScreenWidth() - window.innerWidth)/2,(LxExt.Dialog.getScreenHeight() - window.innerHeight)/2);
};

//��ʾ����
LxExt.Dialog.showWnd = function(){
	LxDialog.show();
};

//���ش���
LxExt.Dialog.hideWnd = function(){
	//
};

//���¼���UI��Դ
LxExt.Dialog.Reload = function(){
	LxDialog.reload();
};
//Ĭ�����������ַ
LxExt.Dialog.openURL = function(addr){
	LxDialog.openUrl(addr);
};
//��������
LxExt.Dialog.exec = function(exeName){
	LxDialog.openUrl(exeName);
};

LxExt.Dialog.updateClientSize = function( objClient,offset ){
	objClient.height( document.documentElement.clientHeight - objClient.position().top - offset );
} 

/*
 ����:Ĭ�϶������Divʵ�ֱ߿���ק����
  param:obj  		�����ק���ܵĶ���
  pargm:int size	�϶���Ӧ���� Ĭ��5 px;
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
				//���Ͻ�
				return true;
			}else if(point.x>=offset.left && point.x>offset.left+size && point.x<= obj.outerWidth(true)+offset.left-size && point.y<=offset.top+size){
				//�ϱ�
				return true;
			}else if(point.x>=offset.left && point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y<=offset.top+size ){
				//���Ͻ�
				return true;
			}else if(point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y>offset.top+size && point.y<= obj.outerHeight(true)+offset.top - size ){
				//�ұ�
				return true;
			}else if(point.x>obj.outerWidth(true)+offset.left-size && point.x<= obj.outerWidth(true)+offset.left && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//���½�
				return true;
			}else if( point.x>offset.left+size && point.x<= obj.outerWidth(true)+offset.left-size && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//�½�
				return true;
			}else if(point.x>=offset.left && point.x<=offset.left+size && point.y>obj.outerHeight(true)+offset.top-size && point.y<= obj.outerHeight(true)+offset.top ){
				//���½�
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
	//�󶨱߿��϶����¼�
	if(obj){
		//��갴��
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
		//����ƶ�
		$(document).bind("mousemove",function(e){
			//��������߿��϶����ı䴰���С
			if(LxExt.Dialog.canDragBorder){
				//��ȡ��ǰ��������
				var newPoint=new Point( e.pageX,e.pageY);
				var offset = obj.offset();
				
				//��������ڶ�Ӧ�����е���ʽ
				//�ж����λ��
				if(!canMoveWindow){
					if(newPoint.x<=offset.left+size && newPoint.y<=offset.top+size ){
						//���Ͻ�
						pointFlag=0;
						obj.css("cursor","nw-resize");
					}else if(newPoint.x>=offset.left && newPoint.x>offset.left+size && newPoint.x<= obj.outerWidth(true)+offset.left-size && newPoint.y<=offset.top+size){
						//�ϱ�
						pointFlag=1;
						obj.css("cursor","n-resize");
					}else if(newPoint.x>=offset.left && newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y<=offset.top+size ){
						//���Ͻ�
						pointFlag=2;
						obj.css("cursor","ne-resize");
					}else if(newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y>offset.top+size && newPoint.y<= obj.outerHeight(true)+offset.top - size ){
						//�ұ�
						pointFlag=3;
						obj.css("cursor","e-resize");
					}else if(newPoint.x>obj.outerWidth(true)+offset.left-size && newPoint.x<= obj.outerWidth(true)+offset.left && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//���½�
						pointFlag=4;
						obj.css("cursor","se-resize");
					}else if( newPoint.x>offset.left+size && newPoint.x<= obj.outerWidth(true)+offset.left-size && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//�½�
						pointFlag=5;
						obj.css("cursor","s-resize");
					}else if(newPoint.x>=offset.left && newPoint.x<=offset.left+size && newPoint.y>obj.outerHeight(true)+offset.top-size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//���½�
						pointFlag=6;
						obj.css("cursor","sw-resize");
					}else if(newPoint.x>=offset.left && newPoint.x<=offset.left+size && newPoint.y>offset.top+size && newPoint.y<= obj.outerHeight(true)+offset.top ){
						//���
						pointFlag=7;
						obj.css("cursor","w-resize");
					}
					else{
						//�ָ�Ĭ��
						obj.css("cursor","default");
					}
				}
				//1.���Ͻǣ����½�ͼ��
				

				//���������С
				if(canMoveWindow){
					//��ȡ��ǰ�����С
					switch(pointFlag){
						case 0:
						//���Ͻ�
							//����TopLeftλ�õ���ǰ
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowWidth=windowWidth- offsetX;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX()+offsetX,LxDialog.getTopLeftY()+offsetY);
							break;
						case 1:
						//�ϱ�
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX(),LxDialog.getTopLeftY()+offsetY);
							break;
						case 2:
						//���Ͻ�
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowHeight=windowHeight - offsetY;
							LxExt.Dialog.initWndWH(windowWidth + offsetX ,windowHeight );
							LxDialog.move(LxDialog.getTopLeftX(),LxDialog.getTopLeftY()+offsetY);
							break;
						case 3:
						//�ұ�
							LxExt.Dialog.initWndWH(windowWidth+ (newPoint.x - oldPoint.x) ,windowHeight );
							break;
						case 4:
						//���½�
							LxExt.Dialog.initWndWH(windowWidth+ (newPoint.x - oldPoint.x) ,windowHeight+ (newPoint.y - oldPoint.y) );
							break;
						case 5:
						//�±�
							LxExt.Dialog.initWndWH(windowWidth,windowHeight+ (newPoint.y - oldPoint.y) );
							break;
						case 6:
						//���½�
							var offsetX=newPoint.x - oldPoint.x;
							var offsetY=newPoint.y - oldPoint.y;
							windowWidth=windowWidth- offsetX;
							LxExt.Dialog.initWndWH(windowWidth ,windowHeight+offsetY );
							LxDialog.move(LxDialog.getTopLeftX()+offsetX,LxDialog.getTopLeftY());
							break;
						case 7:
						//���
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
		//���̧��
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
	��Ч->������ť��
*/
/*
	Class
	��ť�๹�캯��
	param:JQueryObject objҪά���Ķ���
*/

/*	
	Public:
	����:ͼƬ��ť�Ĺ��ɶ���
	Config:{
		string	eventName 			�¼��������� Ĭ��Ϊ "mouseenter"
		object	eventTarget 	*	�¼��������� ����ָ��
		object	animTarget 			������ʾ���� Ĭ��ΪeventTarget
		string 	image	 		*	��������Ч����ͼƬ·�� ����ָ�� 
		string  className			����ʽ����
		int 	width				�׸�ͼƬԪ�صĿ� Ĭ��Ϊ32
		int 	height				�׸�ͼƬԪ�صĸ� Ĭ��Ϊ32
		int 	frames 				ͼƬԪ��֡��	 Ĭ��Ϊ1֡
		int 	x 					�׸�ͼƬԪ�ص�x���� Ĭ��Ϊ0
		int 	y 					�׸�ͼƬԪ�ص�y���� Ĭ��Ϊ0
		bool 	pos 				�������򲥷Ż����򲥷ţ�Ĭ��Ϊtrue���򲥷�  			pos[itive]��д
		bool 	hori 				��ťͼƬԪ�ؼ�ˮƽ��ֱ���� [true|false] Ĭ��Ϊtrue   	hori[zontale]��д
		bool 	stop 				ͼ�����Ž����Ƿ�ͣ�������һ֡ [true|false] Ĭ��Ϊtrue 
		int     speed				������ʱ  Ĭ��Ϊ 50����
		int     space    			ͼ��Ԫ�ؼ�� Ĭ��Ϊ0 
	}
	ע�⣺Ϊ�˷���ʹ��һ��Button���ʵ�� �ڲ�ֻά��һ��Config,��֧�ֶ���¼�ͬʱ�������ʵ���������Ҫÿ���¼���Ӧ��Config���ò�ͬ����Ҫʵ���������
*/
LxExt.Transition.Button=function(config){
	//����Button���ö���
	function ButtonConfig(config){
		this.eventName=setConfig(config.eventName,"mouseenter");
		this.eventTarget=setConfig(config.eventTarget);
		this.animTarget=setConfig(config.animTarget,config.eventTarget);
		this.image=setConfig(config.image);
		this.className=config.className;//���û��this.className=undefined;
		this.width=setConfig(config.width,32);
		this.height=setConfig(config.height,32);
		this.frames=setConfig(config.frames,1);
		this.x = setConfig(config.x,0);
		this.y = setConfig(config.y,0);
		this.pos = setConfig(config.pos,true);		//�������ŷ���
		this.hori = setConfig(config.hori,true);
		this.stop=setConfig(config.stop,true);
		this.speed = setConfig(config.speed,50);
		this.space = setConfig(config.space,0);
	}
	//Ĭ��������
	this.defaultConfig =new ButtonConfig( config );
	//����config
	this.eventArray=[];	//���ڴ�Ŷ�Ӧ���¼�����
	
	var buttonscope=this;	//���ֵ�ǰ��������
	/*
		Public:
		����:��ť����µ��¼�֧��
		��Ҫ����
			config{
				string configId �¼���ʾ��ͬһ��������configId�����ظ�
			}
	*/
	this.addEvent=function( configAdd ){
		var newConfig= {};
		newConfig.configId=configAdd.configId;
		newConfig.eventName=setConfig(configAdd.eventName,buttonscope.defaultConfig.eventName);
		newConfig.eventTarget=setConfig(configAdd.eventTarget,buttonscope.defaultConfig.eventTarget);
		newConfig.animTarget=setConfig(configAdd.animTarget,buttonscope.defaultConfig.animTarget);
		newConfig.image=setConfig(configAdd.image,buttonscope.defaultConfig.image);
		newConfig.className=configAdd.className;//���û��this.className=undefined;
		newConfig.width=setConfig(configAdd.width,buttonscope.defaultConfig.width);
		newConfig.height=setConfig(configAdd.height,buttonscope.defaultConfig.height);
		newConfig.frames=setConfig(configAdd.frames,buttonscope.defaultConfig.frames);
		newConfig.x = setConfig(configAdd.x,buttonscope.defaultConfig.x);
		newConfig.y = setConfig(configAdd.y,buttonscope.defaultConfig.y);
		newConfig.pos = setConfig(configAdd.pos,buttonscope.defaultConfig.pos);		//�������ŷ���
		newConfig.hori = setConfig(configAdd.hori,buttonscope.defaultConfig.hori);
		newConfig.stop=setConfig(configAdd.stop,buttonscope.defaultConfig.stop);
		newConfig.speed = setConfig(configAdd.speed,buttonscope.defaultConfig.speed);
		newConfig.space = setConfig(configAdd.space,buttonscope.defaultConfig.space);
		for( var i=0; i<buttonscope.eventArray.length;i++ ){
			if(buttonscope.eventArray[i].configId==configAdd.configId){
				return false; //����¼�ʧ�ܴ����ظ���configId
			}
		}
		//--------------------------------------------------------------------------
		
		buttonscope.eventArray.push( newConfig );  
		var currFrame = 0;							//��ǰ��ʾ�Ķ���֡
		var oldStyle={};
		//���ݲ��ŷ����������
		function InitParams(){
			if(!newConfig.pos){
				currFrame = newConfig.frames - 1;
			}else{
				currFrame = 0;
			}
		}
		//��¼��ͻ����ʽ
		function recordStyle(){
			oldStyle.backgroundImage=newConfig.animTarget.css("background-image");
			oldStyle.backgroundRepeat=newConfig.animTarget.css("background-repeat");
			oldStyle.backgroundPosition=newConfig.animTarget.css("background-position");
			//�������className��ʽ�����
			if(newConfig.className){
				newConfig.animTarget.addClass( newConfig.className );
			}
		}
		//�ظ���ʽ��
		function resetStyle(){
			newConfig.animTarget.css("background-image",oldStyle.backgroundImage);
			newConfig.animTarget.css("background-repeat",oldStyle.backgroundRepeat);
			newConfig.animTarget.css("background-position",oldStyle.backgroundPosition);
			//�Ƴ�className��ʽ
			if(newConfig.className){
				newConfig.animTarget.removeClass( newConfig.className );
			}
		}
		//������ʽ
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
		//��������
		InitParams();
		//��¼��ͻ��ʽ
		recordStyle();
		
		if( newConfig.pos ){
			newConfig.eventTarget.bind(newConfig.eventName,function(){
				function playPos(){
					updateStyle.apply(buttonscope);
					//������һ�ε���ʽ
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
					//������һ�ε���ʽ
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
		����:�Ƴ��¼�֧��
		string configId  �¼�id
		string eventName �¼�����
		return ɾ���Ƿ�ɹ�
	*/
	this.removeEvent=function( configId ){
		for( var i=0; i<buttonscope.eventArray.length;i++ ){
			if(buttonscope.eventArray[i].configId==configId){
				buttonscope.eventArray[i].eventTarget.unbind( buttonscope.eventArray[i].eventName );
				return buttonscope; //����¼�ʧ�ܴ����ظ���configId
			}
		}
		return false;
	};
	
	return buttonscope;
};

