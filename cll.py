import numpy as np
from PIL import Image
import cv2
import os
import time

print("qqqqqqqqq")
print("wwwwwwwww")
f = open("out.txt", "w")
img = cv2.imread("1.jpg")
a=img.shape
img=cv2.resize(img,(int(a[1]/a[0]*150),150),interpolation=cv2.INTER_CUBIC)
print(150," ",int(a[1]/a[0]*150),end=" ",file = f)
imgray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
imgray = cv2.GaussianBlur(imgray, (5, 5), 0)
ret,thresh = cv2.threshold(imgray,127,255,0)
image ,contours,hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
a=img.shape
lx,ly,ll= img.shape
mtr=np.array(image)
for i in range(0,a[0]):
    print(" ",file = f)
    for j in range(0,a[1]):
        print(mtr[i][j], end=" ",file = f )

print("eeeeeeeee")