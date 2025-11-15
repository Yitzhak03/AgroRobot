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
	/// Resumen de frmNuevoAnimal
	/// </summary>
	public ref class frmNuevoAnimal : public System::Windows::Forms::Form
	{
	public:
		frmNuevoAnimal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmNuevoAnimal(GestorNutricionalController^ animalController)
		{
			InitializeComponent();
			this->animalController = animalController;
			aplicarEstilo();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoAnimal()
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
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: GestorNutricionalController^ animalController;
	
	private: void aplicarEstilo()
	{
		System::Drawing::Font^ fuenteGeneral = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Regular);
		System::Drawing::Font^ fuenteNegrita = gcnew System::Drawing::Font("Segoe UI Semibold", 10, FontStyle::Bold);

		this->BackColor = System::Drawing::Color::FromArgb(232, 245, 233); 
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Registrar nuevo animal"; 

		array<GroupBox^>^ grupos = { groupBox1 };
		for each (GroupBox ^ g in grupos)
		{
			g->BackColor = System::Drawing::Color::FromArgb(240, 250, 240);
			g->Font = fuenteNegrita;
			g->ForeColor = System::Drawing::Color::FromArgb(45, 85, 45);
		}

		array<Label^>^ etiquetas = { label2, label3, label4, label5, label7, label8 };
		for each (Label ^ lbl in etiquetas)
		{
			lbl->Font = fuenteGeneral;
			lbl->ForeColor = System::Drawing::Color::FromArgb(35, 75, 45);
		}

		array<TextBox^>^ textos = { textBox1, textBox2, textBox3, textBox4, textBox5, textBox6 };
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
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(232, 405);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoAnimal::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(84, 405);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoAnimal::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(15, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(369, 356);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(219, 294);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 13;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(219, 242);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 12;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(219, 191);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(219, 144);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(219, 91);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 9;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(219, 41);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(51, 197);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 16);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Edad:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(51, 249);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Estado de salud: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(51, 300);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Ultima dieta:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(51, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Peso: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(51, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Especie: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(51, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID Animal:";
			// 
			// frmNuevoAnimal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 478);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmNuevoAnimal";
			this->Text = L"frmNuevoAnimal";
			this->Load += gcnew System::EventHandler(this, &frmNuevoAnimal::frmNuevoAnimal_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevoAnimal_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		int maxId = 0;
		for each (Animal ^ animal in listaAnimales) {
			if (animal->IdAnimal > maxId) {
				maxId = animal->IdAnimal;
			}
		}
		this->textBox1->Text = Convert::ToString(maxId + 1);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(this->textBox1->Text);
		String^ especie = this->textBox2->Text;
		double peso = Convert::ToDouble(this->textBox3->Text);
		double edad = Convert::ToDouble(this->textBox4->Text);
		String^ estadoSalud = this->textBox5->Text;
		String^ ultimaDieta = this->textBox6->Text;
		String^ ultimaVezAlimentado = "-";
		int vecesAlimentado = 0;
		if (id == 0 || especie->Equals("") || peso == 0.0 || edad == 0.0 || estadoSalud->Equals("") || ultimaDieta->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Animal^ nuevoAnimal = gcnew Animal(id, especie, peso, edad, estadoSalud, ultimaDieta, gcnew List<Muestra^>(), gcnew Dieta(), gcnew List<HistoriaClinica^>(), ultimaVezAlimentado, vecesAlimentado);
		this->animalController->registrarAnimal(nuevoAnimal);
		MessageBox::Show("Animal agregado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


	};
}
