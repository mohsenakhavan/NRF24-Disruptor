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
   

## **Technical & Scientific Explanation - How Jamming Works?**  
### **1. Basics of Wireless Communication**
Wireless communication relies on **radio frequency (RF) signals** that travel through the air between devices. These signals operate within specific frequency bands regulated by global standards.  

- **Bluetooth** operates in the **2.402 GHz – 2.480 GHz** range, divided into **79 channels** (each 1 MHz wide).
- **WiFi (2.4 GHz Band)** works between **2.412 GHz – 2.484 GHz**, divided into **14 overlapping channels** (each 22 MHz wide).

Wireless signals are transmitted using **modulation techniques** like **GFSK (Gaussian Frequency Shift Keying) for Bluetooth** and **OFDM (Orthogonal Frequency-Division Multiplexing) for WiFi**.

### **2. What is RF Jamming?**
**RF jamming** is the process of **disrupting wireless signals** by introducing **intentional interference** on the same frequency band. The jammer transmits high-power signals that either:
1. **Flood the communication channel** with constant noise, making it impossible for devices to exchange data.
2. **Mimic real signals** to confuse receiving devices and cause packet loss.

This project uses an **NRF24L01 module** to generate a **constant carrier wave** that overlaps with Bluetooth or WiFi signals, causing **packet collisions and signal degradation**.

### **3. Types of Jamming Techniques**
There are multiple ways to jam wireless signals:

#### **A) Constant Carrier Jamming**
- The jammer continuously transmits a **high-power signal** on a specific frequency.
- This method is **used in this project** via `startConstCarrier()` in the NRF24 library.
- Devices attempting to communicate on this frequency will **experience high interference and fail to transmit/receive data**.

#### **B) Frequency Hopping Jamming**
- The jammer **rapidly switches between multiple channels**, making it harder for devices to adapt.
- This is implemented in the `two()` function of the provided code, where the frequency shifts dynamically.
- **More effective against frequency-hopping systems like Bluetooth**.

#### **C) Reactive Jamming**
- The jammer **monitors** radio signals and **only transmits interference** when an active transmission is detected.
- This technique is **more power-efficient** but requires a more advanced setup.

### **4. Impact on Bluetooth & WiFi**
#### **Bluetooth Jamming:**
- Bluetooth uses **Adaptive Frequency Hopping (AFH)**, meaning it dynamically switches channels.
- A jammer must **cover a wide range of channels** or **hop faster than the Bluetooth device** to be effective.
- Constant carrier signals on **37-50 MHz channels** will disrupt Bluetooth connections.

#### **WiFi Jamming:**
- WiFi operates on **wider channels (22 MHz each)**.
- The NRF24L01 module can **only jam one channel at a time**, so hopping techniques are needed to **cover multiple WiFi channels**.
- WiFi uses **error correction** techniques, so intermittent jamming may only slow down communication instead of fully disrupting it.

### **5. Limitations & Countermeasures**
- **Jammers do not affect wired communication** (Ethernet, fiber optics).
- **Higher-power transmitters** can overcome weak jammers.
- **Spread Spectrum Techniques** (DSSS, FHSS) make modern wireless protocols more resistant to jamming.
- **Shielded environments** (Faraday cages) can block jamming effects.

### **6. Ethical & Legal Considerations**
- RF jamming is **illegal in many countries**, except for military and law enforcement use.
- **Unauthorized jamming can disrupt critical services**, including emergency communications.
- Always ensure compliance with **local regulations** before experimenting with RF jamming.

---

## **Image References**
| ![Device Front](https://github.com/user-attachments/assets/0e18b74e-823e-46de-94e2-5bc520fa959e) | ![Device Front](https://github.com/user-attachments/assets/ae1a8e72-0811-48b9-9404-68dd4c26b61b) | ![Device Front](https://github.com/user-attachments/assets/141f267c-a87e-4bc1-b3f5-97a996c411fe) |
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

## **توضیحات علمی و آموزشی - مختل‌کننده امواج چگونه کار می‌کند؟**  
### **۱. اصول اولیه ارتباطات بی‌سیم**
ارتباطات بی‌سیم مبتنی بر **امواج رادیویی (RF)** است که بین دستگاه‌های مختلف ارسال و دریافت می‌شود. هر فناوری بی‌سیم در **یک باند فرکانسی مشخص** عمل می‌کند:

- **بلوتوث** در محدوده **2.402 GHz – 2.480 GHz** با **79 کانال فرکانسی** (هرکدام 1 مگاهرتز) کار می‌کند.
- **وای‌فای (باند ۲.۴ گیگاهرتز)** بین **2.412 GHz – 2.484 GHz** قرار دارد و دارای **۱۴ کانال همپوشانی** است (هرکدام ۲۲ مگاهرتز).

سیگنال‌های بی‌سیم با استفاده از **مدولاسیون‌های مختلف** ارسال می‌شوند. **GFSK** برای بلوتوث و **OFDM** برای وای‌فای استفاده می‌شود.

### **۲. مختل‌کننده فرکانس چیست؟**
**مختل‌کننده فرکانس رادیویی (RF Jammer)** دستگاهی است که **با ارسال نویز در یک باند مشخص، ارتباطات را مختل می‌کند**. این دستگاه از دو روش برای این کار استفاده می‌کند:
1. **ارسال سیگنال قوی روی فرکانس موردنظر** که باعث از بین رفتن داده‌های ارسالی بین دستگاه‌ها می‌شود.
2. **ایجاد سیگنال‌های جعلی** که گیرنده را گیج کرده و باعث از دست رفتن بسته‌های اطلاعاتی می‌شود.

در این پروژه، **ماژول NRF24L01** با ارسال یک **موج پیوسته (Constant Carrier Wave)** باعث **تداخل در امواج بلوتوث و وای‌فای** می‌شود.

### **۳. انواع روش‌های ایجاد تداخل (Jamming)**
#### **الف) مختل‌کننده پیوسته (Constant Carrier)**
- ارسال **سیگنال قوی مداوم** در یک فرکانس خاص.
- در این پروژه از تابع `startConstCarrier()` برای این نوع تداخل استفاده شده است.
- دستگاه‌هایی که روی این فرکانس کار می‌کنند، **دیگر قادر به ارسال و دریافت اطلاعات نخواهند بود**.

#### **ب) مختل‌کننده با پرش فرکانسی (Frequency Hopping)**
- تغییر سریع فرکانس **جهت پوشش چندین کانال**.
- در تابع `two()` این قابلیت پیاده‌سازی شده است.
- **بیشتر برای مختل کردن بلوتوث استفاده می‌شود** زیرا از پرش فرکانسی بهره می‌برد.

#### **ج) مختل‌کننده واکنشی (Reactive Jamming)**
- مختل‌کننده **منتظر یک سیگنال فعال می‌ماند** و تنها در صورت تشخیص فعالیت، شروع به ارسال نویز می‌کند.
- این روش **بهینه‌تر و کم‌مصرف‌تر** است، اما نیاز به سخت‌افزار پیچیده‌تر دارد.

### **۴. تأثیر روی بلوتوث و وای‌فای**
#### **مختل کردن بلوتوث**
- بلوتوث از **پرش فرکانسی تطبیقی (AFH)** استفاده می‌کند.
- مختل‌کننده باید **چندین کانال را همزمان پوشش دهد** یا **با سرعت بیشتری پرش کند**.
- ارسال نویز روی کانال‌های **۳۷-۵۰** باعث اختلال در ارتباطات بلوتوث خواهد شد.

#### **مختل کردن وای‌فای**
- وای‌فای دارای **کانال‌های وسیع‌تری (۲۲ مگاهرتز)** است.
- ماژول NRF24L01 **فقط می‌تواند یک کانال را مختل کند**، بنابراین برای پوشش کل طیف باید از **پرش فرکانسی** استفاده کرد.
- برخی پروتکل‌های وای‌فای دارای **مکانیزم تصحیح خطا** هستند که باعث می‌شود اختلال جزئی فقط باعث کاهش سرعت شود.

### **۵. محدودیت‌ها و مقابله با جَمینگ**
- مختل‌کننده **روی ارتباطات سیمی تأثیری ندارد**.
- دستگاه‌های با **قدرت سیگنال بالاتر** می‌توانند بر اختلال غلبه کنند.
- استفاده از **محفظه‌های فلزی (Faraday Cage)** می‌تواند از تأثیر مختل‌کننده جلوگیری کند.

### **۶. ملاحظات قانونی و اخلاقی**
- استفاده از جَمِرها در بسیاری از کشورها **غیرقانونی** است.
- **ایجاد اختلال در ارتباطات اضطراری یا عمومی ممکن است عواقب جدی داشته باشد**.
- **قبل از استفاده، قوانین محلی را بررسی کنید**.

---

## **تصاویر پروژه**
| ![Device Front](https://github.com/user-attachments/assets/0e18b74e-823e-46de-94e2-5bc520fa959e) | ![Device Front](https://github.com/user-attachments/assets/ae1a8e72-0811-48b9-9404-68dd4c26b61b) | ![Device Front](https://github.com/user-attachments/assets/141f267c-a87e-4bc1-b3f5-97a996c411fe) |
|----------------------------------|----------------------------------|----------------------------------|

## **هشدار قانونی**
این پروژه **صرفاً برای اهداف تحقیقاتی و آموزشی** طراحی شده است. استفاده از مختل‌کننده‌ها برای ایجاد تداخل در ارتباطات **در بسیاری از کشورها غیرقانونی است**. لطفاً پیش از استفاده از این دستگاه، قوانین محلی را بررسی کنید.




