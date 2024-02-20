const int sensor_pin = 0;
int pulse_signal = 0;
float BPM = 0;

void setup() {
  // put your setup code here, to run once:

  // initialize serial communications
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // collect pulse signal and display in serial monitor
  pulse_signal = analogRead(sensor_pin);
  Serial.println(pulse_signal);

}
