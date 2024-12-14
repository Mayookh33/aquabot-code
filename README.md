# Obstacle Avoidance Boat

This project is an Arduino-based obstacle-avoidance boat that uses ultrasonic sensors to detect obstacles in three directions (front, left, and right). Based on the distance data, the boat can decide whether to move forward, turn left, turn right, or stop.

## Features
- **Obstacle Detection:** Uses three ultrasonic sensors to measure distances in front, left, and right directions.
- **Autonomous Navigation:** Makes decisions to avoid obstacles and navigate effectively.
- **Motor Control:** Controls two DC motors to drive and steer the boat.
- **Real-time Feedback:** Displays sensor data on the Serial Monitor.

## Components Required
1. Arduino Nano or compatible microcontroller.
2. 3 x Ultrasonic sensors (e.g., HC-SR04).
3. Motor driver module (e.g., L298N).
4. 2 x DC motors.
5. Battery pack.
6. Connecting wires.
7. Breadboard (optional).

## Pin Configuration
| Pin Name         | Arduino Pin |
|------------------|-------------|
| Front Trigger    | 2           |
| Front Echo       | 3           |
| Left Trigger     | 4           |
| Left Echo        | 5           |
| Right Trigger    | 6           |
| Right Echo       | 7           |
| Motor 1 Forward  | 8           |
| Motor 1 Backward | 9           |
| Motor 2 Forward  | 10          |
| Motor 2 Backward | 11          |

## Code Overview
### Functions
- **`calculateDistance(trigPin, echoPin)`**
  - Measures the distance using the specified ultrasonic sensor.
- **`moveForward()`**
  - Drives the boat forward.
- **`turnLeft()`**
  - Turns the boat to the left.
- **`turnRight()`**
  - Turns the boat to the right.
- **`stopBoat()`**
  - Stops the boat completely.

### Main Logic
- The `loop()` function measures distances using the ultrasonic sensors and determines the action based on predefined conditions:
  1. If all directions are clear, move forward.
  2. If an obstacle is detected in front, decide to turn left or right based on side distances.
  3. Stop the boat if no safe direction is available.

## How to Use
1. Connect the components as per the pin configuration.
2. Upload the provided Arduino code to the microcontroller.
3. Open the Serial Monitor to view sensor readings in real-time.
4. Place the boat in an environment with obstacles and watch it navigate autonomously.

## Example Output on Serial Monitor
```
Front: 20 cm, Left: 30 cm, Right: 15 cm
Moving Forward

Front: 10 cm, Left: 25 cm, Right: 12 cm
Turning Left

Front: 12 cm, Left: 10 cm, Right: 10 cm
Boat Stopped
```

## Notes
- Ensure the ultrasonic sensors are properly aligned to avoid inaccurate readings.
- Use a power source sufficient to drive the motors and the Arduino.
- Adjust the `SAFE_DISTANCE` value in the code to fine-tune obstacle avoidance behavior.

## License
This project is open-source and available under the MIT License.

---
Feel free to contribute by reporting issues or submitting pull requests!

