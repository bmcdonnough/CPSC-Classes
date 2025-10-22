import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

X = np.array([1, 2, 3, 4, 5]).reshape(-1,1)
y = [1, 3, 9, 15, 24]

poly_features = PolynomialFeatures(degree=3, include_bias=False)
X_poly = poly_features.fit_transform(X)

model = LinearRegression()
model.fit(X_poly, y)

X_vals = np.linspace(1, 5, 100).reshape(-1,1)
X_vals_poly = poly_features.transform(X_vals)

Y_vals = model.predict(X_vals_poly)

plt.scatter(X,y)
plt.plot(X_vals, Y_vals, color='b')
plt.show()

