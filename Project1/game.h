#pragma once
#include <time.h>
#include <stdlib.h>
#include <string>


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class CustomButton : public System::Windows::Forms::Button
	{
	public:
		int customproperty = 0;
		int x = 0;
		int y = 0;
		static int a = 0;
		static array<array<CustomButton^>^>^ sap;
		static bool check = 0;
		static int cou = 0;
		
	public:
		CustomButton(int i, int j)
		{
			InitializeComponent(i, j);
			//
			//TODO: добавьте код конструктора
			//

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CustomButton()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

		void InitializeComponent(int i, int j) {
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ForeColor = System::Drawing::Color::Red;
			this->x = i;
			this->y = j;
			this->Name = L"button4";
			this->Size = System::Drawing::Size(50, 50);
			this->TabIndex = 4;
			this->TabStop = false;
			this->UseVisualStyleBackColor = false;
			this->Visible = true;
			this->Click += gcnew System::EventHandler(this, &CustomButton::CustomButton_Click);
			
		}
	private:
		System::Void CustomButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Press();
		}
		void Press(){
			int k = 0;
			
			this->Enabled = false;
			if (!this->check) {
				this->bomb();
			}
			if (this->customproperty) {
				this->Lose();
				return;
			}
			this->cou--;
			for (int i = (this->x)-1;i <= (this->x)+1;i++)
				for (int j = this->y - 1; j <= this->y + 1; j++)
				{
				
					if (i >= 0 && i < this->a && j >= 0 && j < this->a) {
						if (this->sap[i][j]->customproperty != 0)
						{
							k++;

						}
					}
				
				}
			if (k==0)
				this->Text = System::Convert::ToString("");
			else
				this->Text = System::Convert::ToString(k);
			if (k == 0) {
				for (int i = (this->x) - 1; i <= (this->x) + 1; i++)
					for (int j = this->y - 1; j <= this->y + 1; j++) 
						if (i!=this->x || j !=this->y)
							if (i >= 0 && i < this->a && j >= 0 && j < this->a)
								if (sap[i][j]->Enabled)
									this->sap[i][j]->Press();
					
			}
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			if (!cou)
				this->Win();
			
				
			}
			
		
		void bomb() {
			this->check = 1;
			int k = 9;
			this->cou = a*a - k ;
			srand(time(NULL));
			while (k > 0) {
				CustomButton^ ran = this->sap[rand() % this->a][rand() % this->a];
				if (!ran->customproperty && (abs(ran->x -  this->x) > 1 || abs(ran->y - this->y) > 1)) {
					ran->customproperty = 1;
					k--;

				}
			}
		}
		public: Void Lose()
		{
			for (int i = 0; i < this->a; i++)
				for (int j = 0; j < this->a; j++) {
					sap[i][j]->Enabled = false;
					//sap[i][j]->Text = "";
					if(sap[i][j]->customproperty)
					sap[i][j]->BackColor = System::Drawing::Color::Red;
			}
	};
		public: Void Restart()
		{
			for (int i = 0; i < this->a; i++)
				for (int j = 0; j < this->a; j++) {
					sap[i][j]->BackColor = System::Drawing::SystemColors::Control;
					sap[i][j]->ForeColor = System::Drawing::Color::Red;
					sap[i][j]->Enabled = true;
					sap[i][j]->customproperty = 0;
					sap[i][j]->Text = "";

				}
			this->check = 0;
			
		}
	public: Void Win()
	{
		
		for (int i = 0; i < this->a; i++)
			for (int j = 0; j < this->a; j++) {
				sap[i][j]->Enabled = false;
				//sap[i][j]->Text = "";
				if (sap[i][j]->customproperty)
					sap[i][j]->BackColor = System::Drawing::Color::Red;
			}
	};
	};




	public ref class Sapper_Handle : public System::Windows::Forms::Control
	{
	public:
		
		Sapper_Handle(int a)
		{
			InitializeComponent(a);
			//
			//TODO: добавьте код конструктора
			//

		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Sapper_Handle()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ RestartB;
	private: int buttonspressed = 0;
	private: array<array<CustomButton^>^>^ sap;
		   /// <summary>
		   /// Обязательная переменная конструктора.
		   /// </summary>
		   System::ComponentModel::Container^ components;

		   void InitializeComponent(int a) {
			   
			   this->Visible = true;
			   this->Size = System::Drawing::Size(500, 500);
			   this->Location = System::Drawing::Point(300, 300);

			   sap = gcnew array<array<CustomButton^>^>(a);

			   for (int i = 0; i < a; i++) {
				   sap[i] = gcnew array<CustomButton^>(a);
				   for (int j = 0; j < a; j++) {
					    sap[i][j] = gcnew CustomButton(i, j);
					    sap[i][j]->Location = System::Drawing::Point(i * 50, j * 50);
						sap[i][j]->x = i;
						sap[i][j]->y = j;
						sap[i][j]->a = a;
						sap[i][j]->sap = sap;
					    this->Controls->Add(sap[i][j]);
				   }
			   }
			   this->RestartB = gcnew System::Windows::Forms::Button();
			   // 
			   // RestartB
			   // 
			   this->RestartB->Location = System::Drawing::Point(392, 258);
			   this->RestartB->Name = L"RestartB";
			   this->RestartB->Size = System::Drawing::Size(75, 26);
			   this->RestartB->TabIndex = 40;
			   this->RestartB->Text = L"перезапуск";
			   this->RestartB->UseVisualStyleBackColor = true;
			   this->RestartB->Visible = true;
			   this->RestartB->Click += gcnew System::EventHandler(this, &Sapper_Handle::RestartB_Click);
			   this->Controls->Add(this->RestartB);
		   }
	private: System::Void RestartB_Click(System::Object^ sender, System::EventArgs^ e) {
				sap[0][0]->Restart();	
			
		
	}
	};
}
	
	
			/*if (fr[2] == 1)
			{
				button2->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[3] == 1)
					k++;
				if (fr[8] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (k == 0)
				{
					if (button3->Enabled == true)
						Press(3);
					if (button8->Enabled == true)
						Press(8);
					if (sender->Enabled == true)
						Press(9);
				}

			}
			if (k != 0)
			{
				sender->Text = System::Convert::ToString(k);
			}*/
		
		

/*
* // 
			// RestartB
			// 
			this->RestartB->Location = System::Drawing::Point(392, 258);
			this->RestartB->Name = L"RestartB";
			this->RestartB->Size = System::Drawing::Size(75, 26);
			this->RestartB->TabIndex = 40;
			this->RestartB->Text = L"перезапуск";
			this->RestartB->UseVisualStyleBackColor = true;
			this->RestartB->Visible = false;
			this->RestartB->Click += gcnew System::EventHandler(this, &MyForm::RestartB_Click);
			

		

		


public: Void Lose()
	{
		RestartB->Visible = true;
		if (button2->Enabled == true)
		{
			button2->Enabled = false;
			button2->Text = "";
			if (fr[2] == 1)
				button2->BackColor = System::Drawing::Color::Red;
		}
		if (button3->Enabled == true)
		{
			button3->Enabled = false;
			button3->Text = "";
			if (fr[3] == 1)
				button3->BackColor = System::Drawing::Color::Red;
		}
		
		if (button36->Enabled == true)
		{
			button36->Enabled = false;
			button36->Text = "";
			if (fr[36] == 1)
				button36->BackColor = System::Drawing::Color::Red;
		}
		if (button37->Enabled == true)
		{
			button37->Enabled = false;
			button37->Text = "";
			if (fr[37] == 1)
				button37->BackColor = System::Drawing::Color::Red;
		}
	}
	public: Void Win()
	{
		RestartB->Visible = true;
		if (fr[2] == 1)
		{
			button2->Enabled = false;
			button2->BackColor = System::Drawing::Color::Red;
			button2->Text = "";
		}
		if (fr[3] == 1)
		{
			button3->Enabled = false;
			button3->BackColor = System::Drawing::Color::Red;
			button3->Text = "";
		}
		
		if (fr[37] == 1)
		{
			button37->Enabled = false;
			button37->BackColor = System::Drawing::Color::Red;
			button37->Text = "";
		}
	}

	public: Void Press(int x)
	{
		buttonspressed++;
		int k = 0;
		if (x == 2)
		{
			button2->Enabled = false;
			button2->Text = "";
			if (fr[2] == 1)
			{
				button2->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[3] == 1)
					k++;
				if (fr[8] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (k == 0)
				{
					if (button3->Enabled == true)
						Press(3);
					if (button8->Enabled == true)
						Press(8);
					if (button9->Enabled == true)
						Press(9);
				}

			}
			if (k != 0)
			{
				button2->Text = System::Convert::ToString(k);
			}
		}
		if (x == 3)
		{
			button3->Enabled = false;
			button3->Text = "";
			if (fr[3] == 1)
			{
				button3->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button3->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[2] == 1)
					k++;
				if (fr[4] == 1)
					k++;
				if (fr[8] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (k == 0)
				{
					if (button2->Enabled == true)
						Press(2);
					if (button4->Enabled == true)
						Press(4);
					if (button8->Enabled == true)
						Press(8);
					if (button9->Enabled == true)
						Press(9);
					if (button10->Enabled == true)
						Press(10);
				}

			}
			if (k != 0)
			{
				button3->Text = System::Convert::ToString(k);
			}
		}
		if (x == 4)
		{
			button4->Enabled = false;
			button4->Text = "";
			if (fr[4] == 1)
			{
				button4->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button4->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[3] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[5] == 1)
					k++;
				if (k == 0)
				{
					if (button3->Enabled == true)
						Press(3);
					if (button9->Enabled == true)
						Press(9);
					if (button10->Enabled == true)
						Press(10);
					if (button11->Enabled == true)
						Press(11);
					if (button5->Enabled == true)
						Press(5);
				}

			}
			if (k != 0)
			{
				button4->Text = System::Convert::ToString(k);
			}
		}
		if (x == 5)
		{
			button5->Enabled = false;
			button5->Text = "";
			if (fr[5] == 1)
			{
				button5->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button5->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[4] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[6] == 1)
					k++;
				if (k == 0)
				{
					if (button4->Enabled == true)
						Press(4);
					if (button10->Enabled == true)
						Press(10);
					if (button11->Enabled == true)
						Press(11);
					if (button12->Enabled == true)
						Press(12);
					if (button6->Enabled == true)
						Press(6);
				}

			}
			if (k != 0)
			{
				button5->Text = System::Convert::ToString(k);
			}
		}
		if (x == 6)
		{
			button6->Enabled = false;
			button6->Text = "";
			if (fr[6] == 1)
			{
				button6->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button6->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[5] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[13] == 1)
					k++;
				if (fr[7] == 1)
					k++;
				if (k == 0)
				{
					if (button5->Enabled == true)
						Press(5);
					if (button11->Enabled == true)
						Press(11);
					if (button12->Enabled == true)
						Press(12);
					if (button13->Enabled == true)
						Press(13);
					if (button7->Enabled == true)
						Press(7);
				}

			}
			if (k != 0)
			{
				button6->Text = System::Convert::ToString(k);
			}
		}
		if (x == 7)
		{
			button7->Enabled = false;
			button7->Text = "";
			if (fr[7] == 1)
			{
				button7->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button7->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[6] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[13] == 1)
					k++;
				if (k == 0)
				{
					if (button6->Enabled == true)
						Press(6);
					if (button12->Enabled == true)
						Press(12);
					if (button13->Enabled == true)
						Press(13);
				}

			}
			if (k != 0)
			{
				button7->Text = System::Convert::ToString(k);
			}
		}
		if (x == 8)
		{
			button8->Enabled = false;
			button8->Text = "";
			if (fr[8] == 1)
			{
				button8->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button8->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[2] == 1)
					k++;
				if (fr[3] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[14] == 1)
					k++;
				if (k == 0)
				{
					if (button2->Enabled == true)
						Press(2);
					if (button3->Enabled == true)
						Press(3);
					if (button9->Enabled == true)
						Press(9);
					if (button15->Enabled == true)
						Press(15);
					if (button14->Enabled == true)
						Press(14);
				}

			}
			if (k != 0)
			{ 
				button8->Text = System::Convert::ToString(k);
			}

		}
		if (x == 9)
		{
			button9->Enabled = false;
			button9->Text = "";
			if (fr[9] == 1)
			{
				button9->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button9->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[2] == 1)
					k++;
				if (fr[3] == 1)
					k++;
				if (fr[4] == 1)
					k++;
				if (fr[8] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[14] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (k == 0)
				{
					if (button2->Enabled == true)
						Press(2);
					if (button3->Enabled == true)
						Press(3);
					if (button4->Enabled == true)
						Press(4);
					if (button8->Enabled == true)
						Press(8);
					if (button10->Enabled == true)
						Press(10);
					if (button14->Enabled == true)
						Press(14);
					if (button15->Enabled == true)
						Press(15);
					if (button16->Enabled == true)
						Press(16);
				}
			}
			if (k != 0)
			{
				button9->Text = System::Convert::ToString(k);
			}
		}
		if (x == 10)
		{
			button10->Enabled = false;
			button10->Text = "";
			if (fr[10] == 1)
			{
				button10->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button10->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[3] == 1)
					k++;
				if (fr[4] == 1)
					k++;
				if (fr[5] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (k == 0)
				{
					if (button3->Enabled == true)
						Press(3);
					if (button4->Enabled == true)
						Press(4);
					if (button5->Enabled == true)
						Press(5);
					if (button9->Enabled == true)
						Press(9);
					if (button11->Enabled == true)
						Press(11);
					if (button15->Enabled == true)
						Press(15);
					if (button16->Enabled == true)
						Press(16);
					if (button17->Enabled == true)
						Press(17);
				}

			}
			if (k != 0)
			{
				button10->Text = System::Convert::ToString(k);
			}

		}
		if (x == 11)
		{
			button11->Enabled = false;
			button11->Text = "";
			if (fr[11] == 1)
			{
				button11->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button11->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[4] == 1)
					k++;
				if (fr[5] == 1)
					k++;
				if (fr[6] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (k == 0)
				{
					if (button4->Enabled == true)
						Press(4);
					if (button5->Enabled == true)
						Press(5);
					if (button6->Enabled == true)
						Press(6);
					if (button10->Enabled == true)
						Press(10);
					if (button12->Enabled == true)
						Press(12);
					if (button16->Enabled == true)
						Press(16);
					if (button17->Enabled == true)
						Press(17);
					if (button18->Enabled == true)
						Press(18);
				}
			}
			if (k != 0)
			{
				button11->Text = System::Convert::ToString(k);
			}
		}
		if (x == 12)
		{
			button12->Enabled = false;
			button12->Text = "";
			if (fr[12] == 1)
			{
				button12->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button12->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[5] == 1)
					k++;
				if (fr[6] == 1)
					k++;
				if (fr[7] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[13] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[19] == 1)
					k++;
				if (k == 0)
				{
					if (button5->Enabled == true)
						Press(5);
					if (button6->Enabled == true)
						Press(6);
					if (button7->Enabled == true)
						Press(7);
					if (button11->Enabled == true)
						Press(11);
					if (button13->Enabled == true)
						Press(13);
					if (button17->Enabled == true)
						Press(17);
					if (button18->Enabled == true)
						Press(18);
					if (button19->Enabled == true)
						Press(19);
				}
			}
			if (k != 0)
			{
				button12->Text = System::Convert::ToString(k);
			}
		}
		if (x == 13)
		{
			button13->Enabled = false;
			button13->Text = "";
			if (fr[13] == 1)
			{
				button13->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button13->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[6] == 1)
					k++;
				if (fr[7] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[19] == 1)
					k++;
				if (k == 0)
				{
					if (button6->Enabled == true)
						Press(6);
					if (button7->Enabled == true)
						Press(7);
					if (button12->Enabled == true)
						Press(12);
					if (button18->Enabled == true)
						Press(18);
					if (button19->Enabled == true)
						Press(19);
				}
			}
			if (k != 0)
			{
				button13->Text = System::Convert::ToString(k);
			}
		}
		if (x == 14)
		{
			button14->Enabled = false;
			button14->Text = "";
			if (fr[14] == 1)
			{
				button14->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button14->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[8] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[20] == 1)
					k++;
				if (k == 0)
				{
					if (button8->Enabled == true)
						Press(8);
					if (button9->Enabled == true)
						Press(9);
					if (button15->Enabled == true)
						Press(15);
					if (button21->Enabled == true)
						Press(21);
					if (button20->Enabled == true)
						Press(20);
				}
			}
			if (k != 0)
			{
				button14->Text = System::Convert::ToString(k);
			}
		}
		if (x == 15)
		{
			button15->Enabled = false;
			button15->Text = "";
			if (fr[15] == 1)
			{
				button15->BackColor = System::Drawing::SystemColors::GrayText;

				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button15->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[8] == 1)
					k++;
				if (fr[9] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[14] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[20] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (k == 0)
				{
					if (button8->Enabled == true)
						Press(8);
					if (button9->Enabled == true)
						Press(9);
					if (button10->Enabled == true)
						Press(10);
					if (button14->Enabled == true)
						Press(14);
					if (button16->Enabled == true)
						Press(16);
					if (button20->Enabled == true)
						Press(20);
					if (button21->Enabled == true)
						Press(21);
					if (button22->Enabled == true)
						Press(22);
				}
			}
			if (k != 0)
			{
				button15->Text = System::Convert::ToString(k);
			}
		}
		if (x == 16)
		{
			button16->Enabled = false;
			button16->Text = "";
			if (fr[16] == 1)
			{
				button16->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button16->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[9] == 1)
					k++;
				if (fr[10] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (k == 0)
				{
					if (button9->Enabled == true)
						Press(9);
					if (button10->Enabled == true)
						Press(10);
					if (button11->Enabled == true)
						Press(11);
					if (button15->Enabled == true)
						Press(15);
					if (button17->Enabled == true)
						Press(17);
					if (button21->Enabled == true)
						Press(21);
					if (button22->Enabled == true)
						Press(22);
					if (button23->Enabled == true)
						Press(23);
				}
			}
			if (k != 0)
			{
				button16->Text = System::Convert::ToString(k);
			}
		}
		if (x == 17)
		{
			button17->Enabled = false;
			button17->Text = "";
			if (fr[17] == 1)
			{
				button17->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button17->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[10] == 1)
					k++;
				if (fr[11] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (k == 0)
				{
					if (button10->Enabled == true)
						Press(10);
					if (button11->Enabled == true)
						Press(11);
					if (button12->Enabled == true)
						Press(12);
					if (button16->Enabled == true)
						Press(16);
					if (button18->Enabled == true)
						Press(18);
					if (button22->Enabled == true)
						Press(22);
					if (button23->Enabled == true)
						Press(23);
					if (button24->Enabled == true)
						Press(24);
				}
			}
			if (k != 0)
			{
				button17->Text = System::Convert::ToString(k);
			}

		}
		if (x == 18)
		{
			button18->Enabled = false;
			button18->Text = "";
			if (fr[18] == 1)
			{
				button18->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button18->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[11] == 1)
					k++;
				if (fr[12] == 1)
					k++;
				if (fr[13] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[19] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[25] == 1)
					k++;
				if (k == 0)
				{
					if (button11->Enabled == true)
						Press(11);
					if (button12->Enabled == true)
						Press(12);
					if (button13->Enabled == true)
						Press(13);
					if (button17->Enabled == true)
						Press(17);
					if (button19->Enabled == true)
						Press(19);
					if (button23->Enabled == true)
						Press(23);
					if (button24->Enabled == true)
						Press(24);
					if (button25->Enabled == true)
						Press(25);
				}
			}
			if (k != 0)
			{
				button18->Text = System::Convert::ToString(k);
			}
		}
		if (x == 19)
		{
			button19->Enabled = false;
			button19->Text = "";
			if (fr[19] == 1)
			{
				button19->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button19->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[12] == 1)
					k++;
				if (fr[13] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[25] == 1)
					k++;
				if (k == 0)
				{
					if (button12->Enabled == true)
						Press(12);
					if (button13->Enabled == true)
						Press(13);
					if (button18->Enabled == true)
						Press(18);
					if (button24->Enabled == true)
						Press(24);
					if (button25->Enabled == true)
						Press(25);
				}
			}
			if (k != 0)
			{
				button19->Text = System::Convert::ToString(k);
			}
		}
		if (x == 20)
		{
			button20->Enabled = false;
			button20->Text = "";
			if (fr[20] == 1)
			{
				button20->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button20->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[14] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[26] == 1)
					k++;
				if (k == 0)
				{
					if (button14->Enabled == true)
						Press(14);
					if (button15->Enabled == true)
						Press(15);
					if (button21->Enabled == true)
						Press(21);
					if (button27->Enabled == true)
						Press(27);
					if (button26->Enabled == true)
						Press(26);
				}
			}
			if (k != 0)
			{
				button20->Text = System::Convert::ToString(k);
			}
		}
		if (x == 21)
		{
			button21->Enabled = false;
			button21->Text = "";
			if (fr[21] == 1)
			{
				button21->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button21->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[14] == 1)
					k++;
				if (fr[15] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[20] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[26] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (k == 0)
				{
					if (button14->Enabled == true)
						Press(14);
					if (button15->Enabled == true)
						Press(15);
					if (button16->Enabled == true)
						Press(16);
					if (button20->Enabled == true)
						Press(20);
					if (button22->Enabled == true)
						Press(22);
					if (button26->Enabled == true)
						Press(26);
					if (button27->Enabled == true)
						Press(27);
					if (button28->Enabled == true)
						Press(28);
				}
			}
			if (k != 0)
			{
				button21->Text = System::Convert::ToString(k);
			}
		}
		if (x == 22)
		{
			button22->Enabled = false;
			button22->Text = "";
			if (fr[22] == 1)
			{
				button22->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button22->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[15] == 1)
					k++;
				if (fr[16] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (k == 0)
				{
					if (button15->Enabled == true)
						Press(15);
					if (button16->Enabled == true)
						Press(16);
					if (button17->Enabled == true)
						Press(17);
					if (button21->Enabled == true)
						Press(21);
					if (button23->Enabled == true)
						Press(23);
					if (button27->Enabled == true)
						Press(27);
					if (button28->Enabled == true)
						Press(28);
					if (button29->Enabled == true)
						Press(29);
				}
			}
			if (k != 0)
			{
				button22->Text = System::Convert::ToString(k);
			}
		}
		if (x == 23)
		{
			button23->Enabled = false;
			button23->Text = "";
			if (fr[23] == 1)
			{
				button23->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button23->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[16] == 1)
					k++;
				if (fr[17] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (k == 0)
				{
					if (button16->Enabled == true)
						Press(16);
					if (button17->Enabled == true)
						Press(17);
					if (button18->Enabled == true)
						Press(18);
					if (button22->Enabled == true)
						Press(22);
					if (button24->Enabled == true)
						Press(24);
					if (button28->Enabled == true)
						Press(28);
					if (button29->Enabled == true)
						Press(29);
					if (button30->Enabled == true)
						Press(30);
				}
			}
			if (k != 0)
			{
				button23->Text = System::Convert::ToString(k);
			}
		}
		if (x == 24)
		{
			button24->Enabled = false;
			button24->Text = "";
			if (fr[24] == 1)
			{
				button24->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button24->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[17] == 1)
					k++;
				if (fr[18] == 1)
					k++;
				if (fr[19] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[25] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[31] == 1)
					k++;
				if (k == 0)
				{
					if (button17->Enabled == true)
						Press(17);
					if (button18->Enabled == true)
						Press(18);
					if (button19->Enabled == true)
						Press(19);
					if (button23->Enabled == true)
						Press(23);
					if (button25->Enabled == true)
						Press(25);
					if (button29->Enabled == true)
						Press(29);
					if (button30->Enabled == true)
						Press(30);
					if (button31->Enabled == true)
						Press(31);
				}
			}
			if (k != 0)
			{
				button24->Text = System::Convert::ToString(k);
			}
		}
		if (x == 25)
		{
			button25->Enabled = false;
			button25->Text = "";
			if (fr[25] == 1)
			{
				button25->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button25->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[18] == 1)
					k++;
				if (fr[19] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[31] == 1)
					k++;
				if (k == 0)
				{
					if (button18->Enabled == true)
						Press(18);
					if (button19->Enabled == true)
						Press(19);
					if (button24->Enabled == true)
						Press(24);
					if (button30->Enabled == true)
						Press(30);
					if (button31->Enabled == true)
						Press(31);
				}
			}
			if (k != 0)
			{
				button25->Text = System::Convert::ToString(k);
			}
		}
		if (x == 26)
		{
			button26->Enabled = false;
			button26->Text = "";
			if (fr[26] == 1)
			{
				button26->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button26->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[20] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[32] == 1)
					k++;
				if (fr[33] == 1)
					k++;
				if (k == 0)
				{
					if (button20->Enabled == true)
						Press(20);
					if (button21->Enabled == true)
						Press(21);
					if (button27->Enabled == true)
						Press(27);
					if (button32->Enabled == true)
						Press(32);
					if (button33->Enabled == true)
						Press(33);
				}
			}
			if (k != 0)
			{
				button26->Text = System::Convert::ToString(k);
			}
		}
		if (x == 27)
		{
			button27->Enabled = false;
			button27->Text = "";
			if (fr[27] == 1)
			{
				button27->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button27->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[20] == 1)
					k++;
				if (fr[21] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[26] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[32] == 1)
					k++;
				if (fr[33] == 1)
					k++;
				if (fr[34] == 1)
					k++;
				if (k == 0)
				{
					if (button20->Enabled == true)
						Press(20);
					if (button21->Enabled == true)
						Press(21);
					if (button22->Enabled == true)
						Press(22);
					if (button26->Enabled == true)
						Press(26);
					if (button28->Enabled == true)
						Press(28);
					if (button32->Enabled == true)
						Press(32);
					if (button33->Enabled == true)
						Press(33);
					if (button34->Enabled == true)
						Press(34);
				}
			}
			if (k != 0)
			{
				button27->Text = System::Convert::ToString(k);
			}
		}
		if (x == 28)
		{
			button28->Enabled = false;
			button28->Text = "";
			if (fr[28] == 1)
			{
				button28->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button28->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[21] == 1)
					k++;
				if (fr[22] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[33] == 1)
					k++;
				if (fr[34] == 1)
					k++;
				if (fr[35] == 1)
					k++;
				if (k == 0)
				{
					if (button21->Enabled == true)
						Press(21);
					if (button22->Enabled == true)
						Press(22);
					if (button23->Enabled == true)
						Press(23);
					if (button27->Enabled == true)
						Press(27);
					if (button29->Enabled == true)
						Press(29);
					if (button33->Enabled == true)
						Press(33);
					if (button34->Enabled == true)
						Press(34);
					if (button35->Enabled == true)
						Press(35);
				}
			}
			if (k != 0)
			{
				button28->Text = System::Convert::ToString(k);
			}

		}
		if (x == 29)
		{
			button29->Enabled = false;
			button29->Text = "";
			if (fr[29] == 1)
			{
				button29->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button29->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[22] == 1)
					k++;
				if (fr[23] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[34] == 1)
					k++;
				if (fr[35] == 1)
					k++;
				if (fr[36] == 1)
					k++;
				if (k == 0)
				{
					if (button22->Enabled == true)
						Press(22);
					if (button23->Enabled == true)
						Press(23);
					if (button24->Enabled == true)
						Press(24);
					if (button28->Enabled == true)
						Press(28);
					if (button30->Enabled == true)
						Press(30);
					if (button34->Enabled == true)
						Press(34);
					if (button35->Enabled == true)
						Press(35);
					if (button36->Enabled == true)
						Press(36);
				}
			}
			if (k != 0)
			{
				button29->Text = System::Convert::ToString(k);
			}

		}
		if (x == 30)
		{
			button30->Enabled = false;
			button30->Text = "";
			if (fr[30] == 1)
			{
				button30->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button30->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[23] == 1)
					k++;
				if (fr[24] == 1)
					k++;
				if (fr[25] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[31] == 1)
					k++;
				if (fr[35] == 1)
					k++;
				if (fr[36] == 1)
					k++;
				if (fr[37] == 1)
					k++;
				if (k == 0)
				{
					if (button23->Enabled == true)
						Press(23);
					if (button24->Enabled == true)
						Press(24);
					if (button25->Enabled == true)
						Press(25);
					if (button29->Enabled == true)
						Press(29);
					if (button31->Enabled == true)
						Press(31);
					if (button35->Enabled == true)
						Press(35);
					if (button36->Enabled == true)
						Press(36);
					if (button37->Enabled == true)
						Press(37);
				}
			}
			if (k != 0)
			{
				button30->Text = System::Convert::ToString(k);
			}

		}
		if (x == 31)
		{
			button31->Enabled = false;
			button31->Text = "";
			if (fr[31] == 1)
			{
				button31->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button31->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[24] == 1)
					k++;
				if (fr[25] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[36] == 1)
					k++;
				if (fr[37] == 1)
					k++;
				if (k == 0)
				{
					if (button24->Enabled == true)
						Press(24);
					if (button25->Enabled == true)
						Press(25);
					if (button30->Enabled == true)
						Press(30);
					if (button36->Enabled == true)
						Press(36);
					if (button37->Enabled == true)
						Press(37);
				}
			}
			if (k != 0)
			{
				button31->Text = System::Convert::ToString(k);
			}

		}
		if (x == 32)
		{
			button32->Enabled = false;
			button32->Text = "";
			if (fr[32] == 1)
			{
				button32->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button32->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[26] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[33] == 1)
					k++;
				if (k == 0)
				{
					if (button26->Enabled == true)
						Press(26);
					if (button27->Enabled == true)
						Press(27);
					if (button33->Enabled == true)
						Press(33);
				}
			}
			if (k != 0)
			{
				button32->Text = System::Convert::ToString(k);
			}

		}
		if (x == 33)
		{
			button33->Enabled = false;
			button33->Text = "";
			if (fr[33] == 1)
			{
				button33->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button33->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[32] == 1)
					k++;
				if (fr[26] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[34] == 1)
					k++;
				if (k == 0)
				{
					if (button32->Enabled == true)
						Press(32);
					if (button26->Enabled == true)
						Press(26);
					if (button27->Enabled == true)
						Press(27);
					if (button28->Enabled == true)
						Press(28);
					if (button34->Enabled == true)
						Press(34);
				}
			}
			if (k != 0)
			{
				button33->Text = System::Convert::ToString(k);
			}
		}
		if (x == 34)
		{
			button34->Enabled = false;
			button34->Text = "";
			if (fr[34] == 1)
			{
				button34->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button34->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[33] == 1)
					k++;
				if (fr[27] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[35] == 1)
					k++;
				if (k == 0)
				{
					if (button33->Enabled == true)
						Press(33);
					if (button27->Enabled == true)
						Press(27);
					if (button28->Enabled == true)
						Press(28);
					if (button29->Enabled == true)
						Press(29);
					if (button35->Enabled == true)
						Press(35);
				}
			}
			if (k != 0)
			{
				button34->Text = System::Convert::ToString(k);
			}
		}
		if (x == 35)
		{
			button35->Enabled = false;
			button35->Text = "";
			if (fr[35] == 1)
			{
				button35->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Победа!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button35->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[34] == 1)
					k++;
				if (fr[28] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[36] == 1)
					k++;
				if (k == 0)
				{
					if (button34->Enabled == true)
						Press(34);
					if (button28->Enabled == true)
						Press(28);
					if (button29->Enabled == true)
						Press(29);
					if (button30->Enabled == true)
						Press(30);
					if (button36->Enabled == true)
						Press(36);
				}
			}
			if (k != 0)
			{
				button35->Text = System::Convert::ToString(k);
			}
		}
		if (x == 36)
		{
			button36->Enabled = false;
			button36->Text = "";
			if (fr[36] == 1)
			{
				button36->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button36->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[35] == 1)
					k++;
				if (fr[29] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[31] == 1)
					k++;
				if (fr[37] == 1)
					k++;
				if (k == 0)
				{
					if (button35->Enabled == true)
						Press(35);
					if (button29->Enabled == true)
						Press(29);
					if (button30->Enabled == true)
						Press(30);
					if (button31->Enabled == true)
						Press(31);
					if (button37->Enabled == true)
						Press(37);
				}
			}
			if (k != 0)
			{
				button36->Text = System::Convert::ToString(k);
			}
		}
		if (x == 37)
		{
			button37->Enabled = false;
			button37->Text = "";
			if (fr[37] == 1)
			{
				button37->BackColor = System::Drawing::SystemColors::GrayText;
				label2->Text = "Проигрыш!";
				label2->ForeColor = System::Drawing::Color::Red;
				bomb = 1;
			}
			else
			{
				button37->BackColor = System::Drawing::SystemColors::ControlLightLight;
				if (fr[36] == 1)
					k++;
				if (fr[30] == 1)
					k++;
				if (fr[31] == 1)
					k++;
				if (k == 0)
				{
					if (button36->Enabled == true)
						Press(36);
					if (button30->Enabled == true)
						Press(30);
					if (button31->Enabled == true)
						Press(31);
				}
			}
			if (k != 0)
			{
				button37->Text = System::Convert::ToString(k);
			}
		}
		if (buttonspressed == 29 && bomb == 0)
		{
			label2->Text = "Победа!";
			label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			Win();
		}
		if (bomb != 0)
			Lose();

	}
	public: Void Bombs()
	{

		for (int i = 0; i < 40; i++)
		{
			fr[i] = 0;
		}
		int k = 1;
		srand(time(NULL));
		while (k <= 7)
		{

			int c = rand() % 36 + 1;
			if (fr[c + 1] == 0)
			{
				fr[c + 1] = 1;
				k++;
			}
		}
	}
		  // форма с информацией об авторе
	private: System::Void button_information(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ f2 = gcnew MyForm2(); // создание новой формы
		this->Visible = false; // скрытие формы
		f2->ShowDialog(); // открытие второй формы
		f2->autor = this; // выполенение второй формы, пока она не будет закрыта
		f2->autor->Show(); // показ формы, если предыдущая закрыта

	}



		   // форма с информацией об игре
	private: System::Void button_information_about_game(System::Object^ sender, System::EventArgs^ e) {
		MyForm3^ f3 = gcnew MyForm3(); // создание новой формы
		this->Visible = false; // скрытие формы
		f3->ShowDialog(); // открытие второй формы
		f3->about = this; // выполенение второй формы, пока она не будет закрыта
		f3->about->Show(); // показ формы, если предыдущая закрыта

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Bombs();
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = true;
		button5->Visible = true;
		button6->Visible = true;
		button7->Visible = true;
		button8->Visible = true;
		button9->Visible = true;
		button10->Visible = true;
		button11->Visible = true;
		button12->Visible = true;
		button13->Visible = true;
		button14->Visible = true;
		button15->Visible = true;
		button16->Visible = true;
		button17->Visible = true;
		button18->Visible = true;
		button19->Visible = true;
		button20->Visible = true;
		button21->Visible = true;
		button22->Visible = true;
		button23->Visible = true;
		button24->Visible = true;
		button25->Visible = true;
		button26->Visible = true;
		button27->Visible = true;
		button28->Visible = true;
		button29->Visible = true;
		button30->Visible = true;
		button31->Visible = true;
		button32->Visible = true;
		button33->Visible = true;
		button34->Visible = true;
		button35->Visible = true;
		button36->Visible = true;
		button37->Visible = true;
		checkBox1->Visible = true;

		button1->Enabled = false;
		button1->Visible = false;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button2->Text == "?")
				button2->Text = "";
			else
				button2->Text = "?";
		}
		else
			Press(2);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button3->Text == "?")
				button3->Text = "";
			else
				button3->Text = "?";
		}
		else
			Press(3);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button4->Text == "?")
				button4->Text = "";
			else
				button4->Text = "?";
		}
		else
			Press(4);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button5->Text == "?")
				button5->Text = "";
			else
				button5->Text = "?";
		}
		else
			Press(5);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button6->Text == "?")
				button6->Text = "";
			else
				button6->Text = "?";
		}
		else
			Press(6);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button7->Text == "?")
				button7->Text = "";
			else
				button7->Text = "?";
		}
		else
			Press(7);
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button8->Text == "?")
				button8->Text = "";
			else
				button8->Text = "?";
		}
		else
			Press(8);
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button9->Text == "?")
				button9->Text = "";
			else
				button9->Text = "?";
		}
		else
			Press(9);
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button10->Text == "?")
				button10->Text = "";
			else
				button10->Text = "?";
		}
		else
			Press(10);
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button11->Text == "?")
				button11->Text = "";
			else
				button11->Text = "?";
		}
		else
			Press(11);
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button12->Text == "?")
				button12->Text = "";
			else
				button12->Text = "?";
		}
		else
			Press(12);
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button13->Text == "?")
				button13->Text = "";
			else
				button13->Text = "?";
		}
		else
			Press(13);
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button14->Text == "?")
				button14->Text = "";
			else
				button14->Text = "?";
		}
		else
			Press(14);
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button15->Text == "?")
				button15->Text = "";
			else
				button15->Text = "?";
		}
		else
			Press(15);
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button16->Text == "?")
				button16->Text = "";
			else
				button16->Text = "?";
		}
		else
			Press(16);
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button17->Text == "?")
				button17->Text = "";
			else
				button17->Text = "?";
		}
		else
			Press(17);
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button18->Text == "?")
				button18->Text = "";
			else
				button18->Text = "?";
		}
		else
			Press(18);
	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button19->Text == "?")
				button19->Text = "";
			else
				button19->Text = "?";
		}
		else
			Press(19);
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button20->Text == "?")
				button20->Text = "";
			else
				button20->Text = "?";
		}
		else
			Press(20);
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button21->Text == "?")
				button21->Text = "";
			else
				button21->Text = "?";
		}
		else
			Press(21);
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button22->Text == "?")
				button22->Text = "";
			else
				button22->Text = "?";
		}
		else
			Press(22);
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button23->Text == "?")
				button23->Text = "";
			else
				button23->Text = "?";
		}
		else
			Press(23);
	}
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button24->Text == "?")
				button24->Text = "";
			else
				button24->Text = "?";
		}
		else
			Press(24);
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button25->Text == "?")
				button25->Text = "";
			else
				button25->Text = "?";
		}
		else
			Press(25);
	}
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button26->Text == "?")
				button26->Text = "";
			else
				button26->Text = "?";
		}
		else
			Press(26);
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button27->Text == "?")
				button27->Text = "";
			else
				button27->Text = "?";
		}
		else
			Press(27);
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button28->Text == "?")
				button28->Text = "";
			else
				button28->Text = "?";
		}
		else
			Press(28);
	}
	private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button29->Text == "?")
				button29->Text = "";
			else
				button29->Text = "?";
		}
		else
			Press(29);
	}
	private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button30->Text == "?")
				button30->Text = "";
			else
				button30->Text = "?";
		}
		else
			Press(30);
	}
	private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button31->Text == "?")
				button31->Text = "";
			else
				button31->Text = "?";
		}
		else
			Press(31);
	}
	private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button32->Text == "?")
				button32->Text = "";
			else
				button32->Text = "?";
		}
		else
			Press(32);
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button33->Text == "?")
				button33->Text = "";
			else
				button33->Text = "?";
		}
		else
			Press(33);
	}
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button34->Text == "?")
				button34->Text = "";
			else
				button34->Text = "?";
		}
		else
			Press(34);
	}
	private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button35->Text == "?")
				button35->Text = "";
			else
				button35->Text = "?";
		}
		else
			Press(35);
	}
	private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button36->Text == "?")
				button36->Text = "";
			else
				button36->Text = "?";
		}
		else
			Press(36);
	}
	private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked == true)
		{
			if (button37->Text == "?")
				button37->Text = "";
			else
				button37->Text = "?";
		}
		else
			Press(37);
	}
	private: System::Void RestartB_Click(System::Object^ sender, System::EventArgs^ e) {
		RestartB->Visible = false;
		button2->Enabled = true; button2->Text = ""; button2->BackColor = System::Drawing::SystemColors::Control;
		button3->Enabled = true; button3->Text = ""; button3->BackColor = System::Drawing::SystemColors::Control;
		button4->Enabled = true; button4->Text = ""; button4->BackColor = System::Drawing::SystemColors::Control;
		button5->Enabled = true; button5->Text = ""; button5->BackColor = System::Drawing::SystemColors::Control;
		button6->Enabled = true; button6->Text = ""; button6->BackColor = System::Drawing::SystemColors::Control;
		button7->Enabled = true; button7->Text = ""; button7->BackColor = System::Drawing::SystemColors::Control;
		button8->Enabled = true; button8->Text = ""; button8->BackColor = System::Drawing::SystemColors::Control;
		button9->Enabled = true; button9->Text = ""; button9->BackColor = System::Drawing::SystemColors::Control;
		button10->Enabled = true; button10->Text = ""; button10->BackColor = System::Drawing::SystemColors::Control;
		button11->Enabled = true; button11->Text = ""; button11->BackColor = System::Drawing::SystemColors::Control;
		button12->Enabled = true; button12->Text = ""; button12->BackColor = System::Drawing::SystemColors::Control;
		button13->Enabled = true; button13->Text = ""; button13->BackColor = System::Drawing::SystemColors::Control;
		button14->Enabled = true; button14->Text = ""; button14->BackColor = System::Drawing::SystemColors::Control;
		button15->Enabled = true; button15->Text = ""; button15->BackColor = System::Drawing::SystemColors::Control;
		button16->Enabled = true; button16->Text = ""; button16->BackColor = System::Drawing::SystemColors::Control;
		button17->Enabled = true; button17->Text = ""; button17->BackColor = System::Drawing::SystemColors::Control;
		button18->Enabled = true; button18->Text = ""; button18->BackColor = System::Drawing::SystemColors::Control;
		button19->Enabled = true; button19->Text = ""; button19->BackColor = System::Drawing::SystemColors::Control;
		button20->Enabled = true; button20->Text = ""; button20->BackColor = System::Drawing::SystemColors::Control;
		button21->Enabled = true; button21->Text = ""; button21->BackColor = System::Drawing::SystemColors::Control;
		button22->Enabled = true; button22->Text = ""; button22->BackColor = System::Drawing::SystemColors::Control;
		button23->Enabled = true; button23->Text = ""; button23->BackColor = System::Drawing::SystemColors::Control;
		button24->Enabled = true; button24->Text = ""; button24->BackColor = System::Drawing::SystemColors::Control;
		button25->Enabled = true; button25->Text = ""; button25->BackColor = System::Drawing::SystemColors::Control;
		button26->Enabled = true; button26->Text = ""; button26->BackColor = System::Drawing::SystemColors::Control;
		button27->Enabled = true; button27->Text = ""; button27->BackColor = System::Drawing::SystemColors::Control;
		button28->Enabled = true; button28->Text = ""; button28->BackColor = System::Drawing::SystemColors::Control;
		button29->Enabled = true; button29->Text = ""; button29->BackColor = System::Drawing::SystemColors::Control;
		button30->Enabled = true; button30->Text = ""; button30->BackColor = System::Drawing::SystemColors::Control;
		button31->Enabled = true; button31->Text = ""; button31->BackColor = System::Drawing::SystemColors::Control;
		button32->Enabled = true; button32->Text = ""; button32->BackColor = System::Drawing::SystemColors::Control;
		button33->Enabled = true; button33->Text = ""; button33->BackColor = System::Drawing::SystemColors::Control;
		button34->Enabled = true; button34->Text = ""; button34->BackColor = System::Drawing::SystemColors::Control;
		button35->Enabled = true; button35->Text = ""; button35->BackColor = System::Drawing::SystemColors::Control;
		button36->Enabled = true; button36->Text = ""; button36->BackColor = System::Drawing::SystemColors::Control;
		button37->Enabled = true; button37->Text = ""; button37->BackColor = System::Drawing::SystemColors::Control;
		bomb = 0;
		buttonspressed = 0;
		label2->Text = "";
		Bombs();
	}


*/