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
			//
			//TODO: agregar código de constructor aquí
			//
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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;



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
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 297);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del insumo";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(115, 116);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 255);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoInsumo::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Agregar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoInsumo::button1_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(115, 206);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(115, 163);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(27, 206);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Unidad:";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(27, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Stock:";
			// 
			// label3
			// 
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
			this->label2->Location = System::Drawing::Point(26, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(115, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(26, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id:";
			// 
			// frmNuevoInsumo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 318);
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
		nuevoInsumo->Id = Convert::ToInt32(textBox1->Text);
		nuevoInsumo->Nombre = textBox2->Text;
		nuevoInsumo->Tipo = textBox4->Text;
		nuevoInsumo->Stock = Convert::ToSingle(textBox3->Text);
		nuevoInsumo->Unidad = textBox5->Text;
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
