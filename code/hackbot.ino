int left = A0;
int right = A1;

int led = D7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
}

bool l = false;
int t = 0;

void loop() {
  digitalWrite(led, l ? HIGH : LOW);
  l = !l;

  analogWrite(left, t | t >> 4);
  analogWrite(right, t | t >> 4);
  t++;
}
