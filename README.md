lomox
=====
    lomox is a desktop web ui framework 
    
build：
===========
    vs 2008   
    下载  qt-win-opensource-4.8.4-vs2008.exe 安装
    再下载 qt-vs-addin-1.1.11-opensource.exe
    其他自己调整 
    
    
    

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


[maindialog]
hrefincurrent=0
//主窗体 href链接是否在当前打开 0为否，href在新子窗口打开

[childdialog]
hrefincurrent=1 
//子窗口  href链接是否在当前打开 0为否，href在新子窗口打开

=======================================================
LxDialog. 当前窗口操作

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
 
 
