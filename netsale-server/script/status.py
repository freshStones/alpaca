import psutil,time
def index():
    while True:
        status = False
        for proc in psutil.process_iter():
            if proc.name() == "alpaca-server":
                status = True
        return "%s %s"%(status,time.strftime('%Y-%m-%d-%H:%M:%S',time.localtime(time.time())))
    
