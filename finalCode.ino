#include <SPI.h>
#include <SD.h>

File myFile;

// set pins for motors
int leftMotorPin1 = 8;
int leftMotorPin2 = 9;
int leftMotorPin3 = 10;
int leftMotorPin4 = 11;

int rightMotorPin1 = 3;
int rightMotorPin2 = 5;
int rightMotorPin3 = 6;
int rightMotorPin4 = 7;

int myDelayTime = 10;

void setup() {
  
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
   
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  
  // set pins controlling motors to OUTPUT
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(leftMotorPin3, OUTPUT);
  pinMode(leftMotorPin4, OUTPUT);
  
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(rightMotorPin3, OUTPUT);
  pinMode(rightMotorPin4, OUTPUT);

}

void loop() {
  // open and read the record.txt file in sd card
  myFile = SD.open("record.txt");

  char data=myFile.read();
  myFile.close();
  
  // print received data to serial
  Serial.print("Incoming string: ");
  Serial.println(data);
  

  // move forwards if the command is forwards (f)
  if (data == 'f'){
    moveForwards();
    Serial.println("moveForwards");
  }
  
  // move backwards if the command is backwards (b)
  if (data == 'b'){
    moveBackwards();
    Serial.println("moveBackwards");
  }
  
  // turn left if the command is left (l)
  if (data == 'l'){
    moveLeft();
    Serial.println("moveLeft");
  }
  
  // turn right if the command is right (r)
  if (data == 'r'){
    moveRight();
    Serial.println("moveRight");
  }
  
  if (data == 's'){
    stopMoving();
    Serial.println("stopping");
  }
  
}

void moveForwards(){
  
    // move forward for 4 steps  
  
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, HIGH);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, HIGH);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
	
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, HIGH);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, HIGH);
    delay(myDelayTime);

}
  
  
void moveBackwards(){
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, HIGH);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, HIGH);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, HIGH);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, HIGH);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
}


void moveLeft() {
  
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, HIGH);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, HIGH);
    delay(myDelayTime);

}

void moveRight(){

  
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, HIGH);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
    
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, HIGH);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);

}

void stopMoving(){
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(leftMotorPin3, LOW);
    digitalWrite(leftMotorPin4, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(rightMotorPin3, LOW);
    digitalWrite(rightMotorPin4, LOW);
    delay(myDelayTime);
}
