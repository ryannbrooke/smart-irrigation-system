// -------- Pin Definitions --------
const int moisturePin = 34;    
const int pumpPin = 18;        

// -------- Moisture Thresholds --------
const int dryThreshold = 3000; 
const int wetThreshold = 2500; 

// -------- Timing --------
const unsigned long dryDelay = 5000; 

bool pumpOn = false;
bool dryTimerRunning = false;
unsigned long dryStartTime = 0;


void setup() {
  Serial.begin(115200);

  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // Pump OFF

  Serial.println("Smart Irrigation System Started");
}


void loop() {

  int moisture = analogRead(moisturePin);

  Serial.print("Moisture: ");
  Serial.println(moisture);


  // Soil is dry
  if (moisture > dryThreshold) {

    if (!dryTimerRunning) {
      dryStartTime = millis();
      dryTimerRunning = true;
      Serial.println("Dry soil detected. Starting timer...");
    }


    if (!pumpOn && (millis() - dryStartTime >= dryDelay)) {

      pumpOn = true;
      digitalWrite(pumpPin, HIGH);

      Serial.println("Pump ON");
    }
  }


  // Soil is wet enough
  else if (moisture < wetThreshold) {

    dryTimerRunning = false;


    if (pumpOn) {

      pumpOn = false;
      digitalWrite(pumpPin, LOW);

      Serial.println("Pump OFF");
    }
  }


  delay(500);
}
