import matplotlib.pyplot as plt
import numpy as np

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