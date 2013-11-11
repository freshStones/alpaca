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

def genurl(dep,arv,ti):
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
	return url

def filewriter(fileid,strtow):
	while fileflag[fileid] == 1:
		time.sleep(2)
	fileflag[fileid] = 1
	filelist[fileid].write(strtow)
	filelist[fileid].flush()
	fileflag[fileid] = 0


def onedriver(ti,src):
	fp = webdriver.FirefoxProfile()
	fp.set_preference('network.proxy.type',1)
	fp.set_preference('network.proxy.no_proxies_on', "api.qunar.com hotel.qunar.com img1.qunarzz.com simg4.qunarzz.com source.qunar.com userimg.qunar.com history.qunar.com qunarzz.com")
	driver = webdriver.Firefox(fp)
	driver.set_page_load_timeout(45)
	driver.set_script_timeout(60)

	while line:
		[dep,arv]=line.pop().split(' ')
		proxy = ipline.pop()
		[ip,port] = proxy.split(':')
		print ip + ' ' + port
#		fp.set_preference("network.proxy.http",ip)
#		fp.set_preference("network.proxy.http_port",string.atoi(port))
#		fp.update_preferences()
		print 'new '  + dep +' '+arv+' '
		print datetime.datetime.now()
		res = onepage(driver,dep,arv,ti,src)
		if 'bad proxy' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			deadIP.append(proxy)
		elif 'identify code' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			lockIP.append(proxy)
		elif 'time exceeded' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			slowIP.append(proxy)
		elif 'no flight' in res:
			filewriter('fex',dep+' '+arv+'\n')
			activeIP.append(proxy)
		elif 'have flight' in res:	
			filewriter('fin',dep+' '+arv+'\n')
			activeIP.append(proxy)
		elif 'errorPage' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			deadIP.append(proxy)
		else:
			print 'amazing!!'	
		print res
	driver.quit()

def onepage(driver,dep,arv,ti,src):
	url = genurl(dep,arv,ti)	
	try:
		driver.get(url)
	except Exception as e:
		return "bad proxy"
	time.sleep(40)
	cururl = driver.current_url
	if 'busy' in cururl:
		return "identify code found"
	try:
		webdriver.support.wait.WebDriverWait(driver,60).until_not(webdriver.support.expected_conditions.text_to_be_present_in_element((By.CLASS_NAME,'msg'),'请稍等'))
	except Exception as e:
		return "time exceeded"
	try:	
		driver.find_element_by_class_name('msg2')
		return 'no flight'
	except Exception as e:
#		print e
		a = 1
	try:
		driver.find_element_by_class_name('dec')
		return 'have flight'
	except Exception as e:
#		print e
		a = 1
	return 'errorPage'

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
filelist = {
	'f':f,
	'fpro':fpro,
	'fex':fex,
	'fin':fin,
	'fuh':fuh
}
fileflag ={ 
	'f':0,
	'fpro':0,
	'fex':0,
	'fin':0,
	'fuh':0
}

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

for i in range(0,1):
	t = threading.Thread(target=onedriver,args=('2013-11-13','qunar.com'))
	t.start()
	time.sleep(2)
while line:
	time.sleep(60)
fex.close()
fin.close()
fuh.close()
