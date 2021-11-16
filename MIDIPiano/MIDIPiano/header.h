#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "wimmm.lib")

#pragma pack(push, 1) // 데이터 전송 1바이트

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

void CALLBACK MIDI_out_proc(HMIDIOUT, UINT,	DWORD, DWORD, DWORD);

void MIDI_output_error(MMRESULT);