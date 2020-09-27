#pragma once
#pragma comment(lib,"ws2_32.lib")
#include<windows.h>
#include<string>
#include<iostream>


namespace kagge {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	SOCKET s;
	/// <summary>
	/// Zusammenfassung für Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse ändern, müssen Sie auch
	///          die Ressourcendateiname-Eigenschaft für das Tool zur Kompilierung verwalteter Ressourcen ändern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abhängt.
	///          Anderenfalls können die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();


			WSADATA w;
			::WSAStartup(MAKEWORD(1,1),&w);

			timer1->Start();


		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 11);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(1299, 614);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(226, 631);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(1021, 20);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1251, 632);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 19);
			this->button1->TabIndex = 2;
			this->button1->Text = L"senden";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(10, 631);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"127.0.0.1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(90, 631);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(24, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"1";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(121, 630);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(75, 20);
			this->textBox5->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1320, 662);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				String ^a = Convert::ToString(textBox5->Text + ": " + textBox2->Text);
				textBox2->Text = "";
				String ^c = Convert::ToString(textBox3->Text);
				String ^b = Convert::ToString(textBox4->Text);
				IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(c);
				char* cs = static_cast<char*>(ptrToNativeString.ToPointer());
				ptrToNativeString = Marshal::StringToHGlobalAnsi(b);
				char* bs = static_cast<char*>(ptrToNativeString.ToPointer());
				ptrToNativeString = Marshal::StringToHGlobalAnsi(a);
				char* as = static_cast<char*>(ptrToNativeString.ToPointer());
				s=socket(AF_INET,1,0);
				sockaddr_in info;
				int l=sizeof(info);
				info.sin_family=AF_INET;
				info.sin_addr.S_un.S_addr=inet_addr(cs);
				info.sin_port=htons(atoi(bs));
				connect(s,(sockaddr*)&info,l);
				int i=WSAGetLastError();
				send(s,"s",1,0);
				recv(s,0,0,0);
				send(s,as,a->Length,0);
				textBox2->Focus();
			 }

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				textBox1->Text=gcnew String("test");
				s=socket(AF_INET,1,0);
				sockaddr_in info;
				int l=sizeof(info);
				info.sin_family=AF_INET;
				String ^c = Convert::ToString(textBox3->Text);
				String ^b = Convert::ToString(textBox4->Text);
				IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(c);
				char* cs = static_cast<char*>(ptrToNativeString.ToPointer());
				ptrToNativeString = Marshal::StringToHGlobalAnsi(b);
				char* bs = static_cast<char*>(ptrToNativeString.ToPointer());
				info.sin_addr.S_un.S_addr=inet_addr(cs);
				info.sin_port=htons(atoi(bs));
				connect(s,(sockaddr*)&info,l);
				send(s,"g",1,0);
				char buf[10000]={0};
				recv(s,buf,10000,0);
				std::string temp(buf);
				String ^a = gcnew String(temp.c_str());
				textBox1->Text=a;
		 }
};
}

