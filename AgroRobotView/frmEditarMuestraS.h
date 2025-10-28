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
	/// Resumen de frmEditarMuestraS
	/// </summary>
	public ref class frmEditarMuestraS : public System::Windows::Forms::Form
	{
	public:
		frmEditarMuestraS(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarMuestraS(Muestra^ muestra, MuestraController^ muestraController)
		{
			InitializeComponent();
			this->muestra = muestra;
			this->muestraController = muestraController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarMuestraS()
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
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
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
	private: Muestra^ muestra;
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
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(150, 363);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Guardar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmEditarMuestraS::button1_Click);
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
			this->groupBox1->Location = System::Drawing::Point(39, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(207, 315);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos Sangre";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(101, 277);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 280);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Fecha:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"SI", L"NO" });
			this->comboBox2->Location = System::Drawing::Point(101, 188);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 21);
			this->comboBox2->TabIndex = 10;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"SI", L"NO" });
			this->comboBox1->Location = System::Drawing::Point(101, 146);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Color:";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(16, 191);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 30);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Contaminacion visible:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(101, 234);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(16, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 30);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Presencia de coagulos:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(16, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 30);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Cantidad extraida:";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(101, 57);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(16, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Animal:";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(101, 24);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(16, 27);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"ID Muesta:";
			// 
			// frmEditarMuestraS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 398);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEditarMuestraS";
			this->Text = L"frmEditarMuestraS";
			this->Load += gcnew System::EventHandler(this, &frmEditarMuestraS::frmEditarMuestraS_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int idMuestra = Convert::ToInt32(textBox5->Text);
		int idAnimal = Convert::ToInt32(textBox1->Text);
		String^ cantidad = textBox2->Text;
		String^ coagulos = comboBox1->Text;
		String^ contaminacion = comboBox2->Text;
		String^ color = textBox3->Text;
		String^ fecha = textBox4->Text;

		Muestra^ muestraEditada = gcnew Muestra(idMuestra, idAnimal, "Sangre", fecha,
			"", "", "", "", cantidad, color, coagulos, contaminacion);

		muestraController->editarMuestraArchivo(idMuestra, muestraEditada);
		MessageBox::Show("Muestra editada correctamente.");
		this->Close();
	}
	private: System::Void frmEditarMuestraS_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox5->Text = Convert::ToString(this->muestra->getIdMuestra());
		this->textBox1->Text = Convert::ToString(this->muestra->getIdAnimal());
		this->textBox2->Text = this->muestra->getCantidadExtraida();
		this->comboBox1->Text = this->muestra->getCoagulos();
		this->comboBox2->Text = this->muestra->getContaminacion();
		this->textBox3->Text = this->muestra->getColorSangre();
		this->textBox4->Text = this->muestra->getFechaToma();
	}
};
}
