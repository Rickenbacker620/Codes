# pylint:disable=no-member

# import cv2 as cv
# import numpy as np

# # Read in an image
# img = cv.imread('../Resources/Photos/RGB.png')

# img = img[300:350, 300:350]

# # Converting to grayscale
# gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('Gray', gray)
# print(gray)

# gray2 = gray * 0.3
# print(gray2)
# cv.imshow('Gray2', gray2)

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
# print(img.shape[0], img.shape[1])
# cropped = img[50:200, 200:400]
# print(cropped.shape[0], cropped.shape[1])
# cv.imshow('Cropped', cropped)

# cv.waitKey(0)

import numpy as np
import os as os


print(np.__version__)

np.arange()


mu, sigma = 0, 1

s = np.random.normal(mu, sigma, 100000)


np.arange()

np.arange()


print(s.max())
print(s.min())

count, bins, ignored = plt.hist(s, 300, density=True)

x = bins
y = 1/(sigma * np.sqrt(2 * np.pi)) * np.exp(- (bins - mu)**2 / (2 * sigma**2))

plt.plot(x, y, linewidth=1, color='r')


plt.show()

print(gauss)
