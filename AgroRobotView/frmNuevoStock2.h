#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Referencias a los modelos y controladores
	using namespace AgroRobotModel;
	using namespace AgroRobotController;
	/// <summary>
	/// Resumen de frmNuevoStock2
	/// </summary>
	public ref class frmNuevoStock2 : public System::Windows::Forms::Form {
	public:
		frmNuevoStock2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmNuevoStock2(StockInsumo^ stockOri, int idAlm, float newStock)
		{
			InitializeComponent();
			this->stockOrigen = stockOri;
			this->idAlmacen = idAlm;
			this->nuevoStock = newStock;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoStock2()
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
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label1;
	private: StockInsumo^ stockOrigen;
		   int idAlmacen;
		   float nuevoStock;
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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 402);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del stock";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(115, 302);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(141, 346);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoStock2::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Agregar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoStock2::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(115, 262);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(27, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Máximo:";
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(115, 187);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 5;
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(27, 187);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 20);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Actual:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(115, 223);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(27, 223);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Mínimo:";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(27, 302);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Nuevo:";
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(116, 73);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(115, 151);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(27, 76);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Unidad:";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(26, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Estado:";
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(116, 33);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(115, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(27, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 17);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(26, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Almacén:";
			// 
			// frmNuevoStock2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(294, 424);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmNuevoStock2";
			this->Text = L"Nuevo Stock";
			this->Load += gcnew System::EventHandler(this, &frmNuevoStock2::frmNuevoStock2_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void frmNuevoStock2_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Cargar los datos del stock seleccionado en los campos correspondientes
		this->textBox6->Text = this->stockOrigen->Insumoo->Nombre;
		this->textBox7->Text = this->stockOrigen->Insumoo->Unidad;
		this->textBox1->Text = Convert::ToString(idAlmacen);
		// Indicar estado del stock
		this->textBox2->Text = "Nuevo";
		// Cargar los datos existentes
		this->textBox8->Text = "0";
		// Cargar el nuevo stock a agregar
		this->textBox4->Text = Convert::ToString(nuevoStock);
	}
		   //Agregar el nuevo stock al almacén destino y actualizar el stock del almacén origen
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		StockInsumoController^ sCtrl = gcnew StockInsumoController();
		//int nuevoId = sCtrl->generarNuevoId();
		AlmacenController^ aCtrl = gcnew AlmacenController();
		Almacen^ almacenDestino = aCtrl->buscarPorId_BD(this->idAlmacen);
		//Crear el nuevo stockInsumo para el almacén destino
		StockInsumo^ nuevoStockInsumo = gcnew StockInsumo(
			1,
			this->stockOrigen->Insumoo,
			almacenDestino,
			Convert::ToSingle(textBox4->Text),
			Convert::ToSingle(textBox5->Text),
			Convert::ToSingle(textBox3->Text)
		);
		sCtrl->agregarStockInsumo_BD(nuevoStockInsumo);
		//Actualizar el stock del almacén origen
		this->stockOrigen->Stock -= Convert::ToSingle(textBox4->Text);
		sCtrl->actualizarStockInsumo_BD(stockOrigen);
		MessageBox::Show("El insumo ha sido agregado al almacén destino correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	};
}
