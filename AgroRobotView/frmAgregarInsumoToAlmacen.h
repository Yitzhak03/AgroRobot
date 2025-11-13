#pragma once
#include "frmNuevoStock2.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// Agregar referencia al controlador de almacenes
	using namespace AgroRobotController;
	using namespace System::Collections::Generic; //Para List<>
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmAgregarInsumoToAlmacen
	/// </summary>
	public ref class frmAgregarInsumoToAlmacen : public System::Windows::Forms::Form {
	public:
		frmAgregarInsumoToAlmacen(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			aplicarEstilo();
		}
		frmAgregarInsumoToAlmacen(int idAlmacen)
		{
			InitializeComponent();
			this->idAlmacenDestino = idAlmacen;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarInsumoToAlmacen()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: int idAlmacenDestino;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;

		   void aplicarEstilo()
		   {
			   this->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);

			   this->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10, FontStyle::Regular);
			   this->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);

			   array<TextBox^>^ textos = { this->textBox1, this->textBox2 };
			   for each (TextBox ^ t in textos) {
				   t->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
				   t->ForeColor = System::Drawing::Color::White;
				   t->BorderStyle = BorderStyle::FixedSingle;
				   t->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			   }

			   this->button1->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			   this->button1->FlatStyle = FlatStyle::Flat;
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->ForeColor = System::Drawing::Color::Black;
			   this->button1->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);


			   this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(45, 93, 80);
			   this->dataGridView1->BorderStyle = BorderStyle::None;
			   this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(30, 61, 54);
			   this->dataGridView1->EnableHeadersVisualStyles = false;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
			   this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			   this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;

			   array<Button^>^ botones = { this->button2, this->button3, this->button1, this->button4};
			   for each (Button ^ b in botones) {
				   b->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
				   b->FlatStyle = FlatStyle::Flat;
				   b->FlatAppearance->BorderSize = 0;
				   b->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);
				   b->ForeColor = System::Drawing::Color::Black;
				   b->Cursor = Cursors::Hand;
			   }

			   // 🏷️ Etiquetas
			   array<Label^>^ labels = { this->label1 };
			   for each (Label ^ l in labels) {
				   l->ForeColor = System::Drawing::Color::White;
				   l->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			   }

			   // 📏 Config general
			   this->Text = L"AgroRobot - Mantenimiento de Roles";
			   this->StartPosition = FormStartPosition::CenterScreen;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6)
			{
				this->Column7,
					this->Column1, this->Column2, this->Column9, this->Column10, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(37, 104);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(335, 328);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6)
			{
				this->Column8,
					this->Column4, this->Column5, this->Column11, this->Column12, this->Column6
			});
			this->dataGridView2->Location = System::Drawing::Point(522, 104);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(334, 328);
			this->dataGridView2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(401, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Añadir  > >";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(401, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 30);
			this->button2->TabIndex = 3;
			this->button2->Text = L"< <   Quitar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(401, 120);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 20);
			this->textBox1->TabIndex = 4;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(37, 67);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(228, 21);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->DropDown += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::comboBox1_DropDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Origen:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(519, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Destino:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(522, 67);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(212, 20);
			this->textBox2->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(272, 66);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Buscar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(740, 66);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(87, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Actualizar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(398, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Cantidad a transferir:";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Id";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 30;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Nombre";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Stock";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 50;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Min";
			this->Column11->Name = L"Column11";
			this->Column11->ReadOnly = true;
			this->Column11->Width = 50;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"Max";
			this->Column12->Name = L"Column12";
			this->Column12->ReadOnly = true;
			this->Column12->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Unidad";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 50;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Id";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 30;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Nombre";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Stock";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 50;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Min";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Width = 50;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Max";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			this->Column10->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Unidad";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 50;
			// 
			// frmAgregarInsumoToAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(916, 485);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmAgregarInsumoToAlmacen";
			this->Text = L"frmAgregarInsumoToAlmacen";
			this->Load += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::frmAgregarInsumoToAlmacen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Mostrar todos los nombres de los almacenes existentes
	private: System::Void comboBox1_DropDown(System::Object^ sender, System::EventArgs^ e)
	{
		//Cargar los nombres de los almacenes en el comboBox
		comboBox1->Items->Clear();
		AlmacenController^ almacenCtrl = gcnew AlmacenController();
		List<String^>^ nombres = almacenCtrl->obtenerNombresAlmacenes();
		for each (String ^ nombre in nombres) {
			comboBox1->Items->Add(nombre);
		}
	}
		   //Mostrar los insumos del almacén seleccionado al cerrar el comboBox
	/*private: System::Void comboBox1_DropDownClosed(System::Object^ sender, System::EventArgs^ e)
	{
		String^ nombreAlmacen = comboBox1->Text;
		AlmacenController^ aCtrl = gcnew AlmacenController();
		Almacen^ almacen = aCtrl->obtenerAlmacenPorNombre(nombreAlmacen);
		if (almacen != nullptr) {
			StockInsumoController^ sCtrl = gcnew StockInsumoController();
			List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen(almacen->Id);
			mostrarGrilla(listaStockInsumos);
		}
	}*/
	//Mostrar la grilla de insumos del almacén seleccionado
	private: System::Void mostrarGrilla1(List<StockInsumo^>^ lista)
	{
		dataGridView1->Rows->Clear();
		for each (StockInsumo ^ stockInsumo in lista) {
			dataGridView1->Rows->Add(
				stockInsumo->Id,
				stockInsumo->Insumoo->Nombre,
				Convert::ToString(stockInsumo->Stock),
				stockInsumo->LimiteBajo,
				stockInsumo->LimiteAlto,
				stockInsumo->Insumoo->Unidad
			);
		}
	}
	private: System::Void mostrarGrilla2(List<StockInsumo^>^ lista)
	{
		dataGridView2->Rows->Clear();
		for each (StockInsumo ^ stockInsumo in lista) {
			dataGridView2->Rows->Add(
				stockInsumo->Id,
				stockInsumo->Insumoo->Nombre,
				Convert::ToString(stockInsumo->Stock),
				stockInsumo->LimiteBajo,
				stockInsumo->LimiteAlto,
				stockInsumo->Insumoo->Unidad
			);
		}
	}
		   //Acción al presionar el boton de buscar
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ nombreAlmacen = comboBox1->Text;
		AlmacenController^ aCtrl = gcnew AlmacenController();
		Almacen^ almacen = aCtrl->obtenerAlmacenPorNombre(nombreAlmacen);
		if (almacen != nullptr) {
			StockInsumoController^ sCtrl = gcnew StockInsumoController();
			List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen(almacen->Id);
			mostrarGrilla1(listaStockInsumos);
		}
	}
		   //Mostrar nombre y grilla del almacén destino al cargar el formulario
	private: System::Void frmAgregarInsumoToAlmacen_Load(System::Object^ sender, System::EventArgs^ e)
	{
		AlmacenController^ aCtrl = gcnew AlmacenController();
		String^ nombreAlmacen = aCtrl->buscarNombrePorId(this->idAlmacenDestino);
		textBox2->Text = nombreAlmacen;
		//Mostrar la grilla del almacén destino
		StockInsumoController^ sCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen(this->idAlmacenDestino);
		mostrarGrilla2(listaStockInsumos);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Validar si existe el insumo en el almacén destino por nombre
		if (dataGridView1->SelectedRows->Count > 0) {
			StockInsumoController^ sCtrl = gcnew StockInsumoController();
			//Obtener el insumo seleccionado del dataGridView1
			int idStock = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
			StockInsumo^ stockOrigen = sCtrl->buscarPorId(idStock);
			//Verificar si el insumo ya existe en el almacén destino
			//buscarPorIdInsumoYAlmacen
			StockInsumo^ stockDestino = sCtrl->buscarPorIdInsumoYAlmacen(stockOrigen->Insumoo->Id, this->idAlmacenDestino);
			if (stockDestino != nullptr) {
				//Si existe, actualizar ambos stocks de acuerdo a la cantidad a transferir 
				float cantidadATransferir = Convert::ToSingle(textBox1->Text);
				stockOrigen->Stock -= cantidadATransferir;
				stockDestino->Stock += cantidadATransferir;
				sCtrl->actualizarStockInsumo(stockOrigen);
				sCtrl->actualizarStockInsumo(stockDestino);
			} else {
				//Si no existe, mostrar mensaje para agregar limites de stock minimo y maximo
				MessageBox::Show("El insumo no existe en el almacén destino. Por favor, agregue los límites de stock mínimo y máximo en la siguiente ventana.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Information);
				frmNuevoStock2^ frm = gcnew frmNuevoStock2(stockOrigen, this->idAlmacenDestino, Convert::ToSingle(textBox1->Text));
				frm->ShowDialog();

			}

		} else {
			MessageBox::Show("Seleccione un insumo para agregar.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}
		   //Actualizar grilla del almacén destino
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		StockInsumoController^ sCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen(this->idAlmacenDestino);
		mostrarGrilla2(listaStockInsumos);
	}
	};
}
