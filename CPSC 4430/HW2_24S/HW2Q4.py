import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from scipy.io import loadmat

# Load the dataset
data = loadmat('olivettifaces.mat')
faces = data['faces']

print(faces.shape)
faces = faces.T

# Perform PCA
pca = PCA(n_components=10)
pca.fit(faces)

# Get the top 10 principal components
top_components = pca.components_

# Plot the top 10 principal components
fig, axes = plt.subplots(2, 5, figsize=(15, 6))
for i, ax in enumerate(axes.flat):
    ax.imshow(top_components[i].reshape(64, 64, order='F'), cmap='gray')
    ax.axis('off')
    ax.set_title(f'Component {i+1}')

plt.suptitle('Top 10 Principal Components')
plt.show()
