#include <stdio.h>
#include <time.h>
//#include <wiringPi.h>

int main(){

 
    int delayTime;
    
    for(int i = 0; i <= 3; i++){
        for(int distance = 1000; i >= 0; i--)
            if (distance > 200) {
                //digitalWrite(BUZZER_PIN, LOW); // Buzzer ausschalten, wenn die Distanz größer als 200 cm ist
                printf("NO BUZZ\n");
            } else if (distance > 800) {
                delayTime = 1000; // langsames Piepen, wenn die Distanz groß ist
            } else if (distance > 500) {
                delayTime = 500; // mittleres Piepen
            } else if (distance > 300) {
                delayTime = 250; // schnelleres Piepen
            } else {
                delayTime = 100; // sehr schnelles Piepen
            }

            //digitalWrite(BUZZER_PIN, HIGH);
            printf("BUZZ ON\n");
            sleep(delayTime);
            //digitalWrite(BUZZER_PIN, LOW);
            printf("BUZZ OF\n");
            sleep(delayTime);
        }


    return 0;
}