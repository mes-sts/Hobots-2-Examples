/*
 * h2_rc_90x120_temperature_module_check
 * 
 * Проверка модуля датчика температуры H2 RC90x120
 * 
 * Ссылки на библиотеки для работы с датчиком DS18B20
 * OneWire - https://github.com/PaulStoffregen/OneWire
 * DallasTemperature - https://github.com/milesburton/Arduino-Temperature-Control-Library
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотек для датчика
#include <OneWire.h>
#include <DallasTemperature.h>

// Вывод датчика температуры
const int TEMPERATURE_SENSOR_PIN = 30;

// Порядковый номер датчика на шине. В модуле датчк 1, счет идет с 0
const byte TEMPERATURE_SENSOR_INDEX = 0;

// Создание объекта шины взаимодействия с датчиком температуры
OneWire oneWire(TEMPERATURE_SENSOR_PIN);

// Создание объекта для работы с датчиком
DallasTemperature sensor(&oneWire);

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Инициализация датчика температуры
  sensor.begin();
}

void loop() {
  // Запрос показаний температуры
  sensor.requestTemperatures();

  // Получение тепературы в град. С от датчика с индексом 0
  float temp_c = sensor.getTempCByIndex(TEMPERATURE_SENSOR_INDEX);

  // Вывод температуры в монитор порта
  Serial.print("Temp C: ");
  Serial.println(temp_c);
  Serial.println();
  
  delay(100);
}
