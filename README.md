lomox
=====
    lomox is a desktop web ui framework 
    
build：
===========
    vs 2013 or vs2012   
    下载  qt-win-opensource-5.4-vs2012.exe or  qt-win-opensource-5.4-vs2013.exe安装
    再下载 qt-vs-addin-opensource.exe
	默认为VS2013工程 若要变为VS2012 请自行调整，如何调整自行百度
    其他自己调整 
    
   
changelog:

==========================
lomox.dll 0.8.0.1 (曹良Colin3dmax)
1.测试Lomox在QT5.5.1下的运行情况，修复VS工程配置对Win32和x86的支持

2.Lomox代码编码格式统一改成UTF8-BOM编码格式

3.测试新手首次配置Lomox是可能遇到的问题，整理成下面的链接，后续有新问题，会更新进来
http://www.evernote.com/l/ANYux0NyZ9FIW50-TUU7965jGJFSjHcCUtY/


==========================
lomox.dll 0.7.0.4 (詹晨辉KeoJam)

1.QT升级到QT5版本，由于QT4和QT5类库不同，不能再用QT4进行编译

2.bugfix

3.增加了系统托盘

4.增加了加载图标

5.增加了窗口父子关系配置

6.增加了打印接口（lxDialog.printPreview()）

7.增加了下载功能


build QT5  LX 0.7.0.4 : http://pan.baidu.com/s/1jGIN5jS
    

www.lomox.org
==============================================
The new version 20140427

Download the new version:

http://pan.baidu.com/s/1mgKBloO

github:

https://github.com/caidongyun/lomox

official: www.lomox.org

Modify points:

[cfg]
url = http://www.baidu.com / / If you specify the url from the url started, if not start the default directory to find their own resources or resources main.lx packaged index.html or main.html

title = https://github.com/caidongyun/lomox|config.ini / /

mainframe = 1 main window if you want to bring a non-client area of ​​a window frame system, one does not need to need 0, 0 is for the use of profiled window

maintop = 1 if the main window Top

childframe = 1 child window if you want to bring a non-client area of ​​a window frame system, one does not need to need 0, 0 is for the use of profiled window

[maindialog]
hrefincurrent = 0 / / main form href link is not currently open to 0, 1 href open in a new child window

[childdialog]
hrefincurrent = 1 / / child window href link is not currently open to 0, 1 href open in a new child window


==============================================

配置：
lomox / Release / config.ini \r\n


[cfg]
url=http://www.baidu.com 
//如果指定url则从url启动，如果没有启动则默认在自己resources 目录下面找 main.lx打包资源 或index.html 或者 main.html  

title=https://github.com/caidongyun/lomox|config.ini \r\n

mainframe=1 
//主窗口是否要带非客户区系统窗口边框，1为需要 0 为不需要，0是给异形窗口使用

maintop=1
//主窗口是否置顶

childframe=1
//子窗口是否要带非客户区系统窗口边框，1为需要 0 为不需要，0是给异形窗口使用

dialogsrelation=0
//父子窗口关系，1为需要 0 为不需要，1是主窗口最小化 子窗口也最小化

systemtray=1
//是否显示系统托盘 1为需要 0 为不需要

trayicon=lomox.ico
//系统托盘 图标，程序目录下

showloadinggif=1
//加载动画 1为需要 0 为不需要

loadinggifwidth=60
loadinggifheight=60
//动画大小

[maindialog]
hrefincurrent=0
//主窗体 href链接是否在当前打开 0为否，href在新子窗口打开

[childdialog]
hrefincurrent=1 
//子窗口  href链接是否在当前打开 0为否，href在新子窗口打开

=======================================================
LxDialog. 当前窗口操作

LxDialog  API控制实例包装库（几百年前的库，终于找到了 by 曹良 超朋）
http://pan.baidu.com/s/1qWJXnxM


===============
LomoX.libs

LomoX.dialogs

LomoX.file

LomoX.dir

LomoX.appPath


LomoX.args


LomoX.version


LomoX.net


LomoX.res

----------------------------------------------------------------------------------------------------------------------------------
js扩展层
http://pan.baidu.com/s/1kT1PcJP
使用说明，里面加了一层库，不懂api可以看 下载文件里面 LxExt

----------------------------------
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
	LxExt.Dialog.moveWnd((LxExt.Dialog.getScreenWidth - LxExt.Dialog.width)/2,(LxExt.Dialog.getScreenHeight - LxExt.Dialog.height)/2);
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




--------------------------------------------------------------------
===================================================


LxExt.Dialog.initWndWH(width, height)
设置窗口初始大小
	width
	类型: int
	指定初始化窗口宽度

	height
	类型：int
	指定初始化窗口高度

LxExt.Dialog.setBorderDrag(drag)
设置边框是否可以拖动
	drag
	类型：boolean
	设置边框是否可以拖动

	return
	类型：boolean
	返回边框是否可以拖动

LxExt.Dialog.dragRegion(element)
指定一个element，使得这个element被拖动时来移动窗口位置
通常element可指向页面中的标题栏，使得拖动标题栏来移动窗口
	element
	类型：jQueryElement
	一个jQuery对像

	例子：
	<body>
		<div id="MyTitle">LxExt.Dialog 演示
			<span id="btnExit" class="MyCloseButton" title="退出演示程序">[退出]</span>
			<span id="btnMax" class="MyCloseButton" title="最大化">[最大]</span>
			<span id="btnMin" class="MyCloseButton" title="最小化">[最小]</span>
		</div>
		<script type="text/javascript">
			// 标题栏拖动可移动窗口
			LxExt.Dialog.dragRegion($("#MyTitle"));
		</script>
	</body>

LxExt.Dialog.borderDrag(objBody, obj, size)
设定objBody与obj两个DIV之间的边距位置可以实现窗口大小调整
	objBody
	类型：jQueryElement
	外层DIV的jQuery对像

	obj
	类型：jQueryElement
	内层DIV的jQuery对像

	size
	类型：int
	objBody与obj两个DIV之间的边距
	默认为5

	例子
	<body>
		<div id="MyWindow">
			<div id="MyTitle">LxExt.Dialog 演示
				<span id="btnExit" class="MyCloseButton" title="退出演示程序">[退出]</span>
				<span id="btnMax" class="MyCloseButton" title="最大化">[最大]</span>
				<span id="btnMin" class="MyCloseButton" title="最小化">[最小]</span>
			</div>
			<div id="MyBody">窗体内容区域<span id="test"></span></div>
		</div>
		<script type="text/javascript">
			// 标题栏拖动可移动窗口
			LxExt.Dialog.dragRegion($("#MyTitle"));
			// 使得#MyWindow 与 #MyBody两个DIV之间的边距5px的位置可以实现窗口大小调整
			LxExt.Dialog.borderDrag($("#MyBody"),$("#MyWindow"), 5);
		</script>
	</body>

LxExt.Dialog.moveWnd(x,y)
移动窗口至x,y坐标处
	x
	类型：int
	指定窗口移动到x坐标

	y
	类型：int
	指定窗口移动到y坐标

LxExt.Dialog.showMaximized()
最大化窗口

LxExt.Dialog.isMaximized()
判断窗口是否最大化
	return
	类型：boolean
	返回窗口是否已经最大化

LxExt.Dialog.showMinimized()
最小化窗口

LxExt.Dialog.isMinimized()
判断窗口是否最小化
	return
	类型：boolean
	返回窗口是否已经最小化

LxExt.Dialog.showNormal()
窗口最大化或最小化时，恢复窗口的大小

LxExt.Dialog.closeWnd()
关闭窗口

LxExt.Dialog.getMinWidth()
取得当前窗口限制的最小宽度
	return
	类型：int
	返回当前窗口限制的最小宽度

LxExt.Dialog.getMinHeight()
取得当前窗口限制的最小高度
	return
	类型：int
	返回当前窗口限制的最小高度

LxExt.Dialog.getMaxWidth
取得当前窗口限制的最大宽度
	return
	类型：int
	返回当前窗口限制的最大宽度

LxExt.Dialog.getMaxHeight
取得当前窗口限制的最大高度
	return
	类型：int
	返回当前窗口限制的最大高度

LxExt.Dialog.setMinimumSize(width, height)
限制当前窗口最小宽度和最小高度
	width
	类型：int
	限制当前窗口最小宽度

	height
	类型：int
	限制当前窗口最小高度

LxExt.Dialog.setMinimumWidth(width)
限制当前窗口最小宽度
	width
	类型：int
	限制当前窗口最小宽度

LxExt.Dialog.setMinimumHeight(height)
限制当前窗口最小高度
	height
	类型：int
	限制当前窗口最小高度

LxExt.Dialog.setMaximumSize(width, height)
限制当前窗口最大宽度和最大高度
	width
	类型：int
	限制当前窗口最大宽度

	height
	类型：int
	限制当前窗口最大高度

LxExt.Dialog.setMaximumWidth(width)
限制当前窗口最大宽度
	width
	类型：int
	限制当前窗口最大宽度

LxExt.Dialog.setMaximumHeight(height)
限制当前窗口最大高度
	height
	类型：int
	限制当前窗口最大高度

LxExt.Dialog.getScreenWidth()
获取屏幕宽度
	return
	类型：int
	返回屏幕宽度

LxExt.Dialog.getScreenHeight()
获取屏幕高度
	return
	类型：int
	返回屏幕高度

LxExt.Dialog.centerWnd()
窗口屏幕居中

LxExt.Dialog.showWnd()
显示窗口

LxExt.Dialog.hideWnd()
隐藏窗口

LxExt.Dialog.Reload()
重新加载UI资源

LxExt.Dialog.openURL(url)
默认浏览器打开网址

LxExt.Dialog.exec(exeName)
启动应用程序
	exeName
	类型：string
	应用程序路径

LxExt.Dialog.updateClientSize(objClient, offset)
调整指定objClient对像的偏移位置
	objClient
	类型：jQueryElement
	需要调整偏移位置的元素的jQuery对像

	offset
	类型：int
	要调整的偏移值

LxExt.Transition.Button(config)
动画按钮类，实现图片按钮的过渡动画
	config
	类型：JSON
	config:{
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
 
 
 
