# **NRF24 Disruptor - Bluetooth & WiFi Signal Jammer**

## **Introduction**
The NRF24 Disruptor is a **radio frequency (RF) jammer** designed to interfere with Bluetooth and WiFi communications. It works by continuously transmitting signals on selected frequency channels, effectively preventing devices from establishing or maintaining connections.

### **How It Works**
Wireless communication relies on specific frequency bands regulated by standards like **IEEE 802.11** (WiFi) and **Bluetooth SIG**. This device disrupts these signals using the **NRF24L01** transceiver, which can send **constant carrier waves** that introduce noise into the target frequency range.

This project operates in two primary modes:

1. **Bluetooth Jamming Mode**: Transmits interference on Bluetooth frequency channels (37-50), affecting devices that communicate over **2.402 GHz – 2.480 GHz**.
2. **WiFi Interference Mode**: Disrupts WiFi signals on channels 1-14, which operate in the **2.4 GHz ISM band**.

The **ESP32-S3** microcontroller handles signal modulation and allows switching between jamming modes.

## **Technical Details**
- The **NRF24L01 module** operates in **constant carrier transmission mode**, flooding the target frequency with high-power signals.
- A **toggle switch** selects between Bluetooth and WiFi jamming modes.
- **Frequency hopping** is implemented for more effective interference across a range of channels.
- The device can cycle through frequencies dynamically or hold a constant jamming signal.

## **Hardware Components**
| Component          | Description                            |
|-------------------|------------------------------------|
| ESP32-S3         | Microcontroller                     |
| NRF24L01 Module  | RF Transceiver for signal jamming  |
| Toggle Switch    | Selects between Bluetooth and WiFi modes |

## **Installation & Usage**
1. **Connect the components** as per the circuit diagram.
2. **Upload the provided code** to the ESP32-S3 using Arduino IDE.
3. **Power on the device** and select the mode using the toggle switch:
   - **Up**: Activates Bluetooth jamming.
   - **Down**: Activates WiFi interference.
   - **Middle**: No jamming.
4. The device immediately starts transmitting interference signals.

## **Image References**
| ![Image 1](https://github.com/user-attachments/assets/0e18b74e-823e-46de-94e2-5bc520fa959e) | ![Image 2](https://github.com/user-attachments/assets/ae1a8e72-0811-48b9-9404-68dd4c26b61b) | ![Image 3](https://github.com/user-attachments/assets/141f267c-a87e-4bc1-b3f5-97a996c411fe) |
|----------------------------------|----------------------------------|----------------------------------|

## **Legal Disclaimer**
This project is intended **only for educational and research purposes**. Using RF jammers to interfere with communications is **illegal in many countries**. Ensure compliance with local laws before using this device.

---

# **مختل‌کننده NRF24 - مسدودکننده سیگنال‌های بلوتوث و وای‌فای**

## **مقدمه**
**مختل‌کننده NRF24** یک دستگاه **تداخل فرکانس رادیویی (RF Jammer)** است که ارتباطات **بلوتوث** و **وای‌فای** را از طریق ارسال سیگنال‌های مزاحم مختل می‌کند. این دستگاه با استفاده از **ماژول NRF24L01** و یک **میکروکنترلر ESP32-S3** ساخته شده است و می‌تواند دو حالت مختلف را اجرا کند:

1. **حالت مختل‌کننده بلوتوث**: ارسال نویز در کانال‌های 37-50 بلوتوث که ارتباطات در باند **2.402 GHz – 2.480 GHz** را مختل می‌کند.
2. **حالت ایجاد تداخل در وای‌فای**: ارسال سیگنال در کانال‌های 1-14 وای‌فای که در باند **2.4 GHz ISM** عمل می‌کند.

## **نحوه عملکرد**
- ماژول **NRF24L01** در **حالت ارسال سیگنال پیوسته** عمل می‌کند، که باعث ایجاد نویز قوی در باندهای مشخص‌شده می‌شود.
- **کلید تغییر وضعیت** برای انتخاب بین حالت‌های مختل‌کننده بلوتوث و وای‌فای استفاده می‌شود.
- قابلیت **پرش فرکانسی (Frequency Hopping)** برای تأثیرگذاری بیشتر و پوشش گسترده‌تر پیاده‌سازی شده است.
- دستگاه می‌تواند به‌صورت **پیوسته** روی یک فرکانس خاص تداخل ایجاد کند یا **به‌صورت دوره‌ای کانال را تغییر دهد**.

## **قطعات سخت‌افزاری**
| قطعه              | توضیحات                            |
|-------------------|------------------------------------|
| ESP32-S3         | میکروکنترلر                         |
| ماژول NRF24L01   | فرستنده-گیرنده RF برای ایجاد اختلال |
| کلید تغییر وضعیت | انتخاب بین حالت‌های بلوتوث و وای‌فای |

## **نصب و راه‌اندازی**
1. **اتصال قطعات** طبق دیاگرام سیم‌کشی.
2. **آپلود کد در برد ESP32-S3** با استفاده از Arduino IDE.
3. **روشن کردن دستگاه** و تغییر وضعیت کلید:
   - **بالا**: فعال‌سازی مختل‌کننده بلوتوث.
   - **پایین**: فعال‌سازی تداخل وای‌فای.
   - **وسط**: عدم ایجاد تداخل.
4. دستگاه بلافاصله ارسال سیگنال‌های اختلال‌زا را آغاز خواهد کرد.

## **تصاویر پروژه**
| ![تصویر 1](images/device_front.jpg) | ![تصویر 2](images/device_side.jpg) | ![تصویر 3](images/device_back.jpg) |
|----------------------------------|----------------------------------|----------------------------------|

## **هشدار قانونی**
این پروژه **صرفاً برای اهداف تحقیقاتی و آموزشی** طراحی شده است. استفاده از مختل‌کننده‌ها برای ایجاد تداخل در ارتباطات **در بسیاری از کشورها غیرقانونی است**. لطفاً پیش از استفاده از این دستگاه، قوانین محلی را بررسی کنید.



![20250215_223138](https://github.com/user-attachments/assets/0e18b74e-823e-46de-94e2-5bc520fa959e)
![20250215_223945](https://github.com/user-attachments/assets/ae1a8e72-0811-48b9-9404-68dd4c26b61b)
![20250215_224053](https://github.com/user-attachments/assets/141f267c-a87e-4bc1-b3f5-97a996c411fe)
