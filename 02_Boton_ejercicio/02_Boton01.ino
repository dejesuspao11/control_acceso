//ejericio en clase (:

const int inputPin = 7;
int input7 = 0;

void setup(){
	pinMode(inputPin, INPUT);
	Serial.begin(9600);

}

void loop() {
	input7 = digitalRead(inputPin);
	if(input7 == HIGH)
{
	Serial.println("1");
	}

	else {
	Serial.println("0");
	}
}