&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;__Hi__ 👋,Welcome to the **Smart-Energy-System** project 🌞🔋💡. This project focuses on creating an intelligent battery and load management system using solar panels, batteries, and Arduino. It converts solar energy into electrical power, charges batteries, and provides power to Arduino and peripherals. The system also includes real-time monitoring of battery and load parameters such as voltage, current, and power using the INA226 module.

---

## 🌟 Table of Contents 📜

- 💡 [Project Overview](#project-overview)
- ✨ [Features](#features)
- 📐 [Hardware Design and Circuit Connections](#hardware-design-and-circuit-connections)
- 🗂️ [BOM (Bill of Materials)](#bom-bill-of-materials)
- 🛠️ [Software Environment Setup](#software-environment-setup)
- 🎇 [How to Use](#how-to-use)
- 🌐 [IoT Platform and Data Upload](#iot-platform-and-data-upload)
- 📝 [Notes and Common Issues](#notes-and-common-issues)
- 🚀 [Future Outlook](#future-outlook)

---

## 💡 Project Overview

The **Smart-Energy-System** project integrates solar panels, battery management, and real-time data monitoring into a smart energy solution. The system uses solar panels to convert sunlight into electrical energy, which charges a 5V battery. The battery powers Arduino and connected peripherals through a boost module. The Arduino monitors and displays the battery and load data, while the **INA226 module** tracks the battery and load voltage, current, and power.

---

## ✨ Features

- **Real-time Battery Monitoring**: Monitors the battery's voltage, current, and power through INA226, providing instant feedback.
- **Load Management**: Monitors two connected loads (motor and solar lamp), adjusting power supply based on real-time data.
- **Solar Energy Utilization**: Uses solar panels to charge the battery, making the system energy-efficient and eco-friendly.
- **Remote Control**: Potential integration with a smart home platform for remote monitoring and control through a mobile app.

---

## 📐 Hardware Design and Circuit Connections

### Main Hardware Components

- **Solar Panel**: Provides electrical power to charge the battery (12V support).
- **Solar Step-down Module**: Converts the solar panel output to 5V via USB.
- **5V Battery**: Powers Arduino and load devices.
- **Arduino Uno**: The main controller, processing data and controlling the loads.
- **INA226**: Voltage, current, and power monitoring module for the battery and loads.
- **TFT Display**: Displays voltage, current, and power data for both the battery and loads.
- **Splitter**: Used for connecting multiple electrical devices.
- **Loads**: Includes a motor (R300C) and a solar lamp.
- **LED**: White 3V7, additional lighting for the system.

### Circuit Connections

- **Solar Panel** is connected to the **Step-down Module** to charge the battery.
- **Battery** is connected to the **Arduino Uno** and provides power.
- **INA226** is connected between the battery and the loads to monitor their performance.
- **TFT Display** is connected to Arduino via I2C to show real-time data.

---

## 🗂️ BOM (Bill of Materials)

| Component                 | Specification                                  | Quantity |
|---------------------------|------------------------------------------------|----------|
| **Solar Panel**            | 12V solar panel for battery charging           | 1        |
| **Solar Step-down Module** | 5V USB step-down module                        | 1        |
| **5V Battery**             | Battery for powering Arduino and devices       | 1        |
| **Arduino Uno**            | Main controller                                | 1        |
| **INA226 Module**          | Monitors voltage, current, and power           | 1        |
| **TFT Display**            | 2.4-inch display for data display              | 1        |
| **Splitter**               | For connecting multiple devices                | 1        |
| **R300C Motor**            | Micro motor as load 1                          | 1        |
| **Solar Lamp**             | Solar-powered lamp as load 2                  | 1        |
| **LED**                    | White LED 3V7                                  | 1        |

---

## 🛠️ Software Environment Setup

1. **Development Environment**: Use **VSCode** with the **PlatformIO** plugin for code development.
2. **Library Installation**:
   - **Adafruit INA226**: Library to interface with the INA226 for current, voltage, and power monitoring.
   - **TFT_eSPI**: For controlling the TFT display.
   - **ArduinoJson**: Used to parse and handle JSON data.
3. **Import Project**: Open the project folder in VSCode and import the Arduino project to start working.

---

## 🎇 How to Use

### Assemble the Hardware:

1. Connect all components as per the circuit diagram.
2. Power the system with the solar panel and ensure the connections are correct.

### Configure and Debug:

1. Upload the code to Arduino using **PlatformIO** or the Arduino IDE.
2. Check the data displayed on the TFT display for voltage, current, and power of the battery and loads.
3. You can adjust settings like monitoring intervals or load configurations through the Arduino code.

### Monitor and Adjust:

1. Use the TFT display to monitor the system’s performance in real-time.
2. Optionally, integrate the system with a smart home app to view data and control settings remotely.

---

## 🌐 IoT Platform and Data Upload

1. **Platform Selection**: We use **ThingSpeak** or **Blynk** as IoT platforms to upload data and manage the system remotely.
2. **Device Connection and Binding**: Follow the tutorial to bind your device with the IoT platform.
3. **Data Upload**: Real-time sensor data can be uploaded via HTTP requests or MQTT.

```cpp
// Example code to upload data
void sendDataToCloud(float voltage, float current, float power) {
    String data = "{\"voltage\": " + String(voltage) + ", \"current\": " + String(current) + ", \"power\": " + String(power) + "}";
    // Send data to IoT platform here
}

```

## 📝 Notes and Common Issues

- **Sensor Calibration**: Ensure that the INA226 module is correctly calibrated for accurate readings.
- **Battery Management**: Make sure the battery is fully charged before running the system to avoid power interruptions.
- **Power Supply**: Check the solar panel’s power output to ensure it's sufficient for the battery charging.

---

## 🚀 Future Outlook

- **Multi-Sensor Integration**: Adding more sensors such as temperature and humidity sensors to provide a comprehensive environmental monitoring system.
- **AI-powered Predictions**: Implementing machine learning to predict energy usage patterns based on historical data and adjusting power distribution automatically.
- **Optimizing Solar Panel Efficiency**: Future integration with more efficient solar cells to improve energy collection and storage.
- **Remote Management**: Expanding support for multiple devices connected to the cloud for easier control via a smartphone app.
