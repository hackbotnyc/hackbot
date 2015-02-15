int left = A0;
int right = A1;

int led = D7;

TCPClient client;
char server[] = "https://stream.watsonplatform.net/text-to-speech-beta/api/v1/synthesize";

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

  Serial.begin(9600);
  delay(2000);
  Serial.println("connecting...");

  if (client.connect(server)) {
    Serial.println("connected");

    client.println("Authorization: Basic YjU1Y2VlYWYtZjc0ZS00YTJhLWFkMjYtZGUzMWI5MDA3ZGQwOlJiYk5SYWtZVDA2Qg==");
    client.println("GET /text-to-speech-beta/api/v1/synthesize?accept=audio%2Fwav&text=Testing HTTP/1.1");
    client.println("Host: stream.watsonplatform.net");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
}
