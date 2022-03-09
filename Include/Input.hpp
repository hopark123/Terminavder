#ifndef _INPUT_
# define _INPUT_

# include <termios.h>
# include <iostream>
# include <stdint.h>

enum KeyCode
	{
		KEY_SPACE = 49,
		KEY_UP = 126,
		KEY_DOWN = 125,
		KEY_LEFT = 123,
		KEY_RIGHT = 124,
		KEY_A = 0,
		KEY_B = 11,
		KEY_C = 8,
		KEY_D = 2,
		KEY_E = 14,
		KEY_F = 3,
		KEY_G = 5,
		KEY_H = 4,
		KEY_I = 34,
		KEY_J = 38,
		KEY_K = 40,
		KEY_L = 37,
		KEY_M = 46,
		KEY_N = 45,
		KEY_O = 31,
		KEY_P = 35,
		KEY_Q = 12,
		KEY_R = 15,
		KEY_S = 1,
		KEY_T = 17,
		KEY_U = 32,
		KEY_W = 13,
		KEY_X = 7,
		KEY_Y = 16,
		KEY_Z = 6,
		KEY_CTRL = 59,
		KEY_SHIFT = 57,
		KEY_ESC = 53,
		KEY_1 = 18,
		KEY_2 = 19,
		KEY_3 = 20,
		KEY_4 = 21,
		KEY_5 = 23,
		KEY_6 = 22,
		KEY_7 = 26,
		KEY_8 = 28,
		KEY_9 = 25,
		KEY_0 = 29
	};

class Input {
	public :
		static int GetKeyDown(KeyCode keycode);
		static int GetKey(KeyCode keycode);
		static int GetKeyUp(KeyCode keycode);
		static int GetMultiKeyDown(KeyCode keycode1, KeyCode keycode2);
		static int GetDoubleKeyDown(KeyCode keyCode);
	
	private :
		unsigned int	_currentTime;
}


#endif