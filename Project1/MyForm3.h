#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ about;
		MyForm3(void)
		{
			MyForm: System::Windows::Forms::Form^ home;
			about = home;
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;


	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(31, 146);
			this->label1->MaximumSize = System::Drawing::Size(500, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(500, 75);
			this->label1->TabIndex = 3;
			this->label1->Text = L"���� ������ ������� ��� ������ �� ������� ��� ���� , �� �������� ������ ������� �"
				L"��������� ���� ����������� ����� ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm3::label1_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 300);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm3";
			this->Text = L"���������� �� ����";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// ������ �� ������� �����
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Visible = false; // ������� �����
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}