import sys
import time
import math
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver
driver = webdriver.Firefox()
driver.get('http://flight.qunar.com/site/oneway_list.htm?searchDepartureAirport=%E5%8C%97%E4%BA%AC&searchArrivalAirport=%E4%B8%8A%E6%B5%B7&searchDepartureTime=2013-10-29&searchArrivalTime=2013-10-29&nextNDays=0&sd_idx=0&SearchLocation=sevenday_search');

html = driver.page_source
time.sleep(10)

file_object = open("datagrab.txt",'w')
script="var editPrice = function(price, pos, num) { var t = price.split(''); t[t.length - pos] = num; return t.join(''); }; var getPriceById = function(itemId) { var prices = document.getElementById(itemId).getElementsByClassName('prc')[0].getElementsByTagName('b'); var width = 0; var price = 0; for (var i = 0; i < prices.length; ++i) { if (prices[i].style.width) { width = prices[i].style.width; width = width.substring(0, width.indexOf('px')); price = prices[i].innerHTML; } else { var left = prices[i].style.left; left = Math.abs(left.substring(0, left.indexOf('px'))); price = editPrice(price, left / 11, prices[i].innerHTML); } } return price; }; var key = new Array(); var priceArray = new Array(); var d = document.getElementById('hdivResultPanel').children; for (var i = 0; i < d.length; ++i) { key[i] = d[i].id; priceArray[i] = getPriceById(d[i].id); } alert(priceArray); "
driver.execute_script(script)
a = 1
while  a == 1:
	try:
		time.sleep(10)
		data = driver.find_element_by_id('hdivResultPanel').text
#		print data
		file_object.write(data)

		nextp = driver.find_element_by_id('nextXI3')
		nextp.click()
	except Exception as e:
		a = 0
		
file_object.close()
driver.quit()


