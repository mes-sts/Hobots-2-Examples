/*
 * h2_rc_90x120_servo_check
 * 
 * Проверка сервоприводов H2 RC90x120
 * 
 * Сервоприводы подключены в разъемы 4, 6, 7, 8, 9, 44, 45, 46
 * 
 * Необходимо подключить внешний источник питания!
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами
#include <Servo.h>

// Выводы управления сервоприводами
const int SERVO_0_PIN = 4;
const int SERVO_1_PIN = 6;
const int SERVO_2_PIN = 7;
const int SERVO_3_PIN = 8;
const int SERVO_4_PIN = 9;
const int SERVO_5_PIN = 44;
const int SERVO_6_PIN = 45;
const int SERVO_7_PIN = 46;

// Переменная для хранения текущего положения
int current_pos = 0;

// Создание объектов сервоприводов
Servo MyServo0;
Servo MyServo1;
Servo MyServo2;
Servo MyServo3;
Servo MyServo4;
Servo MyServo5;
Servo MyServo6;
Servo MyServo7;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Присвоение объектам сервоприводов выводов управления
  MyServo0.attach(SERVO_0_PIN);
  MyServo1.attach(SERVO_1_PIN);
  MyServo2.attach(SERVO_2_PIN);
  MyServo3.attach(SERVO_3_PIN);
  MyServo4.attach(SERVO_4_PIN);
  MyServo5.attach(SERVO_5_PIN);
  MyServo6.attach(SERVO_6_PIN);
  MyServo7.attach(SERVO_7_PIN);

  // Установка всех сервоприводов в начальное положение 0
  MyServo0.write(current_pos);
  MyServo1.write(current_pos);
  MyServo2.write(current_pos);
  MyServo3.write(current_pos);
  MyServo4.write(current_pos);
  MyServo5.write(current_pos);
  MyServo6.write(current_pos);
  MyServo7.write(current_pos);
}

void loop() {
  Serial.println("Direction 1");
  // Поворот вала каждого сервопривода в направлении 1
  for (current_pos = 0; current_pos <= 180; current_pos++) {
    MyServo0.write(current_pos);
    MyServo1.write(current_pos);
    MyServo2.write(current_pos);
    MyServo3.write(current_pos);
    MyServo4.write(current_pos);
    MyServo5.write(current_pos);
    MyServo6.write(current_pos);
    MyServo7.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(200);
  
  Serial.println("Direction 2");
  // Поворот вала каждого сервопривода в направлении 2
  for (current_pos = 180; current_pos >= 0; current_pos--) {
    MyServo0.write(current_pos);
    MyServo1.write(current_pos);
    MyServo2.write(current_pos);
    MyServo3.write(current_pos);
    MyServo4.write(current_pos);
    MyServo5.write(current_pos);
    MyServo6.write(current_pos);
    MyServo7.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(200);
}
