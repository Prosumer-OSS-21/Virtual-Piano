#include "header.h"
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

void CALLBACK midi_out_proc(HMIDIOUT h_midi_device, UINT u_msg, DWORD_PTR instance, DWORD_PTR param1, DWORD_PTR param2)
{
}

void midi_output_error(MMRESULT mm_result)
{
	char sz_err_msg[128];
	wchar_t w_sz_err_msg[128];
	char err_msg_text_t[] = "Midi Error!!!";
	wchar_t err_msg_text_w[20];
	mbstowcs(w_sz_err_msg, sz_err_msg, strlen(sz_err_msg) + 1);
	mbstowcs(err_msg_text_w, err_msg_text_t, strlen(err_msg_text_t) + 1);
	LPWSTR err_msg = w_sz_err_msg;
	LPWSTR err_msg_text = err_msg_text_w;
	midiInGetErrorText(mm_result, err_msg, sizeof(sz_err_msg));
	MessageBox(0, err_msg, err_msg_text, MB_OK);
}

long midi_get_dev_id(HMIDIOUT h_midi_device)
{
	UINT u_device_id;

	MMRESULT mm_result = midiOutGetID(h_midi_device, &u_device_id);

	if (mm_result != MMSYSERR_NOERROR)
	{
		midi_output_error(mm_result);
		return -1;
	}

	return (long)u_device_id;
}

void midi_get_dev_caps(HMIDIOUT h_midi_device, MIDIOUTCAPS* caps)
{
	long l_device_id;

	MMRESULT mm_result;

	l_device_id = midi_get_dev_id(h_midi_device);

	if (l_device_id < 0) return;

	mm_result = midiOutGetDevCaps((UINT)l_device_id, caps, sizeof(MIDIOUTCAPS));

	if (mm_result != MMSYSERR_NOERROR)
		midi_output_error(mm_result);
}

HMIDIOUT midi_open(WORD w_midi_num)
{
	WORD w_midi_max = 0;
	MMRESULT mm_result = 0;
	HMIDIOUT h_midi_device = NULL;

	w_midi_max = midiInGetNumDevs();

	if (w_midi_num >= w_midi_max) w_midi_num = 0;

	mm_result = midiOutOpen(&h_midi_device, w_midi_num, (DWORD)midi_out_proc, NULL, CALLBACK_FUNCTION);

	if (mm_result != MMSYSERR_NOERROR)
	{
		midi_output_error(mm_result);
		return NULL;
	}

	return h_midi_device;
}

LRESULT midi_close(HMIDIOUT h_midi_device)
{
	MMRESULT mm_result;

	mm_result = midiOutClose(h_midi_device);

	if (mm_result != MMSYSERR_NOERROR)
	{
		midi_output_error(mm_result);
		return FALSE;
	}

	return TRUE;
}

void midi_send_short_msg(HMIDIOUT h_midi_device, BYTE byte_state, BYTE byte_note, BYTE byte_valo)
{
	midi_short_msg s_msg;

	s_msg.st_midi_data.byte_velocity = byte_valo;
	s_msg.st_midi_data.byte_note = byte_note;
	s_msg.st_midi_data.byte_state = byte_state;
	s_msg.st_midi_data.byte_null = 0;

	midiOutShortMsg(h_midi_device, s_msg.dw_midi_data);
}

void midi_all_channel_sound_off(HMIDIOUT h_midi_device)
{
	BYTE channel;

	for (channel = 0; channel < 16; channel++)
	{
		// 0xB0: control / mode change
		// 0x78: all sound off
		midi_send_short_msg(h_midi_device, (BYTE)(0xB0 + channel), 0x78, 0);
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void music_note(HMIDIOUT h_midi_device, int* byte_note, BYTE byte_valo, int octave)
{
	while (byte_note != '\0')
	{
		if (*byte_note > 100 && *byte_note < 200)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note - 100) + (BYTE)(octave), byte_valo);
			Sleep(250);
			byte_note++;
		}
		else if (*byte_note == 100)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note), byte_valo);
			Sleep(400);
			byte_note++;

		}
		else if (*byte_note > 200 && *byte_note < 300)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note - 200) + (BYTE)(octave), byte_valo);
			Sleep(400);
			byte_note++;

		}
		else if (*byte_note > 300 && *byte_note < 400)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note - 300) + (BYTE)(octave), byte_valo);
			Sleep(375);
			byte_note++;

		}
		else if (*byte_note > 400 && *byte_note < 500)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note - 400) + (BYTE)(octave), byte_valo);
			Sleep(125);
			byte_note++;

		}
		else if (*byte_note > 500 && *byte_note < 600)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note - 500) + (BYTE)(octave), byte_valo);
			Sleep(1000);
			byte_note++;

		}
		else if (*byte_note < 100 && *byte_note>0)
		{
			midi_send_short_msg(h_midi_device, 0x90, (BYTE)(0x30 + *byte_note) + (BYTE)(octave), byte_valo);
			Sleep(500);
			byte_note++;
		}
		else
		{
			int i = 0;
			break;

		}
	}
}