#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#define SOUND_SPEED 343 // m/s, speed of sound at 20 degrees Celsius

int main() {
    wiringPiSetup();

    double time_start;
    double time_end;
    double time_diff;

    double distance;
    const int TRIG_pin = 4; // GPIO Pin 4 for TRIG
    const int ECHO_pin = 5; // GPIO Pin 5 for ECHO

    pinMode(TRIG_pin, OUTPUT);
    pinMode(ECHO_pin, INPUT);

    while (1) {
        // Send a short pulse to trigger the sensor
        digitalWrite(TRIG_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG_pin, LOW);

        // Wait for the ECHO pin to go high, indicating the start of the pulse
        while (digitalRead(ECHO_pin) == LOW);
        time_start = micros();

        // Wait for the ECHO pin to go low again, indicating the end of the pulse
        while (digitalRead(ECHO_pin) == HIGH);
        time_end = micros();

        // Calculate the time difference between the start and end of the pulse
        time_diff = time_end - time_start;

        // Calculate distance using the formula: distance = (time_diff * speed of sound) / 2
        distance = (time_diff * SOUND_SPEED) / (2 * 1000000); // Convert microseconds to seconds and divide by 2 for round trip

        printf("Distance: %.2f cm\n", distance * 100); // Convert meters to centimeters for display

        delay(1000); // Delay 1 second before next measurement
    }

    return 0;
}
