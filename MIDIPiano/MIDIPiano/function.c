#include "header.h"

void CALLBACK midi_out_proc(HMIDIOUT h_midi_device, UINT u_msg, DWORD instance, DWORD paraml, DWORD param2)
{
}

void MIDI_output_error(MMRESULT mm_result)
{
	//에러 문자열을 저장할 배열
	char sz_err_msg[128];

	midiInGet_error_text(mm_result, (char*)sz_err_msg, sizeof(sz_err_msg));

	MessageBox(0, sz_err_msg, "Midi Error!!!", MB_OK);
}

long MIDI_get_dev_id(HMIDIOUT h_midi_device)
{
	UINT u_device_id;

	MMRESULT mm_result = midi_out_get_id(h_idi_device, &u_device_id);

	if (mm_result != MMSYSERR_NOERROR)
	{
		MIDI_output_error(mm_result);
		return -1;
	}

	return (long)u_device_id;
}

void MIDI_get_dev_caps(HMIDIOUT h_midi_device, MIDIOUTCAPS *caps)
{
 
    long l_device_id;

    MMRESULT mm_result;

    l_device_id = MIDI_get_dev_id(h_midi_device);
 
    if (l_device_id < 0) return;
 
    mm_result = midi_out_get_dev_caps((UINT)l_device_id, caps, sizeof(MIDIOUTCAPS));

    if(mm_result != MMSYSERR_NOERROR)
    {
        MIDI_output_error(mm_result);
    }
}

HMIDIOUT MIDI_open(WORD w_midi_num)
 
{
    WORD w_midi_max = 0;
    MMRESULT mm_result = 0;
    HMIDIOUT h_midi_device = NULL;

    w_midi_max = midi_in_get_num_devs();

    if (w_midi_num >= w_midi_max) w_midi_num = 0;

    mm_result = midi_out_open(&h_midi_device, w_midi_num, (DWORD)(midi_out_proc), (DWORD)NULL, CALLBACK_FUNCTION);

    if (mm_result != MMSYSERR_NOERROR)
    {
        MIDI_output_error(mm_result);
        return NULL;
    }

    return h_midi_device;
}

LRESULT MIDI_close(HMIDIOUT h_midi_device)
{
    MMRESULT mm_result;

    mm_result = midi_out_close(h_midi_device);

    if(mm_result != MMSYSERR_NOERROR)
    {
        MIDI_output_error(mm_result);
        return FALSE;
    }
    return TRUE;
}
