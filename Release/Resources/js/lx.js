var WindowSettings = {
	minWidth: 800,
	minHeight: 600,
	width: screen.width - 100,
	height: 640,
	center: true,
	debug: true
}

$(function(){
	//添加窗口Resize
	//LxExt.Dialog.setBorderDrag(true);
	//LxExt.Dialog.borderDrag($("#MyBody"),$("#MyWindow"),5);
	//设置最小大小
	LxExt.Dialog.setMinimumSize(WindowSettings.minWidth, WindowSettings.minHeight);
	//设置窗口的大小
	LxExt.Dialog.initWndWH(WindowSettings.width, WindowSettings.height);
	//窗口居中
	WindowSettings.center && LxExt.Dialog.centerWnd();
	//LxExt.Dialog.updateClientSize($("#MyBody"),30);
	//设置窗口标题栏目可移动
	LxExt.Dialog.dragRegion($('#lx-head>label'));
	//添加 最小化，关闭事件
	var _max = function() {
		if($("#lx-max").hasClass('lx-normal')) {
			$("#lx-max").removeClass('lx-normal');
			LxExt.Dialog.showNormal();
		} else {
			$("#lx-max").addClass('lx-normal');
			LxExt.Dialog.showMaximized();
		}
	}
	$("#lx-max").on('mouseup', _max);
	$('#lx-title>label').dblclick(_max);
	$("#lx-min").on('mouseup', function(){
		LxExt.Dialog.showMinimized();
	});
	$("#lx-close").on('mouseup', function(){
		LxExt.Dialog.closeWnd();
	});

});

//Debug 设置
if(WindowSettings.debug) {
	$(window).keydown(function(event) {
		if(event.keyCode == 116) {
			location.reload();
		}
	});
}
