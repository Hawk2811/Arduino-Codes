#define pinled1 12
#define pinled2 11
String prompt;

void setup(){
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  Serial.begin(9600);
  Serial.print("ArduLuke EFI Firmware\n");
}

void loop(){
  if(Serial.available()){
    prompt = Serial.readStringUntil('\n');

    if(prompt.equals("led1ON")){
      Serial.println("EFI Execute: HardwareControl=led1=PowerON\n");
         led1ON();
    }
    else if(prompt.equals("led1OFF")){
      Serial.println("EFI Execute: HardwareControl=led1=PowerOFF\n");
         led1OFF();
    }
    else if(prompt.equals("led2ON")){
      Serial.println("EFI Execute: HardwareControl=led2=PowerON\n");
         led2ON(); 
    }
    else if(prompt.equals("led2OFF")){
      Serial.println("EFI Execute: HardwareControl=led2=PowerOFF\n");
         led2OFF();
    }
    else{
      Serial.println("EFI ERROR: command not found\n");
    }

  }
}

void led1ON(){
  digitalWrite(pinled1,HIGH);
}
void led1OFF(){
  digitalWrite(pinled1,LOW);
}

void led2ON(){
  digitalWrite(pinled2,HIGH);
}
void led2OFF(){
  digitalWrite(pinled2,LOW);
}
