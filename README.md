# FloraFeel: Smart Pots That Care 🌱

**Bringing your plants to life with smart, expressive pots that care for them!**

<img src="https://user-images.githubusercontent.com/83647206/219926655-4d209fb8-d2ac-4ccb-8a87-718523876854.jpg" width="425" height="400"> <img src="https://user-images.githubusercontent.com/83647206/219939344-5445a053-adfc-4705-98be-c910b9ba8975.jpg" width="350" height="400">

---

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Setup Instructions](#setup-instructions)
6. [Web Dashboard](#web-dashboard)
7. [Contributing](#contributing)
8. [License](#license)
9. [Acknowledgements](#acknowledgements)

---

## Introduction
**FloraFeel** is an innovative project that brings your plants to life by making them interactive and expressive. Using sensors and IoT, the smart pot monitors your plant's health (soil moisture, temperature, light, and humidity) and displays its needs through emojis on an OLED screen. It also sends real-time data to a cloud platform for remote monitoring, ensuring your plant gets the care it deserves.

---

## Features
- **Real-time Monitoring**: Tracks soil moisture, temperature, light intensity, and humidity.
- **Expressive Emojis**: Displays emojis to indicate the plant's condition (e.g., 😢 for thirsty, 😊 for happy).
- **Cloud Integration**: Sends data to ThingSpeak for remote monitoring.
- **Web Dashboard**: A simple web page to monitor your plant from anywhere.
- **Alerts**: Notifies you when the plant needs attention (e.g., water or sunlight).

---

## Hardware Requirements
- **Microcontroller**: ESP32
- **Sensors**:
  - Soil Moisture Sensor
  - Temperature and Humidity Sensor (DHT11)
  - Light Intensity Sensor (LDR)
- **Display**: OLED Display (SSD1306)
- **Buzzer**: For alerts
- **Power Supply**: 5V USB or battery
- **Miscellaneous**: Jumper wires, breadboard, resistors, etc.

---

## Software Requirements
- **Arduino IDE**: For programming the ESP32.
- **Libraries**:
  - `DHT` (for temperature and humidity sensor)
  - `Adafruit_SSD1306` (for OLED display)
  - `WiFi` (for ESP32 Wi-Fi connectivity)
  - `ThingSpeak` (for cloud data logging)
- **Web Dashboard**: HTML, CSS, JavaScript (for monitoring).

---

## Setup Instructions

### 1. Hardware Setup
- Connect the sensors to the ESP32 as follows:
  - **Soil Moisture Sensor**: Analog pin (e.g., GPIO34)
  - **DHT11**: Digital pin (e.g., GPIO32)
  - **LDR**: Analog pin (e.g., GPIO35)
  - **OLED Display**: I2C pins (SDA: GPIO21, SCL: GPIO22)
  - **Buzzer**: Digital pin (e.g., GPIO25)

### 2. Software Setup
1. **Install Arduino IDE**:
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Install Required Libraries**:
   - Open Arduino IDE and install the following libraries via the Library Manager:
     - `DHT`
     - `Adafruit SSD1306`
     - `ThingSpeak`

3. **Upload Code**:
   - Open the `florafeel.ino` file in the Arduino IDE.
   - Replace the placeholders in the code with your Wi-Fi credentials and ThingSpeak API key.
   - Upload the code to the ESP32.

4. **Set Up ThingSpeak**:
   - Create a ThingSpeak account and set up a channel with fields for soil moisture, light intensity, temperature, and humidity.
   - Note down the **Channel ID** and **Write API Key**.

5. **Web Dashboard**:
   - Host the `index.html` file on GitHub Pages, Netlify, or any other hosting platform.
   - Replace `YOUR_CHANNEL_ID` and `YOUR_READ_API_KEY` in the JavaScript code with your ThingSpeak credentials.

---

## Web Dashboard
The web dashboard allows you to monitor your plant's health from anywhere. It displays real-time data and emojis based on the plant's condition.

<img src="https://user-images.githubusercontent.com/83647206/219940251-7a8cc103-a7fb-411d-9bae-4907bff3e478.jpg" width="400" height="225"> <img src="https://user-images.githubusercontent.com/83647206/219940258-3def7f4e-47de-4e26-acfd-365fcd397f57.jpg" width="400" height="225">

### Access the Dashboard
- Open the hosted web page in your browser.
- Example URL: `https://your-username.github.io/florafeel`

---

## Contributing
We welcome contributions to the **FloraFeel** project! Here's how you can help:
1. **Report Issues**: If you find any bugs or have suggestions, open an issue on GitHub.
2. **Submit Pull Requests**: Fork the repository, make your changes, and submit a pull request.
3. **Improve Documentation**: Help us improve the README or add more documentation.

---

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgements
- **ThingSpeak**: For cloud data logging and visualization.
- **Arduino Community**: For libraries and support.
- **GitHub**: For hosting and collaboration.

---

## Project Links
- **GitHub Repository**: [FloraFeel: Smart Pots That Care](https://github.com/adiys/florafeel)

---

**Let's make plant care smarter and more expressive with FloraFeel! 🌱🚀**
