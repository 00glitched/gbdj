#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>


const uint8_t tableEff[0x8][0b1111]; 

// freq = 0xFFFF
// b0 = freq / 0xFF + 0x80
// b0 = freq >> 7 + 0x80
// b1 = freq % 0xFF
// b1 = freq & 0x00FF

const uint16_t freq[9] = {73,73,87,110,73,73,87,110,880};

uint8_t freqToByteA(uint8_t note)
    {
        uint8_t byteOut = freq[note] & 0x00FF;
        return byteOut;
    }
uint8_t freqToByteB(uint8_t note)
    {
        uint8_t byteOut = freq[note] >> 7 | 0x80;
        return byteOut;
    }

void audioProcessGlobal (uint8_t muteall, uint8_t left, uint8_t right)
    {
        
        if (muteall == 0)
            {
                NR52_REG = 0x80;
            }
        else if (muteall == 1)
            {
                NR52_REG = 0x00;
            }
        if (left < 8 && right < 8)
            {
                NR50_REG = left << 4 | right;
            } 
        else
            {
                NR50_REG = 0x77;
            }
    }


void audioProcessChanns (uint8_t *ctrlByte, uint8_t *c1reg, uint8_t *c2reg, uint8_t *c3reg, uint8_t *c4reg)
    {
        // BYTE 0:
        // A : 0, stop; 1, do-nothing;
        // B : 0, not-play; 1, play;
        // BYTE 1:
        // stereo
        uint8_t astate = *ctrlByte  & 0xF;
        uint8_t bstate = *ctrlByte >> 4;
        uint8_t stereo = *(ctrlByte+1);

        uint8_t varNR51 = NR51_REG;

        // -- step 0 --
        // stop process
        if (astate == 0b0000)
            {
                NR51_REG = astate;
            }
        if (astate & 0b1000 == 0)
            {
                NR12_REG = 0b00000000;
                varNR51 &= 0b00111111 & stereo;
            }
        if (astate & 0b0100 == 0)
            {
                NR22_REG = 0b00000000;
                varNR51 &= 0b11001111 & stereo;
            }
        if (astate & 0b0010 == 0)
            {
                NR32_REG = 0b00000000;
                varNR51 &= 0b11110011 & stereo;
            }
        if (astate & 0b0001 == 0)
            {
                NR42_REG = 0b00000000;
                varNR51 &= 0b11111100 & stereo;

            }

        // --step 2 --
        // write process
        if(bstate & 0b1000 != 0)
            {
                // if new regs are diff of actual regs
                if (*(c1reg  ) != NR10_REG) { NR10_REG = *(c1reg  ); }
                if (*(c1reg+1) != NR11_REG) { NR11_REG = *(c1reg+1); }
                if (*(c1reg+2) != NR12_REG) { NR12_REG = *(c1reg+2); }
                if (*(c1reg+3) != NR13_REG) { NR13_REG = *(c1reg+3); }
                if (*(c1reg+4) != NR14_REG) { NR14_REG = *(c1reg+4); }
            }
        if(bstate & 0b0100 != 0)
            {
                //if (*(c2reg  ) != NR20_REG) { NR20_REG = *(c2reg  ); }
                if (*(c2reg+1) != NR21_REG) { NR11_REG = *(c2reg+1); }
                if (*(c2reg+2) != NR22_REG) { NR12_REG = *(c2reg+2); }
                if (*(c2reg+3) != NR23_REG) { NR13_REG = *(c2reg+3); }
                if (*(c2reg+4) != NR24_REG) { NR14_REG = *(c2reg+4); }
            }
        if(bstate & 0b0010 != 0)
            {
                if (*(c3reg  ) != NR30_REG) { NR10_REG = *(c3reg  ); }
                if (*(c3reg+1) != NR31_REG) { NR11_REG = *(c3reg+1); }
                if (*(c3reg+2) != NR32_REG) { NR12_REG = *(c3reg+2); }
                if (*(c3reg+3) != NR33_REG) { NR13_REG = *(c3reg+3); }
                if (*(c3reg+4) != NR34_REG) { NR14_REG = *(c3reg+4); }
            }
        if(bstate & 0b0001 != 0)
            {
                //if (*(c4reg  ) != NR40_REG) { NR40_REG = *(c4reg  ); }
                if (*(c4reg+1) != NR41_REG) { NR11_REG = *(c4reg+1); }
                if (*(c4reg+2) != NR42_REG) { NR12_REG = *(c4reg+2); }
                if (*(c4reg+3) != NR43_REG) { NR13_REG = *(c4reg+3); }
                if (*(c4reg+4) != NR44_REG) { NR14_REG = *(c4reg+4); }
            }
        
        // -- step 3 --
        // play
        NR51_REG = varNR51;
    }

int8_t audioProcessEffect(uint8_t conf, uint8_t quant, uint8_t astep)
    {
        uint8_t type = conf >> 6;
        uint8_t  val = conf & 0b00111111;
        
        if (type == 0x0) // linear increase/decrease
            {
                uint8_t vc = (val >> 4) & 0b01;     // val conf: up-down
                uint8_t vv = val & 0x0F;            // val val: steps delay

                if (vv != 0 && astep % vv == 0)
                    {
                        int8_t signedq = (quant & 0b01111111) | (vc<<7);
                        return signedq;
                    }
                else
                    {
                        return 0;
                    }
            }
        if (type == 0x1) //tremolo
            {
                uint8_t vc = (val >> 4) & 0b01;
                uint8_t vv = val & 0x0F;

                if (vv != 0 && astep % vv > ( vv >> 1))
                    {
                        int8_t signedq = (quant & 0b01111111) | (vc<<7);
                        return signedq;
                    }
                else
                    {
                        return 0;
                    }
            }
        if (type == 0x2) // arp
            {
                uint8_t vc = (val >> 4) & 0b01;
                uint8_t vv = val & 0x0F;
                if (vv!=0)
                    {
                        if (astep % 3 == 0)
                            {
                                int8_t signedq = 0x0;
                                return signedq;
                            }
                        else if (astep % 3 == 1)
                            {
                                int8_t signedq = (quant & 0b00111000) >> 3 | (vc << 7);
                                return signedq;
                            }
                        else if (astep % 3 == 2)
                            {
                                int8_t signedq = (quant & 0b00000111) | (vc << 7);
                                return signedq;
                            }

                    }
                else
                    {
                        return 0;
                    }
            }
        if (type == 0x3) // table
            {
                uint8_t t = astep % 8;
                return tableEff[t][val];
            }
    }