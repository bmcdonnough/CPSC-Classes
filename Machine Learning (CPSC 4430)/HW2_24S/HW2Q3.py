import numpy as np
import matplotlib.pyplot as plt
from skimage import io

image = io.imread('barbara.bmp', as_gray=True)

A, Z, CT = np.linalg.svd(image, full_matrices=False)

r_vals = [1, 5, 10, 20, 50, 100, 200, 300, 500, 512]

storage_ratio = []

for r in r_vals:
    A_bar = A[:, :r]
    Z_bar = np.diag(Z[:r])
    C_bar = CT[:r, :]

    image_bar = A_bar @ Z_bar @ C_bar

    plt.imshow(image_bar, cmap="gray")
    plt.show()

    original_storage = image.shape[0] * image.shape[1]
    new_storage = A_bar.size + Z_bar.size + C_bar.size
    ratio = new_storage / original_storage
    storage_ratio.append(ratio)

optimal_r = r_vals[np.argmin(storage_ratio)]
print(f"The optimal r value is {optimal_r}")
print(f"The storage ratio is: {storage_ratio[r_vals.index(optimal_r)]}")

