# MR Industries Monitor

An IoT-based machine health and worker safety monitoring system built for a small PVC pipe fittings manufacturing facility in Akkaraipattu, Eastern Province, Sri Lanka.

This is a personal engineering project developed by a high school student to address real operational problems observed in a family manufacturing business.

---

## Background

The factory manufactures PVC pipe fittings and electrical conduit accessories using hydraulic injection molding machines. Like many small manufacturing facilities in Sri Lanka, it currently relies entirely on manual observation for quality control, machine monitoring, and worker safety checks.

Problems identified through direct observation:

- No real-time data on machine condition or performance
- No environmental monitoring for worker safety (heat, fumes, noise)
- Unexpected machine breakdowns cause unplanned production stops
- CEB power cuts in Akkaraipattu interrupt both production and any monitoring systems
- Rejection rates generate material waste with no systematic root-cause tracking

This project is an attempt to address these problems with low-cost, accessible hardware.

---

## What It Does

A sensor system built on NodeMCU ESP8266 (ESP-12E), measuring:

| Sensor | Measures | Purpose |
|---|---|---|
| DHT22 | Temperature + Humidity | Worker heat safety monitoring |
| MQ135 | Air quality / CO2 / fumes | Chemical exposure detection |
| MAX4466 | Ambient noise | Hearing safety awareness |
| SW-420 | Machine vibration | Early warning for machine degradation |

Data is logged continuously to ThingSpeak (cloud). Threshold alerts notify when readings exceed safe levels. An 18650 Li-ion battery with TP4056 charging module maintains operation during power cuts.

Three units are planned for different locations across the factory floor.

---

## Machines

### Chen Hsong SM250
- In-Line Screw Injection Molding Machine
- Manufacturer: Chen Hsong Group, Taiwan
- Manufactured: September 2008
- Voltage: 380V, 3-phase, 50Hz
- Primary monitoring target — oldest machine, highest breakdown risk

### Chen De EM260-MK6
- Plastic Injection Moulding Machine
- Manufacturer: Chen De Plastics Machinery Co., Ltd (Chen Hsong Group), China
- Manufactured: November 2020
- Clamping force: 260 tons | Injection volume: 777 cm³ | Max power: 43.3 kW
- Secondary monitoring target

### Nanrong 120A
- Injection Molding Machine (purchased used, no manual available)
- Manufacturer: Nanrong, Taiwan
- Estimated clamping force: ~120 tons
- To be added in later deployment phase

---

## Hardware Per Unit

- NodeMCU ESP8266 (ESP-12E, CH340)
- DHT22 temperature and humidity sensor
- MQ135 air quality sensor
- MAX4466 microphone amplifier module
- SW-420 vibration sensor module
- 18650 Li-ion battery (3500mAh)
- TP4056 charging module with protection circuit
- BS 74HC4051 analog multiplexer (shares A0 pin between MQ135 and MAX4466)
- Enclosure fabricated from factory PVC conduit offcuts

---

## Project Phases

- [x] Phase 1 — NodeMCU confirmed working (blink test)
- [x] Phase 2 — MQ135 calibrated, RZero ~240, reading 16-19 PPM indoors
- [x] Phase 3 — DHT22 working, 33.3C, 64% humidity, heat index 42C
- [x] Phase 4 — MAX4466 noise sensor working, home baseline peak-to-peak 32-78
- [x] Phase 5 — SW-420 vibration sensor working, logic confirmed for this module.
- [ ] Phase 6 — All sensors integrated
- [ ] Phase 7 — ThingSpeak WiFi logging
- [ ] Phase 8 — Threshold alert system
- [ ] Phase 9 — Battery backup and power cut detection
- [ ] Phase 10 — Factory deployment, Unit 1 (30-day continuous run)
- [ ] Phase 11 — Units 2 and 3 deployed
- [ ] Phase 12 — Vibration anomaly detection (scikit-learn, after 60+ days data)

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

## Developer

High school student, Akkaraipattu, Eastern Province, Sri Lanka.
A/L stream: Combined Mathematics, Physics, Chemistry.
Expected A/L examination: mid-2027.

I grew up around this factory and saw firsthand how the absence of real-time data affects decisions — from catching a machine problem early to knowing whether the air quality is safe for workers on a long shift. This project is my attempt to build something that actually helps, using hardware I can afford and skills I am currently learning.
