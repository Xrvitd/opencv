import os
import time

a = time.localtime(os.stat("/root/1.jpg").st_mtime)
la= time.strftime("%min-%s", a)
while 1:
    filemt = time.localtime(os.stat("/root/1.jpg").st_mtime)
    fi=time.strftime("%min-%s", filemt)
    if (fi != la):
        os.system("/usr/bin/python3 /root/cll.py")
        os.system("/root/cl")
        la=fi
# time.sleep(2)

