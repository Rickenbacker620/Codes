# import math

# b = 0.059

# t0 = [1.584,1.581,1.577,1.572,1.569,1.569,1.587,1.584,1.566]
# t1 = [1.640,1.624,1.603,1.588,1.571,1.562,1.548,1.534,1.532]

# theta = [64,80,107,135,150,149,82,60,56]

# def phi(t0, t):
#     return math.atan((-b*pow(t0,2)*t) / ((math.pi)*(pow(t,2)-pow(t0,2)))) * (180/math.pi)

# def omega(w, w0):
#     return w/w0

# for i in t1:
#     print(math.pi*2/i*(180/math.pi))

# u = [89,83,80,78,76,72,69,64,59,56,52,47,40,34,31,24,22,19,16,12,9,7]
# i = [10,41,80,126,185,348,415,562,628,669,702,713,748,781,808,895,961,999,1113,1267,1455,1570]

# for u, i in zip(u, i):
#     print(u*i/1000)
import math

f = [94.1, 92.8, 91.2, 89.8, 88.2, 86.7, 85.2, 83.7, 82.2, 80.9]
for i in f:
    print(math.pi*2*i)
