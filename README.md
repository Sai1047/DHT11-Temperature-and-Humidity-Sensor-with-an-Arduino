# DHT11-Temperature-and-Humidity-Sensor-with-an-Arduino
 
Report: DHT11 Temperature and Humidity Sensor with an Arduino


Abstract
The integration of the DHT11 sensor with an Arduino enables accurate measurement of environmental temperature and humidity. This project focuses on the use of the DHT11 sensor, which is widely recognized for its cost-effectiveness, low power consumption, and user-friendly interface. The primary goal is to monitor and display temperature and humidity values on a serial monitor, showcasing the sensor's capabilities in real-time data acquisition.

Objectives
1.	To understand the working principles of the DHT11 sensor and its interfacing with an Arduino.
2.	To acquire real-time temperature and humidity data and display it using the Arduino serial monitor.
3.	To explore potential applications of temperature and humidity sensors in environmental monitoring systems.

System Components
The key hardware and software components for this project are:
1.	Arduino Board: Serves as the central control unit to process sensor data.
2.	DHT11 Sensor: A compact and affordable sensor for measuring temperature (in Celsius) and humidity (as a percentage).
3.	Breadboard and Jumper Wires: Used for assembling and connecting components.
4.	Arduino IDE: Software environment for writing and uploading the program code.

Methodology
1.	Sensor and Arduino Interfacing:
o	The DHT11 sensor has three essential pins: VCC, GND, and DATA.
o	The VCC and GND pins are connected to the 5V and GND pins on the Arduino, respectively.
o	The DATA pin is connected to a digital pin on the Arduino (e.g., Pin 2) for data communication.

2.	Code Implementation:
o	The Arduino program is written using the DHT library, which simplifies communication with the DHT11 sensor.
o	The program initializes the sensor and continuously reads temperature and humidity values.
o	Data is displayed on the serial monitor in a user-friendly format.
3.	Data Visualization:
o	Real-time temperature and humidity readings are sent to the serial monitor every second, providing a clear demonstration of sensor performance.

Circuit Diagram
The circuit involves the following connections:
•	DHT11 Sensor:
o	VCC to 5V on the Arduino.
o	GND to GND on the Arduino.
o	DATA to a digital pin (e.g., Pin 2).
•	An optional pull-up resistor (10kΩ) is added between the DATA and VCC pins for reliable communication.

Code Snippet:

const int analogIn = A0;
int humiditySensorOutput = 0;

// Defining Variables
int RawValue = 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop() {
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivolts.
  tempC = (Voltage - 500) * 0.1;       // 500 is the offset
  tempF = (tempC * 1.8) + 32;          // Convert to Fahrenheit

  Serial.print("Raw Value = ");
  Serial.print(RawValue);
  Serial.print("\n milli volts = ");
  Serial.print(Voltage, 0); // Display voltage without decimals
  Serial.print("\n Temperature in C = ");
  Serial.print(tempC, 1);   // Display temperature in Celsius with 1 decimal
  Serial.print("\n Temperature in F = ");
  Serial.println(tempF, 1); // Display temperature in Fahrenheit with 1 decimal

  humiditySensorOutput = analogRead(A1);
  Serial.print(" Humidity: ");
  Serial.print(map(humiditySensorOutput, 0, 1023, 0, 100)); // Convert raw reading to percentage
  Serial.println("%"); // Print the % symbol after the humidity value
  
  delay(5000); // Iterate every 5 seconds
}
Output with TInkercad:


Results
•	Accuracy: The DHT11 sensor provides a precision of ±2% for humidity and ±0.5°C for temperature.
•	Real-time Data: Temperature and humidity values are updated every two seconds, demonstrating real-time monitoring.
•	Ease of Use: The Arduino IDE and DHT library simplify the implementation process, making it beginner-friendly.

Applications
1.	Environmental Monitoring: Monitoring weather conditions in agricultural and industrial applications.
2.	Home Automation: Integrating with smart systems to control HVAC systems.
3.	Health Devices: Maintaining optimal conditions for sensitive environments, such as laboratories.

Conclusion
The DHT11 sensor, in combination with Arduino, provides a reliable and efficient way to measure temperature and humidity. The project demonstrates the sensor’s practicality in various real-world applications, highlighting its importance in environmental and automation systems.

