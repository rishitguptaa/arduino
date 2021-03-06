// Ambient RGB light
// Author: Rishit Gupta
//
// Controls RGB LEDs; smoothly transitions through color values.

// Delay time: sets the time in milliseconds between loop iterations.
// Make this value large for slower transitions.
#define DELAY_TIME 300

// Maximum Brightness: the maximum level the pins will reach.
#define MAX_BRIGHT 255

// The pins which each color value is output to.
#define PIN_RED 9
#define PIN_GREEN 10
#define PIN_BLUE 11

// The initial values of each color.
int red = 0;
int green = 170;
int blue = 170;

// Indicates whether a color is incrementing (1) or decrementing (0).
int incR = 1;
int incG = 1;
int incB = 0;

// Smoothly changes the color values
void transition()
{
  if (red >= MAX_BRIGHT)
    incR = 0;
  else if (red <= 0)
    incR = 1;
  if (green >= MAX_BRIGHT)
    incG = 0;
  else if (green <= 0)
    incG = 1;
  if (blue >= MAX_BRIGHT)
    incB = 0;
  else if (blue <= 0)
    incB = 1;

  if (incR)
    red++;
  else
    red--;
  if(incG)
    green++;
  else
    green--;
  if(incB)
    blue++;
  else
    blue--;
}

// Sets the output voltage on the LED pins.
void setColor()
{
  analogWrite(PIN_RED, red);
  analogWrite(PIN_GREEN, green);
  analogWrite(PIN_BLUE, blue);
}

void setup()
{
  // Do nothing.
}

void loop()
{
  transition();
  setColor();
  delay(DELAY_TIME);
}
