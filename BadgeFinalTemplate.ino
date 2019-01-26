#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "bitmaps.h"

#define MAGENTA 0xF81F

#ifdef ADAFRUIT_HALLOWING
  #define TFT_CS        D1 // 39 // Hallowing display control pins: chip select
  #define TFT_RST       D2 // 37 // Display reset
  #define TFT_DC        D3 // 38 // Display data/command select
  #define TFT_BACKLIGHT  7 // Display backlight pin
#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        D1
  #define TFT_RST        D2 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         D3
#endif

; // WHAT??!?!

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

String handle = "geoda"; // Update this for your handle to show up throughout badge
 
//////////////////////////////////////////////////////////
// Print Handle in middle'ish of screen                 //
//////////////////////////////////////////////////////////
void Handle(){
  //String handle = "geoda";  // Update this with handle
  //unsigned int handleLength = handle.length(); // Will be used later to center the handle name
  tft.setTextWrap(false); 
  tft.setCursor(35,72); // Adjust first value (x axis) to align handle in center
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_BLUE);
  tft.println(handle); 
}

// Print The SecKC 7 year glitch with Handle
void HandleGlitchFunc(){
  // Display Avatar Image
  // Update h and w for size of avatar
  int h = 72,w = 128, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      // If needed, add "+X" to col or row to center avatar if less than 128 in size
      tft.drawPixel(col, row, pgm_read_word(SecKCGlitch + buffidx));
      buffidx++;
    } // end pixel
  }
  //String handleGlitch = "geoda";  // Update this with handle
  //unsigned int handleLength = handleGlitch.length(); // Will be used later to center the handle name
  tft.setTextWrap(false); 
  tft.setCursor(6,85); // Adjust first value (x axis) to align handle in center
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_MAGENTA);
  tft.println(handle); 
}

// Print the HAKCER Skyline Image
void HAKCERSkyline(){
  // HAKCER Skyline
  // Update h and w for size of avatar
  tft.fillScreen(ST77XX_WHITE);
  int h = 128,w = 82, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      // If needed, add "+X" to col or row to center avatar if less than 128 in size
      tft.drawPixel(col+23, row, pgm_read_word(HAKCER + buffidx));
      buffidx++;
    } // end pixel
  }
}


// Print your Avatar Image
void AvatarImage(){
  // Display Avatar Image
  // Update h and w for size of avatar
  tft.fillRect(0,0,128,128,ST77XX_WHITE);
  int h = 128,w = 91, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      // If needed, add "+X" to col or row to center avatar if less than 128 in size
      tft.drawPixel(col+18, row, pgm_read_word(Avatar + buffidx));
      buffidx++;
    } // end pixel
  }
}

// Print Alice in a 128x128
void Alice128Func(){
  // HAKCER Skyline
  // Update h and w for size of avatar
  tft.fillScreen(ST77XX_WHITE);
  int h = 128,w = 112, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      // If needed, add "+X" to col or row to center avatar if less than 128 in size
      tft.drawPixel(col+8, row, pgm_read_word(Alice128 + buffidx));
      buffidx++;
    } // end pixel
  }
}

// Print Alice Wallpaper
void AliceWallpaperFunc(){
  // HAKCER Skyline
  // Update h and w for size of avatar
  tft.fillScreen(ST77XX_BLACK);
  int h = 128,w = 128, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      // If needed, add "+X" to col or row to center avatar if less than 128 in size
      tft.drawPixel(col, row+1, pgm_read_word(AliceWallpaper + buffidx));
      buffidx++;
    } // end pixel
  }
  String SecKC = "SecKC";  // Update this with handle
  //String Handle = "geoda";
  tft.setTextWrap(false); 
  tft.setCursor(35,10); // Adjust first value (x axis) to align handle in center
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.println(SecKC); 
  tft.setCursor(35,100); // Adjust first value (x axis) to align handle in center
  tft.println(handle);
}

void setup(void) {

#ifdef ADAFRUIT_HALLOWING
  // HalloWing is a special case.
  // It uses a ST7735R display just like the
  // breakout board, but the orientation and backlight control are different.
  tft.initR(INITR_HALLOWING);        // Initialize HalloWing-oriented screen
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on
#else
 // OR use this initializer (uncomment) if using a 1.44" TFT:
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
#endif

  tft.setRotation(2); // Flip screen 180 degrees
  tft.fillScreen(ST77XX_BLACK); // Clear Screen Black
    
}

//////////////////////////////////////////////////////////
// Begin Loop that will be displayed on the screen      //
//////////////////////////////////////////////////////////

void loop() {
  
  //////////////////////////////////////////////////////////
  // Define Scrolling Text                                //
  //////////////////////////////////////////////////////////
  String text1 = "              HAKCER  ";
  String text2 = "              Kansas City's Hacker Hive  ";
  String text3 = "              HACK THE PLANET   ";
  String text4 = "              5ecKC   "; 
  const int width = 15; // width of the marquee display (in characters)

  //////////////////////////////////////////////////////////
  // Print Handle, then Double font size and set to white //
  //////////////////////////////////////////////////////////
  Handle();
  tft.setTextWrap(false);
  tft.setTextSize(2); 
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK); // White on black

  //////////////////////////////////////////////////////////
  // Draw SecKC Logos on top corners                      //
  //////////////////////////////////////////////////////////
  tft.fillRect(0,0,128,64,ST77XX_WHITE); // FIll top half of screen White (to clear)
  tft.drawBitmap(0,0,SecKCwhiteBMP, 64,64,ST7735_BLACK); // Print SecKC logo top left
  tft.drawBitmap(64,0,SecKCblackBMP,64,64,ST7735_BLACK);  // Print SecKC logo top right

  //////////////////////////////////////////////////////////
  // Scrolling Text1                                      //
  //////////////////////////////////////////////////////////
  for (int offset = 0; offset < text1.length(); offset++)
  {
    //Construct the string to display for this iteration
    String t = "";
    for (int i = 0; i < width; i++)
    t += text1.charAt((offset +i) % text1.length());
    // print the string for this iteration
    tft.setCursor(0,104); 
    tft.print(t);
    delay(150); 
  }

  //////////////////////////////////////////////////////////
  // Flip Flop SecKC Logo on top corners                  //
  ////////////////////////////////////////////////////////// 
  tft.fillRect(0,0,128,64,ST77XX_WHITE); // Fill Top half of screen White (to clear)
  tft.drawBitmap(64,0,SecKCwhiteBMP, 64,64,ST7735_BLACK); // x,y,bitmap,xsize,ysize,color
  tft.drawBitmap(0,0,SecKCblackBMP,64,64,ST7735_BLACK);  // xy,y,bitmap,xsize,ysize,color

  //////////////////////////////////////////////////////////
  // Scrolling Text2                                      //
  //////////////////////////////////////////////////////////
  for (int offset = 0; offset < text2.length(); offset++)
  {
    //Construct the string to display for this iteration
    String t = "";
    for (int i = 0; i < width; i++)
    t += text2.charAt((offset +i) % text2.length());
    // print the string for this iteration
    tft.setCursor(0,104); 
    tft.print(t);
    delay(150); 
  }  

  //////////////////////////////////////////////////////////
  // clear screen and print large black/white seckc logo  //
  //////////////////////////////////////////////////////////
  // Full Screen SecKC - White
  tft.fillRect(0,0,128,128,ST77XX_WHITE); // Clear screen White
  //tft.drawBitmap(0,0,SecKCFullWhite,128,128,ST77XX_BLACK);  // Print 128x128 SecKC Image
  Alice128Func();
  delay(4000); // Keep image for 3 seconds
  // Full Screen SecKC - Black
  tft.fillRect(0,0,128,128,ST77XX_WHITE); // Clear screen White
  tft.drawBitmap(0,0,SecKCFullBlack,128,128,ST77XX_BLACK); // Print 128x128 SecKC Image
  delay(4000); // Keep images for 3 seconds

  //////////////////////////////////////////////////////////
  // Clear Screen, Add SecKC to top corners, print Handle //
  // and prepare for scrolling text                       //
  //////////////////////////////////////////////////////////
  tft.fillRect(0,0,128,128,ST77XX_BLACK); 
  tft.fillRect(0,0,128,64,ST77XX_WHITE); // Fill Top half of screen White (to clear)
  tft.drawBitmap(0,0,SecKCwhiteBMP, 64,64,ST7735_BLACK); // x,y,bitmap,xsize,ysize,color
  tft.drawBitmap(64,0,SecKCblackBMP,64,64,ST7735_BLACK);  // xy,y,bitmap,xsize,ysize,color
  Handle(); // Print Handle
  tft.setTextWrap(false); //
  tft.setTextSize(2); // Double size of Text
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK); // Change font to White
  

  //////////////////////////////////////////////////////////
  // Scrolling Text3                                      //
  //////////////////////////////////////////////////////////
  for (int offset = 0; offset < text3.length(); offset++)
  {
    //Construct the string to display for this iteration
    String t = "";
    for (int i = 0; i < width; i++)
    t += text3.charAt((offset +i) % text3.length());
    // print the string for this iteration
    tft.setCursor(0,104); 
    tft.print(t);
    delay(150); 
  }  
  
  //////////////////////////////////////////////////////////
  // Flip Flop Images and prepare for scrolling text      //
  //////////////////////////////////////////////////////////
    
  tft.fillRect(0,0,128,64,ST77XX_WHITE); // Fill Top half of screen White (to clear)
  tft.drawBitmap(64,0,SecKCwhiteBMP, 64,64,ST7735_BLACK); // x,y,bitmap,xsize,ysize,color
  tft.drawBitmap(0,0,SecKCblackBMP,64,64,ST7735_BLACK);  // xy,y,bitmap,xsize,ysize,color

  //////////////////////////////////////////////////////////
  //  Scrolling Text 4                                    //
  //////////////////////////////////////////////////////////
  for (int offset = 0; offset < text4.length(); offset++)
  {
    //Construct the string to display for this iteration
    String t = "";
    for (int i = 0; i < width; i++)
    t += text4.charAt((offset +i) % text4.length());
    // print the string for this iteration
    tft.setCursor(0,104); 
    tft.print(t);
    delay(150); 
  }  
  
  //////////////////////////////////////////////////////////
  // end scrolling text. clear screen and display avatar  //
  //////////////////////////////////////////////////////////

  // Clear Screen
  tft.fillRect(0,0,128,128,ST77XX_WHITE);
  

  //////////////////////////////////////////////////////////
  // end avatar. clear screen and prepare to start over   //
  // Clear Screen                                         //
  //////////////////////////////////////////////////////////
  
  tft.fillRect(0,0,128,128,ST77XX_BLACK); // Clear Screen Black
  Handle(); // Print hacker handle in Middle blue

  //////////////////////////////////////////////////////////
  // Begin multi image print                              //
  //////////////////////////////////////////////////////////

  
  tft.fillRect(0,0,128,128,ST77XX_BLACK);
  HandleGlitchFunc();
  delay(10000);
  tft.fillRect(0,0,128,128,ST77XX_BLACK);
  AvatarImage();
  delay(10000);
  tft.fillRect(0,0,128,128,ST77XX_BLACK);
  HAKCERSkyline();
  delay(10000);
  tft.fillRect(0,0,128,128,ST77XX_BLACK);
  AliceWallpaperFunc();
  delay(10000);
  tft.fillRect(0,0,128,128,ST77XX_BLACK);


}
