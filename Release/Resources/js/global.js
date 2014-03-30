$(document).ready(function() {
	$(document).on('click', function() {
		$('#lx-nav-menu', parent.document).fadeOut('fast');
	}).on('contextmenu', function() {
		return false;
	});
});

