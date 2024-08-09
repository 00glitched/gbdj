#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>
#include "tileSet.h"
#include "/home/glitch00/Documentos/gbdk/examples/gb/bkgGraphLibForGBDK/include/bkgGraphLib.c"


const uint8_t SCREEN_LENX = 20;
const uint8_t SCREEN_LENY = 18;
const uint8_t TILE_BLANK = 96;
const uint16_t UPDATE_TIME = 500;

void setBkg (void) { set_bkg_data (0, 128u, MyTile); }

void main (void)
    {
        setBkg;
        uint8_t count = 0;

        while (TRUE)
            {
                if (count==0 || count==2)
                    {
                        bkgl_blankScreen(SCREEN_LENX,SCREEN_LENY,TILE_BLANK);
                    }
                else if (count==1)
                    {
                        uint8_t PX = 3;
                        uint8_t PY = 9;
                        uint8_t ARF = 31;
                        uint8_t TXT_LEN = 13;
                        uint8_t TXT[] = "Hello world!";
                        
                        
                        bkgl_printInLine(3,9,31,13,"Hello world!");
                    }
                else if (count==3)
                    {
                        uint8_t PX = 3;
                        uint8_t PY = 9;
                        uint8_t LX = 4;
                        uint8_t LY = 4;
                        uint8_t ARF = 31;
                        uint8_t TXT_LEN = 26;
                        uint8_t TXT[] = "Hello world! Hello world!";
                        

                        bkgl_printInMatrix(3,9,4,4,31,26,"Hello world! Hello world!");
                    }
                if (count==4)
                    {
                        count = 0;
                    }
                
                bkgl_updateBkg();
                count++;
                
                delay(UPDATE_TIME);
            }
    }