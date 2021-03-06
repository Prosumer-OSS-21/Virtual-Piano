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

int small_star[10000] = { 1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100,1008,8,6,6,5,5,3,100,8,8,6,6,5,5,3,100,100,1,1,8,8,10,10,8,100,6,6,5,5,3,3,1,100, '\0' };
int school_bell[10000] = { 8,8,10,10,8,8,5,100,8,8,5,5,3,100,100,100,8,8,10,10,8,8,5,100,8,5,3,5,1,100,'\0' };
int hare[1000] = { 8,105,105,108,105,1,100,3,105,103,101,105,8,100,100,101,108,101,108,101,108,5,100,  8, 103,106,105,103,1,100,'\0' };
int bicycle[10000] = { 105 ,108, 8, 105,108,8 ,10,110,110,110,110,10 ,100,108,108,108,108 ,106,106,106,106, 105,105,105,105,5,100,105,108,108,108,105,108,8 ,110, 110 ,105,105,8,100,106,106,106,106, 105,105,105,105 ,103,103,108,108,1,'\0' };
int airplane[10000] = { 305 ,403, 1, 3, 5 ,5 ,105 ,100,3, 3, 3 ,5, 5, 105 ,100,305,403,1,3,5,5,105,100,3,3,305,403,501,'\0' };

namespace VirtualPiano {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// mainForm?? ???? ??????????.
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ?????? ?????? ?????? ??????????.
			//

		}

	protected:
		/// <summary>
		/// ???? ???? ???? ???????? ??????????.
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
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;



	protected:

	protected:

	private:
		/// <summary>
		/// ???? ???????? ??????????.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ???????? ?????? ?????? ????????????. 
		/// ?? ???????? ?????? ???? ???????? ???????? ??????.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainForm::typeid));
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->Location = System::Drawing::Point(0, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 300);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Z";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button2_MouseDown);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button3->Location = System::Drawing::Point(69, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 300);
			this->button3->TabIndex = 2;
			this->button3->Text = L"X";
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button3_MouseDown);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button4->Location = System::Drawing::Point(207, 82);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 300);
			this->button4->TabIndex = 4;
			this->button4->Text = L"V";
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button4_MouseDown);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button5->Location = System::Drawing::Point(138, 82);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 300);
			this->button5->TabIndex = 3;
			this->button5->Text = L"C";
			this->button5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button5_MouseDown);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button6->Location = System::Drawing::Point(414, 82);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 300);
			this->button6->TabIndex = 7;
			this->button6->Text = L"M";
			this->button6->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button6_MouseDown);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button7->Location = System::Drawing::Point(345, 82);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 300);
			this->button7->TabIndex = 6;
			this->button7->Text = L"N";
			this->button7->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button7_MouseDown);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button8->Location = System::Drawing::Point(276, 82);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 300);
			this->button8->TabIndex = 5;
			this->button8->Text = L"B";
			this->button8->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button8_MouseDown);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Black;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Location = System::Drawing::Point(49, 82);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(40, 180);
			this->button9->TabIndex = 8;
			this->button9->Text = L"S";
			this->button9->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button9->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button9_MouseDown);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Black;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Location = System::Drawing::Point(118, 82);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(40, 180);
			this->button10->TabIndex = 9;
			this->button10->Text = L"D";
			this->button10->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button10->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button10_MouseDown);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Black;
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Location = System::Drawing::Point(256, 82);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(40, 180);
			this->button11->TabIndex = 10;
			this->button11->Text = L"G";
			this->button11->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button11_MouseDown);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Black;
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button12->ForeColor = System::Drawing::Color::White;
			this->button12->Location = System::Drawing::Point(325, 82);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(40, 180);
			this->button12->TabIndex = 11;
			this->button12->Text = L"H";
			this->button12->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button12_MouseDown);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Black;
			this->button13->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button13->ForeColor = System::Drawing::Color::White;
			this->button13->Location = System::Drawing::Point(394, 82);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(40, 180);
			this->button13->TabIndex = 12;
			this->button13->Text = L"J";
			this->button13->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button13_MouseDown);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Black;
			this->button14->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button14->ForeColor = System::Drawing::Color::White;
			this->button14->Location = System::Drawing::Point(877, 82);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(40, 180);
			this->button14->TabIndex = 24;
			this->button14->Text = L"7";
			this->button14->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button14_MouseDown);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::Black;
			this->button15->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Location = System::Drawing::Point(808, 82);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(40, 180);
			this->button15->TabIndex = 23;
			this->button15->Text = L"6";
			this->button15->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button15->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button15_MouseDown);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::Black;
			this->button16->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button16->ForeColor = System::Drawing::Color::White;
			this->button16->Location = System::Drawing::Point(739, 82);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(40, 180);
			this->button16->TabIndex = 22;
			this->button16->Text = L"5";
			this->button16->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button16->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button16_MouseDown);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::Black;
			this->button17->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button17->ForeColor = System::Drawing::Color::White;
			this->button17->Location = System::Drawing::Point(601, 82);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(40, 180);
			this->button17->TabIndex = 21;
			this->button17->Text = L"3";
			this->button17->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button17->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button17_MouseDown);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::Black;
			this->button18->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button18->ForeColor = System::Drawing::Color::White;
			this->button18->Location = System::Drawing::Point(532, 82);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(40, 180);
			this->button18->TabIndex = 20;
			this->button18->Text = L"2";
			this->button18->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button18->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button18_MouseDown);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::White;
			this->button19->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button19->Location = System::Drawing::Point(897, 82);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(70, 300);
			this->button19->TabIndex = 19;
			this->button19->Text = L"U";
			this->button19->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button19->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button19_MouseDown);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::White;
			this->button20->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button20->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button20->Location = System::Drawing::Point(828, 82);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(70, 300);
			this->button20->TabIndex = 18;
			this->button20->Text = L"Y";
			this->button20->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button20->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button20_MouseDown);
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::White;
			this->button21->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button21->Location = System::Drawing::Point(759, 82);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(70, 300);
			this->button21->TabIndex = 17;
			this->button21->Text = L"T";
			this->button21->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button21_MouseDown);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::White;
			this->button22->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button22->Location = System::Drawing::Point(690, 82);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(70, 300);
			this->button22->TabIndex = 16;
			this->button22->Text = L"R";
			this->button22->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button22_MouseDown);
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::Color::White;
			this->button23->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button23->Location = System::Drawing::Point(621, 82);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(70, 300);
			this->button23->TabIndex = 15;
			this->button23->Text = L"E";
			this->button23->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button23_MouseDown);
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::White;
			this->button24->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button24->Location = System::Drawing::Point(552, 82);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(70, 300);
			this->button24->TabIndex = 14;
			this->button24->Text = L"W";
			this->button24->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button24_MouseDown);
			// 
			// button25
			// 
			this->button25->BackColor = System::Drawing::Color::White;
			this->button25->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button25->Location = System::Drawing::Point(483, 82);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(70, 300);
			this->button25->TabIndex = 13;
			this->button25->Text = L"Q";
			this->button25->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button25->UseVisualStyleBackColor = false;
			this->button25->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button25->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button25_MouseDown);
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::Black;
			this->button26->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button26->ForeColor = System::Drawing::Color::White;
			this->button26->Location = System::Drawing::Point(1084, 82);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(40, 180);
			this->button26->TabIndex = 29;
			this->button26->Text = L"0";
			this->button26->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button26->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button26_MouseDown);
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::Color::Black;
			this->button27->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button27->ForeColor = System::Drawing::Color::White;
			this->button27->Location = System::Drawing::Point(1015, 82);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(40, 180);
			this->button27->TabIndex = 28;
			this->button27->Text = L"9";
			this->button27->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button27->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button27_MouseDown);
			// 
			// button28
			// 
			this->button28->BackColor = System::Drawing::Color::White;
			this->button28->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button28->Location = System::Drawing::Point(1104, 82);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(70, 300);
			this->button28->TabIndex = 27;
			this->button28->Text = L"P";
			this->button28->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button28->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button28_MouseDown);
			// 
			// button29
			// 
			this->button29->BackColor = System::Drawing::Color::White;
			this->button29->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button29->Location = System::Drawing::Point(1035, 82);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(70, 300);
			this->button29->TabIndex = 26;
			this->button29->Text = L"O";
			this->button29->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button29->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button29_MouseDown);
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::White;
			this->button30->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button30->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->button30->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button30->Location = System::Drawing::Point(966, 82);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(70, 300);
			this->button30->TabIndex = 25;
			this->button30->Text = L"I";
			this->button30->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			this->button30->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainForm::button30_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"?????????? ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(14, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(371, 27);
			this->label1->TabIndex = 31;
			this->label1->Text = L"    Instrument : Acoustic Piano";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"?????????? ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(658, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 27);
			this->label2->TabIndex = 32;
			this->label2->Text = L"    Octave : 48";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"?????????? ExtraBold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(885, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 27);
			this->label3->TabIndex = 33;
			this->label3->Text = L"    Volume : 127";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(204, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 18);
			this->label5->TabIndex = 35;
			this->label5->Text = L"[F1] Little Star";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(360, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(132, 18);
			this->label6->TabIndex = 36;
			this->label6->Text = L"[F2] School Bell";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(519, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(137, 18);
			this->label7->TabIndex = 37;
			this->label7->Text = L"[F3] Jack Rabbit";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(687, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(81, 18);
			this->label8->TabIndex = 38;
			this->label8->Text = L"[F4] Bike";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"?????????? Bold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label9->Location = System::Drawing::Point(805, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(174, 18);
			this->label9->TabIndex = 39;
			this->label9->Text = L"[F5] Plane In The Sky";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1174, 382);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
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
		/*piano_key_on_off[0] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 0), velocity);
		piano_key_on_off[0] = 0;*/
		for (key = 0; key < NKEY; key++) {
			if (piano_key_on_off[key] != 0)
			{
				piano_key_on_off[key] = 0;
				midi_send_short_msg(h_midi_device, 0x80, (BYTE)(octave + key), velocity);
			}
		}
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
		else if (e->KeyCode == Keys(0x70)) {
			Sleep(500);
			music_note(h_midi_device, small_star, velocity, octave / 12);
		}
		else if (e->KeyCode == Keys(0x71)) {
			Sleep(500);
			music_note(h_midi_device, school_bell, velocity, octave / 12);
		}
		else if (e->KeyCode == Keys(0x72)) {
			Sleep(500);
			music_note(h_midi_device, hare, velocity, octave / 12);
		}
		else if (e->KeyCode == Keys(0x73)) {
			Sleep(500);
			music_note(h_midi_device, bicycle, velocity, octave / 12);
		}
		else if (e->KeyCode == Keys(0x74)) {
			Sleep(500);
			music_note(h_midi_device, airplane, velocity, octave / 12);
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
	private: System::Void button9_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[1] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 1), velocity);
	}
	private: System::Void button3_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[2] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 2), velocity);
	}
	private: System::Void button10_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[3] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 3), velocity);
	}
	private: System::Void button5_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[4] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 4), velocity);
	}
	private: System::Void button4_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[5] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 5), velocity);
	}
	private: System::Void button11_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[6] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 6), velocity);
	}
	private: System::Void button8_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[7] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 7), velocity);
	}
	private: System::Void button12_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[8] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 8), velocity);
	}
	private: System::Void button7_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[9] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 9), velocity);
	}
	private: System::Void button13_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[10] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 10), velocity);
	}
	private: System::Void button6_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[11] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 11), velocity);
	}
	private: System::Void button25_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[12] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 12), velocity);
	}
	private: System::Void button18_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[13] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 13), velocity);
	}
	private: System::Void button24_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[14] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 14), velocity);
	}
	private: System::Void button17_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[15] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 15), velocity);
	}
	private: System::Void button23_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[16] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 16), velocity);
	}
	private: System::Void button22_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[17] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 17), velocity);
	}
	private: System::Void button16_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[18] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 18), velocity);
	}
	private: System::Void button21_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[19] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 19), velocity);
	}
	private: System::Void button15_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[20] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 20), velocity);
	}
	private: System::Void button20_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[21] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 21), velocity);
	}
	private: System::Void button14_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[22] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 22), velocity);
	}
	private: System::Void button19_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[23] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 23), velocity);
	}
	private: System::Void button30_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[24] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 24), velocity);
	}
	private: System::Void button27_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[25] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 25), velocity);
	}
	private: System::Void button29_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[26] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 26), velocity);
	}
	private: System::Void button26_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[27] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 27), velocity);
	}
	private: System::Void button28_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[28] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 28), velocity);
	}
	private: System::Void button2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		piano_key_on_off[0] = 1;
		midi_send_short_msg(h_midi_device, 0x90, (BYTE)(octave + 0), velocity);
	}
	};
}