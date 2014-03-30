var Page = new function() {
	this.turn = function(from, to, url, method) {
		var turn = function(from, to, method) {
			if(method != 'back') {
				from.removeClass().addClass('content animated fadeOutLeft');
				to.removeClass().addClass('content current animated fadeInRight');
			} else {
				from.removeClass().addClass('content animated fadeOutRight');
				to.removeClass().addClass('content current animated fadeInLeft').find('[autofocus]').focus();
			}
			$('#lx-back').fadeIn();
			$(to).trigger('ready');
		}

		var f = $(from);
		var t = $(to);
		if(url == 'back') {
			method = url;
		}
		if(t.length == 0) {
			var t = $('<div class="content" id="' + (to.replace(/^#/, '')) + '"></div>');
			t.html('<iframe src="' + url + '" frameborder="no"></iframe>');
			t.appendTo('#lx-body');
			turn(f, t, method);
		} else {
			turn(f, t, method);
		}
	}
}