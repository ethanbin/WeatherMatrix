#pragma once
#include"Matrix.h"
#include<string>
#include<fstream>

namespace WeatherMatrix {
	Matrix WeatherMatrix;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(std::string arg0)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			std::ifstream WeatherMatrixFile;
			WeatherMatrixFile.open(arg0);

			if (!WeatherMatrixFile.is_open())
			{
				MessageBox::Show("ERROR: File not found!");
				exit(EXIT_SUCCESS);
			}

			std::string lineCollector;
			int numLines=0;
			//for (; WeatherMatrixFile.eof(); numLines++) { getline(WeatherMatrixFile, lineCollector); }
			//WeatherMatrix.resize(numLines);




			WeatherMatrixFile.close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::ComboBox^  monthBox;
	private: System::Windows::Forms::NumericUpDown^  yearBox;
	private: System::Windows::Forms::Button^  avgMonthEvent;
	private: System::Windows::Forms::Button^  avgYearEvent;


	private: System::Windows::Forms::Button^  highestMonthEvent;
	private: System::Windows::Forms::Button^  highestYearEvent;
	private: System::Windows::Forms::Button^  dateTempEvent;



	private: System::Windows::Forms::TextBox^  outputBox;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->monthBox = (gcnew System::Windows::Forms::ComboBox());
			this->yearBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->avgMonthEvent = (gcnew System::Windows::Forms::Button());
			this->avgYearEvent = (gcnew System::Windows::Forms::Button());
			this->highestMonthEvent = (gcnew System::Windows::Forms::Button());
			this->highestYearEvent = (gcnew System::Windows::Forms::Button());
			this->dateTempEvent = (gcnew System::Windows::Forms::Button());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearBox))->BeginInit();
			this->SuspendLayout();
			// 
			// monthBox
			// 
			this->monthBox->FormattingEnabled = true;
			this->monthBox->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"January", L"Febrary", L"March", L"April", L"May",
					L"June", L"July", L"August", L"September", L"October", L"November", L"December"
			});
			this->monthBox->Location = System::Drawing::Point(15, 18);
			this->monthBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->monthBox->Name = L"monthBox";
			this->monthBox->Size = System::Drawing::Size(140, 26);
			this->monthBox->TabIndex = 1;
			this->monthBox->Text = L"Select Month";
			// 
			// yearBox
			// 
			this->yearBox->Location = System::Drawing::Point(181, 19);
			this->yearBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->yearBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2016, 0, 0, 0 });
			this->yearBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1869, 0, 0, 0 });
			this->yearBox->Name = L"yearBox";
			this->yearBox->Size = System::Drawing::Size(140, 23);
			this->yearBox->TabIndex = 2;
			this->yearBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1869, 0, 0, 0 });
			// 
			// avgMonthEvent
			// 
			this->avgMonthEvent->Location = System::Drawing::Point(15, 53);
			this->avgMonthEvent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->avgMonthEvent->Name = L"avgMonthEvent";
			this->avgMonthEvent->Size = System::Drawing::Size(141, 72);
			this->avgMonthEvent->TabIndex = 3;
			this->avgMonthEvent->Text = L"Search Average Temperature of a Month from Each Year";
			this->avgMonthEvent->UseVisualStyleBackColor = true;
			this->avgMonthEvent->Click += gcnew System::EventHandler(this, &MyForm::avgMonthEvent_Click);
			// 
			// avgYearEvent
			// 
			this->avgYearEvent->Location = System::Drawing::Point(179, 53);
			this->avgYearEvent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->avgYearEvent->Name = L"avgYearEvent";
			this->avgYearEvent->Size = System::Drawing::Size(141, 72);
			this->avgYearEvent->TabIndex = 4;
			this->avgYearEvent->Text = L"Find Average Temperature of Given Year";
			this->avgYearEvent->UseVisualStyleBackColor = true;
			this->avgYearEvent->Click += gcnew System::EventHandler(this, &MyForm::avgYearEvent_Click);
			// 
			// highestMonthEvent
			// 
			this->highestMonthEvent->Location = System::Drawing::Point(15, 137);
			this->highestMonthEvent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->highestMonthEvent->Name = L"highestMonthEvent";
			this->highestMonthEvent->Size = System::Drawing::Size(141, 72);
			this->highestMonthEvent->TabIndex = 5;
			this->highestMonthEvent->Text = L"Find Highest Temperature of a Month for Each Year";
			this->highestMonthEvent->UseVisualStyleBackColor = true;
			this->highestMonthEvent->Click += gcnew System::EventHandler(this, &MyForm::highestMonthEvent_Click);
			// 
			// highestYearEvent
			// 
			this->highestYearEvent->Location = System::Drawing::Point(179, 137);
			this->highestYearEvent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->highestYearEvent->Name = L"highestYearEvent";
			this->highestYearEvent->Size = System::Drawing::Size(141, 72);
			this->highestYearEvent->TabIndex = 6;
			this->highestYearEvent->Text = L"Find Highest Monthly Temperate Within a Year";
			this->highestYearEvent->UseVisualStyleBackColor = true;
			this->highestYearEvent->Click += gcnew System::EventHandler(this, &MyForm::highestYearEvent_Click);
			// 
			// dateTempEvent
			// 
			this->dateTempEvent->Location = System::Drawing::Point(97, 217);
			this->dateTempEvent->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dateTempEvent->Name = L"dateTempEvent";
			this->dateTempEvent->Size = System::Drawing::Size(141, 72);
			this->dateTempEvent->TabIndex = 7;
			this->dateTempEvent->Text = L"Find Month\'s Average Temperature for the Given Year";
			this->dateTempEvent->UseVisualStyleBackColor = true;
			this->dateTempEvent->Click += gcnew System::EventHandler(this, &MyForm::dateTempEvent_Click);
			// 
			// outputBox
			// 
			this->outputBox->Enabled = false;
			this->outputBox->Location = System::Drawing::Point(14, 299);
			this->outputBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->outputBox->Name = L"outputBox";
			this->outputBox->Size = System::Drawing::Size(308, 23);
			this->outputBox->TabIndex = 8;
			this->outputBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 343);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->dateTempEvent);
			this->Controls->Add(this->highestYearEvent);
			this->Controls->Add(this->highestMonthEvent);
			this->Controls->Add(this->avgYearEvent);
			this->Controls->Add(this->avgMonthEvent);
			this->Controls->Add(this->yearBox);
			this->Controls->Add(this->monthBox);
			this->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void avgMonthEvent_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void highestMonthEvent_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void avgYearEvent_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void highestYearEvent_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dateTempEvent_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
