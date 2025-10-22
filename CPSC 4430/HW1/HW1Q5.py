from sklearn.linear_model import LinearRegression
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split

file = open('Auto.csv')

data = pd.read_csv(file, delimiter=',')

x = data[['cylinders', 'displacement', 'horsepower', 'weight', 'acceleration']]
y = data['mpg']

x['Intercept'] = 1

X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=92, random_state=None,shuffle=False)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

model = LinearRegression()
model.fit(X_train_scaled, y_train)

y_pred = model.predict(X_test_scaled)

mse = mean_squared_error(y_test, y_pred)

print("Mean Squared Error is", mse)
