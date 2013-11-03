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
a = 1
while  a == 1:
	try:
		time.sleep(10)
		data = driver.find_element_by_id('hdivResultPanel').text
		print data
		nextp = driver.find_element_by_id('nextXI3')
		nextp.click()
	except Exception as e:
		a = 0
driver.quit()


