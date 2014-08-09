#coding=utf-8
from urllib import urlencode
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

def doitbabe():
	
	conn = MySQLdb.connect(host='localhost',user='root',passwd='root',db='airTicketOnline',port=3306,charset='utf8')
	cur = conn.cursor()
	
	file_object = open('airport.txt')
	try:
		list_of_all_lines = file_object.readlines()
	finally:
		file_object.close()

	for i in range(0, len(list_of_all_lines)):
		print list_of_all_lines[i]
		line = list_of_all_lines[i].split(',')
#		for j in range(0, len(line)):
#			print line[j]
		query = "insert into AirportInfo (airportName,codeIATA,codeICAO,cityName,provinceName,countryName) values (%s,%s,%s,%s,%s,%s);"
		value = (line[3],line[0],line[1],line[2],line[4],line[5])
		#print (query,value)
		cur.execute(query,value)
		conn.commit()
	return

def qunarCityMark():

	conn = MySQLdb.connect(host='localhost',user='root',passwd='root',db='airTicketOnline',port=3306,charset='utf8')
	cur = conn.cursor()
	
	file_object = open('city.lst')
	try:
		list_of_all_lines = file_object.readlines()
	finally:
		file_object.close()

#	for i in range(0, len(list_of_all_lines)):
#		update
	

doitbabe()

