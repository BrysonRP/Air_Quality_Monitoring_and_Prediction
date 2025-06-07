import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.arima.model import ARIMA
from statsmodels.tsa.stattools import adfuller

# Load dataset
df = pd.read_csv(r'D:\College\SEM 4\PROJECT\ChennaiAQI.csv',
parse_dates=['date'])

# Preprocessing
df = df[['date', 'Index Value']]
df = df.dropna()
df.set_index('date', inplace=True)
df = df.asfreq('D')
df.fillna(method='ffill', inplace=True)
print("\n--- Augmented Dickey-Fuller (ADF) Test ---")
result = adfuller(df['Index Value'])
print(f"ADF Statistic: {result[0]:.4f}")
print(f"p-value: {result[1]:.4f}")

if result[1] <= 0.05:
	print(" The data is stationary.")
else:
	print("The data is non-stationary.")
	
print("\n--- Training ARIMA Model ---")
model = ARIMA(df['Index Value'], order=(5, 1, 2))
model_fit = model.fit()
print(" Model trained successfully.")

forecast = model_fit.forecast(steps=30)
forecast_index = pd.date_range(start=df.index[-1] + pd.Timedelta(days=1),
periods=30)
forecast = pd.Series(forecast, index=forecast_index)

plt.figure(figsize=(12, 5))
plt.plot(df['Index Value'], label='Original AQI Data')
plt.title('Original AQI Data')
plt.xlabel('Date')
plt.ylabel('AQI Index')
plt.grid()
plt.legend()
plt.figure(figsize=(12, 5))
plt.plot(df['Index Value'], label='Observed')
plt.plot(forecast, label='Forecast (Next 30 Days)', color='red')
plt.title('AQI Forecast for Next 30 Days')
plt.xlabel('Date')
plt.ylabel('AQI Index')
plt.legend()
plt.grid()
plt.show()
print("\n--- Forecasted AQI Values ---")
print(forecast)
