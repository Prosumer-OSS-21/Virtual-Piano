#include "header.h"

void CALLBACK MIDI_out_proc(HMIDIOUT h_Midi_device, UINT u_msg,
	DWORD instance, DWORD paraml,
	DWORD param2)
{
}

void MIDI_output_error(MMRESULT mm_result)
{
	//에러 문자열을 저장할 배열
	char sz_err_msg[128];

	midiInGet_error_text(mm_result, (char*)sz_err_msg, sizeof(sz_err_msg));

	MessageBox(0, sz_err_msg, "Midi Error!!!", MB_OK);
}