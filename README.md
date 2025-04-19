# TinyML TimeSeries Forecasting on ESP32  

This project showcases two different time series forecasting approaches — SARIMAX and XGBoost — implemented and tested independently on an ESP32 microcontroller. The goal is to evaluate classical statistical and machine learning methods for low-power, on-device prediction.

![ESP32 Wokwi Screenshot](sarimax/esp32_sarimax.png)

## 🧠 Models Implemented

- **SARIMAX**  
  A classical time series model with seasonal and autoregressive components. C++ implementation performs recursive step-ahead forecasting using trained parameters.

- **XGBoost Regressor**  
  A gradient-boosted tree model trained on lagged time series features and manually ported to C++ for embedded inference.

> Both models are implemented in plain C++ and run directly on the ESP32 without any external ML libraries.

## 🧪 Dataset & Preprocessing

- Notebooks (`tsa_analysis.ipynb`, `tsa_modeling.ipynb`) contain:
  - EDA and visualization
  - Feature engineering for XGBoost (lags, rolling windows, etc.)
  - SARIMAX parameter tuning and diagnostics

## 🛠️ Deployment

- **Board**: ESP32 DevKit v1  
- **Toolchain**: Arduino IDE or PlatformIO  
- **Dependencies**: None — models are hardcoded and self-contained

## 🧪 Wokwi Simulation

- This project runs well in Wokwi — a browser-based ESP32 emulator:
    - Upload your code files to a Wokwi project
    - Run and view serial output to test predictions

## 🚀 Project Goals

- Explore and benchmark SARIMAX vs XGBoost for microcontroller-based forecasting.
- Demonstrate pure C++ model inference without any ML runtime.
- Enable forecasting at the edge with limited memory and no connectivity.

## 📈 Use Cases

- Smart thermostat / local temperature prediction.
- Power usage or sensor reading forecasting.
- Time-based anomaly detection in embedded systems.