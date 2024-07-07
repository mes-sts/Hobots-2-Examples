/*
 * h2_rc_90x120_light_module_check
 * 
 * Проверка модуля датчика освещенности H2 RC90x120
 * 
 * формула перевода значений АЦП в напряжение Vo = ADC * (Vref / 2^n)
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод фототранзистора
const int LIGHT_SENSOR_PIN = A3;

// Напряжение питания микроконтроллера и АЦП
const float POWER_SUPPLY_V = 5.0;

// Разрядность АЦП
const int BIT_DEPTH_ADC = 1024; // 2^10

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода датчика освещености на вход
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  // Получение оцифрованного значения на датчике освещенности
  word light_sensor_value = analogRead(LIGHT_SENSOR_PIN);
  // Перевод оцифрованного значения в напряжение
  float light_sensor_voltage = light_sensor_value * (POWER_SUPPLY_V / BIT_DEPTH_ADC);
  
  Serial.print("Light ADC ");
  Serial.println(light_sensor_value);
  Serial.print("Light V ");
  Serial.println(light_sensor_voltage);
  Serial.println();

  delay(100);
}
