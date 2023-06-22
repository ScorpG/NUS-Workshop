#define ONBOARD_LED 12    // LED GP12
#define ONBOARD_SW  7    // Switch GP7

int current_LED = LOW;
int current_buttonstate = HIGH;
int previous_buttonstate = HIGH;
int current_mode = 0;

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT_PULLUP);

   digitalWrite(ONBOARD_LED, current_LED);    // turn the LED off by making the voltage LOW   
}

void loop() {
   //current_LED = (current_LED == HIGH) ? LOW: HIGH;
   current_buttonstate = digitalRead(ONBOARD_SW);


   digitalWrite(ONBOARD_LED, current_LED);
   
   if ((current_buttonstate == LOW) && (previous_buttonstate == HIGH)) {  // Switch is asserted Low (Active Low)
   current_mode = (current_mode >= 3) ? 0 : current_mode + 1;
   Serial.println("Button Mode: ");
   Serial.println(current_mode);
   }
previous_buttonstate = current_buttonstate; 

if (current_mode == 0) {
current_LED = ((millis()/1000)% 2 == 0) ? LOW: HIGH;

} else if (current_mode == 1){

  current_LED = ((millis()/500)% 2 == 0) ? LOW: HIGH;

} else if (current_mode == 2){

 current_LED = ((millis()/100)% 2 == 0) ? LOW: HIGH;
  
} else {
current_LED = LOW; 

}
digitalWrite(ONBOARD_LED, current_LED);
}
