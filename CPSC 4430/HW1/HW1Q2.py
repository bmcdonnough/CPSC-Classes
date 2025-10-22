import random
import numpy as np
from sklearn.linear_model import LinearRegression

def main():
    random.seed(2024)

    #Create the random data that is being used
    data = []
    x = []
    y = []
    for i in range(0, 100):
        x.append(random.randint(0, 100))
        y.append(random.randint(0, 100))

    for i in range(0, 100):
        data.append((x[i], [y[i]]))

    #Calculate the mean for x and y values 
    x_mean = 0
    y_mean = 0

    for point in data:
        x_mean += float(point[0])
        y_mean += float(point[1][0])
    x_mean /= len(data)
    y_mean /= len(data)


    #Calculate the numerator and denominator to get a based on the data points
    numerator = 0
    denominator = 0

    for point in data:
        numerator += (float(point[0] - x_mean) * (float(point[1][0]) - y_mean))
        denominator += pow(float(point[0] - x_mean), 2)

    a = numerator / denominator
    b = y_mean - a * x_mean

    print("A and B without sklearn")
    print(f'Slope of data: {a}')
    print(f'Intercept of data: {b}')

    #Use sklearn to get the slope and the intercept of the linear regression line
    X = np.array(x).reshape(-1,1)
    Y  = np.array(y)

    model = LinearRegression()
    model.fit(X, Y)

    print("A and B with sklearn")
    print(f'Slope of fitted line: {model.coef_}')
    print(f'Intercept of fitted line: {model.intercept_}')

if __name__ == "__main__":
    main()
    