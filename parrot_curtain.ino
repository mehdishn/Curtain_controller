int Pin1 = 10, Pin2 = 7;
int LED_signal = 5;

void take_action(char command)
{
  if (command == 'U')
  {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
  }
  else if (command == 'D')
  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, HIGH);
  }
  else if(command == 'S')
  {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
  }
  else if(command == 'A')
  {
    digitalWrite(LED_signal, HIGH);
  }
  else if(command == 'B')
  {
    digitalWrite(LED_signal, LOW);
  }
}

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);

  pinMode(LED_signal, OUTPUT);

  // default state for the motor
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, HIGH);
  
  digitalWrite(LED_signal, HIGH);
}

void loop()
{
  // print the string when a newline arrives:
  if(Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    take_action(inChar);
    Serial.println("gotIt");
  }
}

