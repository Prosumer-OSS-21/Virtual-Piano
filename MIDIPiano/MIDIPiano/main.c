#include "header.h"

int main()
{
	int loop;
	int telling = 0;
	BYTE key = 0;
	BYTE instrument = 0;
	BYTE volume = 127;   // max
	BYTE octave = 48;    // default
	BYTE velocity = 120; // default

	HMIDIOUT h_midi_device;

	BYTE piano_key[NKEY] = {
		0x5A, 0x53, 0x58, 0x44, 0x43,             // Z S X D C
		0x56, 0x47, 0x42, 0x48, 0x4E, 0x4A, 0x4D, // V G B H N J M
		0x51, 0x32, 0x57, 0x33, 0x45,             // Q 2 W 3 E
		0x52, 0x35, 0x54, 0x36, 0x59, 0x37, 0x55, // R 5 T 6 Y 7 U
		0x49, 0x39, 0x4F, 0x30, 0x50              // I 9 O 0 P
	};

	BYTE piano_key_on_off[NKEY] = { 0 };

	char inst_name[][NINSTRUMENT] = {
		"x`", "Bright Acoustic", "Electric Grand", "Honkey-Tonk",
		"Electric Piano 1", "Electric Piano 2", "Harpsichord", "Clav",
		"Celesta", "Glockenspiel", "Music Box", "Vibraphone",
		"Marimba", "Xylophone", "Tubular Bells", "Dulcimer",
		"Drawbar Organ", "Percussive Organ", "Rock Organ", "Church Organ",
		"Reed Organ", "Accordion", "Harmonica", "Tango Accordion",
		"Acoustic Guitar(nylon)", "Acoustic Guitar(Steel)", "Electric Guitar(Jazz)", "Electric Guitar(Clean)",
		"Electric Guitar(muted)", "Overdriven Guitar", "Distortion Guitar", "Guitar Harmonics",
		"Acoustic Bass", "Electric Bass(finger)", "Electric Bass(Pick)", "Fretless Bass",
		"Slap Bass 1", "Slap Bass 2", "Synth Bass 1", "Synth Bass 2",
		"Violin", "Viola", "Cello", "Contrabass",
		"Tremolo Strings", "Pizzicato Strings", "Orchestral Harp", "Timpani",
		"String Ensemble 1", "String Ensemble 2", "SynthStrings 1", "SynthStrings 2",
		"Choir Aahs", "Voice Oohs", "Synth Voice", "orchestra Hit",
		"Trumpet", "Trombone", "Tuba", "Muted Trumpet",
		"French Horn", "Brass Section", "SynthBrass 1", "SynthBrass 2",
		"Soprano Sax", "Alto Sax", "Tenor Sax", "Baritone Sax",
		"Oboe", "English Horn", "Bassoon", "Clarinet",
		"Piccolo", "Flute", "Recorder", "Pan Flute",
		"Blown Bottle", "Shakuhachi", "Whistle", "Ocarina",
		"Lead 1: square", "Lead 2: sawtooth", "Lead 3: calliope", "Lead 4: chiff",
		"Lead 5: charang", "Lead 6: voice", "Lead 7: fifths", "Lead 8: bass+lead",
		"Pad 1: new age", "Pad 2: warm", "Pad 3: polysynth", "Pad 4: choir",
		"Pad 5: bowed", "Pad 6: voice", "Pad 7: halo", "Pad 8: sweep",
		"FX 1: rain", "FX 2: soundtrack", "FX 3: crystal", "FX 4: atmosphere",
		"FX 5: brightness", "FX 6: goblins", "FX 7: echoes", "FX 8: sci-fi",
		"Sitar", "Banjo", "Shamisen", "Koto",
		"Kalimba", "Bagpipe", "Fiddle", "Shanai",
		"Tinkle Bell", "Agogo", "Steel Drums", "Woodblock",
		"Taiko Drum", "Melodic Tom", "Synth Drum", "Reverse Cymbal",
		"Guitar Fret Noise", "Breath Noise", "Seashore", "Bird Tweet",
		"Telephone Ring", "Helicopter", "Applause", "Gunshot"
	};
	char music_name[][NINSTRUMENT] = { "x`","smallstar","schoolbell","mountinrabbit","biycle","airplane"};

	h_midi_device = midi_open(0);

	if (h_midi_device == NULL) return;

	printf("[ESC]: Exit\n\n");
	printf(" Instrument : %-25s    Octave : %03d    Volume : %03d\n\n", inst_name[0], octave, volume);
	printf("   musicname : %s\n\n", music_name[0]);
	puts(" │  │  │ │  │   │  │  │ │  │ │  │   │   │  │ │  │  │  │  │ │  │ │  │   │  │  │ │  │   │");
	puts(" │  │  │ │  │   │  │  │ │  │ │  │   │   │  │ │  │  │  │  │ │  │ │  │   │  │  │ │  │   │");
	puts(" │  │  │ │  │   │  │  │ │  │ │  │   │   │  │ │  │  │  │  │ │  │ │  │   │  │  │ │  │   │");
	puts(" │  │ S│ │ D│   │  │ G│ │ H│ │ J│   │   │ 2│ │ 3│  │  │ 5│ │ 6│ │ 7│   │  │ 9│ │ 0│   │");
	puts(" │  └──┘ └──┘   │  └──┘ └──┘ └──┘   │   └──┘ └──┘  │  └──┘ └──┘ └──┘   │  └──┘ └──┘   │");
	puts(" │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │");
	puts(" │ Ｚ │ Ｘ │ Ｃ │ Ｖ │ Ｂ │ Ｎ │ Ｍ │ Ｑ │ Ｗ │ Ｅ │ Ｒ │ Ｔ │ Ｙ │ Ｕ │ Ｉ │ Ｏ │ Ｐ │");
	puts(" └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘");

	midi_all_channel_sound_off(h_midi_device);

	midi_send_short_msg(h_midi_device, 0xB0, 7, volume);

	

	
	int note[10][10000] = { { 1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100,100,8,8,6,6,5,5,3,100,8,8,6,6,5,5,3,100,100,1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100, '\0'}
	                       ,{ 8,8,10,10,8,8,5,100,8,8,5,5,3,100,100,100,8,8,10,10,8,8,5,100,8,5,3,5,1,100,'\0' }
	                       ,{ 8,105,105,108,105,1,100,3,105,103,101,105,8,100,100,101,108,101,108,101,108,5,100,  8, 103,106,105,103,1,100,'\0'}
		                   ,{ 105 ,108, 8, 105,108,8 ,10,110,110,110,110,10 ,100,108,108,108,108 ,106,106,106,106, 105,105,105,105,5,100,105,108,108,108,105,108,8 ,110, 110 ,105,105,8,100,106,106,106,106, 105,105,105,105 ,103,103,108,108,1,'\0'}
	                       ,{ 305 ,403, 1, 3, 5 ,5 ,105 ,100,3, 3, 3 ,5, 5, 105 ,100,305,403,1,3,5,5,105,100,3,3,305,403,501,'\0' } 
	                        };
	
	int small_star[10000]= { 1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100,1008,8,6,6,5,5,3,100,8,8,6,6,5,5,3,100,100,1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100, '\0' };
	int shcool_bell[10000]= { 8,8,10,10,8,8,5,100,8,8,5,5,3,100,100,100,8,8,10,10,8,8,5,100,8,5,3,5,1,100,'\0' };
	int hare[1000]= { 8,105,105,108,105,1,100,3,105,103,101,105,8,100,100,101,108,101,108,101,108,5,100,  8, 103,106,105,103,1,100,'\0' };
	int bicycle[10000] = { 105 ,108, 8, 105,108,8 ,10,110,110,110,110,10 ,100,108,108,108,108 ,106,106,106,106, 105,105,105,105,5,100,105,108,108,108,105,108,8 ,110, 110 ,105,105,8,100,106,106,106,106, 105,105,105,105 ,103,103,108,108,1,'\0'};
	int airplane[10000] = { 305 ,403, 1, 3, 5 ,5 ,105 ,100,3, 3, 3 ,5, 5, 105 ,100,305,403,1,3,5,5,105,100,3,3,305,403,501,'\0' };

	//100은 소리가 안나면서 박자를 맞추기 위함
	//1000ms 1초이다
	//bpm 120을 기준을 작성하였다.
	//기준점 500ms는 4분에 1박이라는 개념 10의 자리수
	//250ms 1/8박이라는 개념 100의 자리수
	//375 1/8.박 300자리수
	//125 1/16 400자리수 
	//1000ms 1/2박 500자리수 
	int ar2 = 0;

	loop = 1;
	int bpm = 120;
	
	while (loop)
	{
		int ar2 = 0;
		if (GetKeyState(VK_ESCAPE) < 0) loop = 0;
		else if (GetKeyState(VK_OEM_PLUS) < 0)
		{
			if (volume < (NVOLUME - 1)) volume += 1;
			midi_send_short_msg(h_midi_device, 0xB0, 7, volume);
			gotoxy(59, 2);
			printf("Volume : %03d", volume);
			Sleep(60);
			
		}
		else if (GetKeyState(VK_OEM_MINUS) < 0)
		{
			if (volume != 0) volume -= 1;
			midi_send_short_msg(h_midi_device, 0xB0, 7, volume);
			gotoxy(59, 2);
			printf("Volume : %03d", volume);
			Sleep(60);
			
		}
		else if (GetKeyState(VK_RIGHT) < 0)
		{
			if (instrument < (NINSTRUMENT - 1)) instrument += 1;
			midi_send_short_msg(h_midi_device, 0xC0, instrument, 0); // 0xC0: program change
			gotoxy(1, 2);
			printf("Instrument : %-24s", inst_name[instrument]);
			Sleep(120);
			
		}
		else if (GetKeyState(VK_LEFT) < 0)
		{
			if (instrument != 0) instrument -= 1;
			midi_send_short_msg(h_midi_device, 0xC0, instrument, 0); // 0xC0: program change
			gotoxy(1, 2);
			printf("Instrument : %-24s", inst_name[instrument]);
			Sleep(120);
		
			
		}
		else if (GetKeyState(VK_UP) < 0)
		{
			if (octave < (NNOTE - NKEY)) octave += 12;
			gotoxy(43, 2);
			printf("Octave : %03d", octave);
			Sleep(200);
			gotoxy(0, 12);      			
		}
		else if (GetKeyState(VK_DOWN) < 0)
		{
			if (octave != 0) octave -= 12;
			gotoxy(43, 2);
			printf("Octave : %03d", octave);
			Sleep(200);
			
		}
		else if (GetKeyState(VK_F1) < 0)
		{
			if (telling < (5 - 1)) telling += 1;
			gotoxy(4, 4);
			printf(" musicname : %-25s", music_name[telling]);
			Sleep(120);

		}
		else if (GetKeyState(VK_F2) < 0)
		{
			if (telling != 0) telling -= 1;
			gotoxy(4, 4);
			printf(" musicname : %-25s", music_name[telling]);
			Sleep(120);


		}
		else if (GetKeyState(VK_LBUTTON)<0) {

			Sleep(2000);	
			int note1[1000];
			while (note[telling][ar2] != '\0')
			{
				note1[ar2] = note[telling][ar2];
				ar2++;
			}
			ar2 = 0;
				
			
			music_note(h_midi_device, note1, velocity, bpm);
				
				

				
		}
			
		else
			for (key = 0; key < NKEY; key++)
				if (GetKeyState(piano_key[key]) < 0)
					if (piano_key_on_off[key] == 0)
					{
						
						piano_key_on_off[key] = 1;
						midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + key), velocity);
					}

		for (key = 0; key < NKEY; key++)
			if (!(GetKeyState(piano_key[key]) < 0))
				if (piano_key_on_off[key] != 0)
				{
					piano_key_on_off[key] = 0;
					midi_send_short_msg(h_midi_device, 0x80, (BYTE)(octave + key), velocity);
				}
	}

	for (key = 0; key < NKEY; key++)
		if (piano_key_on_off[key] != 0)
			midi_send_short_msg(h_midi_device, 0x80, (BYTE)(octave + key), velocity);

	midi_all_channel_sound_off(h_midi_device);

	midi_close(h_midi_device);
}
