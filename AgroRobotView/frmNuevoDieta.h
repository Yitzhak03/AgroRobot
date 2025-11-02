#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmNuevoDieta
	/// </summary>
	public ref class frmNuevoDieta : public System::Windows::Forms::Form
	{
	public:
		frmNuevoDieta(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmNuevoDieta(GestorNutricionalController^ dietaController)
		{
			InitializeComponent();
			this->dietaController = dietaController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoDieta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: GestorNutricionalController^ dietaController;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(28, 22);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(383, 300);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(232, 245);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(232, 193);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(232, 141);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(232, 87);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(232, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(63, 251);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Frecuencia:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(63, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Alimentos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(64, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Fecha Inicio:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID Animal: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 352);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoDieta::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(260, 352);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoDieta::button2_Click);
			// 
			// frmNuevoDieta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(460, 426);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmNuevoDieta";
			this->Text = L"frmNuevoDieta";
			this->Load += gcnew System::EventHandler(this, &frmNuevoDieta::frmNuevoDieta_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevoDieta_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
		int maxId = 0;
		for each (Dieta^ dieta in listaDietas) {
			if (dieta->Id > maxId) {
				maxId = dieta->Id;
			}
		}
		this->textBox1->Text = Convert::ToString(maxId + 1);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(this->textBox1->Text);
		int idAnimal = Convert::ToInt32(this->textBox2->Text);
		String^ fechaInicio = this->textBox3->Text;
		String^ alimentos = this->textBox4->Text;
		String^ frecuencia = this->textBox5->Text;
		if (id == 0 || idAnimal == 0 || fechaInicio->Equals("") || alimentos->Equals("") || frecuencia->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Dieta^ nuevaDieta = gcnew Dieta(id, idAnimal, fechaInicio, alimentos, frecuencia, gcnew List<OrdenDistribucion^>());
		this->dietaController->registrarDieta(nuevaDieta);
		MessageBox::Show("Dieta agregada correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	};
}
