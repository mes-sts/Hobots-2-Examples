/*
 * h2_rc_90x120_robotis_xl_bus_servo_check
 * 
 * Проверка интеллектуального сервопривода H2 RC90x120
 * 
 * В примере используется сервопривод XL430-W250-T
 * Можно использовать с другой маркировкой, но версией протокола 2.0
 * 
 **********************************************************************************
 * Требуется модификация файла "pins_arduino.h" для плат mega                     *
 * Подробное описание есть в файле "README.md" в каталоге "Robocontroller_90x120" *
 **********************************************************************************
 * 
 * Ссылки:
 * Протокол 2.0 https://emanual.robotis.com/docs/en/dxl/protocol2/
 * Сервопривод XL430-W250-T https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/
 * Библиотека Dynamixel2Arduino https://github.com/ROBOTIS-GIT/Dynamixel2Arduino
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами от ROBOTIS
#include <Dynamixel2Arduino.h>

// Скорость обмена данными отладочного порта
const long DEBUG_SERIAL_BAUDRATE = 115200;
// Скорость обмена данными с интеллектуальным сервоприводом
const long DXL_SERIAL_BAUDRATE = 57600;
// Контакт переключения режима работы полудуплексного UART (прием / передача)
const byte DXL_DIR_PIN = 70; // Физический вывод МК ATmega2560 - PJ2 (см. Требование Выше!)
// Индивидуальный номер сервопривода
const byte DXL_ID = 1; // 254 - Широковещательный. По умолчанию с завода 1
// Версия протокола сервопривода
const float DXL_PROTOCOL_VERSION = 2.0; // 1.0 - устаревшие, 2.0 - актуальные

// Создание объекта для взаимодействия с сервоприводами
Dynamixel2Arduino dxl(Serial3, DXL_DIR_PIN);

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(DEBUG_SERIAL_BAUDRATE);
  // Ожидание инициализации отладочного порта
  while(!Serial);
  // Запуск шины сервоприводов
  dxl.begin(DXL_SERIAL_BAUDRATE);
  // Установка версии протокола связи
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Отсановить вращение вала
  dxl.torqueOff(DXL_ID);
  // Выбор режима управления сервоприводами. Должен назначаться только после вызова torqueOff
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  // Запустить вращение вала
  dxl.torqueOn(DXL_ID);
}

void loop() {
  // Включение встроенного в интеллектуальный сервопривод светодиода
  dxl.ledOn(DXL_ID);
  // Установка вала интеллектуального сервопривода в положение 0
  dxl.setGoalPosition(DXL_ID, 0);
  delay(1000);
  // Получение и отображение позиции в монитор порта
  Serial.print("RAW Position: ");
  Serial.println(dxl.getPresentPosition(DXL_ID));

  // Выключение встроенного в интеллектуальный сервопривод светодиода
  dxl.ledOff(DXL_ID);
  // Установка вала интеллектуального сервопривода в положение 100
  dxl.setGoalPosition(DXL_ID, 250);
  delay(1000);
  // Получение и отображение позиции в монитор порта
  Serial.print("RAW Position: ");
  Serial.println(dxl.getPresentPosition(DXL_ID));
}
