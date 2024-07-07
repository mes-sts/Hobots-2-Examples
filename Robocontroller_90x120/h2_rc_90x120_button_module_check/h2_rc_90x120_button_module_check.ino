/*
 * h2_rc_90x120_button_module_check
 * 
 * Проверка модуля кнопки H2 RC90x120
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Вывод кнопки
const int BUTTON_PIN = 38;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода кнопки на вход
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (!digitalRead(BUTTON_PIN)) {
    Serial.println("Button PRESSED");
  }
  else {
    Serial.println("Button RELEASED");
  }
  delay(20);
}
