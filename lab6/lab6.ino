// initial variables
const int sensor_pin = 0;
int pulse_signal = 0;
float BPM = 0;

// two flags & two variables to store time data
bool any_peak_detected = false;
bool first_peak_detected = false;
unsigned long first_pulse_time = 0;
unsigned long second_pulse_time = 0;

// thresholds for pulse waveform
int upper_threshold = 820;
int lower_threshold = 800;

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
