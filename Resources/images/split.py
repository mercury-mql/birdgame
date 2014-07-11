import cv2
img = cv2.imread('atlas.png', -1)
cv2.namedWindow('test')
cv2.imshow('test',img)
cv2.waitKey(3)
for line in open('atlas.txt'):
	alist = line.rstrip().split(' ')
	segName = alist[0] + '.png'
	segW = int(alist[1])
	segH = int(alist[2])
	segX = int(1024*float(alist[3]))
	segY = int(1024*float(alist[4]))
	print segName, segX, segY, segW, segH
	seg = img[segY : segY+segH, segX : segX+segW,  :]
	cv2.imwrite(segName, seg)
	