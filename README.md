# Smart Plant Watering System 

An automatic plant watering system built with Arduino Uno.

The system monitors soil moisture and water tank level, then automatically activates a water pump when the soil becomes dry. A 16x2 LCD displays real-time system information including soil moisture, water level, and pump status.

---

## Features

* Automatic plant watering
* Soil moisture monitoring
* Water tank level monitoring
* LCD1602 I2C display
* Relay-controlled water pump
* Dry-run protection (prevents pump operation when water is insufficient)
* Hysteresis control to avoid rapid relay switching

---

## Components

| Component              | Quantity |
| ---------------------- | -------- |
| Arduino Uno R3         | 1        |
| LCD1602 I2C            | 1        |
| Soil Moisture Sensor   | 1        |
| Water Level Sensor     | 1        |
| 1-Channel Relay Module | 1        |
| Mini Water Pump (3–6V) | 1        |
| Silicone Tube          | 1        |
| Breadboard             | 1        |
| Jumper Wires           | Several  |

---

## System Logic

### Pump ON

The pump starts when:

* Soil moisture < 30%
* Water level is sufficient

### Pump OFF

The pump stops when:

* Soil moisture > 45%
* Water level is too low

This hysteresis design prevents frequent ON/OFF switching.

---

## Pin Connections

| Device               | Arduino Pin |
| -------------------- | ----------- |
| Soil Moisture Sensor | A0          |
| Water Level Sensor   | A1          |
| Relay IN             | D7          |
| LCD SDA              | A4          |
| LCD SCL              | A5          |

---

## Project Photos

### Full System Overview

![System Overview](images/overview.jpg)

### LCD Display

![LCD Display](images/lcd_display.jpg)

### Soil Moisture Sensor

![Soil Sensor](images/soil_sensor.jpg)

### Water Level Sensor

![Water Sensor](images/water_sensor.jpg)

---

## Future Improvements

* ESP32 WiFi integration
* Web dashboard monitoring
* Mobile notifications
* Temperature and humidity monitoring
* Cloud data logging

---

## Author

Phạm Bảo Quân

---

## License

This project is licensed under the MIT License.
