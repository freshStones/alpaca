var editPrice = function(price, pos, num) {
var t = price.split('');
t[t.length - pos] = num;
return t.join('');
};

var getPriceById = function(itemId) {
var prices = document.getElementById(itemId).getElementsByClassName('prc')[0].getElementsByTagName('b');
var width = 0;
var price = 0;
for (var i = 0; i < prices.length; ++i) {
if (prices[i].style.width) {
width = prices[i].style.width;
width = width.substring(0, width.indexOf('px'));
price = prices[i].innerHTML;
} else {
var left = prices[i].style.left;
left = Math.abs(left.substring(0, left.indexOf('px')));
price = editPrice(price, left / 11, prices[i].innerHTML);
}
}
for (var i = prices.length - 1; i > 0; --i) {
prices[i].parentNode.removeChild(prices[i]);
}
prices[0].innerHTML = price;
return price;
};

var key = new Array();
var priceArray = new Array();
var d = document.getElementById('hdivResultPanel').children;
for (var i = 0; i < d.length; ++i) {
key[i] = d[i].id; 
priceArray[i] = getPriceById(d[i].id);
}
alert(priceArray);

