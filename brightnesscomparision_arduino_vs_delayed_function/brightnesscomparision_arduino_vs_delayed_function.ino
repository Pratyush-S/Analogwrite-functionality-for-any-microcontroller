void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
int T=10000;
int t=10;
analogWrite(3,2);
while(1){  
digitalWrite(2,HIGH);
delayMicroseconds(t);
digitalWrite(2,LOW);  
delayMicroseconds(T-t);
}
}
