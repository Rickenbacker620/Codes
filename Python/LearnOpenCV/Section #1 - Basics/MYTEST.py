# pylint:disable=no-member

import cv2 as cv
import matplotlib
import numpy as np
import matplotlib.pyplot as plt

origin = cv.imread("../Resources/Photos/park.jpg")
cv.imshow("origin", origin)
print(origin.shape)

gray = cv.cvtColor(origin, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)

height = gray.shape[0]
width = gray.shape[1]
noise = np.random.normal(1/2, 0.1, (height, width))


cv.imshow("noise", noise)

bins = np.linspace(0, 1, 400)
plt.hist(noise.flatten(), bins)

plt.show()

print(gray.shape)

cv.waitKey(0)
