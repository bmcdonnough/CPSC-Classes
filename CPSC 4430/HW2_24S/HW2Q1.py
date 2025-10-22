import numpy as np
import time

A = np.random.rand(10000, 5000)
y = np.random.rand(10000, 1)

start_time = time.time()
ATA_invs = np.linalg.inv((A.T @ A))
x = (ATA_invs @ A.T) @ y
end_time = time.time()
process_one = end_time - start_time

iterations = 1000
lambda_value = 1 / np.linalg.norm(A, ord='fro') ** 2

x_grad = np.zeros((5000, 1))
start_time_grad = time.time()
for i in range(iterations):
    gradient = A.T @ (A @ x_grad - y) 
    x_grad -= lambda_value * gradient
end_time_grad = time.time()
process_two = end_time_grad - start_time_grad

print(f"Closed solution took {process_one} seconds.")
print(f"Gradient descent took {process_two} seconds.")

if process_one < process_two:
    print("The closed solution method is faster")
elif process_one > process_two:
    print("The gradient descent method is faster")
else:
    print("They are both the same speed")

A_pt2 = np.random.rand(100, 50)
y_pt2 = np.random.rand(100, 1)

start_time_pt2 = time.time()
ATA_invs = np.linalg.inv(A_pt2.T @ A_pt2)
x = (ATA_invs @ A_pt2.T) @ y_pt2
end_time_pt2 = time.time()
process_one_pt2 = end_time_pt2 - start_time_pt2

iterations = 1000
lambda_value = 1 / np.linalg.norm(A_pt2, ord='fro') ** 2

x_grad = np.zeros((50, 1))
start_time_grad_pt2 = time.time()
for i in range(iterations):
    gradient = A_pt2.T @ (A_pt2 @ x_grad - y_pt2) 
    x_grad -= lambda_value * gradient
end_time_grad_pt2 = time.time()
process_two_pt2 = end_time_grad_pt2 - start_time_grad_pt2

print(f"Closed solution took {process_one_pt2} seconds.")
print(f"Gradient descent took {process_two_pt2} seconds.")

if process_one_pt2 < process_two_pt2:
    print("The closed solution method is faster")
elif process_one_pt2 > process_two_pt2:
    print("The gradient descent method is faster")
else:
    print("They are both the same speed")