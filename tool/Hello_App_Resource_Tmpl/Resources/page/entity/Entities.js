/*
	@author: remy sharp
	@info: http://leftlogic.com/entity-lookup/
	@date: 2007-05-28
	@description: finds and returns entity charaters matching 'like' data
	@license: Creative Commons License - ShareAlike http://creativecommons.org/licenses/by-sa/3.0/
*/

function Entities() {
  if ( window == this ) return new Entities();
  var list = [];
  
  return {
    add: function(e, c, d, l) {
      if (!c) {
        l = e.like;
        d = e.description;
        c = e.code;
        e = e.entity;
      }
      if (typeof l == 'string') l = [l];
      l.push(e);
      l.push(c.toString());
      list.push({ entity: e, code: c, html: '&' + e + ';', description: d, like: l });
      // this.length++;
      return this;
    },
    dump: function() {
      var rlist = list.reverse();
      var i = rlist.length;
      while (i--) {
        console.log('n("' + rlist[i].entity + '", ' + rlist[i].code + ', "' + rlist[i].description + '", ["' + rlist[i].like.join('", "') + '"]);');
      }
    },
    each: function(fn) {
      for (var i = 0; i < list.length; i++) {
        fn.call(list[i], i, !!(i == list.length-1));
      }
      return this;
    },
    find: function(s) {
      s = s.replace(/[&#;]/g, '');
      var i = list.length;
      while (i--) {
        if (list[i].entity == s || list[i].code == s) {
          return list[i];
        }
      }
    },
    get: function(i) {
      return list[i];
    },
    length: function() {
      return list.length;
    },
    like: function(s) {
      var found = Entities();
      if (s.length == 0) return found;
      var flagged = {};
      var i = list.length;
	  var partial = function(s, l) {
        return s.length > 1 ? !!(l.substring(0, s.length) === s) : !!(s == l);
      };
      var parts = s == ' ' ? [' '] : s.toLowerCase().split(' ');
      while (i--) {
        var j = list[i].like.length;
        while (j--) {
		  var m = list[i].like[j].toLowerCase();
          var k = parts.length;
          while (k--) { // tripple loop...::sigh::
            if (partial(parts[k], m) && !flagged[list[i].code]) {
              found.add(list[i]);
              flagged[list[i].code] = true;
            }            
          }
        }
      }
      found.reverse();
      return found;
    },
    list: function() {
      console.log(list);
    },
    reverse: function() {
      list = list.reverse();
    },
    set: function(i, o) {
      list[i] = o;
    }
  };
}

var e = new Entities();
var n = e.add;
