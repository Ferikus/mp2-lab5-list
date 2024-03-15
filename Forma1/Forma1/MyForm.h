#pragma once
//#include "../../Queue/Queue.h"

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
		/*int MaxSize, Size;
		double P, Q;
		int PushCount, PopCount;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;
		bool flag;
	private: System::Windows::Forms::TextBox^ textBox_maxsize;
	private: System::Windows::Forms::Label^ label_maxsize;

	private: System::Windows::Forms::Button^ button_close;

	private: System::Windows::Forms::Label^ label_size;
	private: System::Windows::Forms::TextBox^ textBox_size;

	private: System::Windows::Forms::Label^ label_p;
	private: System::Windows::Forms::TextBox^ textBox_p;

	private: System::Windows::Forms::Label^ label_q;
	private: System::Windows::Forms::TextBox^ textBox_q;

	private: System::Windows::Forms::Button^ button_stop;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label_PopCount;


	private: System::Windows::Forms::Label^ label_PushCount;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_pushedres;
	private: System::Windows::Forms::Label^ label_poppedres;
	private: System::Windows::Forms::Label^ label_cursizeres;
	private: System::Windows::Forms::Label^ label_err;*/



	private: System::Windows::Forms::Button^ button_go;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gr = CreateGraphics();
			/*rnd1 = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			CenterX = 400;
			CenterY = 350;
			Width = Height = 200;

			PopCount = PushCount = 0;
			flag = 0;*/
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
	protected:

	protected:

	protected:

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
			this->components = (gcnew System::ComponentModel::Container());
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Queue Circle Buffer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*private: System::Void button_close_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}*/
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}