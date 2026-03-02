# Agribot Component List 🤖🌱

**Status:** Prototype Phase (Manual Control) → Future Upgrade (Autonomous)

This repository outlines the key components used in the **Agribot**, a multifunctional agricultural robot designed for ploughing, seeding, and watering. The current prototype is manually controlled, with plans for automation using LiDAR and additional sensors.

---

## 1. Controller

- **Microcontroller:** ESP32  
  - Central processing unit for motor control, sensor integration, and communication.  
  - Handles both locomotion and functional modules (plough, seeding, watering).  
- **Control Interface (Prototype):** PS3 Controller  
  - Provides manual control over movement and functional modules.  
- **Planned Automation:**  
  - LiDAR, GPS, IMU sensors for autonomous navigation.  
  - Future integration with ROS or custom path-planning algorithms.

---

## 2. Motors

- **Locomotion Motors:**  
  - 12V High Torque DC Motors x4   
  - Provide driving force for wheels or legs.  
- **Functional Motors:**  
  - Elevation motors for plough attachment.  
  - Motors for seeding and watering mechanisms.  

---

## 3. Motor Drivers

- **L298N Motor Drivers (x2)**  
  - **Driver 1:** Locomotion (movement control).  
  - **Driver 2:** Functional modules (plough, seeding, watering).  
  - Supports bi-directional DC motor control.  

---

## 4. Mechanical Components

- **Chassis:**  
  - Prototype: Wooden frame with PVC pipes for legs.  
  - Future: Metal chassis for improved strength and durability.  
- **Attachments:**  
  - Removable plough attachment for soil tilling.  
  - Elevation motor mechanism to adjust plough depth.  
  - Mounting points for seeding and watering modules.  

---

## 5. Sensors & Future Automation

- **LiDAR Sensor:** For obstacle detection and autonomous navigation.  
- **IMU (Inertial Measurement Unit):** For orientation and stability.  
- **GPS Module:** For precision navigation in the field.  
- **Soil/Water Sensors:** Future integration for intelligent irrigation and seeding.  

---

## 6. Power Supply

- **Battery:** 12V Lipo Rechargeable Battery (Capacity TBD)  
  - Powers both motors and ESP32.  
  - Separate voltage regulation for logic circuits if needed.  

---

## 7. Connectivity

- **Wired Connections:** Jumper wires for motor driver and sensor connections.  
- **Wireless Communication (Planned):** Wi-Fi/Bluetooth for remote monitoring and control.

---

## 8. Notes

> ⚠️ The current prototype is manually controlled and built with lightweight materials. Future iterations will include full automation, stronger mechanical components, and additional functional modules for improved agricultural efficiency.
