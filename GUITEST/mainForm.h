#pragma once
#include "header.h"

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
	"Acoustic Grand", "Bright Acoustic", "Electric Grand", "Honkey-Tonk",
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

namespace GUITEST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// mainForm¿¡ ´ëÇÑ ¿ä¾àÀÔ´Ï´Ù.
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: »ý¼ºÀÚ ÄÚµå¸¦ ¿©±â¿¡ Ãß°¡ÇÕ´Ï´Ù.
			//

		}

	protected:
		/// <summary>
		/// »ç¿ë ÁßÀÎ ¸ðµç ¸®¼Ò½º¸¦ Á¤¸®ÇÕ´Ï´Ù.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	protected:

	protected:

	private:
		/// <summary>
		/// ÇÊ¼ö µðÀÚÀÌ³Ê º¯¼öÀÔ´Ï´Ù.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// µðÀÚÀÌ³Ê Áö¿ø¿¡ ÇÊ¿äÇÑ ¸Þ¼­µåÀÔ´Ï´Ù. 
		/// ÀÌ ¸Þ¼­µåÀÇ ³»¿ëÀ» ÄÚµå ÆíÁý±â·Î ¼öÁ¤ÇÏÁö ¸¶¼¼¿ä.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->Location = System::Drawing::Point(0, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 300);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Z";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button3->Location = System::Drawing::Point(69, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 300);
			this->button3->TabIndex = 2;
			this->button3->Text = L"X";
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &mainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button4->Location = System::Drawing::Point(207, 82);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 300);
			this->button4->TabIndex = 4;
			this->button4->Text = L"V";
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &mainForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button5->Location = System::Drawing::Point(138, 82);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 300);
			this->button5->TabIndex = 3;
			this->button5->Text = L"C";
			this->button5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &mainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button6->Location = System::Drawing::Point(414, 82);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 300);
			this->button6->TabIndex = 7;
			this->button6->Text = L"M";
			this->button6->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &mainForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button7->Location = System::Drawing::Point(345, 82);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 300);
			this->button7->TabIndex = 6;
			this->button7->Text = L"N";
			this->button7->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &mainForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button8->Location = System::Drawing::Point(276, 82);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 300);
			this->button8->TabIndex = 5;
			this->button8->Text = L"B";
			this->button8->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &mainForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Black;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Location = System::Drawing::Point(49, 82);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(40, 180);
			this->button9->TabIndex = 8;
			this->button9->Text = L"S";
			this->button9->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &mainForm::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Black;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Location = System::Drawing::Point(118, 82);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(40, 180);
			this->button10->TabIndex = 9;
			this->button10->Text = L"D";
			this->button10->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &mainForm::button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Black;
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Location = System::Drawing::Point(256, 82);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(40, 180);
			this->button11->TabIndex = 10;
			this->button11->Text = L"G";
			this->button11->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &mainForm::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Black;
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button12->ForeColor = System::Drawing::Color::White;
			this->button12->Location = System::Drawing::Point(325, 82);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(40, 180);
			this->button12->TabIndex = 11;
			this->button12->Text = L"H";
			this->button12->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &mainForm::button12_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Black;
			this->button13->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button13->ForeColor = System::Drawing::Color::White;
			this->button13->Location = System::Drawing::Point(394, 82);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(40, 180);
			this->button13->TabIndex = 12;
			this->button13->Text = L"J";
			this->button13->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &mainForm::button13_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Black;
			this->button14->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button14->ForeColor = System::Drawing::Color::White;
			this->button14->Location = System::Drawing::Point(877, 82);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(40, 180);
			this->button14->TabIndex = 24;
			this->button14->Text = L"7";
			this->button14->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &mainForm::button14_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::Black;
			this->button15->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Location = System::Drawing::Point(808, 82);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(40, 180);
			this->button15->TabIndex = 23;
			this->button15->Text = L"6";
			this->button15->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &mainForm::button15_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::Black;
			this->button16->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button16->ForeColor = System::Drawing::Color::White;
			this->button16->Location = System::Drawing::Point(739, 82);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(40, 180);
			this->button16->TabIndex = 22;
			this->button16->Text = L"5";
			this->button16->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &mainForm::button16_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::Black;
			this->button17->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button17->ForeColor = System::Drawing::Color::White;
			this->button17->Location = System::Drawing::Point(601, 82);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(40, 180);
			this->button17->TabIndex = 21;
			this->button17->Text = L"3";
			this->button17->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &mainForm::button17_Click);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::Black;
			this->button18->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button18->ForeColor = System::Drawing::Color::White;
			this->button18->Location = System::Drawing::Point(532, 82);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(40, 180);
			this->button18->TabIndex = 20;
			this->button18->Text = L"2";
			this->button18->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &mainForm::button18_Click);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::White;
			this->button19->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button19->Location = System::Drawing::Point(897, 82);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(70, 300);
			this->button19->TabIndex = 19;
			this->button19->Text = L"U";
			this->button19->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &mainForm::button19_Click);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::White;
			this->button20->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button20->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button20->Location = System::Drawing::Point(828, 82);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(70, 300);
			this->button20->TabIndex = 18;
			this->button20->Text = L"Y";
			this->button20->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &mainForm::button20_Click);
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::White;
			this->button21->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button21->Location = System::Drawing::Point(759, 82);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(70, 300);
			this->button21->TabIndex = 17;
			this->button21->Text = L"T";
			this->button21->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &mainForm::button21_Click);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::White;
			this->button22->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button22->Location = System::Drawing::Point(690, 82);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(70, 300);
			this->button22->TabIndex = 16;
			this->button22->Text = L"R";
			this->button22->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &mainForm::button22_Click);
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::Color::White;
			this->button23->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button23->Location = System::Drawing::Point(621, 82);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(70, 300);
			this->button23->TabIndex = 15;
			this->button23->Text = L"E";
			this->button23->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &mainForm::button23_Click);
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::White;
			this->button24->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button24->Location = System::Drawing::Point(552, 82);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(70, 300);
			this->button24->TabIndex = 14;
			this->button24->Text = L"W";
			this->button24->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &mainForm::button24_Click);
			// 
			// button25
			// 
			this->button25->BackColor = System::Drawing::Color::White;
			this->button25->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button25->Location = System::Drawing::Point(483, 82);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(70, 300);
			this->button25->TabIndex = 13;
			this->button25->Text = L"Q";
			this->button25->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button25->UseVisualStyleBackColor = false;
			this->button25->Click += gcnew System::EventHandler(this, &mainForm::button25_Click);
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::Black;
			this->button26->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button26->ForeColor = System::Drawing::Color::White;
			this->button26->Location = System::Drawing::Point(1084, 82);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(40, 180);
			this->button26->TabIndex = 29;
			this->button26->Text = L"0";
			this->button26->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &mainForm::button26_Click);
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::Color::Black;
			this->button27->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button27->ForeColor = System::Drawing::Color::White;
			this->button27->Location = System::Drawing::Point(1015, 82);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(40, 180);
			this->button27->TabIndex = 28;
			this->button27->Text = L"9";
			this->button27->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &mainForm::button27_Click);
			// 
			// button28
			// 
			this->button28->BackColor = System::Drawing::Color::White;
			this->button28->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button28->Location = System::Drawing::Point(1104, 82);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(70, 300);
			this->button28->TabIndex = 27;
			this->button28->Text = L"P";
			this->button28->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &mainForm::button28_Click);
			// 
			// button29
			// 
			this->button29->BackColor = System::Drawing::Color::White;
			this->button29->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button29->Location = System::Drawing::Point(1035, 82);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(70, 300);
			this->button29->TabIndex = 26;
			this->button29->Text = L"O";
			this->button29->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &mainForm::button29_Click);
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::White;
			this->button30->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button30->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button30->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button30->Location = System::Drawing::Point(966, 82);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(70, 300);
			this->button30->TabIndex = 25;
			this->button30->Text = L"I";
			this->button30->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &mainForm::button30_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(14, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(371, 27);
			this->label1->TabIndex = 31;
			this->label1->Text = L"    Instrument : Acoustic Piano";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(658, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 27);
			this->label2->TabIndex = 32;
			this->label2->Text = L"    Octave : 48";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"³ª´®½ºÄù¾î ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(885, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 27);
			this->label3->TabIndex = 33;
			this->label3->Text = L"    Volume : 127";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1174, 382);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->HelpButton = true;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"mainForm";
			this->Text = L"Virtual Piano";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &mainForm::mainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &mainForm::mainForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		h_midi_device = midi_open(0);

		if (h_midi_device == NULL) return;

		midi_all_channel_sound_off(h_midi_device);

		midi_send_short_msg(h_midi_device, 0xB0, 7, volume);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		piano_key_on_off[0] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 0), velocity);
		piano_key_on_off[0] = 0;
	}
	private: System::Void mainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int local_volume = 0;
		int local_octave = 0;
		if (e->KeyCode == Keys(0x68))
		{
			if (volume < (NVOLUME - 1)) volume += 1;
			midi_send_short_msg(h_midi_device, 0xB0, 7, volume);
			local_volume = volume;
			string string1 = to_string(local_volume);
			String^ str2 = gcnew String(string1.c_str());
			this->label3->Text = "    Volume : " + str2;
		}
		else if (e->KeyCode == Keys(0x67))
		{
			if (volume != 0) volume -= 1;
			midi_send_short_msg(h_midi_device, 0xB0, 7, volume);
			local_volume = volume;
			string string1 = to_string(local_volume);
			String^ str2 = gcnew String(string1.c_str());
			this->label3->Text = "    Volume : " + str2;
		}
		else if (e->KeyCode == Keys(0x66)) {
			midi_all_channel_sound_off(h_midi_device);
		}
		else if (e->KeyCode == Keys(0x62))
		{
			if (instrument < (NINSTRUMENT - 1)) instrument += 1;
			midi_send_short_msg(h_midi_device, 0xC0, instrument, 0);
			string string1 = string(inst_name[instrument]);
			String^ str2 = gcnew String(string1.c_str());
			this->label1->Text = L"    Instrument : " + str2;
		}
		else if (e->KeyCode == Keys(0x61))
		{
			if (instrument != 0) instrument -= 1;
			midi_send_short_msg(h_midi_device, 0xC0, instrument, 0);
			string string1 = string(inst_name[instrument]);
			String^ str2 = gcnew String(string1.c_str());
			this->label1->Text = L"    Instrument : " + str2;
		}
		else if (e->KeyCode == Keys(0x65))
		{
			if (octave < (NNOTE - NKEY)) octave += 12;
			local_octave = octave;
			string string1 = to_string(local_octave);
			String^ str2 = gcnew String(string1.c_str());
			this->label2->Text = L"    Octave : " + str2;
		}
		else if (e->KeyCode == Keys(0x64))
		{
			if (octave != 0) octave -= 12;
			local_octave = octave;
			string string1 = to_string(local_octave);
			String^ str2 = gcnew String(string1.c_str());
			this->label2->Text = L"    Octave : " + str2;
		}
		else {
			for (key = 0; key < NKEY; key++) {
				if (e->KeyCode == Keys(piano_key[key]))
					if (piano_key_on_off[key] == 0)
					{

						piano_key_on_off[key] = 1;
						midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + key), velocity);
					}
			}
		}
	}
	private: System::Void mainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		for (key = 0; key < NKEY; key++) {
			if (e->KeyCode == Keys(piano_key[key])) {
				if (piano_key_on_off[key] != 0)
				{
					piano_key_on_off[key] = 0;
					midi_send_short_msg(h_midi_device, 0x80, (BYTE)(octave + key), velocity);
				}
			}
		}
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		piano_key_on_off[1] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 1), velocity);
		piano_key_on_off[1] = 0;
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[2] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 2), velocity);
	piano_key_on_off[2] = 0;
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[3] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 3), velocity);
	piano_key_on_off[3] = 0;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[4] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 4), velocity);
	piano_key_on_off[4] = 0;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[5] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 5), velocity);
	piano_key_on_off[5] = 0;
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[6] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 6), velocity);
	piano_key_on_off[6] = 0;
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[7] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 7), velocity);
	piano_key_on_off[7] = 0;
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[8] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 8), velocity);
	piano_key_on_off[8] = 0;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[9] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 9), velocity);
	piano_key_on_off[9] = 0;
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[10] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 10), velocity);
	piano_key_on_off[10] = 0;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[11] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 11), velocity);
	piano_key_on_off[11] = 0;
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[12] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 12), velocity);
	piano_key_on_off[12] = 0;
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[13] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 13), velocity);
	piano_key_on_off[13] = 0;
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[14] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 14), velocity);
	piano_key_on_off[14] = 0;
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[15] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 15), velocity);
	piano_key_on_off[15] = 0;
}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[16] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 16), velocity);
	piano_key_on_off[16] = 0;
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[17] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 17), velocity);
	piano_key_on_off[17] = 0;
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[18] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 18), velocity);
	piano_key_on_off[18] = 0;
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[19] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 19), velocity);
	piano_key_on_off[19] = 0;
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[20] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 20), velocity);
	piano_key_on_off[20] = 0;
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[21] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 21), velocity);
	piano_key_on_off[21] = 0;
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[22] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 22), velocity);
	piano_key_on_off[22] = 0;
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[23] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 23), velocity);
	piano_key_on_off[23] = 0;
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[24] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 24), velocity);
	piano_key_on_off[24] = 0;
}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[25] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 25), velocity);
	piano_key_on_off[25] = 0;
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[26] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 26), velocity);
	piano_key_on_off[26] = 0;
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[27] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 27), velocity);
	piano_key_on_off[27] = 0;
}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	piano_key_on_off[28] = 1;
	midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 28), velocity);
	piano_key_on_off[28] = 0;
}
};
}