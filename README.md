# <p align="center"><span style="color:#89CFF0; font-size:42px;">SMART BIN SYSTEM</span></p>

<p align="center">
  <strong>An IoT-Based Smart Waste Monitoring System</strong>
</p>

---

## ABOUT THE PROJECT

The **Smart Bin System** is an Internet of Things (IoT)-based project designed to improve waste management through real-time bin monitoring.

The system monitors the waste level inside the bin and communicates the collected information to **ThingSpeak**, where users can view the bin's status through a monitoring dashboard.

It also monitors the lid position, indicating whether the bin is **open or closed**, while classifying the waste level into three categories: **Empty, Medium, and Full**.

By combining sensor technology, embedded systems, and cloud-based data visualization, the project provides a smarter approach to monitoring waste collection points.

## HOW IT WORKS

The system operates through four main functions:

<table>
<tr>
<td width="50%" valign="top">

### <img src="https://img.icons8.com/fluency/48/sensor.png" width="22" /> 01 / LEVEL DETECTION

The system detects the amount of waste inside the bin and determines its current fill level.

</td>
<td width="50%" valign="top">

### <img src="https://img.icons8.com/fluency/48/opened-folder.png" width="22" /> 02 / LID MONITORING

The system monitors the lid position and identifies whether the bin is open or closed.

</td>
</tr>
<tr>
<td width="50%" valign="top">

### <img src="https://img.icons8.com/fluency/48/cloud.png" width="22" /> 03 / THINGSPEAK INTEGRATION

The collected sensor information is sent to ThingSpeak for online monitoring and visualization.

</td>
<td width="50%" valign="top">

### <img src="https://img.icons8.com/fluency/48/combo-chart.png" width="22" /> 04 / STATUS DISPLAY

The dashboard displays the bin's fill level as Empty, Medium, or Full, alongside its lid status.

</td>
</tr>
</table>

<p align="center">
  <strong style="color:#89CFF0;">DETECT → MONITOR → TRANSMIT → VISUALIZE</strong>
</p>

## PROJECT DOCUMENTATION

<details>
<summary><strong>01 / WASTE LEVEL MONITORING</strong></summary>

The system monitors the amount of waste inside the bin and classifies the detected level into three categories:

- **EMPTY** — The bin has little or no waste.
- **MEDIUM** — The bin has reached an intermediate fill level.
- **FULL** — The bin has reached its full-level threshold.

</details>

<details>
<summary><strong>02 / LID STATUS MONITORING</strong></summary>

The system monitors the position of the bin lid and reports its current state:

- **OPEN** — The bin lid is open.
- **CLOSED** — The bin lid is closed.

</details>

<details>
<summary><strong>03 / THINGSPEAK DASHBOARD</strong></summary>

ThingSpeak is used as the cloud-based platform for displaying the information collected by the system.

The dashboard allows users to monitor:

- Waste fill level.
- Bin status: Empty, Medium, or Full.
- Lid status: Open or Closed.
- Sensor data submitted by the system.

</details>

<details>
<summary><strong>04 / SYSTEM OPERATION</strong></summary>

1. Sensors detect the waste level and lid position.
2. The controller processes the sensor readings.
3. The system determines the appropriate waste-level category and lid status.
4. The collected information is transmitted to ThingSpeak.
5. The dashboard displays the updated bin information.

</details>

## KEY CONCEPTS

- Internet of Things (IoT)
- Smart Waste Management
- Embedded Systems
- Sensor-Based Monitoring
- Cloud Data Visualization
- ThingSpeak Integration
- Real-Time Status Monitoring
- Waste Level Classification
- Hardware and Software Integration

## TECH STACK

| CATEGORY | TECHNOLOGY |
|:---|:---|
| IoT Platform | ThingSpeak |
| Hardware | Project-specific sensors and electronic components |
| Controller | Project-specific microcontroller |
| Communication | Internet Connectivity |
| Monitoring | ThingSpeak Dashboard |
| Programming | Project-specific firmware |

## PROJECT DETAILS

| CATEGORY | DETAILS |
|:---|:---|
| Project | Smart Bin System |
| Type | IoT-Based Embedded Systems Project |
| Domain | Smart Waste Management |
| Monitoring Platform | ThingSpeak |
| Waste Status | Empty, Medium, Full |
| Lid Status | Open, Closed |
| Developer | Munashe Walter Jojo |
| Brand | Munaxxe |

## EXPLORE THE PROJECT

<p align="center">
  <a href="https://github.com/Munaxxe/Smart-Bin-System-Munaxxe">
    <img src="https://img.shields.io/badge/VIEW_SOURCE_CODE-89CFF0?style=for-the-badge&labelColor=111827" alt="View Repository" />
  </a>
</p>

---

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=89CFF0&height=3&section=footer" width="100%" />
  <br/><br/>
  <strong>MUNASHE WALTER JOJO</strong>
  <br/>
  <sub>© 2026 MUNAXXE · ALL RIGHTS RESERVED</sub>
  <br/><br/>
</p>
