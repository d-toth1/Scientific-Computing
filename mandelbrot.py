import sys
import pandas as pd
import matplotlib.pyplot as plt
from tqdm import tqdm #Progress bar library

def f(z, c):
    return z**2 + c

N = int(sys.argv[1])
K = int(sys.argv[2])

real_values = []
imag_values = []

tolerance = 1.0e-14

for i in tqdm(range(0,N)):
    
    for j in range(0,N):
        
        it = 0
        z = complex(0,0)
        x = -2.0 + ((4.0*i)/N)
        
        if abs(x) < tolerance:
            x = 0
            
        y = -2.0 + ((4.0*j)/N)
        
        if abs(y) < tolerance:
            y = 0
            
        c = complex(x, y)
        
        while it < K and abs(z) <= 2:
            
            z = f(z, c)
            it += 1

        if it == K and abs(z) <= 2:
            
            real_values.append(c.real)
            imag_values.append(c.imag)

df = pd.DataFrame({"Real": real_values, "Imaginary" : imag_values})
print(df)

plt.axis("square")
plt.axis([-2.1, 1.1, -1.5, 1.5])
plt.scatter(real_values, imag_values, s = 0.2)
plt.xlabel("Real")
plt.ylabel("Imaginary")
plt.show()
