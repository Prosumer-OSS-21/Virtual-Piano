

#include "header.h"

void main()
{
	//�ǾƳ� �������̽�
	puts("��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��");
	puts("��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��");
	puts("��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��  �� �� �� �� �� ��  ��  �� �� �� ��  ��");
	puts("��  ��S�� ��D��  ��  ��G�� ��M�� ��J��  ��  ��2�� ��3��  ��  ��5�� ��6�� ��7��  ��  ��9�� ��0��  ��");
	puts("��  ������ ������  ��  ������ ������ ������  ��  ������ ������  ��  ������ ������ ������  ��  ������ ������  ��");
	puts("��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��");
	puts("�� Z �� X �� C �� V �� B �� N �� M �� Q �� W �� E �� R �� T �� Y �� U �� I �� O �� P ��");
	puts("������������������������������������������������������������������������������������������������������������������������������������������");
    while (1) {

        if (GetAsyncKeyState(0x5A))
        {// Z��
            Beep(260, 200);
        }
        else if (GetAsyncKeyState(0x58))
        {// X��
            Beep(290, 200);
        }
        else if (GetAsyncKeyState(0x43))
        {// C��
            Beep(330, 200);
        }
        else if (GetAsyncKeyState(0x56))
        {// V��
            Beep(340, 200);
        }
        else if (GetAsyncKeyState(0x4E))
        {// B��
            Beep(380, 200);
        }
        else if (GetAsyncKeyState(0x4D))
        {// N��
            Beep(430, 200);
        }
        else if (GetAsyncKeyState(0x51))
        {// M��
            Beep(490, 200);
        }
        else if (GetAsyncKeyState(0x57))
        {// Q��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x52))
        {// W��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x45))
        {// E��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x52))
        {// R��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x54))
        {// T��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x59))
        {// Y��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x53))
        {// S��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x44)) {
            Beep(510, 200);//D���� ���� �ȵǰ� ���� ������ �𸣰ڴ�
        }
        else if (GetAsyncKeyState(0x47))
        { // G��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x48))
        {// H��
            Beep(510, 200);
        }
        else if (GetAsyncKeyState(0x4A))
        { // J��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x32))
        {// 2��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x33))
        {// 3��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x35))
        {// 5��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x36))
        {// 6��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x37))
        {// 7��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x39))
        {//9��
            Beep(510, 200);

        }
        else if (GetAsyncKeyState(0x30)) {
            Beep(510, 200);
        }


    }
}