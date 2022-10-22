#pragma once
#include "Arr_Figuras.h"

namespace Semana9Ej1Algoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmFiguras
	/// </summary>
	public ref class FrmFiguras : public System::Windows::Forms::Form
	{
		public:
			FrmFiguras(void)
			{
				InitializeComponent();
				//
				//TODO: agregar código de constructor aquí
				//
			}

		protected:
			/// <summary>
			/// Limpiar los recursos que se estén usando.
			/// </summary>
			~FrmFiguras()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::GroupBox^ groupBox1;
		protected:
			private: System::Windows::Forms::Label^ label1;
			private: System::Windows::Forms::Button^ BtnDibujar;
			private: System::Windows::Forms::ComboBox^ CboFigura;
			private: System::Windows::Forms::GroupBox^ groupBox2;
			private: System::Windows::Forms::GroupBox^ groupBox3;
			private: System::Windows::Forms::GroupBox^ groupBox4;
			private: System::Windows::Forms::Label^ label3;
			private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ TxtPosY1;

	private: System::Windows::Forms::TextBox^ TxtPosX1;

			private: System::Windows::Forms::Label^ lblArea_Elipse;

			private: System::Windows::Forms::Label^ label5;
			private: System::Windows::Forms::TextBox^ TxtRadioA;

			private: System::Windows::Forms::Label^ label4;
			private: System::Windows::Forms::Label^ label6;
			private: System::Windows::Forms::Label^ lblArea_Rectangulo;

			private: System::Windows::Forms::Label^ label9;
			private: System::Windows::Forms::TextBox^ TxTLado2;


			private: System::Windows::Forms::Label^ label7;
			private: System::Windows::Forms::TextBox^ TxTLado1;
			private: System::Windows::Forms::Panel^ PnlDibujo;


			private: System::Windows::Forms::GroupBox^ groupBox5;
			private: System::Windows::Forms::Label^ lblArea_Circulo;

			private: System::Windows::Forms::Label^ label11;
			private: System::Windows::Forms::TextBox^ TxTRadio;


			private: System::Windows::Forms::Label^ label12;
			private: System::Windows::Forms::TextBox^ TxtRadioB;
			private: System::Windows::Forms::Label^ label13;
			private: System::Windows::Forms::GroupBox^ groupBox6;
			private: System::Windows::Forms::Label^ lblArea_Cuadrado;

			private: System::Windows::Forms::Label^ label10;
			private: System::Windows::Forms::TextBox^ TxtLado;

			private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ TxtPosY2;

	private: System::Windows::Forms::TextBox^ TxtPosX2;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label15;


		private:
			/// <summary>
			/// Variable del diseñador necesaria.
			/// </summary>
			System::ComponentModel::Container ^components;

			#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
			void InitializeComponent(void)
			{
				this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				this->BtnDibujar = (gcnew System::Windows::Forms::Button());
				this->CboFigura = (gcnew System::Windows::Forms::ComboBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				this->TxtPosY1 = (gcnew System::Windows::Forms::TextBox());
				this->TxtPosX1 = (gcnew System::Windows::Forms::TextBox());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				this->TxtRadioB = (gcnew System::Windows::Forms::TextBox());
				this->label13 = (gcnew System::Windows::Forms::Label());
				this->lblArea_Elipse = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->TxtRadioA = (gcnew System::Windows::Forms::TextBox());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
				this->lblArea_Rectangulo = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->TxTLado2 = (gcnew System::Windows::Forms::TextBox());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->TxTLado1 = (gcnew System::Windows::Forms::TextBox());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->PnlDibujo = (gcnew System::Windows::Forms::Panel());
				this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
				this->lblArea_Circulo = (gcnew System::Windows::Forms::Label());
				this->label11 = (gcnew System::Windows::Forms::Label());
				this->TxTRadio = (gcnew System::Windows::Forms::TextBox());
				this->label12 = (gcnew System::Windows::Forms::Label());
				this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
				this->lblArea_Cuadrado = (gcnew System::Windows::Forms::Label());
				this->label10 = (gcnew System::Windows::Forms::Label());
				this->TxtLado = (gcnew System::Windows::Forms::TextBox());
				this->label14 = (gcnew System::Windows::Forms::Label());
				this->TxtPosY2 = (gcnew System::Windows::Forms::TextBox());
				this->TxtPosX2 = (gcnew System::Windows::Forms::TextBox());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->label15 = (gcnew System::Windows::Forms::Label());
				this->groupBox1->SuspendLayout();
				this->groupBox2->SuspendLayout();
				this->groupBox3->SuspendLayout();
				this->groupBox4->SuspendLayout();
				this->groupBox5->SuspendLayout();
				this->groupBox6->SuspendLayout();
				this->SuspendLayout();
				// 
				// groupBox1
				// 
				this->groupBox1->Controls->Add(this->BtnDibujar);
				this->groupBox1->Controls->Add(this->CboFigura);
				this->groupBox1->Controls->Add(this->label1);
				this->groupBox1->Location = System::Drawing::Point(13, 13);
				this->groupBox1->Name = L"groupBox1";
				this->groupBox1->Size = System::Drawing::Size(1160, 56);
				this->groupBox1->TabIndex = 0;
				this->groupBox1->TabStop = false;
				// 
				// BtnDibujar
				// 
				this->BtnDibujar->Location = System::Drawing::Point(238, 17);
				this->BtnDibujar->Name = L"BtnDibujar";
				this->BtnDibujar->Size = System::Drawing::Size(913, 23);
				this->BtnDibujar->TabIndex = 2;
				this->BtnDibujar->Text = L"Dibujar";
				this->BtnDibujar->UseVisualStyleBackColor = true;
				this->BtnDibujar->Click += gcnew System::EventHandler(this, &FrmFiguras::BtnDibujar_Click);
				// 
				// CboFigura
				// 
				this->CboFigura->FormattingEnabled = true;
				this->CboFigura->Location = System::Drawing::Point(91, 17);
				this->CboFigura->Name = L"CboFigura";
				this->CboFigura->Size = System::Drawing::Size(121, 21);
				this->CboFigura->TabIndex = 1;
				this->CboFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &FrmFiguras::CboFigura_SelectedIndexChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(12, 20);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(65, 13);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Elegir Figura";
				// 
				// groupBox2
				// 
				this->groupBox2->Controls->Add(this->TxtPosY1);
				this->groupBox2->Controls->Add(this->TxtPosX1);
				this->groupBox2->Controls->Add(this->label3);
				this->groupBox2->Controls->Add(this->label2);
				this->groupBox2->Location = System::Drawing::Point(13, 76);
				this->groupBox2->Name = L"groupBox2";
				this->groupBox2->Size = System::Drawing::Size(212, 161);
				this->groupBox2->TabIndex = 1;
				this->groupBox2->TabStop = false;
				this->groupBox2->Text = L"Posición Inicial";
				// 
				// TxtPosY1
				// 
				this->TxtPosY1->Location = System::Drawing::Point(93, 61);
				this->TxtPosY1->Name = L"TxtPosY1";
				this->TxtPosY1->Size = System::Drawing::Size(111, 20);
				this->TxtPosY1->TabIndex = 6;
				// 
				// TxtPosX1
				// 
				this->TxtPosX1->Location = System::Drawing::Point(93, 29);
				this->TxtPosX1->Name = L"TxtPosX1";
				this->TxtPosX1->Size = System::Drawing::Size(111, 20);
				this->TxtPosX1->TabIndex = 5;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(9, 64);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(78, 13);
				this->label3->TabIndex = 4;
				this->label3->Text = L"Posición en Y1";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(9, 32);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(78, 13);
				this->label2->TabIndex = 0;
				this->label2->Text = L"Posición en X1";
				// 
				// groupBox3
				// 
				this->groupBox3->Controls->Add(this->TxtRadioB);
				this->groupBox3->Controls->Add(this->label13);
				this->groupBox3->Controls->Add(this->lblArea_Elipse);
				this->groupBox3->Controls->Add(this->label5);
				this->groupBox3->Controls->Add(this->TxtRadioA);
				this->groupBox3->Controls->Add(this->label4);
				this->groupBox3->Location = System::Drawing::Point(251, 76);
				this->groupBox3->Name = L"groupBox3";
				this->groupBox3->Size = System::Drawing::Size(212, 161);
				this->groupBox3->TabIndex = 2;
				this->groupBox3->TabStop = false;
				this->groupBox3->Text = L"Elipse";
				// 
				// TxtRadioB
				// 
				this->TxtRadioB->Location = System::Drawing::Point(72, 52);
				this->TxtRadioB->Name = L"TxtRadioB";
				this->TxtRadioB->Size = System::Drawing::Size(111, 20);
				this->TxtRadioB->TabIndex = 8;
				// 
				// label13
				// 
				this->label13->AutoSize = true;
				this->label13->Location = System::Drawing::Point(15, 53);
				this->label13->Name = L"label13";
				this->label13->Size = System::Drawing::Size(45, 13);
				this->label13->TabIndex = 7;
				this->label13->Text = L"Radio B";
				// 
				// lblArea_Elipse
				// 
				this->lblArea_Elipse->AutoSize = true;
				this->lblArea_Elipse->Location = System::Drawing::Point(62, 87);
				this->lblArea_Elipse->Name = L"lblArea_Elipse";
				this->lblArea_Elipse->Size = System::Drawing::Size(102, 13);
				this->lblArea_Elipse->TabIndex = 6;
				this->lblArea_Elipse->Text = L"Mostrar el área aquí";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(15, 87);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(29, 13);
				this->label5->TabIndex = 5;
				this->label5->Text = L"Área";
				// 
				// TxtRadioA
				// 
				this->TxtRadioA->Location = System::Drawing::Point(72, 20);
				this->TxtRadioA->Name = L"TxtRadioA";
				this->TxtRadioA->Size = System::Drawing::Size(111, 20);
				this->TxtRadioA->TabIndex = 6;
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(15, 21);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(45, 13);
				this->label4->TabIndex = 4;
				this->label4->Text = L"Radio A";
				// 
				// groupBox4
				// 
				this->groupBox4->Controls->Add(this->lblArea_Rectangulo);
				this->groupBox4->Controls->Add(this->label9);
				this->groupBox4->Controls->Add(this->TxTLado2);
				this->groupBox4->Controls->Add(this->label7);
				this->groupBox4->Controls->Add(this->TxTLado1);
				this->groupBox4->Controls->Add(this->label6);
				this->groupBox4->Location = System::Drawing::Point(489, 76);
				this->groupBox4->Name = L"groupBox4";
				this->groupBox4->Size = System::Drawing::Size(212, 161);
				this->groupBox4->TabIndex = 3;
				this->groupBox4->TabStop = false;
				this->groupBox4->Text = L"Rectángulo";
				// 
				// lblArea_Rectangulo
				// 
				this->lblArea_Rectangulo->AutoSize = true;
				this->lblArea_Rectangulo->Location = System::Drawing::Point(92, 87);
				this->lblArea_Rectangulo->Name = L"lblArea_Rectangulo";
				this->lblArea_Rectangulo->Size = System::Drawing::Size(102, 13);
				this->lblArea_Rectangulo->TabIndex = 8;
				this->lblArea_Rectangulo->Text = L"Mostrar el área aquí";
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->Location = System::Drawing::Point(17, 87);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(29, 13);
				this->label9->TabIndex = 7;
				this->label9->Text = L"Área";
				// 
				// TxTLado2
				// 
				this->TxTLado2->Location = System::Drawing::Point(95, 53);
				this->TxTLado2->Name = L"TxTLado2";
				this->TxTLado2->Size = System::Drawing::Size(111, 20);
				this->TxTLado2->TabIndex = 9;
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(15, 53);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(40, 13);
				this->label7->TabIndex = 8;
				this->label7->Text = L"Lado 2";
				// 
				// TxTLado1
				// 
				this->TxTLado1->Location = System::Drawing::Point(95, 21);
				this->TxTLado1->Name = L"TxTLado1";
				this->TxTLado1->Size = System::Drawing::Size(111, 20);
				this->TxTLado1->TabIndex = 7;
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(15, 21);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(40, 13);
				this->label6->TabIndex = 5;
				this->label6->Text = L"Lado 1";
				// 
				// PnlDibujo
				// 
				this->PnlDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->PnlDibujo->Location = System::Drawing::Point(13, 254);
				this->PnlDibujo->Name = L"PnlDibujo";
				this->PnlDibujo->Size = System::Drawing::Size(1160, 310);
				this->PnlDibujo->TabIndex = 4;
				// 
				// groupBox5
				// 
				this->groupBox5->Controls->Add(this->lblArea_Circulo);
				this->groupBox5->Controls->Add(this->label11);
				this->groupBox5->Controls->Add(this->TxTRadio);
				this->groupBox5->Controls->Add(this->label12);
				this->groupBox5->Location = System::Drawing::Point(726, 76);
				this->groupBox5->Name = L"groupBox5";
				this->groupBox5->Size = System::Drawing::Size(212, 161);
				this->groupBox5->TabIndex = 5;
				this->groupBox5->TabStop = false;
				this->groupBox5->Text = L"Circulo";
				// 
				// lblArea_Circulo
				// 
				this->lblArea_Circulo->AutoSize = true;
				this->lblArea_Circulo->Location = System::Drawing::Point(62, 64);
				this->lblArea_Circulo->Name = L"lblArea_Circulo";
				this->lblArea_Circulo->Size = System::Drawing::Size(102, 13);
				this->lblArea_Circulo->TabIndex = 6;
				this->lblArea_Circulo->Text = L"Mostrar el área aquí";
				// 
				// label11
				// 
				this->label11->AutoSize = true;
				this->label11->Location = System::Drawing::Point(15, 64);
				this->label11->Name = L"label11";
				this->label11->Size = System::Drawing::Size(29, 13);
				this->label11->TabIndex = 5;
				this->label11->Text = L"Área";
				// 
				// TxTRadio
				// 
				this->TxTRadio->Location = System::Drawing::Point(65, 29);
				this->TxTRadio->Name = L"TxTRadio";
				this->TxTRadio->Size = System::Drawing::Size(111, 20);
				this->TxTRadio->TabIndex = 6;
				// 
				// label12
				// 
				this->label12->AutoSize = true;
				this->label12->Location = System::Drawing::Point(15, 29);
				this->label12->Name = L"label12";
				this->label12->Size = System::Drawing::Size(35, 13);
				this->label12->TabIndex = 4;
				this->label12->Text = L"Radio";
				// 
				// groupBox6
				// 
				this->groupBox6->Controls->Add(this->lblArea_Cuadrado);
				this->groupBox6->Controls->Add(this->label10);
				this->groupBox6->Controls->Add(this->TxtLado);
				this->groupBox6->Controls->Add(this->label14);
				this->groupBox6->Location = System::Drawing::Point(961, 76);
				this->groupBox6->Name = L"groupBox6";
				this->groupBox6->Size = System::Drawing::Size(212, 161);
				this->groupBox6->TabIndex = 6;
				this->groupBox6->TabStop = false;
				this->groupBox6->Text = L"Cuadrado";
				// 
				// lblArea_Cuadrado
				// 
				this->lblArea_Cuadrado->AutoSize = true;
				this->lblArea_Cuadrado->Location = System::Drawing::Point(62, 64);
				this->lblArea_Cuadrado->Name = L"lblArea_Cuadrado";
				this->lblArea_Cuadrado->Size = System::Drawing::Size(102, 13);
				this->lblArea_Cuadrado->TabIndex = 6;
				this->lblArea_Cuadrado->Text = L"Mostrar el área aquí";
				// 
				// label10
				// 
				this->label10->AutoSize = true;
				this->label10->Location = System::Drawing::Point(15, 64);
				this->label10->Name = L"label10";
				this->label10->Size = System::Drawing::Size(29, 13);
				this->label10->TabIndex = 5;
				this->label10->Text = L"Área";
				// 
				// TxtLado
				// 
				this->TxtLado->Location = System::Drawing::Point(65, 29);
				this->TxtLado->Name = L"TxtLado";
				this->TxtLado->Size = System::Drawing::Size(111, 20);
				this->TxtLado->TabIndex = 6;
				// 
				// label14
				// 
				this->label14->AutoSize = true;
				this->label14->Location = System::Drawing::Point(15, 29);
				this->label14->Name = L"label14";
				this->label14->Size = System::Drawing::Size(31, 13);
				this->label14->TabIndex = 4;
				this->label14->Text = L"Lado";
				// 
				// TxtPosY2
				// 
				this->TxtPosY2->Location = System::Drawing::Point(106, 201);
				this->TxtPosY2->Name = L"TxtPosY2";
				this->TxtPosY2->Size = System::Drawing::Size(111, 20);
				this->TxtPosY2->TabIndex = 10;
				// 
				// TxtPosX2
				// 
				this->TxtPosX2->Location = System::Drawing::Point(106, 169);
				this->TxtPosX2->Name = L"TxtPosX2";
				this->TxtPosX2->Size = System::Drawing::Size(111, 20);
				this->TxtPosX2->TabIndex = 9;
				// 
				// label8
				// 
				this->label8->AutoSize = true;
				this->label8->Location = System::Drawing::Point(22, 204);
				this->label8->Name = L"label8";
				this->label8->Size = System::Drawing::Size(78, 13);
				this->label8->TabIndex = 8;
				this->label8->Text = L"Posición en Y2";
				// 
				// label15
				// 
				this->label15->AutoSize = true;
				this->label15->Location = System::Drawing::Point(22, 172);
				this->label15->Name = L"label15";
				this->label15->Size = System::Drawing::Size(78, 13);
				this->label15->TabIndex = 7;
				this->label15->Text = L"Posición en X2";
				// 
				// FrmFiguras
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1185, 576);
				this->Controls->Add(this->TxtPosY2);
				this->Controls->Add(this->groupBox6);
				this->Controls->Add(this->TxtPosX2);
				this->Controls->Add(this->groupBox5);
				this->Controls->Add(this->label8);
				this->Controls->Add(this->label15);
				this->Controls->Add(this->PnlDibujo);
				this->Controls->Add(this->groupBox4);
				this->Controls->Add(this->groupBox3);
				this->Controls->Add(this->groupBox2);
				this->Controls->Add(this->groupBox1);
				this->Name = L"FrmFiguras";
				this->Text = L"Figuras";
				this->Load += gcnew System::EventHandler(this, &FrmFiguras::FrmFiguras_Load);
				this->groupBox1->ResumeLayout(false);
				this->groupBox1->PerformLayout();
				this->groupBox2->ResumeLayout(false);
				this->groupBox2->PerformLayout();
				this->groupBox3->ResumeLayout(false);
				this->groupBox3->PerformLayout();
				this->groupBox4->ResumeLayout(false);
				this->groupBox4->PerformLayout();
				this->groupBox5->ResumeLayout(false);
				this->groupBox5->PerformLayout();
				this->groupBox6->ResumeLayout(false);
				this->groupBox6->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
			#pragma endregion

			#pragma region Methods
			void Habilitar_Rectangulo(bool isActive) {
				TxTLado1->Enabled = isActive;
				TxTLado2->Enabled = isActive;
			}

			void Habilitar_Cuadrado(bool isActive) {
				TxtLado->Enabled = isActive;
			}

			void Habilitar_Elipse(bool isActive) {
				TxtRadioA->Enabled = isActive;
				TxtRadioB->Enabled = isActive;
			}

			void Habilitar_Circulo(bool isActive) {
				TxTRadio->Enabled = isActive;
			}

			void Habilitar_Lineas_Puntos_2(bool isActive) {
				TxtPosX2->Enabled = isActive;
				TxtPosY2->Enabled = isActive;
			}

			void Proceso_Circulo(Graphics^ g, Pen^ p, Arr_Figuras* figuras, short posX, short posY) {
				if (TxTRadio->Text == "") {
					MessageBox::Show("Debe añadir el radio para dibujar la figura.");
					return;
				}

				figuras->Agregar_Circulo(new Circulo(posX, posY, Convert::ToInt32(TxTRadio->Text)));
				figuras->Ultimo_Circulo()->Dibujar(g, p);
				lblArea_Circulo->Text = figuras->Ultimo_Circulo()->Area().ToString();
			}

			void Proceso_Cuadrado(Graphics^ g, Pen^ p, Arr_Figuras* figuras, short posX, short posY) {
				if (TxtLado->Text == "") {
					MessageBox::Show("Debe añadir el lado para dibujar la figura.");
					return;
				}

				figuras->Agregar_Cuadrado(new Cuadrado(posX, posY, Convert::ToInt32(TxtLado->Text)));
				figuras->Ultimo_Cuadrado()->Dibujar(g, p);
				lblArea_Cuadrado->Text = figuras->Ultimo_Cuadrado()->Area().ToString();
			}

			void Proceso_Elipse(Graphics^ g, Pen^ p, Arr_Figuras* figuras, short posX, short posY) {
				if (TxtRadioA->Text == "" || TxtRadioB->Text == "") {
					MessageBox::Show("Debe añadir los radios A y B para poder dibujar la figura.");
					return;
				}

				figuras->Agregar_Elipse(new Elipse(posX, posY, Convert::ToInt32(TxtRadioA->Text), Convert::ToInt32(TxtRadioB->Text)));
				figuras->Ultimo_Elipse()->Dibujar(g, p);
				lblArea_Cuadrado->Text = figuras->Ultimo_Elipse()->Area().ToString();
			}

			void Proceso_Linea(Graphics^ g, Pen^ p, Arr_Figuras* figuras, short posX1, short posY1) {
				if (TxtPosX2->Text == "" || TxtPosY2->Text == "") {
					MessageBox::Show("Debe añadir las segundas posiciones para dibujar la figura.");
					return;
				}

				figuras->Agregar_Linea(new Linea(posX1, posY1, Convert::ToInt32(TxtPosX2->Text), Convert::ToInt32(TxtPosY2->Text)));
				figuras->Ultima_Linea()->Dibujar(g, p);
			}

			void Proceso_Rectangulo(Graphics^ g, Pen^ p, Arr_Figuras* figuras, short posX, short posY) {
				if (TxTLado1->Text == "" || TxTLado2->Text == "") {
					MessageBox::Show("Debe añadir los lados del rectángulo.");
					return;
				}

				figuras->Agregar_Rectangulo(new Rectangulo(posX, posY, Convert::ToInt32(TxTLado1->Text), Convert::ToInt32(TxTLado2->Text)));
				figuras->Ultimo_Rectangulo()->Dibujar(g, p);
				lblArea_Rectangulo->Text = figuras->Ultimo_Rectangulo()->Area().ToString();
			}
			#pragma endregion

			#pragma region Windows Form Events
			private: System::Void FrmFiguras_Load(System::Object^ sender, System::EventArgs^ e) {
				/* Cargamos la data en el combobox */
				CboFigura->Items->Add("Círculo");
				CboFigura->Items->Add("Rectángulo");
				CboFigura->Items->Add("Elipse");
				CboFigura->Items->Add("Cuadrado");
				CboFigura->Items->Add("Línea");
			}

			private: System::Void BtnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
				/* Validacion que evita el combobox de figuras vacio.*/
				if (CboFigura->SelectedIndex == -1) {
					MessageBox::Show("Debe seleccionar una figura para dibujar.");
					return;
				}

				if (TxtPosX1->Text == "" || TxtPosY1->Text == "") {
					MessageBox::Show("Debe añadir las posiciones para dibujar la figura.");
					return;
				}

				/* Instancio mi clase grafica e indico que realice los
				   dibujos en mi panel PnlDibujo. También, creo una instancia
				   adicional de un lapicero para poder dibujar.
				*/
				Graphics^ g = PnlDibujo->CreateGraphics();
				Pen^ p = gcnew Pen(Color::Black, 5);

				/* Inicialización de mi clase controladora para poder 
				   guardar mis figuras en un arreglo. Además de inicialización
				   de variables básicas que usan todas las figuras para poder
				   ser dibujadas,
				*/
				Arr_Figuras* figuras = new Arr_Figuras();
				short posX = Convert::ToInt32(TxtPosX1->Text);
				short posY = Convert::ToInt32(TxtPosY1->Text);

				switch (CboFigura->SelectedIndex) {
					case 0: Proceso_Circulo(g, p, figuras, posX, posY); break;
					case 1: Proceso_Rectangulo(g, p, figuras, posX, posY); break;
					case 2: Proceso_Elipse(g, p, figuras, posX, posY); break;
					case 3: Proceso_Cuadrado(g, p, figuras, posX, posY); break;
					case 4: Proceso_Linea(g, p, figuras, posX, posY); break;
				}
			}

			private: System::Void CboFigura_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
				switch (CboFigura->SelectedIndex) {
					case 0: 
						Habilitar_Circulo(true);
						Habilitar_Elipse(false);
						Habilitar_Cuadrado(false);
						Habilitar_Rectangulo(false);
						Habilitar_Lineas_Puntos_2(false);
						break;
					case 1:
						Habilitar_Circulo(false);
						Habilitar_Elipse(false);
						Habilitar_Cuadrado(false);
						Habilitar_Rectangulo(true);
						Habilitar_Lineas_Puntos_2(false);
						break;
					case 2:
						Habilitar_Circulo(false);
						Habilitar_Elipse(true);
						Habilitar_Cuadrado(false);
						Habilitar_Rectangulo(false);
						Habilitar_Lineas_Puntos_2(false);
						break;
					case 3:
						Habilitar_Circulo(false);
						Habilitar_Elipse(false);
						Habilitar_Cuadrado(true);
						Habilitar_Rectangulo(false);
						Habilitar_Lineas_Puntos_2(false);
						break;
					case 4:
						Habilitar_Circulo(false);
						Habilitar_Elipse(false);
						Habilitar_Cuadrado(false);
						Habilitar_Rectangulo(false);
						Habilitar_Lineas_Puntos_2(true);
						break;
				}
			}
			#pragma endregion
	};
}
