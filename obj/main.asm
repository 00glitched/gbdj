;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.1 #14650 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _printTest
	.globl _setBkg
	.globl _set_bkg_tile_xy
	.globl _set_bkg_data
	.globl _delay
	.globl _test_tileset
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:8: void setBkg (void) { set_bkg_data (0, 0u, test_tileset); }
;	---------------------------------
; Function setBkg
; ---------------------------------
_setBkg::
	ld	de, #_test_tileset
	push	de
	xor	a, a
	rrca
	push	af
	call	_set_bkg_data
	add	sp, #4
	ret
_test_tileset:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x70	; 112	'p'
	.db #0x70	; 112	'p'
	.db #0xfe	; 254
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x02	; 2
	.db #0x0f	; 15
	.db #0x01	; 1
	.db #0x0f	; 15
	.db #0x01	; 1
	.db #0x17	; 23
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x1f	; 31
	.db #0x00	; 0
	.db #0x1b	; 27
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x01	; 1
	.db #0x03	; 3
	.db #0x01	; 1
	.db #0x81	; 129
	.db #0x02	; 2
	.db #0x82	; 130
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x6f	; 111	'o'
	.db #0xff	; 255
	.db #0x6f	; 111	'o'
	.db #0xff	; 255
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0x3f	; 63
	.db #0x07	; 7
	.db #0x3f	; 63
	.db #0x0f	; 15
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x3f	; 63
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0xd0	; 208
	.db #0xfe	; 254
	.db #0xee	; 238
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0x13	; 19
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0xf0	; 240
	.db #0x80	; 128
	.db #0xd8	; 216
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x1b	; 27
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x1d	; 29
	.db #0x3f	; 63
	.db #0x1d	; 29
	.db #0x1f	; 31
	.db #0x11	; 17
	.db #0x53	; 83	'S'
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xbf	; 191
	.db #0xff	; 255
	.db #0xc8	; 200
	.db #0xfe	; 254
	.db #0xfc	; 252
	.db #0xfe	; 254
	.db #0xdc	; 220
	.db #0xfe	; 254
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xfc	; 252
	.db #0xe0	; 224
	.db #0xf4	; 244
	.db #0xe1	; 225
	.db #0xf7	; 247
	.db #0xef	; 239
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf9	; 249
	.db #0xf9	; 249
	.db #0xff	; 255
	.db #0xfd	; 253
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x02	; 2
	.db #0x7a	; 122	'z'
	.db #0x2e	; 46
	.db #0x7e	; 126
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0xeb	; 235
	.db #0xff	; 255
	.db #0xef	; 239
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xde	; 222
	.db #0x00	; 0
	.db #0xfc	; 252
	.db #0x0c	; 12
	.db #0x0c	; 12
	.db #0x04	; 4
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0xc4	; 196
	.db #0x00	; 0
	.db #0xfc	; 252
	.db #0x00	; 0
	.db #0xf7	; 247
	.db #0x00	; 0
	.db #0xc7	; 199
	.db #0x03	; 3
	.db #0x2f	; 47
	.db #0x2f	; 47
	.db #0x7f	; 127
	.db #0x9f	; 159
	.db #0x9f	; 159
	.db #0x99	; 153
	.db #0x9f	; 159
	.db #0x9f	; 159
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
;src/main.c:10: void printTest (uint8_t len_x, uint8_t len_y)
;	---------------------------------
; Function printTest
; ---------------------------------
_printTest::
	add	sp, #-5
	ldhl	sp,	#1
	ld	(hl-), a
	ld	(hl), e
;src/main.c:12: uint8_t k=0;
	ldhl	sp,	#4
;src/main.c:13: for (uint8_t j=0; j<len_y; j++)
	xor	a, a
	ld	(hl-), a
	dec	hl
	ld	(hl), #0x00
00107$:
	ldhl	sp,	#2
	ld	a, (hl-)
	dec	hl
	sub	a, (hl)
	jr	NC, 00109$
;src/main.c:15: for (uint8_t i=0; i<len_x; i++)
	ldhl	sp,	#4
	ld	a, (hl-)
	ld	(hl+), a
	ld	(hl), #0x00
00104$:
	ldhl	sp,	#4
	ld	a, (hl)
	ldhl	sp,	#1
	sub	a, (hl)
	jr	NC, 00115$
;src/main.c:17: set_bkg_tile_xy (i, j, k);k++;
	inc	hl
	inc	hl
	ld	a, (hl-)
	push	af
	inc	sp
	ld	a, (hl+)
	inc	hl
	ld	e, a
	ld	a, (hl)
	call	_set_bkg_tile_xy
	ldhl	sp,	#3
	inc	(hl)
;src/main.c:15: for (uint8_t i=0; i<len_x; i++)
	inc	hl
	inc	(hl)
	jr	00104$
00115$:
	ldhl	sp,	#3
	ld	a, (hl+)
;src/main.c:13: for (uint8_t j=0; j<len_y; j++)
	ld	(hl-), a
	dec	hl
	inc	(hl)
	jr	00107$
00109$:
;src/main.c:20: }
	add	sp, #5
	ret
;src/main.c:23: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:25: setBkg();
	call	_setBkg
;src/main.c:27: while(TRUE) //loop
00102$:
;src/main.c:29: printTest(4,4);
	ld	a,#0x04
	ld	e,a
	call	_printTest
;src/main.c:30: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;src/main.c:31: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
;src/main.c:32: delay(500);
	ld	de, #0x01f4
	call	_delay
;src/main.c:34: }
	jr	00102$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
