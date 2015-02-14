int left = A0;
int right = A1;

// This routine runs only once upon reset
void setup()
{
  // Initialize left and right pins as output
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
}

int t = 0;

// This routine loops forever
void loop()
{
  analogWrite(left, t | t >> 4);
  analogWrite(right,t | t >> 4);
  t++;
}
