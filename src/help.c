/* 
 * 240p Test Suite for the Neo Geo
 * by Artemio Urbina and Dustin Dembrosky (Dasutin)
 * Copyright (C)2011-2022 Artemio Urbina
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

#include <stdlib.h>
#include <stdio.h>
#include <DATlib.h>
#include <input.h>
#include "ng.h"
#include "externs.h"
#include "help.h"
#include "string_ng.h"
#include "tools.h"

int checkHelp(int helpID)
{
	if (BTTN_HELP)
	{
		DrawHelp(helpID);
		return 1;
	}

	return 0;
}

void DrawHelp(int option)
{
	int exit = 0, page = 1, totalpages = 1, dirty = 0, redraw = 1, index = 0;

	switch (option)
	{
		case HELP_GENERAL:
		case HELP_STRIPES:
		case HELP_SHADOW:
		case HELP_LED:
		case HELP_LAG:
		case HELP_MANUALLAG:
		case HELP_HSCROLL:
		case HELP_MEMVIEW:
		case HELP_WHITE:
		totalpages = 2;
		break;

		case HELP_PLUGE:
		case HELP_MONOSCOPE:
		totalpages = 3;
		break;
	}

	while (!exit)
	{
		if (redraw)
		{
			gfxClear();
			index = draw_background();
			redraw = 0;
		}

		SCClose();
		waitVBlank();

		switch (option)
		{
			case HELP_GENERAL:
				switch (page)
				{
					case 1:
						fixPrint(15, 6, fontColorGreen, 3, "HELP (1/2)");

						fixPrint(4, 8, fontColorWhite, 3, "The 240p Test Suite was designed");
						fixPrint(4, 9, fontColorWhite, 3, "with two goals in mind:");

						fixPrint(4, 11, fontColorWhite, 3, "1) Evaluate 240p signals on TV");
						fixPrint(4, 12, fontColorWhite, 3, "sets and video processors; and");

						fixPrint(4, 14, fontColorWhite, 3, "2) Provide calibration patterns");
						fixPrint(4, 15, fontColorWhite, 3, "from a game console to help in");
						fixPrint(4, 16, fontColorWhite, 3, "properly calibrating the display");
						fixPrint(4, 17, fontColorWhite, 3, "black, white, and color levels.");
						fixPrint(4, 19, fontColorGreen, 3, "Help can be shown with 'START'");
						fixPrint(4, 20, fontColorGreen, 3, "in any test.");

						fixPrint(26, 22, fontColorWhite, 3, "(cont...)");

						fixPrint(5, 26, fontColorWhite, 3, "Press START or B to exit help");

					break;

					case 2:
					{
						picture qr;

						pictureInit(&qr, &barcode, index, 17, 240, 144, FLIP_NONE);
						palJobPut(17,barcode.palInfo->count,barcode.palInfo->data);
						dirty = 1;

						fixPrint(15, 6, fontColorGreen, 3, "HELP (2/2)");

						fixPrint(4, 8, fontColorWhite, 3, "The Neo Geo can output 224");
						fixPrint(4, 9, fontColorWhite, 3, "active video lines. In PAL");
						fixPrint(4, 10, fontColorWhite, 3, "consoles, it can display either");
						fixPrint(4, 11,  fontColorWhite, 3, "224 or 240 lines.");

						fixPrint(4, 13, fontColorWhite, 3, "The 240p suite is also available");
						fixPrint(4, 14, fontColorWhite, 3, "on NES/FC, SNES/SFC, GameCube,");
						fixPrint(4, 15, fontColorWhite, 3, "Wii, GBA, Dreamcast,");
						fixPrint(4, 16, fontColorWhite, 3, "Genesis/Mega Drive, Sega 32X");
						fixPrint(4, 17, fontColorWhite, 3, "Sega/Mega CD, SMS, and");
						fixPrint(4, 18, fontColorWhite, 3, "PCE/TG-16/PCE-Duo/SCD/SCD2");

						fixPrint(4, 20, fontColorWhite, 3, "Visit:");
						fixPrint(4, 21, fontColorGreen, 3, "http://junkerhq.net/240p");
						fixPrint(4, 22, fontColorWhite, 3, "for more information");

						fixPrint(5, 26, fontColorWhite, 3, "Press START or B to exit help");
					}
					break;
				}
			break;

			case HELP_PLUGE:
				switch (page)
				{
					case 1:
						fixPrint(15, 6, fontColorGreen, 3, "PLUGE (1/3)");

						fixPrint(4, 9, fontColorWhite, 3, "NTSC levels require black to be");
						fixPrint(4, 10, fontColorWhite, 3, "at 7.5 IRE for video. This HW");
						fixPrint(4, 11, fontColorWhite, 3, "lowest is 6 IRE (6%), so using");
						fixPrint(4, 12, fontColorWhite, 3, "this value for general 240p use");
						fixPrint(4, 13, fontColorWhite, 3, "is not recommended.");

						fixPrint(4, 15, fontColorWhite, 3, "Of course using it as reference");
						fixPrint(4, 16, fontColorWhite, 3, "will work perfectly for games");
						fixPrint(4, 17, fontColorWhite, 3, "in this platform.");

						fixPrint(4, 19, fontColorWhite, 3, "In PAL - and console gaming in");
						fixPrint(4, 20, fontColorWhite, 3, "general - it is adviced to use");
						fixPrint(4, 21, fontColorWhite, 3, "a value of 2 IRE as black.");

						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(15, 6, fontColorGreen, 3, "PLUGE (2/3)");

						fixPrint(4, 9, fontColorWhite, 3, "The PLUGE pattern is used to");
						fixPrint(4, 10, fontColorWhite, 3, "help adjust the black level to");
						fixPrint(4, 11, fontColorWhite, 3, "a correct value.");

						fixPrint(4, 13, fontColorWhite, 3, "The inner bars on the sides are");
						fixPrint(4, 14, fontColorWhite, 3, "black at 6%, the outer at 12%.");
						fixPrint(4, 15, fontColorWhite, 3, "If these bars are not visible,");
						fixPrint(4, 16, fontColorWhite, 3, "adjust the \"brightness\" control");
						fixPrint(4, 17, fontColorWhite, 3, "until they are.");

						fixPrint(4, 19, fontColorWhite, 3, "You should lower it until they");
						fixPrint(4, 20, fontColorWhite, 3, "are not visible, and raise it");
						fixPrint(4, 21, fontColorWhite, 3, "until they show.");

						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 3:
						fixPrint(15, 6, fontColorGreen, 3, "PLUGE (3/3)");

						fixPrint(4, 9, fontColorWhite, 3, "Within it A button changes");
						fixPrint(4, 10, fontColorWhite, 3, "palettes between the original,");
						fixPrint(4, 11, fontColorWhite, 3, "highest and lowest values the");
						fixPrint(4, 12, fontColorWhite, 3, "hardware can display.");
					break;
				}
			break;

			case HELP_COLORS:
				fixPrint(15, 6, fontColorGreen, 3, "COLORBARS");

				fixPrint(4, 9, fontColorWhite, 3, "This pattern allows you to");
				fixPrint(4, 10, fontColorWhite, 3, "calibrate each color: Red, Green");
				fixPrint(4, 11, fontColorWhite, 3, "and Blue; as well as white.");

				fixPrint(4, 13, fontColorWhite, 3, "Adjust the white level first,");
				fixPrint(4, 14, fontColorWhite, 3, "using the \"Contrast\" control");
				fixPrint(4, 15, fontColorWhite, 3, "on your TV set. Raise it until");
				fixPrint(4, 16, fontColorWhite, 3, "you cannot distinguish between");
				fixPrint(4, 17, fontColorWhite, 3, "the blocks under \"E\" and \"F\",");
				fixPrint(4, 18, fontColorWhite, 3, "and lower it slowly until you");
				fixPrint(4, 19, fontColorWhite, 3, "can clearly tell them appart.");

				fixPrint(4, 21, fontColorWhite, 3, "Do the same for each color.");
			break;

			case HELP_GRID:
				fixPrint(18, 6, fontColorGreen, 3, "GRID");

				fixPrint(4, 9, fontColorWhite, 3, "This grid uses the full 320x224");
				fixPrint(4, 10, fontColorWhite, 3, "resolution.");

				fixPrint(4, 12, fontColorWhite, 3, "You can use it to verify that");
				fixPrint(4, 13, fontColorWhite, 3, "all the visible area is being");
				fixPrint(4, 14, fontColorWhite, 3, "displayed, and that there is no");
				fixPrint(4, 15, fontColorWhite, 3, "distortion present.");

				fixPrint(4, 17, fontColorWhite, 3, "The full active video signal can");
				fixPrint(4, 18, fontColorWhite, 3, "be filled with gray by pressing");
				fixPrint(4, 19, fontColorWhite, 3, "the 'A' button.");
			break;

			case HELP_MONOSCOPE:
				switch (page)
				{
					case 1:
						fixPrint(13, 6, fontColorGreen, 3, "MONOSCOPE (1/3)");

						fixPrint(4, 9, fontColorWhite, 3, "This pattern contains elements");
						fixPrint(4, 10, fontColorWhite, 3, "to calibrate multiple aspects");
						fixPrint(4, 11, fontColorWhite, 3, "of a CRT.");

						fixPrint(4, 13, fontColorWhite, 3, "Read your monitor's service");
						fixPrint(4, 14, fontColorWhite, 3, "manual to learn how, and use");
						fixPrint(4, 15, fontColorWhite, 3, "'A' button to change IRE.");

						fixPrint(4, 17, fontColorWhite, 3, "Brightness adjustment: Adjust");
						fixPrint(4, 18, fontColorWhite, 3, "convergence at low brightness");
						fixPrint(4, 19, fontColorWhite, 3, "(13/25 IRE). An overly bright");
						fixPrint(4, 20, fontColorWhite, 3, "pattern can mask convergence.");
						fixPrint(4, 21, fontColorWhite, 3, "issues.");

						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(13, 6, fontColorGreen, 3, "MONOSCOPE (2/3)");

						fixPrint(4, 9, fontColorWhite, 3, "Convergence: Use the center");
						fixPrint(4, 10, fontColorWhite, 3, "crosshair to check static");
						fixPrint(4, 11, fontColorWhite, 3, "(center of screen) convergence.");
						fixPrint(4, 12, fontColorWhite, 3, "Use the patterns at the sides");
						fixPrint(4, 13, fontColorWhite, 3, "to check dynamic (edge)");
						fixPrint(4, 14, fontColorWhite, 3, "convergence.");

						fixPrint(4, 16, fontColorWhite, 3, "Corners: After setting center");
						fixPrint(4, 17, fontColorWhite, 3, "and edge convergence, use");
						fixPrint(4, 18, fontColorWhite, 3, "magnets to adjust corner purity");
						fixPrint(4, 19, fontColorWhite, 3, "and geometry.");

						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 3:
						fixPrint(13, 6, fontColorGreen, 3, "MONOSCOPE (3/3)");

						fixPrint(4, 9, fontColorWhite, 3, "Size and aspect ratio: If");
						fixPrint(4, 10, fontColorWhite, 3, "vertical and horizontal size are");
						fixPrint(4, 11, fontColorWhite, 3, "correct, the red squares in the");
						fixPrint(4, 12, fontColorWhite, 3, "pattern will be perfect squares.");
						fixPrint(4, 13, fontColorWhite, 3, "After setting H size, use a tape");
						fixPrint(4, 14, fontColorWhite, 3, "measure to adjust V size to");
						fixPrint(4, 15, fontColorWhite, 3, "match it.");

						fixPrint(4, 17, fontColorWhite, 3, "Linearity: The squares in each");
						fixPrint(4, 18, fontColorWhite, 3, "corner should get you started.");
						fixPrint(4, 19, fontColorWhite, 3, "Confirm your adjustment using");
						fixPrint(4, 20, fontColorWhite, 3, "the scroll tests.");

						fixPrint(4, 21, fontColorWhite, 3, "Designed by Keith Raney.");
					break;
				}
			break;

			case HELP_BLEED:
				fixPrint(14, 6, fontColorGreen, 3, "COLOR BLEED");

				fixPrint(4, 9, fontColorWhite, 3, "This pattern helps diagnose");
				fixPrint(4, 10, fontColorWhite, 3, "color bleed caused by");
				fixPrint(4, 11, fontColorWhite, 3, "unneeded color upsampling.");

				fixPrint(4, 13, fontColorWhite, 3, "You can toggle between");
				fixPrint(4, 14, fontColorWhite, 3, "vertical bars and");
				fixPrint(4, 15, fontColorWhite, 3, "checkerboard with 'A'.");
			break;

			case HELP_IRE:
				fixPrint(16, 6, fontColorGreen, 3, "100 IRE");

				fixPrint(4, 9, fontColorWhite, 3, "You can vary IRE intensity");
				fixPrint(4, 10, fontColorWhite, 3, "with 'A' and 'B'. Values are:");
				fixPrint(4, 11, fontColorWhite, 3, "13, 25, 41, 53, 66, 82, 94");
			break;

			case HELP_601CB:
				fixPrint(14, 6, fontColorGreen, 3, "EBU COLORBARS");

				fixPrint(4, 9, fontColorWhite, 3, "You can use color filters or the");
				fixPrint(4, 10, fontColorWhite, 3, "blue only option in your display");
				fixPrint(4, 11, fontColorWhite, 3, "to confirm color balance.");
			break;

			case HELP_SHARPNESS:
				fixPrint(15, 6, fontColorGreen, 3, "SHARPNESS");

				fixPrint(4, 9, fontColorWhite, 3, "You should set the sharpness of");
				fixPrint(4, 10, fontColorWhite, 3, "your CRT to a value that shows");
				fixPrint(4, 11, fontColorWhite, 3, "clean black and gray transitions");
				fixPrint(4, 12, fontColorWhite, 3, "with no white ghosting between.");

				fixPrint(4, 13, fontColorWhite, 3, "Pressing 'A' toggles a diagonal");
				fixPrint(4, 14, fontColorWhite, 3, "brick tileset.");
			break;

			case HELP_OVERSCAN:
				fixPrint(15, 6, fontColorGreen, 3, "OVERSCAN");

				fixPrint(4, 9, fontColorWhite, 3, "With this pattern you can");
				fixPrint(4, 10, fontColorWhite, 3, "interactively find out the");
				fixPrint(4, 11, fontColorWhite, 3, "overscan in pixels of each edge");
				fixPrint(4, 12, fontColorWhite, 3, "in a display.");

				fixPrint(4, 14, fontColorWhite, 3, "Use left and right to change");
				fixPrint(4, 15, fontColorWhite, 3, "the overscan until you see the");
				fixPrint(4, 16, fontColorWhite, 3, "white border, then go back one");
				fixPrint(4, 17, fontColorWhite, 3, "pixel. The resulting number is");
				fixPrint(4, 18, fontColorWhite, 3, "the overscan in each direction.");

				fixPrint(4, 20, fontColorWhite, 3, "C toggles fast/per pixel change");
				fixPrint(4, 21, fontColorWhite, 3, "and A resets to defaults.");
			break;

			case HELP_SMPTE:
				fixPrint(12, 6, fontColorGreen, 3, "SMPTE COLOR BARS");

				fixPrint(4, 9, fontColorWhite, 3, "This pattern can be used to");
				fixPrint(4, 10, fontColorWhite, 3, "approximate for NTSC levels");
				fixPrint(4, 11, fontColorWhite, 3, "regarding contrast,");
				fixPrint(4, 12, fontColorWhite, 3, "brightness and colors.");

				fixPrint(4, 14, fontColorWhite, 3, "You can toggle between 75% and");
				fixPrint(4, 15, fontColorWhite, 3, "100% SMPTE color bars with A.");
				fixPrint(4, 16, fontColorWhite, 3, "Of course the percentages are");
				fixPrint(4, 17, fontColorWhite, 3, "relative to the console output.");

				fixPrint(4, 19, fontColorWhite, 3, "You can use color filters or the");
				fixPrint(4, 20, fontColorWhite, 3, "blue only option in your display");
				fixPrint(4, 21, fontColorWhite, 3, "to confirm color balance");
			break;

			case HELP_GRAY:
				fixPrint(15, 6, fontColorGreen, 3, "GRAY RAMP");

				fixPrint(4, 9, fontColorWhite, 3, "This gray ramp pattern can be");
				fixPrint(4, 10, fontColorWhite, 3, "used to check color balance.");

				fixPrint(4, 12, fontColorWhite, 3, "You should make sure the bars");
				fixPrint(4, 13, fontColorWhite, 3, "are gray, with no color bias.");
			break;

			case HELP_WHITE:
				switch (page)
				{
					case 1:
						fixPrint(11, 6, fontColorGreen, 3, "WHITE SCREEN (1/2)");

						fixPrint(4, 9, fontColorWhite, 3, "This pattern can be changed");
						fixPrint(4, 10, fontColorWhite, 3, "between white, black, red,");
						fixPrint(4, 11, fontColorWhite, 3, "green and blue screens with the");
						fixPrint(4, 12, fontColorWhite, 3, "'A' and 'B' buttons.");

						fixPrint(4, 14, fontColorWhite, 3, "Some displays and scalers have");
						fixPrint(4, 15, fontColorWhite, 3, "issues when changing between a");
						fixPrint(4, 16, fontColorWhite, 3, "black 0 IRE and a white screen.");

						fixPrint(4, 18, fontColorWhite, 3, "A custom color mode is");
						fixPrint(4, 19, fontColorWhite, 3, "available by pressing 'C'");
						fixPrint(4, 20, fontColorWhite, 3, "while in the white screen.");
						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(11, 6, fontColorGreen, 3, "WHITE SCREEN (2/2)");

						fixPrint(4, 9, fontColorWhite, 3, "While in edit mode, left and");
						fixPrint(4, 10, fontColorWhite, 3, "right change between colors,");
						fixPrint(4, 11, fontColorWhite, 3, "and up & down change values.");

						fixPrint(4, 14, fontColorWhite, 3, "'A' and 'B' buttons go to");
						fixPrint(4, 15, fontColorWhite, 3, "zero and 31, while 'D' toggles");
						fixPrint(4, 16, fontColorWhite, 3, "the dark bit.");
					break;
				}
			break;

			case HELP_CONVERGENCE:
				fixPrint(12, 6, fontColorGreen, 3, "CONVERGENCE TESTS");

				fixPrint(4, 9, fontColorWhite, 3, "These are used to adjust color");
				fixPrint(4, 10, fontColorWhite, 3, "convergence in CRT displays");

				fixPrint(4, 12, fontColorWhite, 3, "The 'A' button changes the cross");
				fixPrint(4, 13, fontColorWhite, 3, "hatch pattern between lines,");
				fixPrint(4, 14, fontColorWhite, 3, "dots and crosses");

				fixPrint(4, 16, fontColorWhite, 3, "The 'B' button changes to a");
				fixPrint(4, 17, fontColorWhite, 3, "color pattern for transition");
				fixPrint(4, 18, fontColorWhite, 3, "boundary check.");
			break;

			case HELP_CHECK:
				fixPrint(14, 6, fontColorGreen, 3, "CHECKERBOARD");

				fixPrint(4, 9, fontColorWhite, 3, "This pattern shows all the");
				fixPrint(4, 10, fontColorWhite, 3, "visible pixels in an");
				fixPrint(4, 11, fontColorWhite, 3, "alternating white and black");
				fixPrint(4, 12, fontColorWhite, 3, "grid array.");

				fixPrint(4, 14, fontColorWhite, 3, "You can toggle the pattern with");
				fixPrint(4, 15, fontColorWhite, 3, "button 'Up', or turn on");
				fixPrint(4, 16, fontColorWhite, 3, "auto-toggle each frame with the");
				fixPrint(4, 17, fontColorWhite, 3, "'A' button. A frame counter is");
				fixPrint(4, 18, fontColorWhite, 3, "also available with 'B'.");
			break;

			case HELP_STRIPES:
				switch (page)
				{
					case 1:
						fixPrint(10, 6, fontColorGreen, 3, "HOR/VER STRIPES (1/2)");

						fixPrint(4, 9, fontColorWhite, 3, "You should see a pattern of");
						fixPrint(4, 10, fontColorWhite, 3, "lines, each one pixel in height");
						fixPrint(4, 11, fontColorWhite, 3, "starting with a white one.");

						fixPrint(4, 13, fontColorWhite, 3, "You can toggle the pattern with");
						fixPrint(4, 14, fontColorWhite, 3, "button 'UP', or turn on");
						fixPrint(4, 15, fontColorWhite, 3, "auto-toggle each frame with the");
						fixPrint(4, 16, fontColorWhite, 3, "'A' button. A frame counter is");
						fixPrint(4, 17, fontColorWhite, 3, "also available with 'B'.");

						fixPrint(4, 18, fontColorWhite, 3, "When auto-toggle is set, you");
						fixPrint(4, 19, fontColorWhite, 3, "should see the lines");
						fixPrint(4, 20, fontColorWhite, 3, "alternating rapidly.");
						fixPrint(26, 22, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(10, 6, fontColorGreen, 3, "HOR/VER STRIPES (2/2)");

						fixPrint(4, 9, fontColorWhite, 3, "You can also display vertical");
						fixPrint(4, 10, fontColorWhite, 3, "bars by pressing 'LEFT'. That");
						fixPrint(4, 11, fontColorWhite, 3, "pattern will help you");
						fixPrint(4, 12, fontColorWhite, 3, "evaluate if the signal is not");
						fixPrint(4, 13, fontColorWhite, 3, "distorted horizontaly, since");
						fixPrint(4, 14, fontColorWhite, 3, "all lines should be one pixel");
						fixPrint(4, 15, fontColorWhite, 3, "wide.");
					break;
				}
			break;

			case HELP_SHADOW:
				fixPrint(12, 6, fontColorGreen, 3, "DROP SHADOW TEST");

				fixPrint(4, 9, fontColorWhite, 3, "This is a crucial test for 240p");
				fixPrint(4, 10, fontColorWhite, 3, "It displays a simple sprite");
				fixPrint(4, 11, fontColorWhite, 3, "shadow against a background,");
				fixPrint(4, 12, fontColorWhite, 3, "but the shadow is shown only");
				fixPrint(4, 13, fontColorWhite, 3, "on each other frame. Achieving");
				fixPrint(4, 14, fontColorWhite, 3, "a transparency effect.");

				fixPrint(4, 16, fontColorWhite, 3, "The user can toggle the frame");
				fixPrint(4, 17, fontColorWhite, 3, "used to draw the shadow with");
				fixPrint(4, 18, fontColorWhite, 3, "button 'A'. Backgrounds can be");
				fixPrint(4, 19, fontColorWhite, 3, "switched with the 'B' button,");
				fixPrint(4, 20, fontColorWhite, 3, "and button 'C' toggles sprites.");
			break;

			case HELP_STRIPED:
				fixPrint(11, 6, fontColorGreen, 3, "STRIPED SPRITE TEST");

				fixPrint(4, 9, fontColorWhite, 3, "There are deinterlacers out");
				fixPrint(4, 10, fontColorWhite, 3, "there that can display the drop");
				fixPrint(4, 11, fontColorWhite, 3, "shadows correctly and still");
				fixPrint(4, 12, fontColorWhite, 3, "interpret 240p as 480i. With a");
				fixPrint(4, 13, fontColorWhite, 3, "striped sprite it should be easy");
				fixPrint(4, 14, fontColorWhite, 3, "to tell if a processor tries to");
				fixPrint(4, 15, fontColorWhite, 3, "deinterlace (plus interpolate).");

				fixPrint(4, 17, fontColorWhite, 3, "You can change backgrounds with");
				fixPrint(4, 18, fontColorWhite, 3, "'A'.");
			break;

			case HELP_MANUALLAG:
				switch (page)
				{
					case 1:
						fixPrint(10, 6, fontColorGreen, 3, "TIMING & REFLEX (1/2)");

						fixPrint(4, 8, fontColorWhite, 3, "The main intention is to show a");
						fixPrint(4, 9, fontColorWhite, 3, "changing pattern on the screen,");
						fixPrint(4, 10, fontColorWhite, 3, "which can be complemented with");
						fixPrint(4, 11, fontColorWhite, 3, "audio. This should show to some");
						fixPrint(4, 12, fontColorWhite, 3, "degree any lag when processing");
						fixPrint(4, 13, fontColorWhite, 3, "the signal.");

						fixPrint(4, 15, fontColorWhite, 3, "As an added feature, the user");
						fixPrint(4, 16, fontColorWhite, 3, "can click the 'A' button when");
						fixPrint(4, 17, fontColorWhite, 3, "the sprite is aligned with the");
						fixPrint(4, 18, fontColorWhite, 3, "one on the background, and the");
						fixPrint(4, 19, fontColorWhite, 3, "offset in frames from the actual");
						fixPrint(4, 20, fontColorWhite, 3, "intersection will be shown on");
						fixPrint(4, 21, fontColorWhite, 3, "screen. A 1khz tone will be");
						fixPrint(4, 22, fontColorWhite, 3, "played for 1 frame when pressed.");
						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(10, 6, fontColorGreen, 3, "TIMING & REFLEX (2/2)");

						fixPrint(4, 8, fontColorWhite, 3, "Button 'B' can be used to");
						fixPrint(4, 9, fontColorWhite, 3, "change the direction of the");
						fixPrint(4, 10, fontColorWhite, 3, "sprite.");

						fixPrint(4, 12, fontColorWhite, 3, "Of course the evaluation is");
						fixPrint(4, 13, fontColorWhite, 3, "dependent on reflexes and/or");
						fixPrint(4, 14, fontColorWhite, 3, "rhythm more than anything. The");
						fixPrint(4, 15, fontColorWhite, 3, "visual and audio cues are the");
						fixPrint(4, 16, fontColorWhite, 3, "more revealing aspects which");
						fixPrint(4, 17, fontColorWhite, 3, "the user should consider, of");
						fixPrint(4, 18, fontColorWhite, 3, "course the interactive factor");
						fixPrint(4, 19, fontColorWhite, 3, "can give an experienced player");
						fixPrint(4, 20, fontColorWhite, 3, "the hang of the system when");
						fixPrint(4, 21, fontColorWhite, 3, "testing via different");
						fixPrint(4, 22, fontColorWhite, 3, "connections.");
					break;
				}
			break;

			case HELP_HSCROLL:
				switch (page)
				{
					case 1:
						fixPrint(11, 6, fontColorGreen, 3, "SCROLL TEST (1/2)");

						fixPrint(4, 9, fontColorWhite, 3, "This test shows either an");
						fixPrint(4, 10, fontColorWhite, 3, "horizontal 320x224 back from");
						fixPrint(4, 11, fontColorWhite, 3, "Sonic or a vertical 256x224");
						fixPrint(4, 12, fontColorWhite, 3, "back from Kiki Kaikai.");

						fixPrint(4, 14, fontColorWhite, 3, "Speed can be varied with Up &");
						fixPrint(4, 15, fontColorWhite, 3, "Down and scroll direction with");
						fixPrint(4, 16, fontColorWhite, 3, "'C'. The 'A' button stops the");
						fixPrint(4, 17, fontColorWhite, 3, "scroll and 'B' toggles between");
						fixPrint(4, 18, fontColorWhite, 3, "vertical and horizontal.");

						fixPrint(4, 20, fontColorWhite, 3, "You can use Left & Right while");
						fixPrint(4, 21, fontColorWhite, 3, "using the vertical test to move");
						fixPrint(4, 22, fontColorWhite, 3, "the scroll to each edge.");
						fixPrint(26, 24, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(11, 6, fontColorGreen, 3, "SCROLL TEST (2/2)");

						fixPrint(4, 9, fontColorWhite, 3, "This can be used to notice any");
						fixPrint(4, 10, fontColorWhite, 3, "drops in framerate, or pixel");
						fixPrint(4, 11, fontColorWhite, 3, "width inconsistencies.");

						fixPrint(4, 13, fontColorWhite, 3, "Sonic is a trademark of Sega");
						fixPrint(4, 14, fontColorWhite, 3, "Enterprises Ltd. Kiki Kaikai");
						fixPrint(4, 15, fontColorWhite, 3, "is a trademark of Taito.");
					break;
				}
			break;

				case HELP_VSCROLL:
					fixPrint(10, 6, fontColorGreen, 3, "GRID SCROLL TEST");

					fixPrint(4, 9, fontColorWhite, 3, "A grid is scrolled vertically or");
					fixPrint(4, 10, fontColorWhite, 3, "horizontally, which can be used");
					fixPrint(4, 11, fontColorWhite, 3, "to test linearity of the signal");
					fixPrint(4, 12, fontColorWhite, 3, "and how well the display or");
					fixPrint(4, 13, fontColorWhite, 3, "video processor copes with");
					fixPrint(4, 14, fontColorWhite, 3, "scrolling and framerate.");

					fixPrint(4, 16, fontColorWhite, 3, "Button 'B' can be used to toggle");
					fixPrint(4, 17, fontColorWhite, 3, "between horizontal and vertical,");
					fixPrint(4, 18, fontColorWhite, 3, "while Up/Down regulate speed.");

					fixPrint(4, 20, fontColorWhite, 3, "Button 'A' stops the scroll and");
					fixPrint(4, 21, fontColorWhite, 3, "'Left' changes direction.");
				break;

				case HELP_SOUND:
					fixPrint(12, 6, fontColorGreen, 3, "SOUND TEST");

					fixPrint(4, 9, fontColorWhite, 3, "You can test the sound from the");
					fixPrint(4, 10, fontColorWhite, 3, "4X 2-channel PWM and");
					fixPrint(4, 11, fontColorWhite, 3, "Genesis/Mega Drive PSG here.");

					fixPrint(4, 13, fontColorWhite, 3, "Panning can be changed when");
					fixPrint(4, 14, fontColorWhite, 3, "possible. This can help you");
					fixPrint(4, 15, fontColorWhite, 3, "identify stereo cabling issues.");

					fixPrint(4, 17, fontColorWhite, 3, "PSG has 200hz, 2khz and 4khz");
					fixPrint(4, 18, fontColorWhite, 3, "tones on its channels and white");
					fixPrint(4, 19, fontColorWhite, 3, "noise at 500hz.");
				break;

			case HELP_LED:
				switch (page)
				{
					case 1:
						fixPrint(14, 6, fontColorGreen, 3, "BACKLIT TEST");

						fixPrint(4, 9, fontColorWhite, 3, "This test allows you to check");
						fixPrint(4, 10, fontColorWhite, 3, "how the display's backlit works");
						fixPrint(4, 11, fontColorWhite, 3, "when only a small array of");
						fixPrint(4, 12, fontColorWhite, 3, "pixels is shown.");

						fixPrint(4, 14, fontColorWhite, 3, "The user can move around the");
						fixPrint(4, 15, fontColorWhite, 3, "white pixel arrays with the");
						fixPrint(4, 16, fontColorWhite, 3, "d-pad, and change the size of");
						fixPrint(4, 17, fontColorWhite, 3, "the pixel array with 'A'.");
						fixPrint(4, 18, fontColorWhite, 3, "The 'B' button allows the user");
						fixPrint(4, 19, fontColorWhite, 3, "to hide the pixel array in");
						fixPrint(4, 20, fontColorWhite, 3, "order to alternate a fully black");
						fixPrint(4, 21, fontColorWhite, 3, "screen.");
					break;
				}
			break;

			case HELP_LAG:
				switch (page)
				{
					case 1:
						fixPrint(13, 6, fontColorGreen, 3, "LAG TEST (1/2)");

						fixPrint(4, 9, fontColorWhite, 3, "This test is designed to be used");
						fixPrint(4, 10, fontColorWhite, 3, "with two displays conected at");
						fixPrint(4, 11, fontColorWhite, 3, "the same time. One being a CRT,");
						fixPrint(4, 12, fontColorWhite, 3, "or a display with a known lag as");
						fixPrint(4, 13, fontColorWhite, 3, "reference, and the other the");
						fixPrint(4, 14, fontColorWhite, 3, "display to test.");

						fixPrint(4, 16, fontColorWhite, 3, "Using a camera, a picture should");
						fixPrint(4, 17, fontColorWhite, 3, "be taken of both screens at the");
						fixPrint(4, 18, fontColorWhite, 3, "same time. The picture will show");
						fixPrint(4, 19, fontColorWhite, 3, "the frame discrepancy between");
						fixPrint(4, 20, fontColorWhite, 3, "them.");

						fixPrint(4, 22, fontColorWhite, 3, "The circles in the bottom help");
						fixPrint(4, 23, fontColorWhite, 3, "determine the frame even when");
						fixPrint(26, 22, fontColorWhite, 3, "(cont...)");
					break;

					case 2:
						fixPrint(13, 6, fontColorGreen, 3, "LAG TEST (2/2)");

						fixPrint(4, 9, fontColorWhite, 3, "the numbers are blurry.");

						fixPrint(4, 11, fontColorWhite, 3, "This version of the suite can be");
						fixPrint(4, 12, fontColorWhite, 3, "used with a Sega Nomad as the");
						fixPrint(4, 13, fontColorWhite, 3, "reference display.");

						fixPrint(4, 15, fontColorWhite, 3, "You can also split the video");
						fixPrint(4, 16, fontColorWhite, 3, "signal and feed both displays.");

						fixPrint(4, 18, fontColorWhite, 3, "The vertical bars on the sides");
						fixPrint(4, 19, fontColorWhite, 3, "change color each frame to help");
						fixPrint(4, 20, fontColorWhite, 3, "when using LCD photos.");

						fixPrint(4, 22, fontColorWhite, 3, "Press A to start/stop, B to");
						fixPrint(4, 23, fontColorWhite, 3, "reset and C for B&W test.");
					break;
					}
			break;

			case HELP_ALTERNATE:
				/* fixPrint("ALTERNATE 240p/480i", 7, 6, fontColorGreen);

				fixPrint("Some devices have a delay when", 4, 57, fontColorWhite);
				fixPrint("the source changes between", 4, 65, fontColorWhite);
				fixPrint("resolutions, which happens in", 4, 73, fontColorWhite);
				fixPrint("some games. This test allows to", 4, 81, fontColorWhite);
				fixPrint("time that delay manually.", 4, 89, fontColorWhite);

				fixPrint("Press A to switch the", 4, 106, fontColorWhite);
				fixPrint("resolution; press it again when", 4, 114, fontColorWhite);
				fixPrint("you are able to see the screen", 4, 122, fontColorWhite);
				fixPrint("back in your display.", 4, 130, fontColorWhite); */
			break;

			case HELP_VIDEO:
				/* fixPrint("VIDEO OPTIONS", 10, 6, fontColorGreen);

				fixPrint("Here you can enable interlaced", 4, 57, fontColorWhite);
				fixPrint("(480i) mode for the whole suite", 4, 65, fontColorWhite);
				fixPrint("and disable horizontal 256 in", 4, 73, fontColorWhite);
				fixPrint("compatible screens.", 4, 81, fontColorWhite);

				fixPrint("For PAL consoles, you can also", 4, 98, fontColorWhite);
				fixPrint("enable full 240p, instead of", 4, 106, fontColorWhite);
				fixPrint("224p.", 4, 114, fontColorWhite); */
			break;

			case HELP_AUDIOSYNC:
				fixPrint(11, 6, fontColorGreen, 3, "AUDIO SYNC TEST");

				fixPrint(4, 9, fontColorWhite, 3, "This test flashes the whole");
				fixPrint(4, 10, fontColorWhite, 3, "screen white for 2 frames,");
				fixPrint(4, 11, fontColorWhite, 3, "along with a 1khz test tone.");

				fixPrint(4, 13, fontColorWhite, 3, "You can verify the sync between");
				fixPrint(4, 14, fontColorWhite, 3, "audio and video with recording");
				fixPrint(4, 15, fontColorWhite, 3, "equipment or specialized");
				fixPrint(4, 16, fontColorWhite, 3, "hardware.");

				fixPrint(4, 18, fontColorWhite, 3, "Press A to start/stop the test.");
			break;

			case HELP_CONTRAST:
				fixPrint(12, 6, fontColorGreen, 3, "PLUGE CONTRAST");

				fixPrint(4, 9, fontColorWhite, 3, "This sub test fills the screen");
				fixPrint(4, 10, fontColorWhite, 3, "with a pattern. By default it");
				fixPrint(4, 11, fontColorWhite, 3, "is drawn in color.");

				fixPrint(4, 12, fontColorWhite, 3, "You can change palettes with");
				fixPrint(4, 13, fontColorWhite, 3, "A to display a dark or white");
				fixPrint(4, 14, fontColorWhite, 3, "pattern in order to check");
				fixPrint(4, 15, fontColorWhite, 3, "contrast and brightness.");

				fixPrint(4, 17, fontColorWhite, 3, "The C button returns to PLUGE.");
			break;

			case HELP_MEMVIEW:
				fixPrint(13, 6, fontColorGreen, 3, "MEMORY VIEWER");

				fixPrint(4, 9, fontColorWhite, 3, "This shows selected regions of");
				fixPrint(4, 10, fontColorWhite, 3, "the main CPU memory map.");

				fixPrint(4, 12, fontColorWhite, 3, "The current address range is");
				fixPrint(4, 13, fontColorWhite, 3, "shown in red at the right from");
				fixPrint(4, 14, fontColorWhite, 3, "top to bottom.");

				fixPrint(4, 16, fontColorWhite, 3, "The left part of the screen");
				fixPrint(4, 17, fontColorWhite, 3, "shows 0x1C0 bytes in hex.");

				fixPrint(4, 19, fontColorWhite, 3, "- Button A enabled CRC of the");
				fixPrint(4, 20, fontColorWhite, 3, "current screen.");
				fixPrint(4, 21, fontColorWhite, 3, "- Button B jumps to relevant");
				fixPrint(4, 22, fontColorWhite, 3, "memory locations");
				fixPrint(4, 23, fontColorWhite, 3, "- Button C toggles ASCII");
			break;
		default:
			exit = 1;
			break;
	}

		readController();

		if (PRESSED_RIGHT)
		{
			if (page + 1 <= totalpages)
			{
				suiteClearFixLayer();
				page++;
			}
			if (dirty)
			{
				redraw = 1;
				dirty = 0;
			}
		}

		if (PRESSED_LEFT)
		{
			if (page - 1 > 0)
			{
				suiteClearFixLayer();
				page--;
			}
			if (dirty)
			{
				redraw = 1;
				dirty = 0;
			}
		}

		if (BTTN_EXIT || PRESSED_START)
		{
			exit = 1;
			gfxClear();
		}
	}
	clearController();
}