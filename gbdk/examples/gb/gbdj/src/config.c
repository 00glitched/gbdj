#include <stdint.h>
#include <stdio.h>

// screen tile limits
const uint8_t SCREEN_LENX = 19;
const uint8_t SCREEN_LENY = 17;

// updates
const uint8_t FPS_DELAY_MS = 10;
const uint8_t TIC_DELAY_MS = 10;

// menus
const uint8_t MENU_NUM = 6;
const uint8_t DARK_ZERO = 128;

const uint16_t SOUND_FREQ[64];

//global vars
uint8_t pointer_MENU = 0;
uint8_t pointer_X = 0;
uint8_t pointer_Y = 0;

