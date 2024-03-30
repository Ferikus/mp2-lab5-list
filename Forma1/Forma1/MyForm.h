#pragma once
#include <vector>
#include "../../mp2-lab5-list/Polynomial.h";
#include "../../mp2-lab5-list/Calculation.h";

//using namespace std;

namespace Forma1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		std::vector<TPolynomial>* v;
		int Counter;
		// ќбъ€вить массивы label Numeration Operation?

	private: System::Windows::Forms::Label^ labelPolynomial;
	private: System::Windows::Forms::Label^ labelOperation;
	private: System::Windows::Forms::TextBox^ textBoxPolynomial;
	private: System::Windows::Forms::TextBox^ textBoxOperation;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonExecute;

	private: System::Windows::Forms::Panel^ panel1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gr = CreateGraphics();
			Counter = 0;

			v = new std::vector<TPolynomial>;

		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelPolynomial = (gcnew System::Windows::Forms::Label());
			this->labelOperation = (gcnew System::Windows::Forms::Label());
			this->textBoxPolynomial = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOperation = (gcnew System::Windows::Forms::TextBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonExecute = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// labelPolynomial
			// 
			this->labelPolynomial->AutoSize = true;
			this->labelPolynomial->Location = System::Drawing::Point(27, 30);
			this->labelPolynomial->Name = L"labelPolynomial";
			this->labelPolynomial->Size = System::Drawing::Size(68, 15);
			this->labelPolynomial->TabIndex = 0;
			this->labelPolynomial->Text = L"Polynomial";
			// 
			// labelOperation
			// 
			this->labelOperation->AutoSize = true;
			this->labelOperation->Location = System::Drawing::Point(30, 65);
			this->labelOperation->Name = L"labelOperation";
			this->labelOperation->Size = System::Drawing::Size(61, 15);
			this->labelOperation->TabIndex = 1;
			this->labelOperation->Text = L"Operation";
			// 
			// textBoxPolynomial
			// 
			this->textBoxPolynomial->Location = System::Drawing::Point(119, 27);
			this->textBoxPolynomial->Name = L"textBoxPolynomial";
			this->textBoxPolynomial->Size = System::Drawing::Size(587, 21);
			this->textBoxPolynomial->TabIndex = 2;
			// 
			// textBoxOperation
			// 
			this->textBoxOperation->Location = System::Drawing::Point(119, 62);
			this->textBoxOperation->Name = L"textBoxOperation";
			this->textBoxOperation->Size = System::Drawing::Size(587, 21);
			this->textBoxOperation->TabIndex = 3;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(739, 25);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 4;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::button_add);
			// 
			// buttonExecute
			// 
			this->buttonExecute->Location = System::Drawing::Point(739, 60);
			this->buttonExecute->Name = L"buttonExecute";
			this->buttonExecute->Size = System::Drawing::Size(75, 23);
			this->buttonExecute->TabIndex = 5;
			this->buttonExecute->Text = L"Execute";
			this->buttonExecute->UseVisualStyleBackColor = true;
			this->buttonExecute->Click += gcnew System::EventHandler(this, &MyForm::button_execute);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(33, 102);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(781, 427);
			this->panel1->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(848, 557);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonExecute);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxOperation);
			this->Controls->Add(this->textBoxPolynomial);
			this->Controls->Add(this->labelOperation);
			this->Controls->Add(this->labelPolynomial);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Polynomial Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void MarshalString(String^ s, std::string& os) { // String^ -> string
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: void ProcessPolynomial(std::string& ptext) {
		// пока без сортировки
		// через стек сделать ptext -> TPolynomial
		// TPolynomial записать в string в корректном виде
		// TPolynomial положить в vector<...> v

		TCalc tmp(ptext); // вспомогательный объект
		TPolynomial p = tmp.toPolynomial(); // переформатировали в полином
		ptext = p.outputPolynomial(); // ptext обновлЄн
		(*v).push_back(p);
	}
	private: System::Void button_add(System::Object^ sender, System::EventArgs^ e) {

		if (textBoxPolynomial->Text == "" || Counter > 17) {}
		else {

			//нумераци€
			System::Windows::Forms::Label^ labelNumeration = gcnew System::Windows::Forms::Label();
			System::String^ number = Counter.ToString();
			labelNumeration->Text = number;
			labelNumeration->TextAlign = ContentAlignment::MiddleCenter;
			labelNumeration->BackColor = System::Drawing::Color::LightSteelBlue; // ÷вет фона
			labelNumeration->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // √раница
			labelNumeration->Padding = System::Windows::Forms::Padding(0, 2, 0, 2);
			labelNumeration->Location = System::Drawing::Point(this->panel1->Location.X, this->panel1->Location.Y + Counter * labelNumeration->Height);
			labelNumeration->MinimumSize = System::Drawing::Size(36, 21);
			labelNumeration->MaximumSize = System::Drawing::Size(36, 21);
			labelNumeration->AutoSize = true;
			this->Controls->Add(labelNumeration);
			labelNumeration->BringToFront();

			//вывод полинома
			System::Windows::Forms::Label^ labelOutput = gcnew System::Windows::Forms::Label();
			std::string ptext;
			MarshalString(textBoxPolynomial->Text, ptext);
			ProcessPolynomial(ptext);
			labelOutput->Text = gcnew System::String(ptext.c_str());
			labelOutput->TextAlign = ContentAlignment::MiddleCenter;
			labelOutput->BackColor = System::Drawing::Color::Lavender; // ÷вет фона
			labelOutput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // √раница
			labelOutput->Padding = System::Windows::Forms::Padding(0, 2, 0, 2);
			labelOutput->Location = System::Drawing::Point(this->panel1->Location.X + 35, this->panel1->Location.Y + Counter * labelOutput->Height);
			labelOutput->MinimumSize = System::Drawing::Size(746, 21);
			labelOutput->MaximumSize = System::Drawing::Size(746, 21);
			labelOutput->AutoSize = true;
			this->Controls->Add(labelOutput);
			labelOutput->BringToFront();

			Counter++;

		}
	}
	private: System::Void button_execute(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

