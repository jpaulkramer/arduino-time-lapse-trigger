// Maurice Ribble
// 4-28-2008
// http://www.glacialwanderer.com/hobbyrobotics

// This code just tests my camera trigger.  It lets you
// focus the camera by pressing the 'f' key and take a
// picture by pressing the space bar.

#define FOCUS_PIN 6
#define SHUTTER_PIN 7
#define POWER_LED 13
#define ACTION_LED 12

void setup()
{
  pinMode(FOCUS_PIN, OUTPUT);
  pinMode(SHUTTER_PIN, OUTPUT);
  pinMode(POWER_LED, OUTPUT);
  pinMode(ACTION_LED, OUTPUT);
  digitalWrite(FOCUS_PIN, LOW);
  digitalWrite(SHUTTER_PIN, LOW);
  digitalWrite(POWER_LED, HIGH);
  Serial.begin(9600); // open serial
  Serial.println("Press 'f' to focus and 'spacebar' to trigger shutter");
}

void loop()
{
  int cmd;

  while (Serial.available() > 0)
  {
    cmd = Serial.read();

    switch (cmd)
    {
    case 'f':
      {
        digitalWrite(FOCUS_PIN, HIGH);
        digitalWrite(ACTION_LED, HIGH);
        delay(800); // May want to adjust this depending on focus time
        digitalWrite(ACTION_LED, LOW);
        digitalWrite(FOCUS_PIN, LOW);
        break;
      }
    case ' ':
      {
        digitalWrite(SHUTTER_PIN, HIGH);
        digitalWrite(ACTION_LED, HIGH);
        delay(1000); // May want to adjust this depending on shot type
        digitalWrite(SHUTTER_PIN, LOW);
        digitalWrite(ACTION_LED, LOW);
        break;
      }
    default:
      {
        Serial.println("Press 'f' to focus and 'spacebar' to trigger shutter");
      }
    }
  }
}
