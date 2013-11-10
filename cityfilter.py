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
	proxy = PROXY
	pro = Proxy()
	pro.httpProxy = PROXY
	pro.proxyType = ProxyType.MANUAL

	driver = webdriver.Firefox(None,None,30,None,pro)
#	driver.get('http://www.ip38.com')
#	url = "http://www.facebook.com"
#	time.sleep(5)
	driver.get(url)
	flagex = 0
	flagin = 0
	try:
		webdriver.support.wait.WebDriverWait(driver,3).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.ID,'errorPageContainer'),'搜索结束'))
	except Exception as e:
		print "good network"
	try:
		webdriver.support.wait.WebDriverWait(driver,20).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg2'),'搜索结束'))
		flagex = 1
		fex.write(dep+' '+arv+'\n')
		fact.write(proxy+'\n')
		fex.flush()
		fact.flush()
	except Exception as e:
		print 'not empty'
	try:	
		webdriver.support.wait.WebDriverWait(driver,30).until(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'dec'),'搜索结束'))
		flagin = 1
		fact.write(proxy+'\n')
		fin.write(dep+' '+arv+'\n')
		fin.flush()
		fact.flush()
	except Exception as e:
		print "no flight"
	if (flagin == 0 and flagex ==0):
		fuh.write(dep+' '+arv+'\n')
		fuh.flush()
		print "bad network"

	driver.quit()

f = open('lst/piece1.lst')
fex = open('lst/exclude1.lst','w')
fin = open('lst/include1.lst','w')
fuh = open('lst/unhandle1.lst','w')
fpro = open('lst/proxyIP.lst')
fact = open('lst/activeIP.lst','w')
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
	while (len(threading.enumerate())>1):
		time.sleep(2)
		print 'full'
fex.close()
fin.close()
fuh.close()
fact.close()
