/*
 * h2_rc_90x120_buttons_check
 * 
 * Проверка кнопок H2 RC90x120
 *  
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы кнопок
const byte BTN_0_PIN = 37;
const byte BTN_1_PIN = 36;
const byte BTN_2_PIN = 35;
const byte BTN_3_PIN = 34;
const byte BTN_4_PIN = 33;
const byte BTN_5_PIN = 32;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов кнопок на вход c подтяжкой к питанию
  pinMode(BTN_0_PIN, INPUT_PULLUP);
  pinMode(BTN_1_PIN, INPUT_PULLUP);
  pinMode(BTN_2_PIN, INPUT_PULLUP);
  pinMode(BTN_3_PIN, INPUT_PULLUP);
  pinMode(BTN_4_PIN, INPUT_PULLUP);
  pinMode(BTN_5_PIN, INPUT_PULLUP);
}

void loop() {
  // Вывод информации о состоянии кнопок
  Serial.print("Button 0 State = "); Serial.println(digitalRead(BTN_0_PIN));
  Serial.print("Button 1 State = "); Serial.println(digitalRead(BTN_1_PIN));
  Serial.print("Button 2 State = "); Serial.println(digitalRead(BTN_2_PIN));
  Serial.print("Button 3 State = "); Serial.println(digitalRead(BTN_3_PIN));
  Serial.print("Button 4 State = "); Serial.println(digitalRead(BTN_4_PIN));
  Serial.print("Button 5 State = "); Serial.println(digitalRead(BTN_5_PIN));
  Serial.println();
  delay(100);
}
