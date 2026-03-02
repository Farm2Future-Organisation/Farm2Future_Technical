# AgriArm – Hardware Components

This directory documents all primary electronic, mechanical, and control components used in the AgriArm 6-DOF robotic system.

The current version of AgriArm is built as a small-scale functional prototype using a full metal structural framework and high-torque servo actuation.

---

## 1. Main Controller

### Arduino Uno

The AgriArm is currently controlled using an **Arduino Uno** microcontroller.

### Key Specifications:
- Microcontroller: ATmega328P
- Operating Voltage: 5V
- Input Voltage (recommended): 7–12V
- Digital I/O Pins: 14 (6 PWM outputs used for servo control)
- Communication: USB Serial (for Processing interface)
- Clock Speed: 16 MHz

### Role in System:
- Receives serial commands from Processing application
- Generates PWM signals to control 6 servo motors
- Executes manual motion commands
- Handles position updates for each joint

The Arduino Uno was selected for:
- Reliability
- Ease of integration with servo motors
- Strong community support
- Educational and prototyping flexibility

---

## 2. Actuation System

### Servo Model: AGFRC B53CHM V2 – 26kg Torque RC Servo Motor

The robotic arm uses **AGFRC B53CHM V2 high-torque digital servos** for joint actuation.

### Servo Specifications:
- Torque: 26 kg·cm
- Type: High-torque digital servo
- Gear Type: Metal gear
- Operating Voltage: 6–8.4V
- Rotation Range: 180°
- High holding torque under load
- Stable and precise positioning

### Why This Servo Was Selected:
- Suitable for lifting moderate loads
- Durable metal gear construction
- Higher torque compared to entry-level servos
- Better load stability for agricultural manipulation

All six degrees of freedom are powered by these servo motors, enabling:

- Base rotation
- Shoulder movement
- Elbow articulation
- Wrist pitch
- Wrist rotation
- Gripper control

---

## 3. Mechanical Structure

### Full Metal Frame Construction

AgriArm is constructed using a **metal framework**, providing:

- Structural rigidity
- Reduced vibration during movement
- Improved torque transfer
- Long-term durability

The use of metal over plastic significantly improves:

- Load-bearing capacity
- Joint stability
- Precision positioning under weight

The frame is modular and allows:

- Servo replacement
- Gripper modification
- Structural upgrades

---

## 4. End Effector

### Gripper Mechanism

The end effector is a **servo-driven gripper** designed for:

- Object grasping
- Crop handling simulation
- Educational manipulation tasks
- Small object pick-and-place operations

Features:
- Controlled by independent servo channel
- Adjustable grip width
- Suitable for lightweight agricultural samples

Future upgrades may include:
- Sensor-integrated gripper
- Force feedback
- Crop-specific gripping tools

---

## 5. Power System

### Current Version:
- Direct power supply via socket adapter
- External regulated power source for servo stability

### Design Considerations:
High-torque servos require stable voltage and sufficient current supply. The power system ensures:

- No voltage drop during multi-servo movement
- Stable PWM response
- Reduced jitter

### Future Integration:
- Battery-powered version for mobile deployment
- Dedicated servo power distribution board

---

## 6. Control Interface

### Processing-Based Desktop Application

AgriArm is manually controlled using a **Processing application** running on a computer.

### Communication Flow:
Processing App  
↓ (USB Serial Communication)  
Arduino Uno  
↓ (PWM Signals)  
6 Servo Motors  

The Processing interface enables:
- Individual joint control
- Angle adjustment
- Real-time command transmission
- Demonstration mode operation

Automation logic can be integrated in future firmware revisions.

---

## 7. System Summary

| Component | Model / Type | Purpose |
|------------|--------------|----------|
| Controller | Arduino Uno | Main control logic |
| Servo Motors | AGFRC B53CHM V2 | Joint actuation |
| Structure | Full Metal Frame | Stability & load support |
| End Effector | Servo-driven Gripper | Object manipulation |
| Control Interface | Processing App | Manual operation |

---

## Development Status

- Functional small-scale prototype
- Manual control implementation complete
- Automation integration planned
- Mobile deployment under consideration
