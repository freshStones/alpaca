#coding=utf-8
from urllib import urlencode
import uuid
import sys
import types
import datetime
import time
import MySQLdb
import math
import random
reload(sys)
sys.setdefaultencoding('utf-8')

fcl = open('city.lst')
fw = open('pairs.lst','w')
citys = fcl.readlines()
citypairs =[]
for i in range(0,len(citys)):
	for j in range(0,len(citys)):
		if i!=j:
			
			a = citys[i].rstrip().lstrip().rstrip('\n')
			
			b = citys[j].rstrip().lstrip().rstrip('\n')
			citypairs.append(a+' '+b)
random.shuffle(citypairs)
for i in citypairs:
	fw.write(i+'\n')
fw.close()
