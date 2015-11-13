/**
*日期 ：2010-04-23
*作者 ：Fantasy 目前求职ing:计算机本科，工作5年(3年电信方面)，熟悉JAVA,Javascript.. 地点:成都 目标职位：高级JAVA工程师、架构师、技术经理 
*Email: fantasycs@163.com
*QQ   : 8635335
*Blog : http://www.blogjava.net/fantasy
*版本 ：V1.0
*/

/*
实例：
jQuery( function(){
	var options = {tabID:"Tabs",frameID:"Frames",activeClass:"on",lockClass:"locked",leftID:"Left",
	rightID:"Right",resetID:"Reset",closeID:"Close"};
	window.tab = FantasyTab.create(options);
	window.tab.add({id:"4",name:"搜狗",lock:false,url:"http://www.sogou.cn",title:"搜狗-中国最大的搜索引擎"});
	window.tab.add({id:"5",name:"百度",lock:true,url:"http://www.baidu.com",title:"百度-中国最大的搜索引擎"});
});
*/
window.AbstractTab = {};
AbstractTab.add = function( option ){
	// 如果已经存在,就激活该菜单
	if( this.isExist(option.id) ){
		this.click(option.id);
		return false;
	}
	this.addTab(option);
	this.addFrame(option);
};

// 添加一个Tab
AbstractTab.addTab = function( option ){
	var _this = this;
	var id = option.id;
	var isLock = (option.lock ? true : false);
	var lock = option.lock ? this.lockClass : "";
	var active = this.activeClass;
	var title = option.title ? option.title : "";
	var name = this.getCutName(option.name);
	var args = {id:id,name:name,active:active,title:title,lock:lock,isLock:isLock};
	var html = this.getTabHtml(args);
	var element = jQuery(html);
	// 绑定选择事件并触发。
	element.click( function(){
		_this.click(this.id);
	}).click();
	// 绑定关闭按钮事件
	element.find(".closeTab").click( function(){
		_this.close(jQuery(this).parent().attr("id"));
		return false;
	});
	element.appendTo(this.tabs);
};

// 取得HTML
AbstractTab.getTabHtml = function( o ){
	var li = "<li lock='" + o.isLock + "' id='" + o.id + "' class='" + o.active + "'  title='" + o.title + "'> \n";
	li += "<a href=\"#\" class='li " + o.lock + "'> \n";
	li += "<span class=\"left\"></span> \n";
	li += "<span class=\"text\"><span>" + o.name + "</span></span> \n";
	li += "<span class=\"right\"></span></a>\n";
	li += "<a href='javascript:void(0)' class='closeTab'></a>\n";
	li += "</li> \n";
	return li;
};

// 点击标签
AbstractTab.click = function( id ){
	this.tabs.find("li").removeClass(this.activeClass);
	jQuery("#" + id).addClass(this.activeClass);
	this.loadFrame(id);
};

// 判断标签是否存在
AbstractTab.isExist = function( id ){
	return jQuery("#" + id).size() > 0;
};

// 取得简短的名称
AbstractTab.getCutName = function( name ){
	var text = new String(name);
	if( text.length > 7 ){
		return text.substring(0,7) + "...";
	}
	return text;
};
// 添加Frame
AbstractTab.addFrame = function( option ){
	var url = option.url;
	var id = this.getFrameID(option.id);
	var frame = option.frame || {};
	var style = frame.style || "width:100%;height:100%";
	var name = frame.name || id;
	var frame = "<iframe id='" + id + "' name='" + name + "' frameborder='0' style='" + style + "' src='" + url + "'></iframe>";
	jQuery(frame).appendTo(this.frames);
	this.loadFrame(option.id);
};

// 加载Tab对应的Frame
AbstractTab.loadFrame = function( id ){
	var id = this.getFrameID(id);
	this.frames.find("iframe").hide();
	jQuery("#" + id ).show();
};

// 取得FrameID
AbstractTab.getFrameID = function( id ){
	return "Frame" + id;
};

// 关闭Tab
AbstractTab.close = function( id ){
	var activeClass = this.activeClass;
	var tab = jQuery("#" + id);
	var lock = tab.attr("lock");
	var isActive = tab.hasClass(activeClass);
	if(  lock != "true" ){
		var frame = jQuery("#" + this.getFrameID(id) );
		// 如果当前标签是激活状态,要不打开后一个，要不打开前一个
		if( isActive ){
			if( tab.next().is("li") ){
				tab.next().click();
			}else if( tab.prev().is("li") ){
				tab.prev().click();
			}
		}
		tab.remove();// 删除Tab
		frame.remove();// 删除IFrame
	}
};

// 关闭所有
AbstractTab.closeAll = function(){
	var _this = this;
	// 删除没有锁定的标签
	this.tabs.find("li[lock!='true']").each( function(){
		jQuery(this).remove();
		var id = _this.getFrameID(this.id);
		jQuery("#" + id).remove();
	});
	var activeClass = this.activeClass;
	// 如果没有激活的锁定的标签，那么激活最后一个锁定的标签。
	if( this.tabs.find("." + activeClass).size() == 0 ){
		this.tabs.find("li:last").click();
	}
};

// 锁定/解锁
AbstractTab.lock = function( id , lock ){
	var lockClass = this.lockClass;
	jQuery("#" + id).attr("lock",new String(lock));
	var a = jQuery("#" + id ).find("a");
	if( lock ){
		a.addClass(lockClass);
	}else{
		a.removeClass(lockClass);
	}
};

// 左移、右移动、重置
AbstractTab.move = function( option ){
	if( option.action == "left" ){
		this.tabs.find("li:hidden:last").show();
	}else if(option.action == "right"){
		this.tabs.find("li:visible:first").hide();
	}else if(option.action == "reset"){
		this.tabs.find("li").show();
	}
};

// 初始化
AbstractTab.init = function(){
	var _this = this;
	jQuery("#" + this.leftID ).click( function(){
		_this.move({action:'left'});
	});
	jQuery("#" + this.rightID ).click( function(){
		_this.move({action:'right'});
	});
	jQuery("#" + this.resetID ).click( function(){
		_this.move({action:'reset'});
	});
	jQuery("#" + this.closeID ).click( function(){
		_this.closeAll();
	});
	return this;
};

// 定义类型
window.FantasyTab = function( option ){
	var op = option || {}
	this.tabID = op.tabID || "Tabs";
	this.frameID = op.frameID || "Frames";
	this.activeClass = op.activeClass || "on";
	this.lockClass = op.lockClass || "locked";
	this.leftID = op.leftID || "Left";
	this.rightID = op.rightID || "Right";
	this.resetID = op.resetID || "Reset";
	this.closeID = op.closeID || "Close";
	this.tabs = jQuery("#" + this.tabID);
	this.frames = jQuery("#" + this.frameID);
};
// 继承 AbstractTab;
jQuery.extend(FantasyTab.prototype,AbstractTab);

//传说中的静态方法.......
window.FantasyTab.create = function( option ){
	var tab = new FantasyTab(option);
	return tab.init();
};