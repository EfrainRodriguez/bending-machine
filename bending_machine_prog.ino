const int enablePin = 5;
const int turnRightPin = 6;
const int turnLeftPin = 7;
const int endstopPin = A0;

bool isGoingToLeft = false;

int count = 1;

void disableAll();
void goToRight(int msTime);
void goToLeft();

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(turnRightPin, OUTPUT);
  pinMode(turnLeftPin, OUTPUT);
  pinMode(endstopPin, INPUT_PULLUP);

  digitalWrite(enablePin, HIGH);
  digitalWrite(turnRightPin, HIGH);
  digitalWrite(turnLeftPin, HIGH);
}

void loop() {
  if(count <= 5){
    if (count == 1 || count == 5) {
      goToRight(1300);
    } else {
      goToRight(1100);
    }

    disableAll();

    delay(1000);

    goToLeft();

    isGoingToLeft = true;

    while(isGoingToLeft) {
      if (digitalRead(endstopPin) == HIGH) {
        disableAll();
        isGoingToLeft = false;
      }
      delay(5);
    }

    delay(1000);

    count++;
  }
}

void goToRight(int msTime) {
  digitalWrite(enablePin, LOW);
  digitalWrite(turnRightPin, LOW);
  delay(msTime);
}

void goToLeft() {
  digitalWrite(enablePin, LOW);
  digitalWrite(turnLeftPin, LOW);
}

void disableAll() {
  digitalWrite(enablePin, HIGH);
  digitalWrite(turnRightPin, HIGH);
  digitalWrite(turnLeftPin, HIGH);
}
