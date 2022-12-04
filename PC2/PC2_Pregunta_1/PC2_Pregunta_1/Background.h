/* Background.h */
#pragma once

#include "Controller.h"
#include "Bomberman.h"

namespace PC2Pregunta1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Background
	/// </summary>
	public ref class Background : public System::Windows::Forms::Form
	{
		public:
			Background(void)
			{
				InitializeComponent();

				/* Inicializamos  nuestra variable g que nos permitirá
				 * crear gráficos donde le asignemos.
				*/
				g = pnlCanvas->CreateGraphics();

				/* Creamos un espacio que nos proporciona métodos para poder
				 * configurar nuestro bufer gráfico. Con el método allocate creo
				 * un contenedor bufer de gráficos con las dimensiones de nuestro panel canvas
				*/
				bfSpace = BufferedGraphicsManager::Current;
				bfGraphics = bfSpace->Allocate(g, pnlCanvas->ClientRectangle);

				/* Inicializamos nuestros mapas de bits con las direcciones de su imagen */
				bmBomberman = gcnew Bitmap("bomberman.gif");
				bmFantasma = gcnew Bitmap("fantasma.png");
				bmBomba = gcnew Bitmap("bomba.png");
				bmMap = gcnew Bitmap("fondo.png");

				/* Inicializamos nuestras entidades con sus dimensiones individuales */
				bomberman = new Bomberman(bmBomberman->Width / 7, bmBomberman->Height / 4);
				controller = new Controller();
				//controller->CreateEnemies(bmEnemy->Width / 4, bmEnemy->Height / 4);
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Background()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Panel^ pnlCanvas;
		private:
			Graphics^ g;
			BufferedGraphicsContext^ bfSpace;
			BufferedGraphics^ bfGraphics;

			Bitmap^ bmBomberman;
			Bitmap^ bmFantasma;
			Bitmap^ bmBomba;
			Bitmap^ bmMap;

			Bomberman* bomberman;
			Controller* controller;

			bool isShowMsg = false;

		protected:
		private: System::Windows::Forms::Timer^ Loop;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ lblPuntaje;
		private: System::ComponentModel::IContainer^ components;


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
				this->components = (gcnew System::ComponentModel::Container());
				this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
				this->Loop = (gcnew System::Windows::Forms::Timer(this->components));
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->lblPuntaje = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// pnlCanvas
				// 
				this->pnlCanvas->Location = System::Drawing::Point(1, 2);
				this->pnlCanvas->Name = L"pnlCanvas";
				this->pnlCanvas->Size = System::Drawing::Size(716, 420);
				this->pnlCanvas->TabIndex = 0;
				// 
				// Loop
				// 
				this->Loop->Enabled = true;
				this->Loop->Tick += gcnew System::EventHandler(this, &Background::Loop_Tick);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(12, 430);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(46, 13);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Puntaje:";
				// 
				// lblPuntaje
				// 
				this->lblPuntaje->AutoSize = true;
				this->lblPuntaje->Location = System::Drawing::Point(64, 430);
				this->lblPuntaje->Name = L"lblPuntaje";
				this->lblPuntaje->Size = System::Drawing::Size(53, 13);
				this->lblPuntaje->TabIndex = 2;
				this->lblPuntaje->Text = L"lblPuntaje";
				// 
				// Background
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(717, 452);
				this->Controls->Add(this->lblPuntaje);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->pnlCanvas);
				this->Name = L"Background";
				this->Text = L"Background";
				this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Background::Background_KeyDown);
				this->ResumeLayout(false);
				this->PerformLayout();
			}

			private: System::Void Loop_Tick(System::Object^ sender, System::EventArgs^ e) {
				bfGraphics->Graphics->Clear(Color::White);
				bfGraphics->Graphics->DrawImage(bmMap, 0, 0, bmMap->Width * 2.069, bmMap->Height * 1.58);

				bomberman->Draw(bfGraphics->Graphics, bmBomberman);
				controller->DrawEverything(bfGraphics->Graphics, bmBomba, bmFantasma);
				controller->MoveEverything(bfGraphics->Graphics);
				controller->Collision(bfGraphics->Graphics, bomberman);

				lblPuntaje->Text = controller->getPuntaje().ToString();

				if (controller->getPuntaje() == 85) {
					MessageBox::Show("Esta es la cantidad de fantasmas eliminados: " + controller->getFantasmasMuertos());
				}

				bfGraphics->Render(g);
			}

			private: System::Void Background_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
				switch (e->KeyCode) {
					case Keys::A: bomberman->Move(bfGraphics->Graphics, 'A'); break;
					case Keys::D: bomberman->Move(bfGraphics->Graphics, 'D'); break;
					case Keys::W: bomberman->Move(bfGraphics->Graphics, 'W'); break;
					case Keys::S: bomberman->Move(bfGraphics->Graphics, 'S'); break;
					case Keys::F: controller->AddFantasmas(bmFantasma->Width / 3, bmFantasma->Height/2); break;
					case Keys::Space: controller->AddBombas(new Bomba(bomberman->getX(), bomberman->getY(), bmBomba->Width, bmBomba->Height, bomberman->getDirection())); break;
				}
			}
	};
}
