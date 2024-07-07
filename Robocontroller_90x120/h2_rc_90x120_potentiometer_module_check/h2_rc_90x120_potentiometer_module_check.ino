/*
 * h2_rc_90x120_potentiometer_module_check
 * 
 * Проверка модуля потенциометра H2 RC90x120
 * 
 * Сопротивление потенциометра 10кОм (R1 и R2)
 * Входное сопротивление АЦП микроконтроллера 55МОм - 100МОм (R3).
 * Напряжение питания делителя 5В.
 * 
 * Формулы расчета напряжения на делителе
 * Формула в общем виде без учета сопротивления АЦП Vo = Vi * (R2 / (R1 + R2))
 * Формула в общем виде с учетом сопротивления АЦП Vo = Vi * ((1 / ((1 / R2) + (1 / R3))) / (R1 + (1 / ((1 / R2) + (1 / R3)))))
 * 
 * формула перевода значений АЦП в напряжение Vo = ADC * (Vref / 2^n)
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод потенциометра
const int POTENTIOMETER_PIN = A2;

// Напряжение питания микроконтроллера и АЦП
const float POWER_SUPPLY_V = 5.0;

// Разрядность АЦП
const int BIT_DEPTH_ADC = 1024; // 2^10

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода модуля потенциометра на вход
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  // Получение оцифрованного значения на модуле потенциометра
  word pot_value = analogRead(POTENTIOMETER_PIN);
  // Перевод оцифрованного значения в напряжение
  float pot_voltage = pot_value * (POWER_SUPPLY_V / BIT_DEPTH_ADC);
  
  Serial.print("Pot ADC ");
  Serial.println(pot_value);
  Serial.print("Pot V ");
  Serial.println(pot_voltage);
  Serial.println();

  delay(100);
}
