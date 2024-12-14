// Pin assignments
#define trigPinFront 2
#define echoPinFront 3

#define trigPinLeft 4
#define echoPinLeft 5

#define trigPinRight 6
#define echoPinRight 7

#define motor1Forward 8
#define motor1Backward 9
#define motor2Forward 10
#define motor2Backward 11


#define SAFE_DISTANCE 15  // Minimum distance in cm to avoid obstacles

// Function to calculate distance using an ultrasonic sensor
long calculateDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long pulseDuration = pulseIn(echoPin, HIGH);
  long distance = (pulseDuration * 0.034) / 2;
  return distance;
}

// Function to move forward
void moveForward() {
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Forward, HIGH);
  digitalWrite(motor2Backward, LOW);
  Serial.println("Moving Forward");
}

// Function to turn left
void turnLeft() {
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor1Backward, HIGH);
  digitalWrite(motor2Forward, HIGH);
  digitalWrite(motor2Backward, LOW);
  Serial.println("Turning Left");
}

// Function to turn right
void turnRight() {
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Forward, LOW);
  digitalWrite(motor2Backward, HIGH);
  Serial.println("Turning Right");
}

// Function to stop all motors
void stopBoat() {
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Forward, LOW);
  digitalWrite(motor2Backward, LOW);
  Serial.println("Boat Stopped");
}

void setup() {
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);

  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  pinMode(motor1Forward, OUTPUT);
  pinMode(motor1Backward, OUTPUT);
  pinMode(motor2Forward, OUTPUT);
  pinMode(motor2Backward, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Measure distances
  long distanceFront = calculateDistance(trigPinFront, echoPinFront);
  long distanceLeft = calculateDistance(trigPinLeft, echoPinLeft);
  long distanceRight = calculateDistance(trigPinRight, echoPinRight);

  // Display distances on Serial Monitor
  Serial.print("Front: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right: ");
  Serial.print(distanceRight);
  Serial.println(" cm");

  // Conditions for Boat Operations
  if (distanceFront > SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) {
    moveForward();
  } 

  // Front obstacle
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) {
    if (distanceLeft > distanceRight) {
      turnLeft();
    } else {
      turnRight();
    }
  }

  // Left obstacle
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) {
    if (distanceFront > distanceRight) {
      moveForward();
    } else {
      turnRight();
    }
  } 

  // Right obstacle
  else if (distanceFront > SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) {
    if (distanceFront > distanceLeft) {
      moveForward();
    } else {
      turnLeft();
    }
  }

  // Front and left obstacles
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) {
    turnRight();
  } 

  // Front and right obstacles
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) {
    turnLeft();
  }

  // Left and right obstacles
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) {
    moveForward();
  }
  s 
  // All three sides obstructed
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) {
    stopBoat();
  }

  delay(1000); // Small delay for stability
  Serial.println("");
}
