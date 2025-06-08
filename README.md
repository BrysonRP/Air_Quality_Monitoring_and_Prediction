# Air Quality Monitoring & Prediction System

An IoT-based system that monitors real-time air quality and predicts future pollution levels using a machine learning model. This project combines sensor data, cloud integration, and forecasting models to support public health and environmental awareness.

# Project Overview:
This project uses gas sensors connected to an Arduino Uno to collect real-time air quality data, which is then displayed on an LCD screen and sent to the cloud via an ESP32 Wi-Fi module. The collected data is analyzed using Python, and the ARIMA model is used to predict future Air Quality Index (AQI) values.

# Features:
- Real-time air quality monitoring (using MQ-135 & MQ-7 sensors)
- Live AQI display on 16x2 LCD
- Cloud data transmission via ESP32 Wi-Fi
- AQI prediction using Python and ARIMA time series model

# Hardware Used:
- Arduino Uno  
- MQ-135 Sensor (general air quality)  
- MQ-7 Sensor (Carbon Monoxide)  
- ESP32 Wi-Fi Module  
- 16x2 LCD Display  
- Jumper wires, Breadboard, Power Supply  

# Software & Tools:
- **Arduino IDE** – for programming the microcontroller in C++  
- **Python** – for data analysis and prediction  
  - Libraries: pandas, matplotlib, statsmodels (ARIMA)

# Project Structure:
├── lcd.cpp - Arduino code for displaying real-time AQI on LCD

├── model.py - Python code to train ARIMA model & predict future AQI

└── README.md - Project documentation

# Sample Output:
- **LCD Display**: Real-time air quality (e.g., “CO: 200 ppm”)  
- **Prediction Graph**: Future AQI trend plotted using matplotlib
