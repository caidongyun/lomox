lomox
=====

lomox is a desktop web ui framework 
www.lomox.org


配置：
lomox / Release / config.ini 
[cfg]
url=http://www.baidu.com
title=https://github.com/caidongyun/lomox|config.ini
mainframe=1
maintop=1
childframe=1

[maindialog]
hrefincurrent=0


[childdialog]
hrefincurrent=1


[cfg]
url=http://www.baidu.com //如果指定url则从url启动，如果没有启动则默认在自己resources 目录下面找 main.lx打包资源 或index.html 或者 main.html  

title=https://github.com/caidongyun/lomox|config.ini // 

mainframe=1  主窗口是否要带非客户区系统窗口边框，1为需要 0 为不需要，0是给异形窗口使用

maintop=1 主窗口是否置顶

childframe=1 子窗口是否要带非客户区系统窗口边框，1为需要 0 为不需要，0是给异形窗口使用


[maindialog]
hrefincurrent=0 主窗体 href链接是否在当前打开 0为否，href在新子窗口打开

[childdialog]
hrefincurrent=1 子窗口  href链接是否在当前打开 0为否，href在新子窗口打开

 
