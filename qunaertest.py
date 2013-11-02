import sys
import time
import math
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver
for i in range(0,50):
	driver = webdriver.Firefox()
	driver.get('http://flight.qunar.com/site/oneway_list.htm?searchDepartureAirport=%E5%8C%97%E4%BA%AC&searchArrivalAirport=%E4%B8%8A%E6%B5%B7&searchDepartureTime=2013-10-29&searchArrivalTime=2013-10-29&nextNDays=0&sd_idx=0&SearchLocation=sevenday_search');
	time.sleep(30)
	html = driver.page_source
	data = driver.find_element_by_id('hdivResultPanel').text
	driver.quit()
print data
