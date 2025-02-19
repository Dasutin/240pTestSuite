/* 
 * 240p Test Suite
 * Copyright (C)2011-2014 Artemio Urbina
 *
 * This file is part of the 240p Test Suite
 *
 * The 240p Test Suite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The 240p Test Suite is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 240p Test Suite; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef RES_H
#define RES_H

#include "res/resources.h"

extern u32 color_tiles[224/4]; ; 

extern u32 cb601_tiles[224/4]; 
extern u16 cb601_pal[16/2];
extern u16 cb601_map[2400/2]; 

// Title screen
extern u32 back_tiles[3200/4]; 
extern u16 back_pal[16/2]; 
extern u16 back_map[2240/2]; 

extern u32 gillian_tiles[2912/4]; 
extern u16 gillian_pal[16/2]; 

// blink
extern u32 gillian_b1_tiles[96/4]; 
extern u32 gillian_b2_tiles[96/4]; 

// QR code
extern u32 barcode_tiles[512/4]; 

// Font
extern u32 font_tiles[3072/4];

// Checkerboard
extern u32 check_tile[32/4]; 
extern u32 check_tile_inv[32/4]; 

extern u32 checkbleed_tile[32/4]; 

// Stripes
extern u32 bw_tile[32/4]; 
extern u32 wb_tile[32/4]; 
extern u32 vstripes_tiles[32/4]; 
extern u32 vstripesneg_tiles[32/4]; 

extern u16 bw_pal[16/2]; 

// Grid
extern u32 small_grid_tiles[32/4]; 

extern u32 grid_tiles[64/4]; 
extern u16 grid_pal[16/2]; 

extern u16 grid_map[2240/2];
extern u16 grid_256_map[1792/2];
extern u16 grid_PAL_map[2400/2];
extern u16 grid_PAL_256_map[1920/2];

extern u32 monoscope_tiles[1728/4]; 
extern u16 monoscope_map[1792/2];

extern u32 monoscope320_tiles[2752/4]; 
extern u16 monoscope320_map[2240/2];

extern u32 monoscopePAL_tiles[2304/4]; 
extern u16 monoscopePAL_map[2400/2];

// Sonic background
extern u32 sonicfloor_tiles[2592/4]; 
extern u16 sonicfloor_map[1024/2];
extern u32 sonicback_tiles[6432/4]; 
extern u16 sonicback_map[1216/2];
extern u16 sonicback_pal[16/2]; 
extern u32 sonicwater_tiles[704/4];
extern u16 sonicwater_map[384/2]; 
extern u16 sonicwater_pal[16/2]; 
extern u16 sonicwater2_pal[16/2]; 
extern u16 sonicwater3_pal[16/2]; 

// Waterfall sprite
extern u32 waterfall_tiles[512/4]; 

// Donna background
extern u32 donna_tiles[18272/4]; 
extern u16 donna_map[2240/2];
extern u16 donna_pal[16/2]; 

//Striped Sprite
extern u32 striped_tiles[512/4]; 

// Shadow Sprite
extern u32 shadow_tiles[512/4]; 
extern u16 wb_pal[16/2]; 

// buzz Sprite
extern u32 buzz_tiles[512/4]; 
extern u32 buzzShadow_tiles[512/4]; 
extern u16 buzz_pal[16/2]; 

// Lag sprite
extern u32 lag_tiles[512/4]; 

// Solid Color (White)
extern u32 solid_tiles[32/4]; 

//LED Zone Tiles
extern u32 size0led_t[32/4]; 
extern u32 size1led_t[32/4]; 
extern u32 size2led_t[32/4]; 
extern u32 size3led_t[32/4]; 
extern u32 size4led_t[32/4]; 

// Big Number tiles
extern u32 tiles_0[480/4]; 
extern u32 tiles_1[480/4]; 
extern u32 tiles_2[480/4]; 
extern u32 tiles_3[480/4]; 
extern u32 tiles_4[480/4]; 
extern u32 tiles_5[480/4]; 
extern u32 tiles_6[480/4]; 
extern u32 tiles_7[480/4]; 
extern u32 tiles_8[480/4]; 
extern u32 tiles_9[480/4]; 
extern u32 tiles_c[480/4]; 

extern u32 vbars_tiles[32/4]; 

extern u32 circle56_tiles[1568/4];

extern u16 btw_pal[16/2]; 
extern u16 redw_pal[16/2]; 
extern u16 bluew_pal[16/2]; 
extern u16 greenw_pal[16/2]; 

extern u32 solidw_tiles[32/4]; 

// n
extern u32 n_tiles[3040/4]; 
extern u16 n_pal[16/2]; 
extern u16 n_map[200/2]; 

// SMPTE
extern u32 SMPTECB75_tiles[1440/4]; 
extern u16 SMPTECB75_pal[16/2]; 
extern u16 SMPTECB100_pal[16/2]; 
extern u16 SMPTECB75_map[2240/2]; 

// EBU
extern u32 EBUColorBars75_tiles[256/4];  
extern u16 EBUColorBars75_map[2240/2]; 

// Sharpness
extern u32 sharpness_tiles[3136/4]; 
extern u16 sharpness_pal[16/2]; 
extern u16 sharpness_map[2240/2]; 

extern u32 bricks_tiles[32/4]; 
extern u16 bricks_pal[16/2]; 

// vertical Scroll
extern u32 kiki_tiles[768/4]; 
extern u16 kiki_pal[16/2]; 
extern u16 kiki_map[4096/2]; 

// FireShark
extern u32 FireShark_tiles[512/4]; 
extern u16 FireShark_pal[16/2]; 
extern u16 FireSharkBL_pal[16/2]; 
extern u16 FireSharkWH_pal[16/2]; 

// Float
extern u32 float_tiles[192/4];
extern u16 float_map[320/2];

// Convergence
extern u32 convdot_tiles[32/4]; 
extern u32 convgrid_tiles[32/4]; 
extern u32 convcross_tiles[32/4]; 

extern u32 convcolor_tiles[512/4]; 
extern u16 convcolor_pal[16/2]; 
extern u16 convcolor_map[2240/2]; 

extern u16 convcolor_lines_pal[16/2]; 


#endif
