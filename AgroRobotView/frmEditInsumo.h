#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Referencia al modelo y controlador
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmEditInsumo
	/// </summary>
	public ref class frmEditInsumo : public System::Windows::Forms::Form {
	public:
		frmEditInsumo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmEditInsumo(int idInsumo)
		{
			InitializeComponent();
			//Se cargan los datos del insumo seleccionado
			InsumoController^ insumoCtrl = gcnew InsumoController();
			Insumo^ insumo = insumoCtrl->buscarPorId(idInsumo);
			this->textBox1->Text = Convert::ToString(insumo->Id);
			this->textBox2->Text = insumo->Nombre;
			this->textBox3->Text = insumo->Tipo;
			this->textBox5->Text = insumo->Unidad;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditInsumo()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 266);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del insumo";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(140, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmEditInsumo::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(29, 209);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Modificar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmEditInsumo::button1_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(115, 156);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(115, 113);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(27, 156);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Unidad:";
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
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(115, 71);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
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
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(115, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
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
			// frmEditInsumo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(251)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(287, 289);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEditInsumo";
			this->Text = L"frmEditInsumo";
			this->Load += gcnew System::EventHandler(this, &frmEditInsumo::frmEditInsumo_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//===============================================================================
		//==============================Cancelar=========================================
		//===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
		//===============================================================================
		//==============================Modificar========================================
		//===============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		InsumoController^ insumoCtrl = gcnew InsumoController();
		Insumo^ insumo = gcnew Insumo(
			Convert::ToInt32(this->textBox1->Text),
			this->textBox2->Text,
			this->textBox3->Text,
			this->textBox5->Text
		);
		insumoCtrl->actualizarInsumo(insumo);
		this->Close();
	}
	private: System::Void frmEditInsumo_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}
};
}
