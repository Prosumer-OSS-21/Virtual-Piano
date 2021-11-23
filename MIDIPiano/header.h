#pragma once
#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

#define NKEY 29
#define NINSTRUMENT 128
#define NNOTE 128
#define NVOLUME 128

#pragma pack(push, 1)
typedef struct
{
	BYTE byte_state;
	BYTE byte_note;
	BYTE byte_velocity;
	BYTE byte_null;
} midi_short_msg_st;

typedef union
{
	DWORD dw_midi_data;
	midi_short_msg_st st_midi_data;
} midi_short_msg;
#pragma pack(pop)

void midi_output_error(MMRESULT mm_result);
long midi_get_dev_id(HMIDIOUT h_midi_device);
void midi_get_dev_caps(HMIDIOUT h_midi_device, MIDIOUTCAPS* caps);
HMIDIOUT midi_open(WORD w_midi_num);
LRESULT midi_close(HMIDIOUT h_midi_device);
void midi_send_short_msg(HMIDIOUT h_midi_device, BYTE byte_state, BYTE byte_note, BYTE byte_valo);
void midi_all_channel_sound_off(HMIDIOUT h_midi_device);
void gotoxy(int x, int y);