#include "header.h"

void CALLBACK midi_out_proc(HMIDIOUT h_midi_device, UINT u_msg, DWORD instance, DWORD param1, DWORD param2)
{
}

void midi_output_error(MMRESULT mm_result)
{
	char sz_err_msg[128];

	midiInGetErrorText(mm_result, (char*)sz_err_msg, sizeof(sz_err_msg));

	MessageBox(0, sz_err_msg, "Midi Error!!!", MB_OK);
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

	mm_result = midiOutOpen(&h_midi_device, w_midi_num, midi_out_proc, NULL, CALLBACK_FUNCTION);

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