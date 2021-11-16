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

long midi_get_dev_id(HMIDIOUT h_MIDI_device)
{
	UINT u_device_id;

	MMRESULT mm_result = midiOutGetID(h_MIDI_device, &u_device_id);

	if (mm_result != MMSYSERR_NOERROR)
	{
		MIDI_output_error(mm_result);
		return -1;
	}

	return (long)u_device_id;
}

void midi_get_dev_caps(HMIDIOUT m_dev_out_handle, MIDIOUTCAPS *caps)
{
 
    long l_device_id;
 
    MMRESULT result;

    l_device_id=midi_get_dev_id(m_dev_out_handle);
 
    if (l_device_id < 0) return;
 
    result = midi_out_get_dev_caps((UINT)l_device_id, caps, sizeof(MIDIOUTCAPS));

    if(result != MMSYSERR_NOERROR)
    {
        midi_output_error(result);
 
    }
 
}

HMIDIOUT midi_open(WORD w_devs_num)
 
{
    WORD w_max_dev_num=0;

    MMRESULT ui_midi_open=0;

    HMIDIOUT m_dev_handle=NULL;

    w_max_dev_num=midi_in_get_num_devs();

    if (w_devs_num >= w_max_dev_num)
    {
        w_devs_num=0;
    }

    ui_midi_open = midi_out_open(&m_dev_handle, w_devs_num, (DWORD)(midi_out_proc), (DWORD)NULL, CALLBACK_FUNCTION);

    if (ui_midi_open!=MMSYSERR_NOERROR)
    {
        midi_output_error(ui_midi_open);
        return NULL;
    }

    return m_dev_handle;
}

LRESULT midi_close(HMIDIOUT m_dev_out_handle)
{
    MMRESULT result;

    result = midi_out_close(m_dev_out_handle);

    if(result!=MMSYSERR_NOERROR)
    {
        midi_output_error(result);
        return FALSE;
    }
    else {
        m_dev_out_handle=NULL;
    }
    return TRUE;
}
