#include "XGBRegressor.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  double X[] = {360000, 24.754, 0.658, 23, 24.5};
  double result = score(X);
  Serial.print("Result of predict with input X: ");
  Serial.println(String(result, 7));
}

void loop() {}
