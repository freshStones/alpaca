#coding=utf-8
from urllib import urlencode
import uuid
import sys
import types
import datetime
import time
import MySQLdb
import math
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver
from selenium.webdriver.support.wait import WebDriverWait 
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.common.by import By

def dbinsert(conn,cur,flightNo,isTransferred,flightSequence,airplaneType,flightDate,departureTime,arrivalTime,departureAirport,arrivalAirport,lowestPrice,quotationSource):	
	today = datetime.datetime.now()
	query ="insert into FlightPriceQuotation(flightNo,isTransferred,flightSequence,airplaneType,flightDate,departureTime,arrivalTime,departureAirport,arrivalAirport,lowestPrice,quotationSource,accquiredTime,flightQuotationUUID) values(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,from_unixtime(%s),%s)"
	value = (flightNo,isTransferred,flightSequence,airplaneType,flightDate,departureTime,arrivalTime,departureAirport,arrivalAirport,lowestPrice,quotationSource,time.mktime(today.timetuple()),uuid.uuid1())
	cur.execute(query,value);
	conn.commit()

def calcnode(node,src):
	fl = node.find_element_by_class_name('c1')
	tm = node.find_element_by_class_name('c2')
	local = node.find_element_by_class_name('c3')
	
	fl_name = fl.find_element_by_class_name('a_name').text
	fl_model = fl.find_element_by_class_name('a_model').text
	tm_dep = tm.find_element_by_class_name('a_tm_dep').text
	tm_arv = tm.find_element_by_class_name('a_tm_arv').text
	local_dep = local.find_element_by_class_name('a_lacal_dep').text
	local_arv = local.find_element_by_class_name('a_local_arv').text

	return (fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)

def onepage(dep,arv,ti,src):
	data = {
	'searchDepartureAirport' : dep,
	'searchArrivalAirport' : arv,
	'searchDepartureTime' : ti,
	'searchArrivalTime' : ti,
	'nextNDays' : 0,
	'startSearch' : 'true',
	'from' : 'qunarindex'
	}
	url = 'http://flight.qunar.com/site/oneway_list.htm?' + urlencode(data)

	driver = webdriver.Firefox()
	driver.get(url)
	try:
		webdriver.support.wait.WebDriverWait(driver,20).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg2'),'搜索结束'))
		driver.quit()
		return
	except Exception as e:
		print "have flight from "+dep+''+arv

		webdriver.support.wait.WebDriverWait(driver,30).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'dec'),'搜索结束'))
	script = "var editPrice = function(price, pos, num) { var t = price.split(''); t[t.length - pos] = num; return t.join(''); }; var getPriceById = function(itemId) { var prices = document.getElementById(itemId).getElementsByClassName('prc')[0].getElementsByTagName('b'); var width = 0; var price = 0; for (var i = 0; i < prices.length; ++i) { if (prices[i].style.width) { width = prices[i].style.width; width = width.substring(0, width.indexOf('px')); price = prices[i].innerHTML; } else { var left = prices[i].style.left; left = Math.abs(left.substring(0, left.indexOf('px'))); price = editPrice(price, left / 11, prices[i].innerHTML); } } for (var i = prices.length - 1; i > 0; --i) { prices[i].parentNode.removeChild(prices[i]); } prices[0].innerHTML = price; return price; }; var key = new Array(); var priceArray = new Array(); var d = document.getElementById('hdivResultPanel').children; for (var i = 0; i < d.length; ++i) { key[i] = d[i].id; priceArray[i] = getPriceById(d[i].id); } "

	a = 1
	while  a == 1:
		try:
			driver.execute_script(script)
			result = driver.find_element_by_id('hdivResultPanel').find_elements_by_class_name('avt_column')

			conn = MySQLdb.connect(host='162.105.30.115',user='remote',passwd='alpaca',db='airTicketOnline',port=3306,charset='utf8')
			cur = conn.cursor()

			for i in range(0,len(result)):
				istrans = 0
				c6 = result[i].find_element_by_class_name('c6')
				prc = c6.find_element_by_class_name('prc').text
				try:	
					first = result[i].find_element_by_class_name('avt_column_1st')
					(fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)=calcnode(first,src)

					istrans = 1
					dbinsert(conn,cur,fl_name,istrans,'FIRST',fl_model,ti,tm_dep,tm_arv,local_dep,local_arv,prc,src)

					transcity  = result[i].find_element_by_class_name('avt_column_sp').text

					second = result[i].find_element_by_class_name('avt_column_2nd')
					(fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)=calcnode(second,src)
					dbinsert(conn,cur,fl_name,istrans,'SECOND',fl_model,ti,tm_dep,tm_arv,local_dep,local_arv,prc,src)

				except Exception as e:
#					print e
					print 'straight';
#print e
				if istrans == 0:
					try:
						origin = result[i].find_element_by_class_name('b_avt_lst')	
						(fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)=calcnode(origin,src)
						dbinsert(conn,cur,fl_name,istrans,'FIRST',fl_model,ti,tm_dep,tm_arv,local_dep,local_arv,prc,src)
					except Exception as e:
						print e
						print 'trans'	

			nextp = driver.find_element_by_id('nextXI3')
			nextp.click()
		except Exception as e:
#			print e
			a = 0
			
	driver.quit()


f = open('pairs.lst')
text = f.read();
line = text.split('\n')
line.pop()
j = 0
for i in line:
	j = j + 1
	print j
	[dep,arv] = i.split(' ')
	print datetime.datetime.now()
	onepage(dep,arv,'2013-11-13','qunar.com')
