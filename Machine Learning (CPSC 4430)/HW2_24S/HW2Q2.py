import numpy as np
import matplotlib.pyplot as plt

A = np.random.rand(100, 50)
y = np.random.rand(100)

gammas = [0.01, 0.1, 1, 10, 100]

iterations = 100
x = np.zeros((50, 1))

plt.figure(figsize=(10, 6))

for gamma in gammas:
    obj_vals = []
    
    for _ in range(iterations):
        singular_val = np.linalg.norm(A @ A.T, 2)

        gradient = 2 * A.T @ (A @ x - y) + 2 * gamma * x
        lambda_val = 0.5 / (gamma + singular_val)
        x = x - lambda_val * gradient

        objective = np.linalg.norm(A @ x - y) ** 2 + gamma * np.linalg.norm(x) ** 2
        obj_vals.append(objective)
    
    plt.plot(range(1, iterations + 1), obj_vals, label=f"Gamma={gamma}")

plt.xlabel("Iterations")
plt.ylabel("Objective Value")
plt.title("Objective Changes with Gradient Descent")
plt.legend()
plt.show()

