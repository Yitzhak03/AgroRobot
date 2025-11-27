#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Referencias a controladores y modelos
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmNuevoAlmacen
	/// </summary>
	public ref class frmNuevoAlmacen : public System::Windows::Forms::Form {
	public:
		frmNuevoAlmacen(void)
		{
			InitializeComponent();
			// Aplicar el diseño Menta/Bosque al iniciar
			AplicarEstiloProfesional();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoAlmacen()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;

		   // ===================================================================================
		   // MÉTODO DE ESTILO PROFESIONAL (MENTA/BOSQUE - VERSIÓN DIÁLOGO)
		   // ===================================================================================
	private: void AplicarEstiloProfesional()
	{
		// 1. PALETA DE COLORES
		System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);   // Menta Pálido
		System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240);   // Menta Crema
		System::Drawing::Color colorBtnPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Bosque
		System::Drawing::Color colorBtnCancelar = System::Drawing::Color::FromArgb(220, 220, 220); // Gris claro
		System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45);    // Verde Petróleo
		System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);    // Verde Azulado

		// 2. FUENTES (Explícitas)
		System::Drawing::Font^ fontTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Bold);
		System::Drawing::Font^ fontCuerpo = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Regular);
		System::Drawing::Font^ fontLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);

		// 3. CONFIGURACIÓN VENTANA
		this->BackColor = colorFondo;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Ventana fija
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Text = L"Registrar Nuevo Almacén";

		// 4. GROUPBOX
		this->groupBox1->BackColor = colorPanel;
		this->groupBox1->Font = fontTitulo;
		this->groupBox1->ForeColor = colorTextoSec;

		// Centrado visual del GroupBox
		this->groupBox1->Left = (this->ClientSize.Width - this->groupBox1->Width) / 2;
		this->groupBox1->Top = (this->ClientSize.Height - this->groupBox1->Height) / 2;

		// 5. ETIQUETAS (LABELS)
		array<Label^>^ etiquetas = { this->label1, this->label2, this->label6 };
		for each (Label ^ lbl in etiquetas)
		{
			lbl->Font = fontLabel;
			lbl->ForeColor = colorTextoMain;
		}

		// 6. CAJAS DE TEXTO
		array<TextBox^>^ textos = { textBox1, textBox2, textBox3 };
		for each (TextBox ^ t in textos)
		{
			t->Font = fontCuerpo;
			t->BackColor = System::Drawing::Color::White;
			t->ForeColor = System::Drawing::Color::Black;
			t->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		}
		// ID ReadOnly visual
		this->textBox1->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);

		// 7. BOTONES
		// Botón Guardar (Primario)
		EstilarBotonPrimario(this->button1, colorBtnPrimario, fontTitulo);

		// Botón Cancelar (Secundario)
		EstilarBotonSecundario(this->button2, colorBtnCancelar, System::Drawing::Color::Black, System::Drawing::Color::Gray, fontTitulo);
	}

		   // Helpers de Estilo
		   void EstilarBotonPrimario(Button^ btn, Color backColor, System::Drawing::Font^ font) {
			   btn->BackColor = backColor;
			   btn->ForeColor = System::Drawing::Color::White;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderSize = 0;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

		   void EstilarBotonSecundario(Button^ btn, Color backColor, Color foreColor, Color borderColor, System::Drawing::Font^ font) {
			   btn->BackColor = backColor;
			   btn->ForeColor = foreColor;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderColor = borderColor;
			   btn->FlatAppearance->BorderSize = 1;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(16, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(275, 260);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del almacén";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(13, 139);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 21);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Ubicación:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(139, 192);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoAlmacen::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 192);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoAlmacen::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(105, 135);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 22);
			this->textBox3->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(105, 87);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(12, 91);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre:";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(105, 38);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 42);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id:";
			// 
			// frmNuevoAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 289);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmNuevoAlmacen";
			this->Text = L"AgroRobot - Nuevo almacén ";
			this->Load += gcnew System::EventHandler(this, &frmNuevoAlmacen::frmNuevoAlmacen_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevoAlmacen_Load(System::Object^ sender, System::EventArgs^ e)
	{
		AlmacenController^ aCtrl = gcnew AlmacenController();
		//Generar un Id automático
		this->textBox1->Text = Convert::ToString(aCtrl->generarNuevoId());
	}
		   //========================================================================
		   //==============================Cancelar==================================
		   //========================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
		   //========================================================================
		   //===============================Guardar==================================
		   //========================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Validación básica
		if (String::IsNullOrWhiteSpace(textBox2->Text) || String::IsNullOrWhiteSpace(textBox3->Text)) {
			MessageBox::Show("Por favor complete todos los campos.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Almacen^ nuevoAlmacen = gcnew Almacen();
		AlmacenController^ aCtrl = gcnew AlmacenController();

		//Asignar valores al nuevo almacén
		nuevoAlmacen->Id = Convert::ToInt32(this->textBox1->Text);
		nuevoAlmacen->Nombre = this->textBox2->Text;
		nuevoAlmacen->Ubicacion = this->textBox3->Text;

		//Guardar el nuevo almacén
		aCtrl->agregarAlmacen(nuevoAlmacen);

		//Mensaje de confirmación
		MessageBox::Show("Almacén guardado correctamente.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	};
}