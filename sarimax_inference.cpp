#include <ArduinoEigen.h>

#define P 2  // AR order
#define Q 2  // MA order
#define D 1  // differencing order
#define SEASONAL_P 1  // seasonal AR
#define SEASONAL_Q 1  // seasonal MA
#define SEASONAL_PERIOD 12  // monthly seasonality

using namespace Eigen;

// precomputed SARIMAX parameters
float ar_coeffs[P] = {0.5, -0.3};
float ma_coeffs[Q] = {0.2, 0.1};
float seasonal_ar[SEASONAL_P] = {0.3};
float seasonal_ma[SEASONAL_Q] = {-0.2};
float intercept = 21.5;
float sigma2 = 0.5;

float past_values[P] = {0};
float past_errors[Q] = {0};
float past_seasonal_values[SEASONAL_PERIOD] = {0};

float apply_differencing(float new_value) {
    static float prev_value = 0;
    float diff = new_value - prev_value;
    prev_value = new_value;
    return diff;
}

float predict_sarimax(float new_value) {
    if (D > 0) {
        new_value = apply_differencing(new_value);
    }

    float prediction = intercept;

    for (int i = 0; i < P; i++) {
        prediction += ar_coeffs[i] * past_values[i];
    }

    for (int i = 0; i < Q; i++) {
        prediction += ma_coeffs[i] * past_errors[i];
    }

    for (int i = 0; i < SEASONAL_P; i++) {
        prediction += seasonal_ar[i] * past_seasonal_values[i];
    }
    for (int i = 0; i < SEASONAL_Q; i++) {
        prediction += seasonal_ma[i] * past_seasonal_values[i];
    }

    for (int i = P - 1; i > 0; i--) {
        past_values[i] = past_values[i - 1];
    }
    past_values[0] = new_value;

    for (int i = Q - 1; i > 0; i--) {
        past_errors[i] = past_errors[i - 1];
    }
    past_errors[0] = new_value - prediction;

    return prediction;
}

void setup() {
    Serial.begin(115200);

    float sensor_temp = 22.0;
    float forecast = predict_sarimax(sensor_temp);
    
    Serial.print("Predicted Temp: ");
    Serial.println(forecast);
}