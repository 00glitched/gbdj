#include <stdint.h>
#include <stdio.h>

//#include "../res/include/scren.h"
  #include "../res/include/audio.h"
//#include "../res/include/input.h"

void soundCtrl (void)
    {
        // load values
        audioProcessChanns(0,0x00,0x81,0x43,2,0x81,0x43);
        
        // play sound
        audioPlayallChanns (0b11, 0b11, 0b11, 0b11);
    }
/*
void effctCtrl (void)
    {
        // effs of sounds
    }
*/