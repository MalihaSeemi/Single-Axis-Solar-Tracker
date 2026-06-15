# Single-Axis-Solar-Tracker
An Arduino-based single-axis solar tracking system that uses LDR sensory feedback and a servo motor to dynamically align a solar panel with the brightest light source, maximizing energy efficiency
# Single-Axis Solar Tracking System

An automated, hardware-verified single-axis solar tracker designed to maximize the energy efficiency of a photovoltaic (PV) panel. The system uses a closed-loop feedback mechanism to continuously align the solar panel with the optimal angle of incident light throughout the day, mitigating cosine efficiency losses.

---

## 📺 Project Demonstration
https://github.com/user-attachments/assets/b3e322e2-a176-4766-a509-6938ed9fc58d


---

## 🚀 Key Features
* **Closed-Loop Feedback:** Utilizes a pair of Light Dependent Resistors (LDRs) divided by a central partition to detect differential light intensity.
* **Precision Actuation:** Processes real-time sensor inputs via an Arduino microcontroller to drive a servo motor, smoothly adjusting the panel's tilt angle.
* **Jitter Reduction:** Implements a software-defined error threshold (deadband) to prevent continuous micro-adjustments, reducing structural wear and mechanical power consumption.
* **Hardware-Verified:** Fully prototyped and verified under varied ambient outdoor lighting conditions.

---

## 🛠️ Hardware Components
* **Microcontroller:** Arduino (Uno or Nano)
* **Actuator:** TowerPro SG90 / MG996R Servo Motor
* **Sensors:** 2x Light Dependent Resistors (LDRs)
* **Resistors:** 2x $10\text{k}\Omega$ resistors (configured as a voltage divider network)
* **Power Supply:** 5V External DC Power Source (Recommended for steady servo operation)
* **Structure:** Custom single-axis mechanical rig with a central shadow partition

---

## 📊 System Architecture & Control Logic

The system operates on a differential voltage comparison logic. The two LDRs form separate voltage dividers connected to the microcontroller's analog input pins. The central vertical barrier creates a shadow over one LDR if the light source moves, creating a voltage delta.
