/* Seven_segment_display.h
程式名稱 | Program name
	7 段顯示器控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	7 段顯示器控制函式庫 is part of NTOUCS_Home_Network_W78E58B_board_libraries
	NTOUCS_Home_Network_W78E58B_board_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOUCS_Home_Network_W78E58B_board_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOUCS_Home_Network_W78E58B_board_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef SEVEN_SEGMENT_DISPLAY_H_INCLUDED
	#define SEVEN_SEGMENT_DISPLAY_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		#define SEVEN_SEGMENT_POSITION_ALL 0x0f
		#define SEVEN_SEGMENT_POSITION_NONE 0x00
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void seven_segmentDisable(
			/* 關閉 7 段顯示器的顯示 */
			void
		);
			
		void seven_segmentWritePositionFont(
			unsigned char font
		);
		
		void seven_segmentWritePosition(
			unsigned char position
				/* current max 4 bit defined, from 0x01 to 0x08 */
		);
					
		void seven_segmentDisplayValue4digit(
			unsigned int value
				/* 顯示的數值(0000~9999) */
		);
	
	/*||||| 全域變數 | Global Variables |||||*/
		/* 數字字型 */
			extern code const unsigned char seven_segment_font_digits[10];
		/* 掃描位置 */
			extern code const unsigned char seven_segment_scan_position[4];
	#ifdef __cplusplus
		}
	#endif
#endif /* SEVEN_SEGMENT_DISPLAY_H_INCLUDED */