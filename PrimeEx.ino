/* 
 *  Ex_12 - Loops
 *  Meet the FlintStones
 *  
 */

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   delay(2000);

   Serial.print("When you're with the Flintstones. Have");
   for (int count = 0; count < 5; count ++) {
      Serial.print(" A yabba dabba doo time");
   }
   Serial.println(".");

   String flintStoneS[4] = {"Fred", "Wilma", "Pebbles", "Dino"};
   for (int flntStoneCnt = 0; flntStoneCnt <= 3; flntStoneCnt ++) {
      Serial.println("I am a Flintstone. My name is " + flintStoneS[flntStoneCnt]);
   }

}

void loop() { // <- Loop() is a forever while loop in disguise.
   

   int count = 0;
   int number = 2;

   while (count < 30) {
      bool isPrime = true;

      for (int i = 2; i <= sqrt(number); i++) {
         if (number % i == 0) {
            isPrime = false;
            break;
         }
      }

      if (isPrime) {
         Serial.print(number);
         Serial.print(" ");
         count++;
      }

      number++;
   }


   while (true) {
      
  }

   
}
