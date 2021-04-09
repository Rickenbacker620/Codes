# pylint:disable=no-member

import cv2 as cv
import numpy as np

# Read in an image
# img = cv.imread('../Resources/Photos/park.jpg')
img = cv.imread('../Resources/Photos/RGB.png')

blank = np.ones((500, 500, 3), dtype='uint8')
# cv.imshow('blk', blank)
# green = img[:, :, 0]


# newImg = np.array((300, 300, 3), dtype='uint8')
blank[:] = [255, 255, 255]
# # cv.imshow('Park', img)
# cv.imshow('Park', green)

cv.imshow('Park', blank)


# # Converting to grayscale
# gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('Gray', gray)

# # Blur
# blur = cv.GaussianBlur(img, (7, 7), cv.BORDER_DEFAULT)
# cv.imshow('Blur', blur)

# # Edge Cascade
# canny = cv.Canny(blur, 125, 175)
# cv.imshow('Canny Edges', canny)

# # Dilating the image
# dilated = cv.dilate(canny, (7, 7), iterations=3)
# cv.imshow('Dilated', dilated)

# # Eroding
# eroded = cv.erode(dilated, (7, 7), iterations=3)
# cv.imshow('Eroded', eroded)

# # Resize
# resized = cv.resize(img, (500, 500), interpolation=cv.INTER_CUBIC)
# cv.imshow('Resized', resized)

# # Cropping
# cropped = img[50:200, 200:400]
# cv.imshow('Cropped', cropped)

cv.waitKey(0)
