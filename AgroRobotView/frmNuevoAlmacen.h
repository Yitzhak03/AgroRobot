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
			//
			//TODO: agregar código de constructor aquí
			//
			aplicarEstilo();
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
	private: void aplicarEstilo()
	{
		System::Drawing::Font^ fuenteGeneral = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Regular);
		System::Drawing::Font^ fuenteNegrita = gcnew System::Drawing::Font("Segoe UI Semibold", 10, FontStyle::Bold);

		this->BackColor = System::Drawing::Color::FromArgb(232, 245, 233);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Registrar nueva dieta";

		array<GroupBox^>^ grupos = { groupBox1 };
		for each (GroupBox ^ g in grupos)
		{
			g->BackColor = System::Drawing::Color::FromArgb(240, 250, 240);
			g->Font = fuenteNegrita;
			g->ForeColor = System::Drawing::Color::FromArgb(45, 85, 45);
		}

		array<Label^>^ etiquetas = { this->label1, this->label2, this->label6 };
		for each (Label ^ lbl in etiquetas)
		{
			lbl->Font = fuenteGeneral;
			lbl->ForeColor = System::Drawing::Color::FromArgb(35, 75, 45);
		}

		array<TextBox^>^ textos = { textBox1, textBox2, textBox3};
		for each (TextBox ^ t in textos)
		{
			t->Font = fuenteGeneral;
			t->BackColor = System::Drawing::Color::White;
			t->ForeColor = System::Drawing::Color::FromArgb(30, 70, 40);
			t->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		}

		array<Button^>^ botones = { button1, button2 };
		for each (Button ^ b in botones)
		{
			b->FlatStyle = FlatStyle::Flat;
			b->FlatAppearance->BorderSize = 0;
			b->BackColor = System::Drawing::Color::FromArgb(183, 223, 185);
			b->ForeColor = System::Drawing::Color::FromArgb(20, 60, 30);
			b->Font = fuenteNegrita;
			b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(153, 203, 155);
		}
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
		Almacen^ nuevoAlmacen = gcnew Almacen();
		AlmacenController^ aCtrl = gcnew AlmacenController();
		//Asignar valores al nuevo almacén
		nuevoAlmacen->Id = Convert::ToInt32(this->textBox1->Text);
		nuevoAlmacen->Nombre = this->textBox2->Text;
		nuevoAlmacen->Ubicacion = this->textBox3->Text;
		//Guardar el nuevo almacén
		aCtrl->agregarAlmacen(nuevoAlmacen);
		this->Close();
		//Mensaje de confirmación
		MessageBox::Show("Almacén guardado correctamente.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}
