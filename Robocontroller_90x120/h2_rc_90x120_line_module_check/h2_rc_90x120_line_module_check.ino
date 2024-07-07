/*
 * h2_rc_90x120_line_module_check
 * 
 * Проверка модуля датчика линии H2 RC90x120
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Вывод канала датчика линии
const byte LINE_SENSOR_PIN = A0;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода датчика на вход
  pinMode(LINE_SENSOR_PIN, INPUT);
}

void loop() {
  // Получение значения канала датчика линии
  word line_sensor = analogRead(LINE_SENSOR_PIN);

  // Вывод значения в монитор порта
  Serial.print("CH - ");
  Serial.println(line_sensor);
  
  delay(100);
}
