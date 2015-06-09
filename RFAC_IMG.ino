/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Imagenes           *
********************************/

void bmpDraw(char* filename, int x, int y) {
  SdFile   bmpFile;
  int      bmpWidth, bmpHeight;
  uint8_t  bmpDepth;
  uint32_t bmpImageoffset;
  uint32_t rowSize;
  uint8_t  sdbuffer[3*BUFFPIXEL];
  uint16_t lcdbuffer[BUFFPIXEL];
  uint8_t  buffidx = sizeof(sdbuffer);
  boolean  goodBmp = false;
  boolean  flip    = true;
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();
  uint8_t  lcdidx = 0;
  boolean  first = true;

  if((x >= tft.width()) || (y >= tft.height())) return;
  if (!bmpFile.open(filename, O_READ)) {
    return;
  } else {
  }

  if(read16(bmpFile) == 0x4D42) { 
    uint32_t fileSize    = read32(bmpFile);
    uint32_t fileCreator = read32(bmpFile); 
    bmpImageoffset       = read32(bmpFile);
    uint32_t fileHeader  = read32(bmpFile);
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);

    if(read16(bmpFile) == 1) {
      bmpDepth = read16(bmpFile);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) {
        goodBmp = true;

        rowSize = (bmpWidth * 3 + 3) & ~3;
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        for (row=0; row<h; row++) {
          int Ypos = y+row;
          tft.setAddrWindow(x, Ypos, x+w-1, Ypos);
          first  = true;
          lcdidx = 0;
          buffidx = 0;
          
          if(flip)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.curPosition() != pos) {
            bmpFile.seekSet(pos);
            buffidx = sizeof(sdbuffer); 
          }

          for (col=0; col<w; col++) { 
            if (buffidx >= sizeof(sdbuffer)) { 
              if(lcdidx > 0) {
                tft.pushColors(lcdbuffer, lcdidx, first);
                lcdidx = 0;
                first  = false;
              }
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0;
            }

            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            lcdbuffer[lcdidx++] = tft.color565(r,g,b);
          }
          if(lcdidx > 0) {
            tft.pushColors(lcdbuffer, lcdidx, first);
          } 
        }
        if(lcdidx > 0) {
          tft.pushColors(lcdbuffer, lcdidx, first);
        } 
      } 
    }
  }
  //Serial.println(read16(bmpFile), HEX);
  bmpFile.close();
}

uint16_t read16(SdFile& f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read();
  ((uint8_t *)&result)[1] = f.read();
  return result;
}

uint32_t read32(SdFile& f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); 
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read();
  return result;
}

