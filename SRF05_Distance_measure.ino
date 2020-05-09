/*
Vcc - 5v
Gnd - Gnd
Trig - 13
Echo - 12
*/

const int pingPin =13;
int inPin = 12;

void setup() {
    Serial.begin(9600);
    pinMode(pingPin, OUTPUT);
    pinMode(inPin, INPUT);
}

void loop() {
    float duration;
    float cm;

    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);  // 5~10 microsecond
    digitalWrite(pingPin, LOW);
    duration = pulseIn(inPin, HIGH);

    cm = microsecondToCentimeters(duration);

    Serial.print(duration);
    Serial.print(", ");
    Serial.print(cm);
    Serial.print(" cm.");
    Serial.println();
    delay(100);    
}

float microsecondToCentimeters(float microseconds) {
    return microseconds / 29 / 2;
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
}