# 🔥 Smart GSM-Based Fire Alarm System

A Smart GSM-Based Fire Alarm System developed using **Arduino UNO** and an **MQ2 Gas Sensor**. The system detects smoke levels, activates an LED and buzzer during fire conditions, and simulates GSM SMS alerts using AT Commands through the Serial Monitor in Wokwi.

---

## 📌 Project Overview

This project demonstrates a software-simulated embedded fire alarm system built using Arduino. It continuously monitors smoke concentration and classifies it into different safety levels. During critical conditions, the system activates local alarms and simulates SMS notifications.

---

## ✨ Features

- 🔥 MQ2 Smoke Detection
- 📊 Smoke Percentage Monitoring
- 🟢 Safe / 🟡 Warning / 🔴 Critical Fire Detection
- 🚨 LED and Buzzer Alarm
- 📱 GSM SMS Simulation using AT Commands
- 🔄 Manual Alarm Reset
- 📈 Fire Event Counter
- 💻 Real-Time Serial Monitoring
- 🧪 Wokwi Simulation

---

## 🛠 Hardware Components

- Arduino UNO
- MQ2 Gas Sensor
- LED
- 220Ω Resistor
- Buzzer
- Push Button

---

## 💻 Software Used

- Arduino IDE
- Wokwi Simulator
- Embedded C++

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| MQ2 AOUT | A0 |
| LED | D8 |
| Buzzer | D9 |
| Push Button | D2 |

---

## ⚙ Working Principle

1. Arduino continuously reads smoke values from the MQ2 sensor.
2. Smoke concentration is converted into a percentage.
3. The system classifies the environment into:
   - SAFE
   - WARNING
   - CRITICAL FIRE
4. During a fire event:
   - LED turns ON
   - Buzzer sounds
   - GSM SMS alert is simulated using AT Commands
5. The alarm can be reset using the push button.

---

## 📂 Project Structure

```
GSM-Based-Fire-Alarm-System/
│
├── Code/
│   └── FireAlarm.ino
│
├── Images/
│   ├── circuit.png
│   └── output.png
│
├── Report/
│   └── README.md
│
└── README.md
```

---

## 📷 Circuit Diagram

![Circuit Diagram](Images/circuit.png)

---

## 📱 Simulation Output

![Output](Images/output.png)

---

## 🚀 Future Enhancements

- OLED/LCD Display
- ESP32 IoT Integration
- Firebase Cloud Logging
- Blynk Dashboard
- SIM800L GSM Module
- Email & Telegram Alerts
- Temperature Sensor Integration

---

## 📚 Applications

- Smart Homes
- Offices
- Laboratories
- Industrial Safety
- Warehouses
- Server Rooms

---

## 🎯 Learning Outcomes

- Embedded C Programming
- Arduino Programming
- Sensor Interfacing
- Serial Communication
- AT Commands
- Alarm System Design
- Embedded System Simulation

---

## 👨‍💻 Author

**Harsh Rathore**

B.Tech Electronics & Communication Engineering

Chandigarh University

---

⭐ If you found this project useful, consider giving it a **Star** on GitHub.
