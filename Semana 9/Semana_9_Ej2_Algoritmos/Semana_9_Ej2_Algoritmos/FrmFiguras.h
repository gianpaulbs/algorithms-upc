#pragma once
#include "Arr_Figuras.h"

namespace Semana9Ej2Algoritmos {

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
				g = this->CreateGraphics();
				r = gcnew Random();
				figuras = new Arr_Figuras();
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

		private: System::Windows::Forms::Timer^ loop;
		protected: private: System::ComponentModel::IContainer^ components;

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
				this->loop = (gcnew System::Windows::Forms::Timer(this->components));
				this->SuspendLayout();
				// 
				// loop
				// 
				this->loop->Enabled = true;
				this->loop->Tick += gcnew System::EventHandler(this, &FrmFiguras::loop_Tick);
				// 
				// FrmFiguras
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(928, 560);
				this->Name = L"FrmFiguras";
				this->Text = L"FrmFiguras";
				this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguras::FrmFiguras_Paint);
				this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmFiguras::FrmFiguras_KeyDown);
				this->ResumeLayout(false);

			}
			#pragma endregion

		private:
			Graphics^ g;
			Random^ r;
			Arr_Figuras* figuras;


		private: System::Void FrmFiguras_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Space) {
				figuras->agregar_triangulo(new Triangulo(r->Next(870), 1, 50));
			}
		}

		private: System::Void loop_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (r->Next(1000) % 50 == 0) {
				figuras->agregar_circulo(new Circulo(1, r->Next(500), 60));
			}

			figuras->mostrar_circulos(g);
			figuras->mostrar_triangulos(g);
			figuras->gestionar_colision_figuras(g);
		}

		private: System::Void FrmFiguras_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			g->Clear(Color::White);
		}
	};
}
