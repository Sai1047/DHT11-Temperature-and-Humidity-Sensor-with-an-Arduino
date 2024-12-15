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
