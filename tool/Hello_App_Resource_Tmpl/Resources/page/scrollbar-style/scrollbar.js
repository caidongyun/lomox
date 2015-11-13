var Scrollbar = Themes.Default;
var Clone;
var Timer;

function _generateCSS() {
	var key, item, val, n;
	var css = [];
	var button = $('#chkbox-button').attr('checked');
	for(var i in Scrollbar) {
		key = i;
		item = Scrollbar[i];
		if(!button && i.indexOf('button:') === 0) continue;
		
		if(key != 'scrollbar') key = 'scrollbar-' + i;
		key = '::-webkit-' + key;
		val = [];
		for(n in item) {
			val.push(n + ': ' + item[n]);
		}
		if(val.length > 0) {
			css.push(key + ' { ' + val.join('; ') + '; }');
		}
	}
	css = css.join('\n');
	$('#css').html('<pre>' + css + '</pre>');
	
	var style = document.createElement("style");
	$('#css-text').remove();
	style.type = "text/css";
	style.id = "css-text";
	style.textContent = css;
	document.getElementsByTagName("HEAD").item(0).appendChild(style);
	$('#demo-wrap').empty().append(Clone);
}
function generateCSS() {
	clearTimeout(Timer);
	Timer = setTimeout(_generateCSS, 20);
}

function setValue(id, val) {
	var tmp = id.split('_');
	if(val == null) {
		delete Scrollbar[tmp[0]][tmp[1]];
	} else {
		Scrollbar[tmp[0]][tmp[1]] = val;
	}
	generateCSS();
}

function init() {
	var elements = [
		'scrollbar_background-color', 'button_background-color',
		'button_border-color', 'thumb_background-color',
		'thumb_border-color', 'track_background-color'
	];
	var element, tmp;
	for(var i=0, l=elements.length; i<l; i++) {
		element = elements[i];
		tmp = element.split('_');
		if(Scrollbar[tmp[0]][tmp[1]]) {
			$('#' + element).miniColors('value', Scrollbar[tmp[0]][tmp[1]]);
			$('#chkbox-' + element).attr('checked', true);
		} else {
			//$('#' + element).miniColors('value', '#999');
			$('#' + element).miniColors('disabled', true);
			$('#chkbox-' + element).attr('checked', false);
		}
	}
	
	var val, scrollbarWidth;
	val = Scrollbar.scrollbar.width || Scrollbar.scrollbar.width;
	val = parseInt(val, 10) || 10;
	scrollbarWidth = val;
	$('#scrollbar_width').get(0).value = val;
	$('#scrollbar_width').next('output').html(val + 'px');
	val = parseInt(Scrollbar.scrollbar['-webkit-border-radius'], 10) || 6;
	$('#scrollbar_-webkit-border-radius').get(0).value = val;
	$('#scrollbar_-webkit-border-radius').next('output').html(val + 'px');
	val = Scrollbar.button.display != 'none';
	$('#chkbox-button').attr('checked', val);
	val = parseInt(Scrollbar.button['border-width'] || Scrollbar.button['border'], 10) || 1;
	$('#button_border-width').get(0).value = val;
	$('#button_border-width').next('output').html(val + 'px');
	val = parseInt(Scrollbar['button:horizontal:start'], 10) || 6;
	$('#button_radius').get(0).value = val;
	$('#button_radius').next('output').html(val + 'px');
	val = parseInt(Scrollbar.thumb['border-width'] || Scrollbar.thumb['border'], 10) || 1;
	$('#thumb_border-width').get(0).value = val;
	$('#thumb_border-width').next('output').html(val + 'px');
	val = parseInt(Scrollbar.thumb['-webkit-border-radius'], 10) || 6;
	$('#thumb_radius').get(0).value = val;
	$('#thumb_radius').next('output').html(val + 'px');
	val = parseInt(Scrollbar['track:horizontal']['border-width'], 10) || 0;
	val = val == 0? 100: parseInt(val / scrollbarWidth * 100, 10);
	$('#track_width').get(0).value = val;
	$('#track_width').next('output').html(val + '%');
	
	setBoxShadowDefault('scrollbar_-webkit-box-shadow');
	setBoxShadowDefault('thumb_-webkit-box-shadow');
	//setBoxShadowDefault('track_-webkit-box-shadow');
}

function setRangevalueText(element) {
	var unit = element.attr('unit');
	unit = unit == '-'? '': unit || 'px';
	element.next('output').text(element.val() + unit);
}

function setBoxShadowDefault(id) {
	var tmp = id.split('_');
	var val = Scrollbar[tmp[0]][tmp[1]];
	var elem = $('#' + id);
	if(!val) {
		elem.find('select:first').val('');
		elem.children('div:first').hide();
	} else {
		tmp = val.split(' ');
		elem.find('select:first').val(tmp[0]);
		elem.children('div:first').show();
		tmp[1] = parseInt(tmp[1], 10) || 1;
		elem.find('input[name="length"]').get(0).value = tmp[1];
		elem.find('input[name="length"]').next('output').html(tmp[1] + 'px');
		tmp[3] = parseInt(tmp[3], 10) || 1;
		elem.find('input[name="border-radiu"]').get(0).value = tmp[1];
		elem.find('input[name="border-radiu"]').next('output').html(tmp[1] + 'px');
	}
}

function setBoxShadow(id, style) {
	var tmp = id.split('_');
	var css;
	if(style) {
		css	= [
			style.type,
			style.length,
			style.length,
			style.radius,
			style.color
		].join(' ');
		Scrollbar[tmp[0]][tmp[1]] = css;
	} else {
		delete Scrollbar[tmp[0]][tmp[1]];
	}
	generateCSS();
}

function createBoxShadowOption(element) {
	var id = element.attr('id');
	var defaultColor = '#b08b8b';
	var color = element.attr('data-color') || defaultColor;
	var style = {
		'type'	: '',
		'length'	: '1px',
		'radius'	: '1px',
		'color' 	: color
	}
	var select = $(['<select>',
		'<option value="">None</option>',
		'<option value="NO">NO</option>',
		'<option value="inset">Inset</option>',
	'</select>'].join(''));
	var content = $([
		'<div style="display: none;">',
			'<label>Length: </label>',
			'<div class="slider">',
				'<input type="range" name="length" min="0" max="10" step="1" value="1" unit="-" />',
				'<output class="rangevalue">1</output>',
			'</div>',
			'<div class="cb"></div>',
			'<label>Blur Radius: </label>',
			'<div class="slider">',
				'<input type="range" name="border-radiu" min="0" max="30" step="3" value="1" />',
				'<output class="rangevalue">1</output>',
			'</div>',
			'<div class="cb"></div>',
			'<label>Shadow Color: </label>',
			'<div class="slider">',
				'<input type="text" id="button_shadow" class="color-picker black" size="7" value="', color, '" data-opacity=".5" />',
			'</div>',
		'</div>'
	].join(''));
	select.change(function() {
		if(this.value) {
			style.type = this.value == 'NO'? '': this.value;
			setBoxShadow(id, style);
			content.slideDown(100);
		} else {
			setBoxShadow(id, null);
			content.slideUp(100);
		}
	});
	select.appendTo(element);
	$('input[type="range"]', content).change(function() {
		var val = this.value + 'px';
		setRangevalueText($(this));
		if(this.name = 'length') {
			style.length = val;
		} else {
			style.radius = val;
		}
		setBoxShadow(id, style);
	});
	$('.color-picker', content).miniColors({
		change: function(hex, rgba) {
			style.color = 'rgba(' + rgba.r + ', ' + rgba.g + ', ' + rgba.b + ', ' + rgba.a + ')';
			setBoxShadow(id, style);
		}
	});
	content.appendTo(element);
}

$(document).ready(function() {
	var css = '';
	Clone = $('#demo').clone();
	
	var presets = [];
	for(var name in Themes) {
		presets.push('<option value="' + name + '">' + name + '</option>');
	}
	$('#presets').append(presets.join(''));
	$('#presets').change(function() {
		Scrollbar = Themes[this.value];
		init();
		_generateCSS();
	});
	
	$('#scrollbar_width').change(function() {
		Scrollbar.scrollbar.width = this.value + 'px';
		Scrollbar.scrollbar.height = this.value + 'px';
		generateCSS();
	});
	
	$('#chkbox-button').attr('checked', Scrollbar.button.display == 'inline').click(function() {
		Scrollbar.button.display = this.checked? 'inline': 'none';
		generateCSS();
	});
	$('#button_radius').change(function() {
		var radius = this.value + 'px';
		Scrollbar['button:horizontal:start']['-webkit-border-radius'] = radius + ' 0 0 ' + radius;
		Scrollbar['button:horizontal:end']['-webkit-border-radius'] = '0 ' + radius + ' ' + radius + ' 0';
		Scrollbar['button:vertical:start']['-webkit-border-radius'] = radius + ' ' + radius + ' 0 0';
		Scrollbar['button:vertical:end']['-webkit-border-radius'] = '0 0 ' + radius + ' ' + radius;
		generateCSS();
	});
	$('#button_border-width, #button_border-color, #thumb_border-width, ' +
		'#scrollbar_-webkit-border-radius, ' +
		'#track_background-color, #thumb_border-color').change(function() {
		setValue(this.id, this.value + 'px');
	});
	$('#track_-webkit-border-radius').change(function() {
		Scrollbar['track-piece']['-webkit-border-radius'] = this.value + 'px';
		generateCSS();
	});
	
	$('#thumb_radius').change(function() {
		Scrollbar.thumb['-webkit-border-radius'] = this.value + 'px';
		generateCSS();
	});
	
	$('#track_width').change(function() {
		var max = $(this).attr('max') * 1;
		var val = (max - this.value * 1) / max;
		if(val == 1) {
			Scrollbar['track:horizontal']['border-width'] = 'none';
			Scrollbar['track:vertical']['border-width'] = 'none';
		} else {
			val = parseInt(($('#scrollbar_width').val() / 2 * val), 10);
			Scrollbar['track:horizontal']['border-width'] = val + 'px 0';
			Scrollbar['track:vertical']['border-width'] = '0 ' + val + 'px';
		}
		generateCSS();
	});
	
	$('input[type="range"]').change(function() {
		setRangevalueText($(this));
	});
	$('input:checkbox').click(function() {
		if(this.id != 'chkbox-button') {
			var target = this.id.substring(7);
			setValue(target, this.checked? $('#' + target).val(): null);
			$('#' + target).miniColors('disabled', !this.checked);
		}
	});
	$('.color-picker').miniColors({
		change: function(hex, rgba) {
			setValue(this.id, hex);
		}
	});
	$('.boxshadow-options').each(function() {
		createBoxShadowOption($(this));
	});
	
	init();
	_generateCSS();
});