int h = 12;
int m;
int s;
int flag;
int TIME;
const int hs = 8;
const int ms = 9;
int state1;
int state2;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  clock();
}

int clock(){
  s = s + 1;
  Serial.print("TIME:");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.print(s);

  if (flag < 12)Serial.print("AM");
  if (flag == 12)Serial.print("PM");
  if (flag > 12)Serial.print("PM");
  if (flag == 24)flag = 0;

  delay(1000);

  if (s == 60) {
    s = 0;
    m = m + 1;
  }
  if (m == 60) {
    m = 0;
    h = h + 1;
    flag = flag + 1;
  }
  if (h == 13)h = 1;

  Serial.println(" ");
  Serial.write(12);

  state1 = digitalRead(hs);

  if (state1 == 1) {
    h = h + 1;
    flag = flag + 1;
    if (flag < 12)Serial.print("AM");
    if (flag == 12)Serial.print("PM");
    if (flag > 12)Serial.print("PM");
    if (flag == 24)flag = 0;
    if (h == 13)h = 1;
  }

  state2 = digitalRead(ms);

  if (state2 == 1) {
    s = 0;
    m = m + 1;
  }
}
