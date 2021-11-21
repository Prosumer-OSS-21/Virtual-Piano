

#include "header.h"

void main()
{
	//피아노 인터페이스
	puts("│  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │");
	puts("│  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │");
	puts("│  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │  │ │ │ │ │ │  │  │ │ │ │  │");
	puts("│  │S│ │D│  │  │G│ │M│ │J│  │  │2│ │3│  │  │5│ │6│ │7│  │  │9│ │0│  │");
	puts("│  └─┘ └─┘  │  └─┘ └─┘ └─┘  │  └─┘ └─┘  │  └─┘ └─┘ └─┘  │  └─┘ └─┘  │");
	puts("│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │");
	puts("│ Z │ X │ C │ V │ B │ N │ M │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │");
	puts("└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘");
    while (1) {

        if (GetAsyncKeyState(0x5A))
        {// Z값
            Beep(260, 200);
        }
        else if (GetAsyncKeyState(0x58))
        {// X값
            Beep(290, 200);
        }
        else if (GetAsyncKeyState(0x43))
        {// C값
            Beep(330, 200);
        }
        else if (GetAsyncKeyState(0x56))
        {// V값
            Beep(340, 200);
        }
        else if (GetAsyncKeyState(0x4E))
        {// B값
            Beep(380, 200);
        }
        else if (GetAsyncKeyState(0x4D))
        {// N값
            Beep(430, 200);
        }
        else if (GetAsyncKeyState(0x51))
        {// M값
            Beep(490, 200);
        }
        else if (GetAsyncKeyState(0x57))
        {// Q값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x52))
        {// W값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x45))
        {// E값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x52))
        {// R값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x54))
        {// T값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x59))
        {// Y값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x53))
        {// S값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x44)) {
            Beep(510, 200);//D값은 현재 안되고 있음 이유를 모르겠다
        }
        else if (GetAsyncKeyState(0x47))
        { // G값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x48))
        {// H값
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x4A))
        { // J값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x32))
        {// 2값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x33))
        {// 3값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x35))
        {// 5값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x36))
        {// 6값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x37))
        {// 7값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x39))
        {//9값
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x30)) {
            Beep(510, 200);
        }


    }
}