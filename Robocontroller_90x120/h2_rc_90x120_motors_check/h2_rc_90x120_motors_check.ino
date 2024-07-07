/*
 * h2_rc_90x120_motors_check
 * 
 * Проверка моторов H2 RC90x120
 * 
 * Моторы подключены в разъемы M1 и M2 (или M1-D и M2-D)
 * 
 * Необходимо подключить внешний источник питания!
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы направления моторов
const int DIR_M1_PIN = 40;
const int DIR_M2_PIN = 41;
// Выводы скорости моторов
const int PWM_M1_PIN = 2;
const int PWM_M2_PIN = 3;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Настройка всех выводов на выход
  pinMode(DIR_M1_PIN,OUTPUT);
  pinMode(DIR_M2_PIN,OUTPUT);
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
}

void loop() {
  Serial.println("Motors Case 1/4");
  // Первое направление
  digitalWrite(DIR_M1_PIN, LOW);
  digitalWrite(DIR_M2_PIN, HIGH);
  for (byte i = 0; i <= 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  Serial.println("Motors Case 2/4");
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  delay(300);
  for (byte i = 255; i >= 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(1000);
  
  Serial.println("Motors Case 3/4");
  // Второе направление
  digitalWrite(DIR_M1_PIN, HIGH);
  digitalWrite(DIR_M2_PIN, LOW);
  for (byte i = 0; i <= 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  Serial.println("Motors Case 4/4");
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  delay(300);
  for (byte i = 255; i >= 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(1000);
}
