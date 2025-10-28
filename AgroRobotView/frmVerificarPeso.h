#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmVerificarPeso
	/// </summary>
	public ref class frmVerificarPeso : public System::Windows::Forms::Form
	{
	public:
		double pesoEsperado;
		bool confirmado;

		frmVerificarPeso(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			confirmado = false;
			pesoEsperado = 0.0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmVerificarPeso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(45, 21);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(332, 133);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Control de peso:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Peso deseado:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(176, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(53, 90);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Consultar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmVerificarPeso::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(199, 90);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmVerificarPeso::button2_Click);
			// 
			// frmVerificarPeso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(453, 201);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmVerificarPeso";
			this->Text = L"frmVerificarPeso";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double pesoIngresado;
		if (!Double::TryParse(this->textBox1->Text, pesoIngresado) || pesoIngresado <= 0) {
			MessageBox::Show("Ingrese un valor numérico válido para el peso esperado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->pesoEsperado = pesoIngresado;
		this->confirmado = true;
		this->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->confirmado = false;
		this->Close();
	}
	};
}
