import sys
import time
reload(sys)
sys.setdefaultencoding('utf-8')
from selenium import webdriver

driver = webdriver.Firefox()
driver.get('http://flights.ctrip.com/booking/CAN-BJS-day-1.html')
time.sleep(5)
html = driver.page_source
data = driver.find_element_by_id('flt_list').text
driver.quit()
print data
