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

def onepage(proxy,dep,arv,ti,src):
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
	pro.httpProxy = proxy
	pro.noProxy = "api.qunar.com hotel.qunar.com img1.qunarzz.com simg4.qunarzz.com source.qunar.com userimg.qunar.com history.qunar.com qunarzz.com"
	pro.proxyType = ProxyType.MANUAL
	
	fp = webdriver.FirefoxProfile()
#	fp.set_preference("network.http.keep-alive.timeout",45)

	driver = webdriver.Firefox(fp,None,30,None,pro)
#	driver.get('http://www.ip38.com')
#	url = "http://www.facebook.com"
#	time.sleep(50)
	driver.set_page_load_timeout(45)
	driver.set_script_timeout(60)
	try:
		driver.get(url)
	except Exception as e:
		driver.quit()
		print "bad proxy"
		fuh.write(dep+' '+arv+'\n')
		fuh.flush()
		deadIP.append(proxy)
		return "bad proxy"

	flag= 0
	cururl = driver.current_url
	if 'busy' in cururl:
		driver.quit()
		print "identify code found"
		fuh.write(dep+' '+arv+'\n')
		fuh.flush()
		lockIP.append(proxy)
		return "busy"
	else:
		print "not busy"

	try:
		webdriver.support.wait.WebDriverWait(driver,60).until_not(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg'),'请稍等'))
		activeIP.append(proxy)
	except Exception as e:
		driver.quit()
		print 'time exceeded'
		fuh.write(dep+' '+arv+'\n')
		fuh.flush()
		slowIP.append(proxy)
		return "time exceeded"

	try:	
		driver.find_element_by_class_name('msg2')
		driver.quit()
		print 'no flight'
		flag = 1
		fex.write(dep+' '+arv+'\n')
#		fact.write(''.join(proxy)+'\n')
		fex.flush()
#		fact.flush()
		return 'no flight'
	except Exception as e:
#		print e
		a = 1
		
	try:
		driver.find_element_by_class_name('dec')
		driver.quit()
		flag = 1
		print 'have flight'
#		fact.write(''.join(proxy)+'\n')
		fin.write(dep+' '+arv+'\n')
		fin.flush()
#		fact.flush()
		return 'have flight'
	except Exception as e:
#		print e
		a = 1
	if flag == 0:
		driver.quit()
		print "bad network"
		fuh.write(dep+' '+arv+'\n')
		fuh.flush()
		return 'errorPage'

	driver.quit()
	return "the end"

def oneip(proxy,dep,arv,ti,src):
	res = onepage(proxy,dep,arv,ti,src)
	while 'busy' not in res:
		res = onepage(proxy,dep,arv,ti,src)

def wrapitup():
	f0 = open(SOURCEFILE,'r')
	lst0 = f0.read()
	f0.close()
	lines0 = lst0.split('\n')
	f1 = open(EXCLUDEFILE,'r')
	lst1 = f1.read()
	f1.close()
	lines1 = lst1.split('\n')
	f2 = open(INCLUDEFILE,'r')
	lst2 = f2.read()
	f2.close()
	lines2 = lst2.split('\n')
	f3 = open(UNHANDLEFILE,'r')
	lst3 = f3.read()
	f3.close()
	lines3 = lst3.split('\n')
	for i in lines0:
		if len(i) == 0: 
			lines0.remove(i)
			continue 
		if i in lines1 or i in lines2:	
			lines0.remove(i)
			print i
	f4 = open(SOURCEFILE,'w')
	for i  in lines0:
		f4.write(i+'\n')
	f4.close()
	return

SOURCEFILE = 'lst/piece2.lst'
EXCLUDEFILE = 'lst/exclude2.lst'
INCLUDEFILE = 'lst/include2.lst'
UNHANDLEFILE = 'lst/unhandle2.lst'
IPSOURCEFILE = 'lst/newIP.lst'

f = open(SOURCEFILE)
fpro = open(IPSOURCEFILE)
fex = open(EXCLUDEFILE,'w')
fin = open(INCLUDEFILE,'w')
fuh = open(UNHANDLEFILE,'w')

activeIP = []
lockIP = []
slowIP = []
deadIP = []

iplist = fpro.read()
ipline = iplist.split('\n')
ipline.pop()

text = f.read();
line = text.split('\n')
line.pop()
j = 0
for i in line:
#	j = j+ 1
	[dep,arv] = i.split(' ')
	t = threading.Thread(target=onepage,args=(ipline[j],dep,arv,'2013-11-13','qunar.com'))
	t.start()
	print 'new'  + dep +' '+arv+' '
	print datetime.datetime.now()
	time.sleep(1)
	while (len(threading.enumerate())>1):
		time.sleep(2)
#		print 'full'
	j = j + 1
	if j == len(ipline):
		print "ip runs out"
		break;
fex.close()
fin.close()
fuh.close()

wrapitup()
