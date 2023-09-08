import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

df = pd.read_csv('calibrationValues.csv')
pwm = df['pwm'].values.reshape(-1, 1)
flow = df['flow(L/D)'].values.reshape(-1, 1)

linearRegressor = LinearRegression()
linearRegressor.fit(flow, pwm)
concentration_predict = linearRegressor.predict(flow)
concentration_predict
m = linearRegressor.coef_[0][0]
c = linearRegressor.intercept_[0]
label = r'$Flow Rate= %0.4fx %+0.4f$' % (m, c)
print(label)
R2 = r2_score(pwm, concentration_predict)
print(R2)

fig = plt.figure()
ax = fig.subplots()
plt.scatter(flow, pwm, edgecolors='red')
plt.plot(flow, pwm, color='blue', label='Datos experimentales')
plt.plot(flow, concentration_predict,
         color='red', label='Tendencia central')
ax.text(0.04, 140, r'$R^2= %0.4f$' % (R2))
ax.text(0.04, 200, label)
ax.set_xlabel('Flow')
ax.set_ylabel('pwm')
ax.set_title('Peristaltic pump 12V')
plt.legend()
plt.grid()
plt.show()
