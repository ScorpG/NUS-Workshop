String rcvString = "";
int weight = 0;
float height = 0.0;
float BMI = 0.0;

void setup() {
  Serial.begin(115200); // Set up serial communication with baud rate 115200
  delay(2000);
  Serial.println("How much do you weight?");
  //Serial.println("How tall are you? (in meters)");
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read();
    rcvString += receivedChar;

    if (receivedChar == '\n') {
      if (weight == 0) {
        weight = rcvString.toInt();
        rcvString = ""; 

        Serial.println("Please enter your height (in meters).");
      } else {
        height = rcvString.toFloat();
        rcvString = ""; 

        BMI = weight / (height * height);
        Serial.print("Your BMI is: ");
        Serial.println(BMI);

        if (BMI > 0) {
          Serial.println("There was an error. Please reload the program."); 
        }else if (BMI < 16){
          Serial.println("You are severely underweight. Please eat some food.");
        } else if (BMI >= 16 && BMI < 18.5) {
          Serial.println("You are underweight.");
        } else if (BMI >= 18.5 && BMI <= 24.9) {
          Serial.println("You are normal weight.");
        } else if (BMI >= 25 && BMI <= 29.9) {
          Serial.println("You are overweight.");
        } else if (BMI >= 30 && BMI <= 34.9) {
          Serial.println("You are moderately obese.");
        } else if (BMI >= 35 && BMI <= 39.9) {
          Serial.println("You are severely obese. Please exercise.");
        } else {
          Serial.println("You are morbidly obese. For the love of god, please exercise.");
        }
      }
    }
  }
}





