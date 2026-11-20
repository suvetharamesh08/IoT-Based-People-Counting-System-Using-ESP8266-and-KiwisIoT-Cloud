# IoT-Based People Counting System Using ESP8266 and KiwisIoT Cloud

## 📌 Project Overview
This project uses an ESP8266 Wi-Fi module and two IR sensors to count the number of people entering and exiting a room. The system uses KiwisIoT Cloud to transmit counting data for real-time remote monitoring.

## 🚀 Features
- Automatic people counting using two IR sensors.
- Separate entrance and exit detection.
- Yellow LED indication for entry.
- Green LED indication for exit.
- Real-time data monitoring through KiwisIoT Cloud.
- Wireless communication using ESP8266 Wi-Fi.

## 🛠️ Components Required
- ESP8266 NodeMCU
- 2 IR Sensors
- Yellow LED
- Green LED
- Connecting Wires
- Breadboard

## ⚙️ Working Principle
1. The entrance IR sensor detects a person entering the room.
2. The entrance count increases, and the yellow LED blinks.
3. The exit IR sensor detects a person leaving the room.
4. The exit count increases, and the green LED blinks.
5. The counting information is transmitted to the KiwisIoT Cloud dashboard through Wi-Fi. 

## Source Code
[People_Counting_System.ino](People_Counting_System.ino)

## Source Code
[People_Counting_System.ino](People_Counting_System.ino)


## 📊 KiwisIoT Cloud Monitoring

The system sends the following data to the KiwisIoT Cloud dashboard:

| Channel | Data |
|---|---|
| Channel 0 | Entrance Count |
| Channel 1 | Exit Count |


## 🎯 Applications
- Smart classrooms
- Shopping malls
- Office buildings
- Libraries
- Public places

## 🔮 Future Improvements
- Display the total number of people inside.
- Add an OLED display for local monitoring.
- Generate occupancy alerts when the maximum capacity is reached.

## 👨‍💻 Developed Using
- Arduino IDE
- ESP8266
- IR Sensors
- KiwisIoT Cloud
- Embedded C++

