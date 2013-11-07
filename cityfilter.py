#coding=utf-8
from urllib import urlencode
import uuid
import threading
import thread
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
		f1.write(dep+' '+arv+'\n')
	except Exception as e:
		f2.write(dep+' '+arv+'\n')
	driver.quit()

f = open('pairs.lst')
f1 = open('exclude.lst','w')
f2 = open('include.lst','w')
text = f.read();
line = text.split('\n')
line.pop()
for i in line:
	[dep,arv] = i.split(' ')
#	thread.start_new_thread(onepage,(dep,arv,'2013-11-13','qunar.com'))
	t = threading.Thread(target=onepage,args=(dep,arv,'2013-11-13','qunar.com'))
	t.start()
	print 'new'
#	while (len(threading.enumerate())>2):
#		print 'full'
f1.close()
f2.close()
