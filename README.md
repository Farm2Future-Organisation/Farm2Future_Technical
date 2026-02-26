# Farm2Future Agricultural Robotics Platform

Farm2Future is developing a modular agricultural robotics ecosystem designed to reduce labour dependency and improve operational efficiency for Indian farmers.

The platform currently includes:

- Agribot – Multi-function modular ground robot  
- AgriArm – 6-DOF greenhouse automation arm  
- AgriDrone – High-capacity aerial spraying and monitoring system (Planned)

---

# Agribot

Agribot is a modular ground-based agricultural robot designed to perform multiple farming operations using interchangeable mechanical attachments.

## Core Specifications

- Controller: ESP32
- Drive Motors: 12V High-Torque DC Motors
- Motor Drivers:
  - Driver 1: Locomotion control
  - Driver 2: Functional module control
- Power System: 12V DC system

## Functional Capabilities

- Seeding
- Watering
- Ploughing (Mechanical removable attachment)
- Raise/Lower plough mechanism using motor actuation
- Manual module switching

## Current Control System

- Remote controlled (manual operation)
- No autonomous navigation at present
- Future roadmap includes LiDAR-based autonomous navigation

## Design Philosophy

- Modular mechanical interface
- Scalable to small and medium farms
- Designed for rental deployment model

---

# AgriArm

AgriArm is a 6-DOF robotic arm designed for repetitive greenhouse tasks.

## Core Specifications

- Controller: Arduino Uno
- Actuation: Servo Motors
- Degrees of Freedom: 6 DOF
- Power Source:
  - Direct AC socket connection (current)
  - Battery option possible

## Deployment Flexibility

- Can be fixed in greenhouse
- Can be integrated into mobile platform

## Current Status

- Small-scale functional prototype built
- Manual control for demonstration
- Can be automated using programmed task loops

## Intended Use Cases

- Precision repetitive agricultural tasks
- Controlled greenhouse operations
- Sorting and structured crop handling

---

# AgriDrone (Planned Development)

AgriDrone is a high-capacity agricultural drone platform under development.

## Planned Specifications

- Flight Controller: Pixhawk
- Motors: BLDC
- Wings: Foldable for transport and storage
- Tank Capacity: 15 Litres
- Integrated Camera System

## Intended Capabilities

- Precision crop monitoring
- Field data collection
- Aerial spraying operations

---

# System Architecture Overview

The Farm2Future platform is built on:

- Embedded ESP32-based control systems
- Modular mechanical design
- Expandable automation logic
- Future AI and LiDAR integration roadmap

---

# Repository Structure

Agribot/  
AgriArm/  
AgriDrone/  
common-modules/  
docs/  
demo/  

---

# 📍 Development Status

Agribot – Functional prototype  
AgriArm – Small-scale functional prototype  
AgriDrone – Planned  

---

© 2026 Farm2Future. All rights reserved.
