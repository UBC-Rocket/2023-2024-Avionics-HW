const int en_pin = 9; //enable pin to the e-fuse ic
const int pg_pin = 10; // power good pin from the e-fuse ic
const int cell_1_pin = 1;
const int cell_2_pin = 2;
const int cell_3_pin = 3;

const int r1 = 10; // has a unit of kilo-ohm
const int r2 = 30;
const int r3 = 25;
const int r4 = 15;
const int r8 = 30;
const int r9 = 10; 

const float vcc_threshold = 3.0;

void setup() {
  pinMode(en_pin, OUTPUT);
  pinMode(pg_pin, INPUT);

  pinMode(cell_1_pin, INPUT);
  pinMode(cell_2_pin, INPUT);
  pinMode(cell_3_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  float vcc = analogRead(cell_3_pin);
  float cell_1_voltage = float (5 * cell_1_pin / 1024 * (r2 + r1) / r2);
  float cell_2_voltage = float ((5 * cell_2_pin / 1024 * (r4 + r3) / r4) - cell_1_voltage);
  float cell_3_voltage = float ((5 * cell_3_pin / 1024 * (r9 + r8) / r9) - cell_1_voltage - cell_2_voltage);

  if (cell_1_voltage <= vcc_threshold || cell_2_voltage <= vcc_threshold || cell_3_voltage <= vcc_threshold || !digitalRead(pg_pin)) 
    digitalWrite(en_pin, LOW);
  else
    digitalWrite(en_pin, HIGH);


  //Serial.print()
  delay(250);
}