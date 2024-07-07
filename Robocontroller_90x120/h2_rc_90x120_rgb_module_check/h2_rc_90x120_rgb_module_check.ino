/*
 * h2_rc_90x120_rgb_module_check
 * 
 * Проверка модуля адресного RGB светодиода H2 RC90x120
 * 
 * Библиотека Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки адресных светодиодов
#include <Adafruit_NeoPixel.h>

// Вывод с подключенным адресным светодиодом
const int PIXELS_PIN = 30;
// Количество адресных светодиодов
const int PIXELS_NUM = 1;

// Создание объекта для адресных светодиодов
Adafruit_NeoPixel Pixels(PIXELS_NUM, PIXELS_PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Инициализация объекта адресных светодиодов
  Pixels.begin();
  // Выключение всех адресных светодиодов
  Pixels.clear();
}

void loop() {
  Serial.println("Color RED");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Pixels.setPixelColor(i, Pixels.Color(255, 0, 0)); // Красный
    Pixels.show();
    delay(500);
  }
  Serial.println("Color GREEN");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Pixels.setPixelColor(i, Pixels.Color(0, 255, 0)); // Зеленый
    Pixels.show();
    delay(500);
  }
  Serial.println("Color BLUE");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Pixels.setPixelColor(i, Pixels.Color(0, 0, 255)); // Синий
    Pixels.show();
    delay(500);
  }
}
