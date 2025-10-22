import numpy as np
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from matplotlib.colors import ListedColormap

# Data
X = np.array([[0, 3], [2, 0], [0, 1], [0, 1], [-1, 0], [1, 1]])
y = np.array(['Red', 'Red', 'Red', 'Green', 'Green', 'Red'])

cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA', '#AAAAFF'])
cmap_bold = ListedColormap(['#FF0000', '#00FF00', '#0000FF'])

for weights in ['uniform', 'distance']:      
    # Fit KNN classifier
    knn = KNeighborsClassifier(n_neighbors=3)
    knn.fit(X[:, :2], y)

    # Plot the decision boundary. For that, we will assign a color to each
    # point in the mesh [x_min, x_max]x[y_min, y_max].
    x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
    y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
    xx, yy = np.meshgrid(np.linspace(-2, 3, 100), np.linspace(-2, 4, 100))

    # Predict on meshgrid points
    Z = knn.predict(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)

    # Plot data points
    plt.figure()
    plt.pcolormesh(xx, yy, Z, cmap=cmap_light)


    plt.scatter(X[:, 0], X[:, 1], c=y, cmap=plt.cm.Paired)
    plt.xlim(xx.min(), xx.max())
    plt.ylim(yy.min(), yy.max())
    plt.title('KNN Decision Boundary')

plt.show()
