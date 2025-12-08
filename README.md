# Endoscopic Sinus Fluid Extraction Device

## 📌 Overview
A **minimally invasive endoscopic sinus fluid extraction device** designed for sinusitis surgeries.  
This system integrates **inspection, irrigation, and suction channels** into a single tube, while combining **servo-controlled bending**, **embedded microcontroller logic**, and **AI-assisted imaging** for enhanced precision and efficiency.

---

## 🚀 Features
- **Multi-channel tube design**: Inspection, irrigation, and suction in one device  
- **Servo-controlled distal tip**: Precision bending with PWM signals  
- **Camera integration**: Real-time endoscopic visualization  
- **AI assistance**: Computer vision for fluid/pathogen detection  
- **Embedded control**: Atmega328p microcontroller for reliable low-level operations  

---

## 🛠️ Technical Stack

### Hardware
- Atmega328p microcontroller  
- Micro-servo motors (PWM controlled)  
- Endoscopic camera module  
- Rigid shaft + flexible distal tip  

### Software
- Arduino IDE for firmware development  
- OpenCV for computer vision tasks  
- Python/AI models for inspection and navigation assistance  

---

## ⚙️ Installation

### Firmware (Atmega328p)
1. Install [Arduino IDE](https://www.arduino.cc/en/software)  
2. Connect Atmega328p via USB programmer  
3. Upload the provided firmware (`/firmware/servo_control.ino`)  

### AI & Camera
1. Install Python 3.9+  
2. Install dependencies:
   ```bash
   pip install opencv-python numpy
