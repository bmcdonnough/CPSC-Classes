import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import Lasso

def lasso_solver(A, y, lambda_val, max_iter = 100):
    x = np.zeros(A.shape[1])

    _, s, _ = np.linalg.svd(A.T @ A)

    sigma = max(s)
    t = 1/sigma
    objective_vals = []

    for k in range(1, max_iter + 1):
        z = x - t * A.T @ (A @ x - y)
        x = np.sign(z) * np.maximum(np.abs(z) - t * lambda_val, 0)

        objective = 0.5 * np.linalg.norm(A @ x - y)**2 + lambda_val * np.linalg.norm(x, 1)
        objective_vals.append(objective)

    return x, objective_vals

np.random.seed(42)
A = np.random.rand(100, 50)
true_coef = np.random.rand(50)
y = A @ true_coef + 0.1 * np.random.rand(100)

lambda_vals = [1, 2]

plt.figure(figsize=(12,6))

for lam in lambda_vals:
    x_sol, objective_vals = lasso_solver(A, y, lam)

    plt.plot(range(1, len(objective_vals) + 1), objective_vals, label=f'Lambda = {lam}')

plt.xlabel("Iterations")
plt.ylabel("Objective Values")
plt.title("Objective Changes with Updates (Lasso Algorithm)")
plt.legend()
plt.show()

for lam in lambda_vals:
    model = Lasso(alpha=lam, max_iter= 100, tol=0.001)
    model.fit(A, y)
    print(f"Lambda = {lam}")
    print("Coefficients from Algorithm 1: ", x_sol)
    print(f"Coefficients from sklearn: {model.coef_}")
    print()
