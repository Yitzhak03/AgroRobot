#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Referencia al Controlador y Modelo
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmNuevoInsumo
	/// </summary>
	public ref class frmNuevoInsumo : public System::Windows::Forms::Form {
	public:
		frmNuevoInsumo(void)
		{
			InitializeComponent();

			// 1. Aplicar diseño profesional
			AplicarEstiloProfesional();

			// 2. Lógica de negocio
			InsumoController^ insumoCtrl = gcnew InsumoController();
			int nuevoId = insumoCtrl->generarNuevoId();
			this->textBox1->Text = Convert::ToString(nuevoId);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoInsumo()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::GroupBox^ groupBox1;

		   // ===================================================================================
		   // MÉTODO DE ESTILO PROFESIONAL (MENTA/BOSQUE - VERSIÓN DIÁLOGO)
		   // ===================================================================================
		   void AplicarEstiloProfesional() {
			   // 1. PALETA DE COLORES
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);   // Menta Pálido
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240);   // Menta Crema
			   System::Drawing::Color colorBtnPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Bosque
			   System::Drawing::Color colorBtnCancelar = System::Drawing::Color::FromArgb(220, 220, 220); // Gris claro
			   System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45);    // Verde Petróleo
			   System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);    // Verde Azulado

			   // 2. FUENTES (Explícitas para evitar error con this->Font)
			   System::Drawing::Font^ fontTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Bold);
			   System::Drawing::Font^ fontCuerpo = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Regular);
			   System::Drawing::Font^ fontLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);

			   // 3. CONFIGURACIÓN VENTANA (Dialog Mode)
			   this->BackColor = colorFondo;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Estilo Dialogo fijo
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->StartPosition = FormStartPosition::CenterScreen; // Centrado en pantalla
			   this->Text = "Registrar Nuevo Insumo";

			   // 4. ESTILIZADO DEL GROUPBOX
			   this->groupBox1->BackColor = colorPanel;
			   this->groupBox1->ForeColor = colorTextoSec; // Color del título del grupo
			   this->groupBox1->Font = fontTitulo;

			   // Centrar GroupBox en el formulario (por si cambiamos tamaño)
			   this->groupBox1->Left = (this->ClientSize.Width - this->groupBox1->Width) / 2;
			   this->groupBox1->Top = (this->ClientSize.Height - this->groupBox1->Height) / 2;

			   // 5. ESTILIZADO DE CONTROLES INTERNOS (Labels y TextBoxes)
			   array<Label^>^ labels = { label1, label2, label3, label5 };
			   for each (Label ^ lbl in labels) {
				   lbl->ForeColor = colorTextoMain;
				   lbl->Font = fontLabel;
			   }

			   array<TextBox^>^ txts = { textBox1, textBox2, textBox4, textBox5 };
			   for each (TextBox ^ txt in txts) {
				   txt->Font = fontCuerpo;
				   txt->BackColor = System::Drawing::Color::White;
				   txt->ForeColor = System::Drawing::Color::Black;
				   txt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   }
			   // El ID suele ser ReadOnly, le damos un toque visual
			   this->textBox1->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);

			   // 6. ESTILIZADO DE BOTONES
			   // Botón 1: AGREGAR (Primario - Verde)
			   EstilarBotonPrimario(this->button1, colorBtnPrimario, fontTitulo);

			   // Botón 2: CANCELAR (Secundario - Gris)
			   EstilarBotonSecundario(this->button2, colorBtnCancelar, System::Drawing::Color::Black, System::Drawing::Color::Gray, fontTitulo);
		   }

		   // Helpers
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(26, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id:";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(115, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(26, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(115, 71);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(27, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Tipo:";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(27, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Unidad:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(115, 160);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(29, 205);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Agregar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoInsumo::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(140, 205);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 29);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoInsumo::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(115, 116);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 12;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 256);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del insumo";
			// 
			// frmNuevoInsumo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(251)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(284, 278);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmNuevoInsumo";
			this->Text = L"frmNuevoInsumo";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//===============================================================================
		//==============================Agregar==========================================
		//===============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Crear el objeto Insumo
		Insumo^ nuevoInsumo = gcnew Insumo();
		// Validación simple de ID numérico
		try {
			nuevoInsumo->Id = Convert::ToInt32(textBox1->Text);
		}
		catch (...) {
			MessageBox::Show("ID inválido", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		nuevoInsumo->Nombre = textBox2->Text;
		nuevoInsumo->Tipo = textBox4->Text;
		nuevoInsumo->Unidad = textBox5->Text;

		// Validación de campos vacíos
		if (String::IsNullOrWhiteSpace(nuevoInsumo->Nombre) || String::IsNullOrWhiteSpace(nuevoInsumo->Tipo)) {
			MessageBox::Show("Por favor complete todos los campos.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Crear el controlador y agregar el insumo
		InsumoController^ insumoCtrl = gcnew InsumoController();
		insumoCtrl->agregarInsumo(nuevoInsumo);

		// Mensaje de confirmación
		MessageBox::Show("Insumo agregado correctamente.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Cerrar el formulario
		this->Close();
	}
		   //===============================================================================
		   //==============================Cancelar=========================================
		   //===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	};
}