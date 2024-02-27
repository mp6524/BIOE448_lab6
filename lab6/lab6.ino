// initial variables
const int sensor_pin = 0;
int pulse_signal = 0;
float BPM = 0;

// two flags & two variables to store time data
bool any_peak_detected = false;
bool first_peak_detected = false;
unsigned long first_pulse_time = 0;
unsigned long second_pulse_time = 0;
float pulse_period = 0;

// thresholds for pulse waveform
int upper_threshold = 950;
int lower_threshold = 775;

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

  // peak detecion if statement
  delay(50);
  if (pulse_signal > upper_threshold && any_peak_detected == false) {
    any_peak_detected = true;
    // Do something about this peak

    if (first_peak_detected == false) {
      first_pulse_time = millis();
      first_peak_detected = true;
    } else {
      second_pulse_time = millis();
      first_peak_detected = false;
      pulse_period = second_pulse_time - first_pulse_time;
    }

  }
  // reset peak detection if drops below lower threshold
  if (pulse_signal < lower_threshold) {
    any_peak_detected = false;
  }

  float pulse = 60000/pulse_period;
  Serial.print(pulse);

}
