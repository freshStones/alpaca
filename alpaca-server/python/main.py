import subprocess  
import sys
process1 = subprocess.Popen(["python","-u","sub.py"], shell=False, stdout = subprocess.PIPE, stderr=subprocess.STDOUT)          
while True:  
	line = process1.stdout.readline()  
	if not line:  
		break  
	else:
		sys.stdout.write(line)  
