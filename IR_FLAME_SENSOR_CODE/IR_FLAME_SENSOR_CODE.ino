// IR Flame Sensor Module
//pin definitions
int flame0= A0; 
int flame1= A1; 
int flame2= A2; 
int flame3= A3; 

void setup() {
  pinMode(flame0, INPUT); // Set flamePin as input
  pinMode(flame1, INPUT); 
  pinMode(flame2, INPUT); 
  pinMode(flame3, INPUT); 
  Serial.begin(9600); // Start the serial communication
}

void loop() {
  int flaVal0 = analogRead(flame0); // Read the flame sensor module value
  int flaVal1 = analogRead(flame1); 
  int flaVal2 = analogRead(flame2); 
  int flaVal3 = analogRead(flame3); 
  Serial.println(flaVal0);
  Serial.println(flaVal1);
  Serial.println(flaVal2);
  Serial.println(flaVal3);
  delay(200);
  
  
  int threshold = 35;
  if (flaVal0<threshold){ 
    Serial.println("Flame0!!");    
  }else{
    Serial.println("No Flame0");
  }
  if (flaVal1<threshold){ 
    Serial.println("Flame1!!");
  }else{
    Serial.println("No Flame1");
  }
  if (flaVal2<threshold){
    Serial.println("Flame2!!");
  }else{
    Serial.println("No Flame2");
  }
  if (flaVal3<threshold){
    Serial.println("Flame3!!");
  }else{
    Serial.println("No Flame3");
  }
}
