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


def onepage(ip,port,dep,arv,ti,src):
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
	print ip
	print port
	fp = webdriver.FirefoxProfile()
	fp.set_preference("network.proxy.type",1)
	fp.set_preference("network.proxy.http",ip)
	fp.set_preference("network.proxy.http_port",port)

	driver = webdriver.Firefox(firefox_profile=fp)
	driver.get(url)
	try:
		webdriver.support.wait.WebDriverWait(driver,20).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg2'),'搜索结束'))
		f1.write(dep+' '+arv+'\n')
		f1.flush()
	except Exception as e:
		f2.write(dep+' '+arv+'\n')
		f2.flush()
	driver.quit()

f = open('pairs.lst')
f1 = open('exclude.lst','w')
f2 = open('include.lst','w')
fpro = open('proxyIP.txt')
iplist = fpro.read()
ipline = iplist.split('\n')
ipline.pop()

text = f.read();
line = text.split('\n')
line.pop()
j = 0
for i in line:
	j = j+ 1
	[dep,arv] = i.split(' ')
	[ip,port] = ipline[j].split(':')
#	thread.start_new_thread(onepage,(dep,arv,'2013-11-13','qunar.com'))
	t = threading.Thread(target=onepage,args=(ip,port,dep,arv,'2013-11-13','qunar.com'))
	t.start()
	print 'new'
	while (len(threading.enumerate())>3):
		time.sleep(1)
		print 'full'
f1.close()
f2.close()
