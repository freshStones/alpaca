import sys
import types
import datetime
import time
import MySQLdb
import math
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver
def calcnode(node):
	fl = node.find_element_by_class_name('company').text
	tm = node.find_element_by_class_name('time').text
	local = node.find_element_by_class_name('port').text

	print fl
	print fl.split('\n');
#	(fl_name ,fl_model) = fl.split('\n')
#	(tm_dep,tm_arv) = tm.split('\n')
#	(local_dep ,local_arv) = local.split('\n')

#	return (fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)
	return (fl,fl,tm,tm,local,local)

driver = webdriver.Firefox()
driver.get('http://s.jipiao.trip.taobao.com/flight_search_result.htm?searchBy=1280&spm=181.1113091.a1z0v.1&depCityName=%B1%B1%BE%A9&depCity=BJS&arrCityName=%C9%CF%BA%A3&arrCity=SHA&tripType=0&depDate=2013-11-12&arrDate=')
time.sleep(20)

#conn = MySQLdb.connect(host='162.105.30.55',user='remote',passwd='alpaca',db='airTicketOnline',port=3306,charset='utf8')
#		cur = conn.cursor()
a = 1
if  a == 1:
	try:
		result = driver.find_element_by_class_name('inner').find_elements_by_class_name('J_onePlane')
		for i in range(0,len(result)):
			today = datetime.datetime.now()
			
			prc = result[i].find_element_by_class_name('price').text
			
			(fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv)=calcnode(result[i])
			print fl_name+fl_model+tm_dep+tm_arv+local_dep+local_arv+prc
			query ="insert into onlinePrice(flightNo,airplaneType,departureTime,arrivalTime,departureAirport,arrivalAirport,lowestPrice,webSource,accquiredTime) values(%s,%s,%s,%s,%s,%s,%s,'qunar.com',from_unixtime(%s))"
			value = (fl_name,fl_model,tm_dep,tm_arv,local_dep,local_arv,prc,time.mktime(today.timetuple()))
#cur.execute(query,value);
#			conn.commit()
	except Exception as e:
		print e
		a = 0
#print e

				

		
driver.quit()


