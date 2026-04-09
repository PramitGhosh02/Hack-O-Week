// forklift_safety.ino
// Implements an ultrasonic sensor setup for a forklift to detect pedestrians.
// Activates a buzzer and stops the motor if an object is detected within 2 meters.

const int TRIG_PIN = 9;    // Ultrasonic sensor TRIG pin
const int ECHO_PIN = 10;   // Ultrasonic sensor ECHO pin
const int BUZZER_PIN = 11; // Buzzer output pin
const int MOTOR_PIN = 12;  // Motor control/enable pin

// Threshold distance in centimeters (2 meters = 200 cm)
const int SAFE_DISTANCE_CM = 200;

void setup() {
  // Initialize serial communication for debugging purposes
  Serial.begin(9600);
  
  // Configure pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  
  // Initialize states
  digitalWrite(BUZZER_PIN, LOW); // Buzzer off initially
  digitalWrite(MOTOR_PIN, HIGH); // Motor running initially (Assuming HIGH = RUN, LOW = STOP)
  
  Serial.println("Forklift Safety System Initialized.");
}

void loop() {
  // 1. Send ultrasonic pulse
  // Clear the TRIG_PIN to ensure a clean HIGH pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond HIGH pulse to trigger a measurement
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // 2. Read pulse reflection
  // pulseIn() returns the sound wave travel time in microseconds
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // 3. Calculate distance
  // Speed of sound is ~343 m/s, which converts to 0.0343 cm/microsecond
  // Distance = (time * speed) / 2 (divide by 2 because it's a round trip: send and bounce back)
  float distance = duration * 0.0343 / 2.0;

  // Print distance to Serial Monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 4. Implement Safety Logic
  // Check if distance is valid (> 0) and an object is within 2m (200cm)
  if (distance > 0 && distance <= SAFE_DISTANCE_CM) {
    // Pedestrian/Object detected!
    Serial.println("WARNING: Object within 2m! Stopping motor and sounding alarm.");
    digitalWrite(BUZZER_PIN, HIGH); // Turn ON buzzer
    digitalWrite(MOTOR_PIN, LOW);   // Disable motor 
  } else {
    // Path is clear
    digitalWrite(BUZZER_PIN, LOW);  // Turn OFF buzzer
    digitalWrite(MOTOR_PIN, HIGH);  // Enable motor
  }
  
  // Short delay between measurements to avoid ping overlap
  delay(100);
}
