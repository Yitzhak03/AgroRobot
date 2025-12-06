#pragma once
#include "frmNuevoStock2.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;

	public ref class frmAgregarInsumoToAlmacen : public System::Windows::Forms::Form {
	public:
		frmAgregarInsumoToAlmacen(void)
		{
			InitializeComponent();
			AplicarEstiloCompacto();
		}

		frmAgregarInsumoToAlmacen(int idAlmacen)
		{
			InitializeComponent();
			this->idAlmacenDestino = idAlmacen;
			AplicarEstiloCompacto();
		}

	protected:
		~frmAgregarInsumoToAlmacen()
		{
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1; // Añadir
	private: System::Windows::Forms::Button^ button2; // Quitar (Oculto)
	private: System::Windows::Forms::TextBox^ textBox1; // Cantidad
	private: System::Windows::Forms::ComboBox^ comboBox1; // Origen Combo
	private: System::Windows::Forms::Label^ label1; // Lbl Origen
	private: System::Windows::Forms::Label^ label2; // Lbl Destino
	private: System::Windows::Forms::TextBox^ textBox2; // Destino Texto
	private: System::Windows::Forms::Button^ button3; // Buscar Origen
	private: int idAlmacenDestino;
	private: System::Windows::Forms::Button^ button4; // Actualizar Destino
	private: System::Windows::Forms::Label^ label3; // Lbl Cantidad

		   // Columnas (Las defino genéricas para no ocupar espacio visual aquí)
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;

		   // ===================================================================================
		   // MÉTODO DE ESTILO: MENTA/BOSQUE (VERSIÓN COMPACTA Y ORDENADA)
		   // ===================================================================================
		   void AplicarEstiloCompacto()
		   {
			   // 1. PALETA DE COLORES (Menta/Bosque)
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240);
			   System::Drawing::Color colorBtn = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Bosque
			   System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(22, 53, 45);
			   System::Drawing::Color colorLineas = System::Drawing::Color::FromArgb(183, 220, 200);

			   // 2. FUENTES (Tamaños estándar, nada gigante)
			   System::Drawing::Font^ fontLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);
			   System::Drawing::Font^ fontNormal = gcnew System::Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Regular);
			   System::Drawing::Font^ fontGridHead = gcnew System::Drawing::Font("Segoe UI Semibold", 9);

			   // 3. CONFIGURACIÓN DEL FORMULARIO
			   this->BackColor = colorFondo;
			   this->Text = "Transferencia de Insumos";
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MaximizeBox = false;
			   // Ajustamos el tamaño para que todo entre cómodo pero sin sobrar mucho espacio
			   this->ClientSize = System::Drawing::Size(920, 500);

			   // 4. RE-POSICIONAMIENTO ORDENADO (Manual layout para evitar desorden)
			   // Lado Izquierdo (ORIGEN)
			   int xIzq = 20;
			   int yTop = 20;

			   this->label1->Text = "Almacén Origen:";
			   this->label1->Font = fontLabel;
			   this->label1->ForeColor = colorTexto;
			   this->label1->Location = System::Drawing::Point(xIzq, yTop);

			   this->comboBox1->Location = System::Drawing::Point(xIzq, yTop + 25);
			   this->comboBox1->Size = System::Drawing::Size(220, 23);
			   this->comboBox1->Font = fontNormal;

			   this->button3->Text = "Cargar";
			   this->button3->Location = System::Drawing::Point(xIzq + 230, yTop + 24); // Al lado del combo
			   this->button3->Size = System::Drawing::Size(80, 25);
			   EstilarBoton(this->button3, colorBtn, fontLabel);

			   this->dataGridView1->Location = System::Drawing::Point(xIzq, yTop + 60);
			   this->dataGridView1->Size = System::Drawing::Size(380, 380);
			   EstilarGrillaCompacta(this->dataGridView1, colorPanel, colorTexto, colorLineas, fontGridHead, fontNormal);

			   // Lado Derecho (DESTINO)
			   int xDer = 520; // Dejamos espacio en el medio

			   this->label2->Text = "Almacén Destino:";
			   this->label2->Font = fontLabel;
			   this->label2->ForeColor = colorTexto;
			   this->label2->Location = System::Drawing::Point(xDer, yTop);

			   this->textBox2->Location = System::Drawing::Point(xDer, yTop + 25);
			   this->textBox2->Size = System::Drawing::Size(220, 23);
			   this->textBox2->Font = fontNormal;
			   this->textBox2->BackColor = System::Drawing::Color::FromArgb(235, 235, 235); // Gris suave para indicar ReadOnly

			   this->button4->Text = "Refrescar";
			   this->button4->Location = System::Drawing::Point(xDer + 230, yTop + 24);
			   this->button4->Size = System::Drawing::Size(80, 25);
			   EstilarBoton(this->button4, colorBtn, fontLabel);

			   this->dataGridView2->Location = System::Drawing::Point(xDer, yTop + 60);
			   this->dataGridView2->Size = System::Drawing::Size(380, 380);
			   EstilarGrillaCompacta(this->dataGridView2, colorPanel, colorTexto, colorLineas, fontGridHead, fontNormal);

			   // Centro (ACCIONES)
			   int xCentro = 410;
			   int yCentro = 200;

			   this->label3->Text = "Cantidad:";
			   this->label3->Font = fontLabel;
			   this->label3->ForeColor = colorTexto;
			   this->label3->Location = System::Drawing::Point(xCentro + 15, yCentro);
			   this->label3->AutoSize = true;

			   this->textBox1->Location = System::Drawing::Point(xCentro + 10, yCentro + 25);
			   this->textBox1->Size = System::Drawing::Size(90, 23);
			   this->textBox1->Font = fontNormal;
			   this->textBox1->TextAlign = HorizontalAlignment::Center;

			   this->button1->Text = "Añadir  >>";
			   this->button1->Location = System::Drawing::Point(xCentro + 10, yCentro + 60);
			   this->button1->Size = System::Drawing::Size(90, 35);
			   EstilarBoton(this->button1, colorBtn, fontLabel);
		   }

		   // Helpers compactos
		   void EstilarBoton(Button^ btn, Color back, System::Drawing::Font^ font) {
			   btn->BackColor = back;
			   btn->ForeColor = Color::White;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderSize = 0;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

		   void EstilarGrillaCompacta(DataGridView^ dgv, Color headBack, Color fore, Color line, System::Drawing::Font^ fHead, System::Drawing::Font^ fCell) {
			   dgv->BackgroundColor = Color::White;
			   dgv->BorderStyle = BorderStyle::FixedSingle; // Borde fino
			   dgv->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			   dgv->GridColor = line;
			   dgv->EnableHeadersVisualStyles = false;

			   // Header Compacto
			   dgv->ColumnHeadersHeight = 30; // Altura reducida
			   dgv->ColumnHeadersDefaultCellStyle->BackColor = headBack;
			   dgv->ColumnHeadersDefaultCellStyle->ForeColor = fore;
			   dgv->ColumnHeadersDefaultCellStyle->Font = fHead;
			   dgv->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;

			   // Celdas Compactas
			   dgv->RowTemplate->Height = 24; // Altura estándar de Excel/Windows
			   dgv->DefaultCellStyle->Font = fCell;
			   dgv->DefaultCellStyle->ForeColor = fore;
			   dgv->DefaultCellStyle->SelectionBackColor = Color::LightGreen;
			   dgv->DefaultCellStyle->SelectionForeColor = fore;

			   dgv->RowHeadersVisible = false;
			   dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		   }

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Honeydew;
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
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::Honeydew;
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
			// frmAgregarInsumoToAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
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
			this->Text = L"Transferir Insumos";
			this->Load += gcnew System::EventHandler(this, &frmAgregarInsumoToAlmacen::frmAgregarInsumoToAlmacen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void comboBox1_DropDown(System::Object^ sender, System::EventArgs^ e)
	{
		comboBox1->Items->Clear();
		AlmacenController^ almacenCtrl = gcnew AlmacenController();
		List<String^>^ nombres = almacenCtrl->obtenerNombresAlmacenes_BD();
		for each (String ^ nombre in nombres) {
			comboBox1->Items->Add(nombre);
		}
	}

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

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ nombreAlmacen = comboBox1->Text;
		AlmacenController^ aCtrl = gcnew AlmacenController();
		Almacen^ almacen = aCtrl->obtenerAlmacenPorNombre_BD(nombreAlmacen);
		if (almacen != nullptr) {
			StockInsumoController^ sCtrl = gcnew StockInsumoController();
			List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen_BD(almacen->Id);
			mostrarGrilla1(listaStockInsumos);
		}
	}

	private: System::Void frmAgregarInsumoToAlmacen_Load(System::Object^ sender, System::EventArgs^ e)
	{
		AlmacenController^ aCtrl = gcnew AlmacenController();
		String^ nombreAlmacen = aCtrl->buscarNombrePorId_BD(this->idAlmacenDestino);
		textBox2->Text = nombreAlmacen;
		//Mostrar la grilla del almacén destino
		StockInsumoController^ sCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen_BD(this->idAlmacenDestino);
		mostrarGrilla2(listaStockInsumos);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count > 0) {
			StockInsumoController^ sCtrl = gcnew StockInsumoController();
			int idStock = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
			StockInsumo^ stockOrigen = sCtrl->buscarPorId_BD(idStock);

			StockInsumo^ stockDestino = sCtrl->buscarPorIdInsumoYAlmacen_BD(stockOrigen->Insumoo->Id, this->idAlmacenDestino);

			if (stockDestino != nullptr) {
				float cantidadATransferir;
				try {
					cantidadATransferir = Convert::ToSingle(textBox1->Text);
				}
				catch (...) {
					MessageBox::Show("Cantidad inválida", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				if (stockOrigen->Stock < cantidadATransferir) {
					MessageBox::Show("No hay suficiente stock en el almacén de origen.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				stockOrigen->Stock -= cantidadATransferir;
				stockDestino->Stock += cantidadATransferir;
				sCtrl->actualizarStockInsumo_BD(stockOrigen);
				sCtrl->actualizarStockInsumo_BD(stockDestino);

				button3_Click(nullptr, nullptr);
				button4_Click(nullptr, nullptr);
			}
			else {
				MessageBox::Show("El insumo no existe en el almacén destino. Por favor, agregue los límites de stock mínimo y máximo.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Information);

				float cant = 0;
				try { cant = Convert::ToSingle(textBox1->Text); }
				catch (...) {}

				frmNuevoStock2^ frm = gcnew frmNuevoStock2(stockOrigen, this->idAlmacenDestino, cant);
				frm->ShowDialog();
				button4_Click(nullptr, nullptr);
				button3_Click(nullptr, nullptr);
			}

		}
		else {
			MessageBox::Show("Seleccione un insumo para agregar.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		StockInsumoController^ sCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ listaStockInsumos = sCtrl->buscarPorIdAlmacen_BD(this->idAlmacenDestino);
		mostrarGrilla2(listaStockInsumos);
	}
	};
}