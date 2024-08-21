#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>




// freq = 0xFFFF
// b0 = freq / 0xFF + 0x80
// b0 = freq >> 8 + 0x80
// b1 = freq % 0xFF
// b1 = freq & 0x00FF

const uint16_t freq[9] = {73,73,87,110,73,73,87,110,880};


void audioProcessGlobal (uint8_t muteall, uint8_t left, uint8_t right)
    {
        
        if (muteall == 0)
            {
                NR52_REG = 0x80;
            }
        else
            {
                NR52_REG = 0x00;
            }
        if (left < 8 && right < 8)
            {
                NR50_REG = left << 4 + right;
            } 
        else
            {
                NR50_REG = 0x77;
            }
    }

void audioProcessChanns (uint8_t c1n, uint8_t c1b0, uint8_t c1b1, uint8_t c1b2, uint8_t c2n, uint8_t c2b1, uint8_t c2b2)
    {
                // -- step 0 --
                // toggle chann1 off L+R
                NR51_REG = 0b00000000;
                //NR51_REG = NR51_REG & 0b00000000;

                // -- step 1 --
                // load swp: byte 1
                NR10_REG = c1b0;
                // load dty: byte 2
                NR11_REG = c1b1;
                // load env: byte 3
                NR12_REG = c1b2;
                // load note: byte 4 + byte 5
                //NR13_REG = freq[note][0];
                NR13_REG = freq[c1n] & 0x00FF;

                //NR14_REG = freq[note][1];
                NR14_REG = freq[c1n] >> 7 | 0x80;


                // -- step 1 --
                // load swp: byte 1
                //NR20_REG = b0;
                // load dty: byte 2
                NR21_REG = c2b1;
                // load env: byte 3
                NR22_REG = c2b2;
                // load note: byte 4 + byte 5
                //NR13_REG = freq[note][0];
                NR23_REG = freq[c2n] & 0x00FF;
                //NR14_REG = freq[note][1];
                NR24_REG = freq[c2n] >> 7 | 0x80;
                
                
                // -- step 2 --
                // toggle chann1 on L+R
                //NR51_REG = NR51_REG | 0b00110000;

                //NR51_REG = NR51_REG & 0b11111111;
    }

void audioPlayallChanns (uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4)
    {
        //assing L+R to play sound
        NR51_REG = (ch1 & 0b00000011) << 6 | (ch2 & 0b00000011) << 4 | (ch3 & 0b00000011) << 2 | (ch4 & 0b00000011);
    }