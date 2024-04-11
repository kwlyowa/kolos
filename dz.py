import matplotlib.pyplot as plt
import numpy as np

# def polinom0(x_znacz, i):
#     def basic_polinom(x):
#         rozdzielacz = 1
#         wynik = 1
#         for j in range(len(x_znacz)):
#             if j != i:
#                 wynik *= (x - x_znacz[j])
#                 rozdzielacz *= (x_znacz[i] - x_znacz[j])
#         razem = wynik / rozdzielacz
#         return razem
#     return basic_polinom           

# def LagrangeCoeff(x_znacz, y_znacz):
#     polinomals = []
#     for i in range(len(x_znacz)):
#         polinomals.append(polinom0(x_znacz, i))

#     def LagrangeVal(x):
#         wynik = 0
#         for i in range(len(y_znacz)):
#             wynik += y_znacz[i] * polinomals[i](x)
#         return wynik
#     return LagrangeVal

# x_znacz = [-8.053, -7.849, -5.44, -1.487, 2.170]                
# y_znacz = [-4.309, 0.786, 2.96, 3.312, 4.595]

# lag_pol = LagrangeCoeff(x_znacz, y_znacz)

# x_values = np.linspace(min(x_znacz), max(x_znacz), 1000)
# y_values = lag_pol(x_values)

# plt.plot(x_values, y_values, label='Wielomian Lagrange\'a')
# plt.scatter(x_znacz, y_znacz, color='purple', label='Węzły')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.title('Wielomian Lagrange\'a i jego węzły')
# plt.legend()
# plt.grid(True)
# plt.show()




mX = np.loadtxt('x.txt')
mY = np.loadtxt('y.txt')

print("X: ")
print(mX)
print("Y: ")
print(mY)

def interp_splajn(mX,mY):
    n = mX.shape[0]
    h = mX[1] - mX[0]
    M = np.zeros((n+2,n+2))
    M[0][0] = -3.0/h
    M[0][2] = 3.0/h
    M[n+1][n-1] = -3.0/h
    M[n+1][n+1] = 3.0/h

    for i in range(1, n+1):
        M[i][i] = 4
        M[i][i+1] = 1
        M[i][i-1] = 1

    print("M: ") 
    print(M)

    B = np.zeros(n+2)
    B[0] = 1
    B[n+1] = 1

    for i in range(1,n+1):
        B[i] = mY[i-1]       
    print("B:")
    print(B)
    K = np.linalg.solve(M, B)
    print("Wspolczynniki K: ")
    return K
print(interp_splajn(mX,mY))
K = interp_splajn(mX,mY)


def B(y, h):
    if -2 * h <= y <= -h:
        return (1 / h**3) * (y + 2 * h)**3
    elif -h < y <= 0:
        return (1 / h**3) * (h**3 + 3 * h**2 * (y + h) + 3 * h * (y + h)**2 - 3 * (y + h)**3)
    elif 0 <= y <= h:
        return (1 / h**3) * (h**3 + 3 * h**2 * (h - y) + 3 * h * (h - y)**2 - 3 * (h - y)**3)
    elif h <= y <= 2 * h:
        return (1 / h**3) * (2*h-y)**3
    else:
        return 0

def C(K, x, x_i, h):
    sum = 0
    n = len(x_i)
    for i in range(n):
        y = x - x_i[i]
        sum = sum + K[i]*B(y,h)
    return sum

n = len(mY)
h = mX[1] - mX[0]
x2 = [mX[0] - h] + list(mX) + [mX[-1] + h]

print(C(K, 0, x2, h ))
I = C(K, 0, x2, h)


x = np.linspace(-1, 1, 1000)
x_i = x2
interpolated_values1 = [C(K, xi, x2, h) for xi in x] 

plt.plot(x, interpolated_values1, label='Interpolated Function')
plt.scatter(mX, mY, color='red', label='Interpolation Nodes')
plt.xlabel('x')
plt.ylabel('Interpolated Value')
plt.title('Interpolated Function Plot')
plt.legend()
plt.grid(True)
plt.show()