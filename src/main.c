#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>
#include <time.h>

#define CLOCKS_PER_SEC 60


//media
//#include "../res/tileset/c/test.c"

//source
#include "../src/screen.h"
#include "../src/audio.h"




uint8_t MyMat[4][4]=
    {
        {1,0,0,0},
        {0,2,0,0},
        {0,0,3,0},
        {0,0,0,4}
    };

uint8_t MyMat1[4]= {1,0,0,0};
uint8_t MyMat2[4]= {2,2,2,5};

uint32_t counter_fps = 0;
const uint8_t delay_fps = 40;

uint32_t counter_bpm = 0;
uint8_t delay_bpm = 20;

uint32_t counter_eff = 0;
uint8_t delay_eff = 4;



uint8_t TEST[3] ={0x00,0x82,0x43};



void main(void)
    {
        NR52_REG = 0x80;
        NR50_REG = 0x77;
        NR51_REG = 0xFF;
        setBkg();
        setBlank(47);
        uint8_t t=0;
        uint8_t Xi=0;
                        
        while(TRUE) //loop
            {
                uint32_t CLK = clock();

                if (counter_fps < CLK)
                    {   
                        //printTile (7, 6, 4, 4, 47);
                        //printTile (Xi-1, 6, 4, 4, 47);
                        //printFunc (Xi, 6, 4, &MyMat1[0], &MyMat2[0]);
                        SHOW_BKG;
                        DISPLAY_ON;
                        
                        counter_fps+=delay_fps;
                    }
                if (counter_bpm < CLK)
                    {
                        audio_process(Xi,TEST[0],TEST[1],TEST[2],8,TEST[1],TEST[2]);
                        audio_play(0b11,0b11,0b00,0b00);
                        Xi++;
                        if (Xi>7){Xi=0;}

                        counter_bpm += delay_bpm;
                    }
                if (counter_eff < CLK)
                    {
                        audio_play(0b00,0b11,0b00,0b00);

                        counter_eff += delay_eff;
                    }
                //delay(375);
            }
    }