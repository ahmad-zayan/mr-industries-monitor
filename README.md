# MR Industries Monitor

Real-time machine health and worker safety monitoring system deployed at **MR Industries**, a PVC pipe fittings manufacturing facility in Akkaraipattu, Eastern Province, Sri Lanka.

Built by the founder's son — a high school student (Sri Lanka A/L, Combined Maths / Physics / Chemistry stream) — to solve documented operational problems using low-cost IoT hardware.

---

## The Problem

MR Industries manufactures approximately **1,000,000 PVC fittings per month** using hydraulic injection molding machines operating at 160–200°C under high pressure. The facility currently has no digital monitoring system.

Documented problems identified from factory operations:

| Problem | Impact |
|---|---|
| Rejection rate 2–5% | 20,000–50,000 units wasted per month |
| Unexpected machine breakdowns | 5–15 hours downtime per week |
| No environmental monitoring | Workers exposed to heat, PVC fumes, noise with no alert system |
| No maintenance data | Failures are reactive, not predictive |
| CEB power cuts (Akkaraipattu, Eastern Province) | Production stops, no data continuity |

When asked "What data do you wish you had?", factory management listed: real-time machine performance, predictive maintenance indicators, energy anomalies, and defect root-cause data. This project delivers all four.

---

## The Solution

A low-cost IoT monitoring system built on **NodeMCU ESP8266 (ESP-12E)**, continuously measuring:

| Sensor | Measures | Purpose |
|---|---|---|
| DHT22 | Temperature + Humidity | Worker heat safety |
| MQ135 | Air quality / CO2 / PVC fumes | Chemical exposure monitoring |
| MAX4466 | Ambient noise level | Hearing safety |
| SW-420 | Machine vibration | Predictive maintenance signal |

Data is logged to **ThingSpeak** (cloud dashboard) with threshold alerts. An **18650 Li-ion battery + TP4056 module** provides backup power during CEB outages — Akkaraipattu is on the Eastern Province CEB feeder and experiences regular scheduled and unscheduled cuts.

Three units will be deployed across the factory:
- **Unit 1** — Near injection molding machine SM250 (Chen Hsong, 2008) with vibration sensor
- **Unit 2** — Near injection molding machine EM260-MK6 (Chen De, 2020) with vibration sensor  
- **Unit 3** — Worker area / packaging zone (environment monitoring only)

---

## Factory Context

| Detail | Information |
|---|---|
| Company | MR Industries |
| Founded | December 2021 |
| Founders | Father and grandfather of project developer |
| Location | 2nd Mile Post, Akkaraipattu, Ampara District, Eastern Province, Sri Lanka |
| Products | PVC pipe fittings and electrical conduit accessories |
| Monthly output | ~1,000,000 units |
| Daily output | ~30,000 units |
| Monthly revenue | LKR 1,500,000 – 2,000,000 |
| Workers | 7 direct employees (~20 families supported) |
| Machines | Chen Hsong SM250 (2008), Chen De EM260-MK6 (2020), Nanrong 120A (year unknown), Grinding machine, Color mixer |

---

## Machines Being Monitored

### Chen Hsong SM250 (Primary monitoring target)
- **Type:** In-Line Screw Injection Molding Machine
- **Manufacturer:** Chen Hsong Group of Companies, Taiwan
- **Manufactured:** September 2008
- **Voltage:** 380V, 3-phase, 50Hz
- **Age:** ~17 years — highest breakdown risk in factory
- **Monitoring:** Vibration (SW-420) + environment sensors

### Chen De EM260-MK6
- **Type:** Plastic Injection Moulding Machine
- **Manufacturer:** Chen De Plastics Machinery Co., Ltd (Chen Hsong Group), China
- **Manufactured:** November 2020
- **Clamping force:** 260 tons
- **Injection volume:** 777 cm³
- **Max power:** 43.3 kW
- **Voltage:** 380V/50Hz, 3-phase
- **Monitoring:** Vibration + environment sensors (Unit 2)

### Nanrong 120A
- **Type:** Injection Molding Machine
- **Manufacturer:** Nanrong, Taiwan
- **Clamping force:** ~120 tons (estimated from model number)
- **Age:** Unknown — purchased used, no manual available
- **Monitoring:** To be added in Phase 2 deployment

---

## Hardware

| Component | Quantity | Purpose |
|---|---|---|
| NodeMCU ESP8266 (ESP-12E, CH340) | 3 | Main controller per unit |
| DHT22 | 3 | Temperature + humidity |
| MQ135 | 3 | Air quality |
| MAX4466 | 3 | Noise level |
| SW-420 | 2 | Machine vibration (SM250 + EM260) |
| 18650 Li-ion battery (2600mAh+) | 3 | Power cut backup |
| TP4056 with protection module | 3 | Battery charging + management |
| Plastic enclosure / PVC housing | 3 | Protection from dust and heat |
| CD4051 analog multiplexer | 3 | Share A0 pin between MQ135 and MAX4466 |

**Total hardware cost per unit: ~LKR 1,500–2,000**
**Total project hardware cost: ~LKR 5,000–6,000**

*Note: Enclosures are fabricated from MR Industries' own PVC conduit offcuts and end caps — factory waste material repurposed for the monitoring system housing.*

---

## Project Phases

- [x] Phase 1 — NodeMCU blink test (Arduino IDE confirmed working)
- [ ] Phase 2 — MQ135 air quality sensor test and calibration
- [ ] Phase 3 — DHT22 temperature + humidity sensor
- [ ] Phase 4 — MAX4466 noise sensor
- [ ] Phase 5 — SW-420 vibration sensor
- [ ] Phase 6 — All sensors integrated on one NodeMCU
- [ ] Phase 7 — ThingSpeak WiFi data logging
- [ ] Phase 8 — Threshold alert system
- [ ] Phase 9 — Battery backup integration and power cut detection
- [ ] Phase 10 — Factory deployment (30-day continuous run, Unit 1)
- [ ] Phase 11 — Units 2 and 3 deployed
- [ ] Phase 12 — Vibration anomaly detection model (scikit-learn, after 60+ days data)

---

## Repository Structure

```
mr-industries-monitor/
├── README.md
├── firmware/
│   ├── phase1_blink/
│   ├── phase2_mq135_test/
│   ├── phase3_dht22_test/
│   ├── phase4_all_sensors/
│   └── phase5_thingspeak/
├── data/
│   ├── calibration_log.csv
│   └── factory_readings/
├── docs/
│   ├── wiring/
│   ├── reports/
│   └── factory/
└── dashboard/
    ├── production_tracker.py
    └── sample_data.csv
```

---

## Data Collected

After deployment, this repository will contain:
- Continuous temperature, humidity, air quality, noise, and vibration readings
- Power cut event log (start time, duration, frequency) for Akkaraipattu
- Machine-specific vibration baselines and anomaly flags
- Before/after comparison of any threshold alert events

---

## Competition and Recognition Targets

- Sri Lanka National Science Foundation (NSF) School Science Competition 2027
- IESL Junior Inventor of the Year 2027
- Sri Lanka Science and Engineering Fair (SLSEF) — ISEF affiliate

---

## Developer

High school student, Akkaraipattu, Eastern Province, Sri Lanka.
A/L stream: Combined Mathematics, Physics, Chemistry.
Expected A/L examination: August 2027.

Growing up in a manufacturing family, I observed firsthand how machine breakdowns, material waste, and the absence of real-time data affect both production efficiency and worker safety. This project is a direct attempt to solve those problems — not as a theoretical exercise, but as a functional system deployed in a real facility that my family operates.

---

## Contact

Project documentation and updates: this repository.
Factory: MR Industries, 2nd Mile Post, Akkaraipattu, Ampara District, Sri Lanka.
