# SecKC LCD Name Badge

Handle             |  Custom Scrolling Text          | Upload your own Avatar     | SecKC Logos
:-------------------------:|:-------------------------:|:-------|:-----------------------:
<img src="https://i.ibb.co/zPGZ5xZ/IMG-3414.png" width="150" height="250">  |  <img src="https://i.ibb.co/Yp4c6DH/IMG-3415.png" width="150" height="250"> | <img src="https://i.ibb.co/f8Y6bCz/IMG-3413.png" width="150" height="250"> | <img src="https://i.ibb.co/sFLQRhd/IMG-3412.png" width="150" height="250">

This is Arduino code for the SecKC Speaker Name Badge.

Currently, the code was designed and tested on: Node MCU 1.0 (ESP-12E Module) and 1.44 inch TFT SPI 128x128 LCD Display.

Below is a list of items that should be upaded in order to make this badge your very own:
* Within the main Arduino file BadgeFinalTemplate.ino, update *String handle = "PutHandleHere";* within the **Handle()** function
* Within the bitmaps.h file, update *const uint16_t Avatar [] PROGMEM =* 
  
# Custom Avatar
Below are instructions on how to have your own custom avatar on the badge:

* Download your custom avatar image
* Open image in an image editor (mspaint for example) and resize the image to no larger than a 128x128 pixel size
* Save image as a 24-bit bmp file
* Use an LCD Image Converter such as (https://www.riuson.com/lcd-image-converter) to open the image
#### If using LCD Image Converter, the following can be done:
* Once image is open in LCD Image Converter, click "Options" then "Conversion"
* Change Preset to *Color R5G6B5*
* Under the *Prepare* tab, change the *Type* to **Color**
* Under the *Image* tab, change the *Block Size* to **16 bit**
* Once done, click *Show Preview* and copy the hex code
* Within the *bitmaps.h* file, find the  **const uint16_t Avatar [] PROGMEM = {}** section and replace the current code with the new code inside the *{}*. This creates an image matrix of your avatar

# Upload

Once display is hooked up to the board and the display has been successfully tested, open Arduino IDE and push the Arduino and bitmaps.h file to the board!

# Next steps

If there's any updates that want to be done, feel free to make this badge your own and customize it further! THis is just the first iteration of the SecKC Speaker Name Badge!

Also, you can check out my blog to see the hardware side of this project: https://blog.geoda-security.com/2019/01/seckc-speaker-badge-name-badge-hack.html

# Future Code Updates
* Would like to update BadgeFinalTemplate.ino with easier to edit functions, rather than all code within the loop
* Add more to the display, maybe animated gif images??
* Incorporate more SecKC logos and custom images made by our members
