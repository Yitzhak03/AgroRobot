#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmNuevoMuestraS
	/// </summary>
	public ref class frmNuevoMuestraS : public System::Windows::Forms::Form
	{
	public:
		frmNuevoMuestraS(void)
		{
			InitializeComponent();

			this->Load += gcnew System::EventHandler(this, &frmNuevoMuestraS::frmNuevoMuestraS_Load);
		}

		frmNuevoMuestraS(int idAnimal, MuestraController^ muestraController, GestorNutricionalController^ gc)
		{
			InitializeComponent();
			this->idAnimal = idAnimal;
			this->muestraController = muestraController;
			this->gestorNutricionalController = gc;
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->BackColor = System::Drawing::Color::LightGreen;
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->BackColor = System::Drawing::Color::LightGreen;
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoMuestraS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: int idAnimal;
	private: GestorNutricionalController^ gestorNutricionalController;
	private: MuestraController^ muestraController;
	
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(143, 368);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoMuestraS::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 368);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoMuestraS::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(22, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(207, 338);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos Sangre";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(96, 37);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(11, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"ID Muesta:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(96, 300);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 303);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Fecha:";
			this->label6->Click += gcnew System::EventHandler(this, &frmNuevoMuestraS::label6_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Sí", L"No" });
			this->comboBox2->Location = System::Drawing::Point(96, 211);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 21);
			this->comboBox2->TabIndex = 10;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Sí", L"No" });
			this->comboBox1->Location = System::Drawing::Point(96, 169);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 260);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Color:";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(11, 214);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 30);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Contaminación visible:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(96, 257);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 169);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 30);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Presencia de coágulos:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(96, 120);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 30);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Cantidad extraída:";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(96, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(11, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Especie:";
			// 
			// frmNuevoMuestraS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(270, 416);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmNuevoMuestraS";
			this->Text = L"AgroRobot - Nueva muestra";
			this->Load += gcnew System::EventHandler(this, &frmNuevoMuestraS::frmNuevoMuestraS_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		int idMuestra = Convert::ToInt32(this->textBox5->Text);
		int idAnimal = this->idAnimal;
		String^ cantidad = this->textBox2->Text;
		String^ coagulos = this->comboBox1->Text;
		String^ contaminacion = this->comboBox2->Text;
		String^ color = this->textBox3->Text;
		String^ fecha = this->textBox4->Text;

		// Validaciones básicas
		if (String::IsNullOrEmpty(cantidad) || String::IsNullOrEmpty(color) || String::IsNullOrEmpty(fecha)) {
			MessageBox::Show("Complete todos los campos obligatorios antes de guardar.");
			return;
		}

		// Consultar el animal asociado
		Animal^ animal = this->gestorNutricionalController->consultarAnimalporId(idAnimal);
		if (animal == nullptr) {
			MessageBox::Show("No se encontró el animal asociado.");
			return;
		}

		// Crear objeto muestra
		Muestra^ nuevaMuestra = gcnew Muestra(idMuestra, "Sangre", fecha,
			"", "", "", "", cantidad, coagulos, contaminacion, color, animal);

		// Guardar en archivo
		this->muestraController->agregarMuestraArchivo(nuevaMuestra, this->gestorNutricionalController);

		MessageBox::Show("La muestra de sangre ha sido registrada con éxito.");
		this->Close();
	}
	private: System::Void frmNuevoMuestraS_Load(System::Object^ sender, System::EventArgs^ e) {
		// Generar nuevo idMuestra
		int nuevoId = this->muestraController->generarNuevoId();
		this->textBox5->Text = Convert::ToString(nuevoId);
		this->textBox5->ReadOnly = true;

		// Consultar el animal asociado
		Animal^ animal = this->gestorNutricionalController->consultarAnimalporId(this->idAnimal);
		if (animal != nullptr) {
			this->textBox1->Text = animal->Especie;   // mostrar especie
			this->textBox1->ReadOnly = true;
		}
		else {
			this->textBox1->Text = "No encontrado";
			this->textBox1->ReadOnly = true;
		}
	}
};
}
