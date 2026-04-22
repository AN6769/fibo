// Fibonacci Clock
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License Version 2
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// You will find the latest version of this code at the following address:
// https://github.com/pchretien/fibo
//
// This project contains code and libraries provided by Adafruit Industries and can be found on their Github account at:
// https://github.com/adafruit
//
// Credits:
// See the credit.txt file for the list of all the backers of the Kickstarter campaign.
// https://www.kickstarter.com/projects/basbrun/fibonacci-clock-an-open-source-clock-for-nerds-wit/description
//

#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_NeoPixel.h>

#define STRIP_PIN 8
#define HOUR_PIN 3
#define MINUTE_PIN 4
#define BTN_PIN 5
#define SET_PIN 6
#define DEBOUNCE_DELAY 10
#define MAX_BUTTONS_INPUT 20
#define MAX_MODES 3
#define MAX_PALETTES 10
#define TOTAL_PALETTES 10
#define CLOCK_PIXELS 5

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, STRIP_PIN, NEO_RGB + NEO_KHZ800);

byte bits[CLOCK_PIXELS];

uint32_t black = strip.Color(0,0,0);
uint32_t colors[TOTAL_PALETTES][4] =           fixTime.year(), 
          fixTime.month(), 
          fixTime.day(), 
          fixTime.hour(), 
          ((fixTime.minute()-fixTime.minute()%5)+5)%60, 
          0);
          
    rtc.adjust( newTime );
          
    displayCurrentTime();
  }
    return val;
  }
  
  currentButtonValue[pin] = lastButtonValue[pin];
  return lastButtonValue[pin];
}

boolean hasChanged(int pin)
{
  return lastButtonValue[pin] != currentButtonValue[pin];
}

void resetButtonValues()
{
  for(int i=0; i<MAX_BUTTONS_INPUT; i++)
    lastButtonValue[i] = currentButtonValue[i];
}

void displayCurrentTime()
{
  DateTime now = rtc.now();  
  setTime(now.hour()%12, now.minute()); 
}

void setTime(byte hours, byte minutes)
{
  if(oldHours == hours && oldMinutes/5 == minutes/5)
    return;
    
  oldHours = hours;
  oldMinutes = minutes;
  
  for(int i=0; i<CLOCK_PIXELS; i++)
    bits[i] = 0;
    
  setBits(hours, 0x01);
  setBits(minutes/5, 0x02);

  for(int i=0; i<CLOCK_PIXELS; i++)
  {   
    setPixel(i, colors[palette][bits[i]]);
    strip.show();
  }
}

void displayErrorCode()
{
  if(oldError == error)
    return;
    
  oldError = error;
  
  for(int i=0; i<CLOCK_PIXELS; i++)
    bits[i] = 0;
  
  if(error == 0)
  {
    setBits(12, 0x02);
  }
  else
  {
    setBits(error, 0x01);
  }

  for(int i=0; i<CLOCK_PIXELS; i++)
  {   
    setPixel(i, colors[palette][bits[i]]);
  }
  
  strip.show();
}

void setBits(byte value, byte offset)
{
  switch(value)
  {
    case 1:
      switch(random(2))
      {
        case 0:
          bits[0]|=offset;
          break;
        case 1:
          bits[1]|=offset;
          break;
      }
      break;
    case 2:
      switch(random(2))
      {
        case 0:
          bits[2]|=offset;
          break;
        case 1:
          bits[0]|=offset;
          bits[1]|=offset;
          break;
      }
      break;
    case 3:
      switch(random(3))
      {
        case 0:
          bits[3]|=offset;
          break;
        case 1:
          bits[0]|=offset;
          bits[2]|=offset;
          break;
        case 2:
          bits[1]|=offset;
          bits[2]|=offset;
          break;
      }
      break;
    case 4:
      switch(random(3))
      {
        case 0:
          bits[0]|=offset;
          bits[3]|=offset;
          break;
        case 1:
          bits[1]|=offset;
          bits[3]|=offset;
          break;
        case 2:
          bits[0]|=offset;
          bits[1]|=offset;
          bits[2]|=offset;
          break;
      }
      break;
    case 5:
      switch(random(3))
      {
        case 0:
          bits[4]|=offset;
          break;
        case 1:
          bits[2]|=offset;
          bits[3]|=offset;
          break;
        case 2:
          bits[0]|=offset;
          bits[1]|=offset;
          bits[3]|=offset;
          break;
      }
      break;
    case 6:
      switch(random(4))
      {
        case 0:
          bits[0]|=offset;
          bits[4]|=offset;
          break;
        case 1:
          bits[1]|=offset;
          bits[4]|=offset;
          break;
        case 2:
          bits[0]|=offset;
          bits[2]|=offset;
          bits[3]|=offset;
          break;
        case 3:
          bits[1]|=offset;
          bits[2]|=offset;
          bits[3]|=offset;
          break;
      }
      break;
    case 7:
      switch(random(3))
      {
        case 0:
          bits[2]|=offset;
          bits[4]|=offset;
          break;
        case 1:
          bits[0]|=offset;
          bits[1]|=offset;
          bits[4]|=offset;
          break;
        case 2:
          bits[0]|=offset;
          bits[1]|=offset;
          bits[2]|=offset;
          bits[3]|=offset;
          break;
      }
      break;
    case 8:
      switch(random(3))
      {
        case 0:
          bits[3]|=offset;
          bits[4]|=offset;
          break;
        case 1:
          bits[0]|=offset;
          bits[2]|=offset;
          bits[4]|=offset;
          break;
        case 2:
          bits[1]|=offset;
          bits[2]|=offset;
          bits[4]|=offset;
          break;
      }      
      break;
    case 9:
      switch(random(2))
      {
        case 0:
          bits[0]|=offset;
          bits[3]|=offset;
          bits[4]|=offset;
          break;
        case 1:
          bits[1]|=offset;
          bits[3]|=offset;
          bits[4]|=offset;
          break;
      }      
      break;
    case 10:
      switch(random(2))
      {
        case 0:
          bits[2]|=offset;
          bits[3]|=offset;
          bits[4]|=offset;
          break;
        case 1:
          bits[0]|=offset;
          bits[1]|=offset;
          bits[3]|=offset;
          bits[4]|=offset;
          break;
      }            
      break;
    case 11:
      switch(random(2))
      {
        case 0:
          bits[0]|=offset;
          bits[2]|=offset;
          bits[3]|=offset;
          bits[4]|=offset;      
          break;
        case 1:
          bits[1]|=offset;
          bits[2]|=offset;
          bits[3]|=offset;
          bits[4]|=offset; 
          break;
      }          

      break;
    case 12:
      bits[0]|=offset;
      bits[1]|=offset;
      bits[2]|=offset;
      bits[3]|=offset;
      bits[4]|=offset;        
      
      break;
  }
}

void setPixel(byte pixel, uint32_t color)
{
  if(!on)
    return;
  
  switch(pixel)
  {
    case 0:
      strip.setPixelColor(0, color);
      break;
    case 1:
      strip.setPixelColor(1, color);
      break;
    case 2:
      strip.setPixelColor(2, color);
      break;
    case 3:
      strip.setPixelColor(3, color);
      strip.setPixelColor(4, color);
      break;
    case 4:
      strip.setPixelColor(5, color);
      strip.setPixelColor(6, color);
      strip.setPixelColor(7, color);
      strip.setPixelColor(8, color);
      strip.setPixelColor(9, color);
      break;
  };
}

void rainbow(uint8_t wait) 
{
  uint16_t i, j;

  for(j=0; j<256; j++) 
  {
    for(i=0; i< CLOCK_PIXELS; i++) 
    {
      setPixel(i, Wheel((i+j) & 255));
    }
    
    strip.show();
    delay(wait);
    
    if(debounce(BTN_PIN) && hasChanged(BTN_PIN))
    {
      mode = (mode + 1)%MAX_MODES;
      resetButtonValues();
      return;
    }
    
    if(debounce(MINUTE_PIN) && hasChanged(MINUTE_PIN))
    {
      toggleOnOff();
      resetButtonValues();
      return;
    }
    
    resetButtonValues();
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) 
{
  uint16_t i, j;

  for(j=0; j<256*5; j++) 
  { 
    // 5 cycles of all colors on wheel
    for(i=0; i< CLOCK_PIXELS; i++) 
    {
      setPixel(i, Wheel(((i * 256 / CLOCK_PIXELS) + j) & 255));
    }
    strip.show();
    delay(wait);
    
    if(debounce(BTN_PIN) && hasChanged(BTN_PIN))
    {
      mode = (mode + 1)%MAX_MODES;
      resetButtonValues();
      return;
    }
    
    if(debounce(MINUTE_PIN) && hasChanged(MINUTE_PIN))
    {
      toggleOnOff();
      resetButtonValues();
      return;
    }
    
    resetButtonValues();
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) 
{
  if(WheelPos < 85) 
  {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) 
  {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else 
  {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void toggleOnOff()
{
  if( on )
  {
    for( int i=0; i<CLOCK_PIXELS; i++)
      setPixel(i, black);
      
    strip.show();
  }
  
  on = !on;
  
  if(on)
  {
    oldHours = 99;
    oldError = 99;
  }
}

void checkErrors()
{
  error = 0;
  oldError = 99;
  mode = 3;
  palette = 0;
  
  // Test sequence
  if (! rtc.isrunning())
  {
    error |= 0x1;
  }
  
  int time1 = rtc.now().unixtime();
  delay(1200);
  int time2 = rtc.now().unixtime();
  if(time1 == time2)
  {
    error |= 0x02;
  }  
}

void printDateTime(DateTime now)
{
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  
  Serial.print(" since midnight 1/1/1970 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");
  
  // calculate a date which is 7 days and 30 seconds into the future
  DateTime future (now.unixtime() + 7 * 86400L + 30);
  
  Serial.print(" now + 7d + 30s: ");
  Serial.print(future.year(), DEC);
  Serial.print('/');
  Serial.print(future.month(), DEC);
  Serial.print('/');
  Serial.print(future.day(), DEC);
  Serial.print(' ');
  Serial.print(future.hour(), DEC);
  Serial.print(':');
  Serial.print(future.minute(), DEC);
  Serial.print(':');
  Serial.print(future.second(), DEC);
  Serial.println();
  
  Serial.println();
  
  delay(1000);
}


