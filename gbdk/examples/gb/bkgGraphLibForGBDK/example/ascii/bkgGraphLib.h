#include <stdint.h>
#include <stdio.h>

// Screen functions
void bkgl_blankScreen (uint8_t len_x, uint8_t len_y, uint8_t blankTile);
void bkgl_updateBkg (void);


// Text functions
void bkgl_printTextInLine (uint8_t pos_x, uint8_t pos_y, uint8_t ref, uint8_t len, char *text);
void bkgl_printTextInMatrix (uint8_t pos_x, uint8_t pos_y, uint8_t len_i, uint8_t len_j, uint8_t ref, uint8_t len, char *text);

// Basic graph functions
void bkgl_makeLine (uint8_t pos_x, uint8_t pos_y, uint8_t dir, uint8_t quant, uint8_t tile);
void bkgl_makeMatrix (uint8_t pos_x, uint8_t pos_y, uint8_t quant_x, uint8_t quant_y, uint8_t tile);