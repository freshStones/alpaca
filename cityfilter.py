#coding=utf-8
from urllib import urlencode
import uuid, threading, thread, sys, getopt, types, datetime, time, MySQLdb, string
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

def getfpconfig(proxy):
	fp = webdriver.FirefoxProfile()
	[ip,port] = proxy.split(':')
	fp.set_preference("network.proxy.http",ip)
	fp.set_preference("network.proxy.http_port",string.atoi(port))
	fp.set_preference('network.proxy.type',1)
	fp.set_preference('network.proxy.no_proxies_on', "api.qunar.com hotel.qunar.com img1.qunarzz.com simg4.qunarzz.com source.qunar.com userimg.qunar.com history.qunar.com qunarzz.com")
	return fp

def onedriver(ti,src):
	proxy = ipline.pop()
	fp = getfpconfig(proxy)
#	fp = webdriver.FirefoxProfile()

	driver = webdriver.Firefox(fp)
	driver.set_page_load_timeout(45)
	driver.set_script_timeout(60)

	while line:
		[dep,arv]=line.pop().split(' ')
		print 'new '  + dep +' '+arv+' '
		print datetime.datetime.now()
		res = onepage(driver,dep,arv,ti,src)
		print res
		if 'bad proxy' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			deadIP.append(proxy)
			break
		elif 'identify code' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			lockIP.append(proxy)
			break
		elif 'time exceeded' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			slowIP.append(proxy)
			break
		elif 'no flight' in res:
			filewriter('fex',dep+' '+arv+'\n')
			activeIP.append(proxy)
		elif 'have flight' in res:	
			filewriter('fin',dep+' '+arv+'\n')
			activeIP.append(proxy)
		elif 'errorPage' in res:
			filewriter('fuh',dep+' '+arv+'\n')
			deadIP.append(proxy)
			break
		else:
			print 'amazing!!'	
	driver.quit()

def onepage(driver,dep,arv,ti,src):
	url = genurl(dep,arv,ti)	
	try:
		driver.get(url)
	except Exception as e:
		return "bad proxy"
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

startp = 0
endp = 50000
opts,args = getopt.getopt(sys.argv[1:],"s:e:")
for op,value in opts:
	if op == "-s":
		startp = string.atoi(value)
	if op == "-e":
		endp = string.atoi(value)

SOURCEFILE = 'lst/source.lst'
EXCLUDEFILE = 'lst/exclude%d-%d.lst'%(startp,endp)
INCLUDEFILE = 'lst/include%d-%d.lst'%(startp,endp)
UNHANDLEFILE = 'lst/unhandle%d-%d.lst'%(startp,endp)
IPSOURCEFILE = 'lst/newIP.lst'

f = open(SOURCEFILE)
text = f.read();
line = text.split('\n')
line.pop()
line = line[startp:endp]
f.close()
fpro = open(IPSOURCEFILE)
fex = open(EXCLUDEFILE,'a')
fin = open(INCLUDEFILE,'a')
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
threads=[]
try:
	while line:
		if (len(threading.enumerate())<2): 
			t = threading.Thread(target=onedriver,args=('2013-11-13','qunar.com'))
			t.start()
			threads.append(t)
		time.sleep(2)
except Exception as e:
	print e
finally:
	for t in threads:
		t.join()
	print 'finally'
	for i in line:
		filewriter('fuh',i+'\n')
	print 'closing file'
	fex.close()
	fin.close()
	fuh.close()
