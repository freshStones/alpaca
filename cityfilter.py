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
import string
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
from selenium.webdriver.support.wait import WebDriverWait 
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.common.by import By
from selenium.webdriver.common.proxy import ProxyType

from selenium.webdriver.common.proxy import Proxy

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
	pro = Proxy()
	pro.httpProxy = PROXY
	pro.proxyType = ProxyType.MANUAL

	driver = webdriver.Firefox(None,None,30,None,pro)
	driver.get('http://www.ip38.com')
	print fp.path
	time.sleep(300)
	driver.get(url)
	try:
		webdriver.support.wait.WebDriverWait(driver,20).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg2'),'搜索结束'))
		f1.write(dep+' '+arv+'\n')
		f1.flush()
	except Exception as e:
		f2.write(dep+' '+arv+'\n')
		f2.flush()
	driver.quit()

f = open('lst/pairs.lst')
f1 = open('lst/exclude.lst','w')
f2 = open('lst/include.lst','w')
fpro = open('lst/proxyIP.lst')
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
	PROXY = ipline[j]
#	thread.start_new_thread(onepage,(dep,arv,'2013-11-13','qunar.com'))
	t = threading.Thread(target=onepage,args=(dep,arv,'2013-11-13','qunar.com'))
	t.start()
	print 'new'
	time.sleep(1)
	while (len(threading.enumerate())>5):
		time.sleep(2)
		print 'full'
f1.close()
f2.close()
