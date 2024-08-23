#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>
#include <time.h>

#define CLOCKS_PER_SEC 60

//source
#include "../src/intrfCtrl.h"
#include "../src/soundCtrl.h"
#include "../src/init.h"

struct coord
    {
        uint8_t x;  //x pos
        uint8_t y;  //y pos
        uint8_t m;  //menu
        uint8_t n;  //submenu
    };


//time vars
uint32_t counter_bpm = 0;
uint8_t delay_bpm = 20;

uint32_t counter_eff = 0;
const uint8_t delay_eff = 4;

uint32_t counter_fps = 0;
const uint8_t delay_fps = 40;


void main(void)
    {
        initFunc();

        //struct coord pivot;
        
                        
        while(TRUE) //loop
            {
                uint32_t CLK = clock();

                if (counter_bpm < CLK)
                    {
                        soundCtrl();

                        counter_bpm += delay_bpm;
                    }
                if (counter_eff < CLK)
                    {

                        //effctCtrl();

                        counter_eff += delay_eff;
                    }
                if (counter_fps < CLK)
                    {   
                        intrfCtrl();
                        //pivot = inputCtrl(pivot.x,pivot.y,pivot.m,pivot.n);
                        
                        counter_fps += delay_fps;
                    }
            }
    }