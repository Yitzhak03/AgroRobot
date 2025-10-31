#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Agregar referencias a los modelos y controladores necesarios
	using namespace AgroRobotModel;
	using namespace AgroRobotController;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de frmVerListadoInsumos
	/// </summary>
	public ref class frmVerListadoInsumos : public System::Windows::Forms::Form {
	public:
		frmVerListadoInsumos(void)
		{
			InitializeComponent();
		}
		/// <summary>
		/// Nuevo constructor que recibe un insumo y su lista de stocks
		/// </summary>
		frmVerListadoInsumos(Insumo^ insumo, List<StockInsumo^>^ stocks)
		{
			InitializeComponent();
			// Guardar referencias en los campos de la clase
			this->insumoActual = insumo;
			this->listaStocks = stocks;
			// Mostrar los datos del insumo en los TextBox
			this->textBox1->Text = Convert::ToString(insumo->Id);
			this->textBox2->Text = insumo->Nombre;
			this->textBox3->Text = insumo->Tipo;
			this->textBox4->Text = insumo->Unidad;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmVerListadoInsumos()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private:
		Insumo^ insumoActual;
		List<StockInsumo^>^ listaStocks;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(11, 197);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(363, 247);
			this->panel1->TabIndex = 3;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmVerListadoInsumos::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 33);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 67);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 106);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Tipo: ";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(86, 30);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(86, 66);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(86, 103);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(95, 20);
			this->textBox3->TabIndex = 6;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(204, 167);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del insumo";
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(220, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(154, 143);
			this->panel2->TabIndex = 4;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmVerListadoInsumos::panel2_Paint);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 139);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Unidad:";
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(86, 136);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(95, 20);
			this->textBox4->TabIndex = 6;
			// 
			// frmVerListadoInsumos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 504);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmVerListadoInsumos";
			this->Text = L"frmVerListadoInsumos";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		/// <summary>
		///	Pinta cuadrados en el panel que contienen el stock y el almacen correspondiente. Verde si el stock está dentro de los límites, rojo si está por debajo del límite bajo, amarillo si está por encima del límite alto.
		/// </summary>
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ graphics = e->Graphics;
		int x = 30, y = 30;
		//for each (StockInsumo ^ stock in listaStocks) {
		//	// Dibujar un rectángulo para cada stock
		//	Rectangle rect = Rectangle(x, y, 50, 50);
		//	graphics->DrawRectangle(Pens::Black, rect);
		//	graphics->FillRectangle(Brushes::LightGreen, rect);
		//	// Dibujar el texto del stock dentro del rectángulo
		//	String^ stockText = String::Format("Stock: {0}", stock->Stock);
		//	graphics->DrawString(stockText, gcnew System::Drawing::Font("Arial", 8), Brushes::Black, x + 5, y + 15);
		//	// Actualizar las coordenadas para el siguiente rectángulo
		//	x += 70;
		//	if (x + 50 > panel1->Width) {
		//		x = 30;
		//		y += 70;
		//	}
		//}
		for each (StockInsumo ^ stock in listaStocks) {
			// Determinar el color según los límites
			Brush^ brush;
			if (stock->Stock < stock->LimiteBajo) {
				brush = Brushes::Red; // Por debajo del límite bajo
			} else if (stock->Stock > stock->LimiteAlto) {
				brush = Brushes::Yellow; // Por encima del límite alto
			} else {
				brush = Brushes::LightGreen; // Dentro de los límites
			}
			// Dibujar un rectángulo para cada stock
			int width = 130;
			int height = 60;
			Rectangle rect = Rectangle(x, y, width, height);
			graphics->DrawRectangle(Pens::Black, rect);
			graphics->FillRectangle(brush, rect);
			// Dibujar el texto del stock y el almacén dentro del rectángulo
			String^ stockText = String::Format("Stock: {0}", stock->Stock);
			String^ almacenText = String::Format("Almacén: {0}", stock->Almacenn->Nombre);
			graphics->DrawString(stockText, gcnew System::Drawing::Font("Arial", 8), Brushes::Black, x + 5, y + 20);
			graphics->DrawString(almacenText, gcnew System::Drawing::Font("Arial", 8), Brushes::Black, x + 5, y + 40);
			// Actualizar las coordenadas para el siguiente rectángulo
			x += width + 20;
			if (x + width > panel1->Width) {
				x = 30;
				y += height + 20;
			}
		}
	}
	/// <summary>
	/// Informacion de colores verde, amarillo, rojo del panel1
	/// </summary>
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ graphics = e->Graphics;
		// Verde
		Rectangle rectVerde = Rectangle(10, 10, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectVerde);
		graphics->FillRectangle(Brushes::LightGreen, rectVerde);
		graphics->DrawString("Stock en rango", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, 15);
		// Amarillo
		Rectangle rectAmarillo = Rectangle(10, 40, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectAmarillo);
		graphics->FillRectangle(Brushes::Yellow, rectAmarillo);
		graphics->DrawString("Alto stock", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, 45);
		// Rojo
		Rectangle rectRojo = Rectangle(10, 70, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectRojo);
		graphics->FillRectangle(Brushes::Red, rectRojo);
		graphics->DrawString("Bajo stock", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, 75);
	}
	};
}
