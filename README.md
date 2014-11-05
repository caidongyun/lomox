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


 
 
