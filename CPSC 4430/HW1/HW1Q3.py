import numpy as np
from numpy.linalg import eig

A = np.random.randint(10, size=(10,5))

P = np.dot(np.dot(A, np.linalg.inv(np.dot(A.T, A))), A.T)

#Checking to see if P is symmetric 
P_tran = P.T

if(P.all() == P_tran.all()):
    print("Part 1 Success!")
else:
    print("Part 1 failed")

#Checking to see if A^T * A is positive definite and thus invertible
v = np.array(range(1,6)) #Column vectors for testing
Av = np.dot(A, v)

if(np.dot(Av.T, Av) > 0).all():
    print("Part 2 success!")
else: 
    print("Part 2 failed")

#Checking to see if P^n = P for all positive integers n
P_sqd = pow(P, 2)

if(P.all() == P_sqd.all()):
    print("Part 3 success!")
else:  
    print("Part 3 failed")

#Checking to see if the eigenvalue of P is = 0 or = 1
eigval, eigvec = eig(P)

if(eigval.all() == 0 or eigval.all() == 1):
    print("Part 4 success!")
else:
    print("Part 4 failed")

#Checking to see if trace(P) == rank(P)
if(round(np.trace(P), 4) == round(np.linalg.matrix_rank(P), 4)):
    print("Part 5 success!")
else:
    print("Part 5 Failed")