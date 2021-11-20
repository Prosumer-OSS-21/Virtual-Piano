#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "wimmm.lib")

#pragma pack(push, 1) // µ¥ÀÌÅÍ Àü¼Û 1¹ÙÀÌÆ®

typedef struct
{
	BYTE byte_state;
	BYTE byte_note;
	BYTE byte_velocity;
	BYTE byte_null;
} MIDI_SHORT_MESSAGE_ST;

typedef union
{
	DWORD dw_MIDI_data;
	MIDI_SHORT_MESSAGE_ST st_MIDI_data;
} MIDI_SHORT_MESSAGE;

#pragma pack(pop)

void CALLBACK midi_out_proc(HMIDIOUT, UINT, DWORD, DWORD, DWORD);
void MIDI_output_error(MMRESULT);
long MIDI_get_dev_id(HMIDIOUT);
void MIDI_get_dev_caps(HMIDIOUT, MIDIOUTCAPS);
HMIDIOUT MIDI_open(WORD);
LRESULT MIDI_close(HMIDIOUT);
