/* FrmBackground.h */
#pragma once
#include "Jugador.h"
#include "Controlador.h"

namespace Semana16EFEj1Algoritmos {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmBackground
	/// </summary>
	public ref class FrmBackground : public System::Windows::Forms::Form
	{
		public:
			FrmBackground(void)
			{
				InitializeComponent();
				srand(time(NULL));

				/* Inicializamos las variables gráficas
				 * que nos permitirá crear gráficos donde
				 * le asignemos.
				*/
				gBackground = PnlBackground->CreateGraphics();

				/* Creamos un espacio que nos proporciona métodos para poder
				 * configurar nuestro bufer gráfico. Con el método allocate creo
				 * un contenedor bufer de gráficos con las dimensiones de nuestros paneles
				*/
				bfSpace = BufferedGraphicsManager::Current;
				bfBackground = bfSpace->Allocate(gBackground, PnlBackground->ClientRectangle);

				/* Inicializamos los mapas de bits con las rutas de la imagen */
				bmpJugador = gcnew Bitmap("resources/jugador.png");
				bmpEnemigo = gcnew Bitmap("resources/enemigo.png");
				bmpBomba = gcnew Bitmap("resources/bomba.png");

				/* Inicializamos controlador jugadores y enemigos */
				jugador = new Jugador(bmpJugador->Width / 2, bmpJugador->Height / 2);
				controlador = new Controlador();
			}

		protected:
			/// <summary>
			/// Limpiar los recursos que se estén usando.
			/// </summary>
			~FrmBackground()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Panel^ PnlBackground;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ lblPuntaje;
		private: System::Windows::Forms::Timer^ Loop;
		private: System::ComponentModel::IContainer^ components;

		private:
			/// <summary>
			/// Variable del diseñador necesaria.
			/// </summary>


			#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				this->PnlBackground = (gcnew System::Windows::Forms::Panel());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->lblPuntaje = (gcnew System::Windows::Forms::Label());
				this->Loop = (gcnew System::Windows::Forms::Timer(this->components));
				this->SuspendLayout();
				// 
				// PnlBackground
				// 
				this->PnlBackground->Location = System::Drawing::Point(1, 2);
				this->PnlBackground->Name = L"PnlBackground";
				this->PnlBackground->Size = System::Drawing::Size(994, 530);
				this->PnlBackground->TabIndex = 0;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(6, 542);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(55, 16);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Puntaje:";
				// 
				// lblPuntaje
				// 
				this->lblPuntaje->AutoSize = true;
				this->lblPuntaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->lblPuntaje->Location = System::Drawing::Point(58, 542);
				this->lblPuntaje->Name = L"lblPuntaje";
				this->lblPuntaje->Size = System::Drawing::Size(66, 16);
				this->lblPuntaje->TabIndex = 2;
				this->lblPuntaje->Text = L"lblPuntaje";
				// 
				// Loop
				// 
				this->Loop->Enabled = true;
				this->Loop->Interval = 50;
				this->Loop->Tick += gcnew System::EventHandler(this, &FrmBackground::Loop_Tick);
				// 
				// FrmBackground
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(994, 567);
				this->Controls->Add(this->lblPuntaje);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->PnlBackground);
				this->Name = L"FrmBackground";
				this->Text = L"FrmBackground";
				this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmBackground::FrmBackground_KeyDown);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
			#pragma endregion

		private:
			Graphics^ gBackground;
			BufferedGraphicsContext^ bfSpace;
			BufferedGraphics^ bfBackground;

			Bitmap^ bmpJugador;
			Bitmap^ bmpEnemigo;
			Bitmap^ bmpBomba;

			Enemigo* enemigo;
			Jugador* jugador;
			Controlador* controlador;
			int numberBackground = 1;

			void Animacion_Background() {
				Bitmap^ bmpBackground = gcnew Bitmap("resources/background" + numberBackground + ".png");
				bfBackground->Graphics->DrawImage(bmpBackground, 0, 0, 994, 530);
				delete bmpBackground;
			}


		#pragma region Windows Events
		private: System::Void Loop_Tick(System::Object^ sender, System::EventArgs^ e) {
			bfBackground->Graphics->Clear(Color::White);
			Animacion_Background();

			jugador->Draw(bfBackground->Graphics, bmpJugador);
			controlador->DrawEverything(bfBackground->Graphics, bmpBomba, bmpEnemigo);
			controlador->MoveEverything(bfBackground->Graphics);
			controlador->Collision(bfBackground->Graphics, jugador);

			lblPuntaje->Text = controlador->getPuntaje().ToString();
			
			if (controlador->getPuntaje() > 120) {
				Loop->Enabled = false;
				MessageBox::Show("El número de enemigos derrotados es: " + controlador->getEnemidosDerrotados());
			}

			if (controlador->terminoJuego()) {
				Loop->Enabled = false;
				MessageBox::Show("Terminó el juego");
			}

			/* Añadimos aleatoriamiente enemigos */
			if ((rand() % (50 - 10 + 1) + 10) == 35) {
				controlador->AddEnemigos(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);
			}

			bfBackground->Render(gBackground);
		}

		private: System::Void FrmBackground_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode) {
				case Keys::W: jugador->Move(bfBackground->Graphics, 'W'); break;
				case Keys::S: jugador->Move(bfBackground->Graphics, 'S'); break;
				case Keys::A: jugador->Move(bfBackground->Graphics, 'A'); break;
				case Keys::D: jugador->Move(bfBackground->Graphics, 'D'); break;
				case Keys::B: controlador->AddBombas(new Bomba(jugador->getX(), jugador->getY(), bmpBomba->Width, bmpBomba->Height, jugador->getDirection())); break;
				case Keys::O: 
					if (numberBackground == 1) numberBackground = 2;
					else numberBackground = 1;
					break;
			}
		}
		#pragma endregion
	};
}
