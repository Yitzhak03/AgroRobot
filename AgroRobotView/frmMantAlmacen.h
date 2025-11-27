#pragma once
#include "frmNuevoAlmacen.h"
#include "frmPaintStockPorAlmacen.h"
#include "frmAgregarInsumoToAlmacen.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmMantAlmacen
	/// </summary>
	public ref class frmMantAlmacen : public System::Windows::Forms::Form {
	public:
		frmMantAlmacen(void)
		{
			InitializeComponent();
			// Aplicamos el nuevo diseño profesional al iniciar
			AplicarEstiloProfesional();
			// Cargar datos iniciales
			button4_Click(nullptr, nullptr);
		}

	protected:
		~frmMantAlmacen()
		{
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button4; // Mostrar
	private: System::Windows::Forms::Button^ button2; // Nuevo
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1; // Agregar Insumos
	private: System::Windows::Forms::Button^ button3; // Ver Insumos
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;

		   // Etiqueta de Título dinámica (para no modificar el InitializeComponent manual)
	private: System::Windows::Forms::Label^ lblTituloPrincipal;

		   // ===================================================================================
		   // MÉTODO DE ESTILO PROFESIONAL (MENTA/BOSQUE)
		   // ===================================================================================
		   void AplicarEstiloProfesional() {
			   // 1. PALETA DE COLORES
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);   // Menta Pálido
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240);   // Menta Crema
			   System::Drawing::Color colorBtnPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Bosque
			   System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45);    // Verde Petróleo
			   System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);    // Verde Azulado
			   System::Drawing::Color colorGridLine = System::Drawing::Color::FromArgb(183, 220, 200);   // Verde Agua
			   System::Drawing::Color colorGridAlt = System::Drawing::Color::FromArgb(244, 250, 246);   // Filas alternas

			   // 2. FUENTES
			   System::Drawing::Font^ fontTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 17, FontStyle::Bold);
			   System::Drawing::Font^ fontBoton = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);
			   System::Drawing::Font^ fontGridHeader = gcnew System::Drawing::Font("Segoe UI Semibold", 10);
			   System::Drawing::Font^ fontGridCell = gcnew System::Drawing::Font("Microsoft Sans Serif", 9);

			   // 3. CONFIGURACIÓN VENTANA
			   this->BackColor = colorFondo;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->AutoSize = false;
			   this->Dock = DockStyle::Fill;
			   this->Text = "Registro General de Almacenes";

			   // 4. CREACIÓN DINÁMICA DEL TÍTULO (Para consistencia visual)
			   this->lblTituloPrincipal = (gcnew System::Windows::Forms::Label());
			   this->lblTituloPrincipal->Text = "Gestión de Almacenes";
			   this->lblTituloPrincipal->Font = fontTitulo;
			   this->lblTituloPrincipal->ForeColor = colorTextoMain;
			   this->lblTituloPrincipal->AutoSize = true;
			   this->lblTituloPrincipal->Location = System::Drawing::Point(20, 20);
			   this->Controls->Add(this->lblTituloPrincipal);

			   // 5. RE-ORGANIZACIÓN DEL LAYOUT (Barra Lateral Izquierda)
			   // Definimos coordenadas para alinear los botones verticalmente a la izquierda
			   int btnLeft = 20;
			   int startY = 70;
			   int btnWidth = 160;
			   int btnHeight = 40;
			   int gap = 10;

			   // Botón 2: NUEVO (Acción Principal)
			   this->button2->Text = "Nuevo Almacén";
			   this->button2->Location = System::Drawing::Point(btnLeft, startY);
			   this->button2->Size = System::Drawing::Size(btnWidth, btnHeight);
			   this->button2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			   EstilarBotonPrimario(this->button2, colorBtnPrimario, fontBoton);

			   // Botón 1: AGREGAR INSUMOS (Acción Principal)
			   this->button1->Location = System::Drawing::Point(btnLeft, startY + btnHeight + gap);
			   this->button1->Size = System::Drawing::Size(btnWidth, btnHeight);
			   this->button1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			   EstilarBotonPrimario(this->button1, colorBtnPrimario, fontBoton);

			   // Botón 3: VER INSUMOS (Acción Secundaria)
			   this->button3->Location = System::Drawing::Point(btnLeft, startY + (btnHeight + gap) * 2);
			   this->button3->Size = System::Drawing::Size(btnWidth, btnHeight);
			   this->button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			   EstilarBotonSecundario(this->button3, colorPanel, colorTextoSec, colorGridLine, fontBoton);

			   // Botón 4: MOSTRAR/REFRESCAR (Acción Secundaria)
			   this->button4->Text = "Refrescar Lista";
			   this->button4->Location = System::Drawing::Point(btnLeft, startY + (btnHeight + gap) * 3);
			   this->button4->Size = System::Drawing::Size(btnWidth, btnHeight);
			   this->button4->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			   EstilarBotonSecundario(this->button4, colorPanel, colorTextoSec, colorGridLine, fontBoton);

			   // 6. ESTILIZADO DE LA GRILLA
			   // Posicionamos la grilla a la derecha de los botones
			   int gridX = btnLeft + btnWidth + 20;
			   this->dataGridView1->Location = System::Drawing::Point(gridX, 70);
			   this->dataGridView1->Size = System::Drawing::Size(this->ClientSize.Width - gridX - 20, this->ClientSize.Height - 90);
			   // Importante: Anclajes para que la grilla crezca
			   this->dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			   this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			   this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			   this->dataGridView1->GridColor = colorGridLine;
			   this->dataGridView1->EnableHeadersVisualStyles = false;

			   // Header
			   this->dataGridView1->ColumnHeadersHeight = 45;
			   this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorTextoMain;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = fontGridHeader;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::White;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->SelectionForeColor = colorTextoMain;

			   // Filas
			   this->dataGridView1->RowTemplate->Height = 35;
			   this->dataGridView1->DefaultCellStyle->Font = fontGridCell;
			   this->dataGridView1->DefaultCellStyle->ForeColor = colorTextoMain;
			   this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGreen;
			   this->dataGridView1->DefaultCellStyle->SelectionForeColor = colorTextoMain;
			   this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = colorGridAlt;

			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			   this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		   }

		   // Helpers para reducir código repetitivo
		   void EstilarBotonPrimario(Button^ btn, Color backColor, System::Drawing::Font^ font) {
			   btn->BackColor = backColor;
			   btn->ForeColor = System::Drawing::Color::White;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderSize = 0;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

		   void EstilarBotonSecundario(Button^ btn, Color backColor, Color foreColor, Color borderColor, System::Drawing::Font^ font) {
			   btn->BackColor = backColor;
			   btn->ForeColor = foreColor;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderColor = borderColor;
			   btn->FlatAppearance->BorderSize = 1;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(11, 49);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 32);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Mostrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button4_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 11);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 34);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Nuevo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4)
			{
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(141, 11);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(383, 259);
			this->dataGridView1->TabIndex = 24;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 121);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Agregar Insumos";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(11, 85);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 32);
			this->button3->TabIndex = 27;
			this->button3->Text = L"Ver Insumos";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button3_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ubicación";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Insumos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 80;
			// 
			// frmMantAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 281);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmMantAlmacen";
			this->Text = L"Registro General de Almacenes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AlmacenController^ almacenCtrl = gcnew AlmacenController();
		List<Almacen^>^ lista = almacenCtrl->readTxt();
		mostrarGrilla(lista);
	}

	private: System::Void mostrarGrilla(List<Almacen^>^ lista)
	{
		dataGridView1->Rows->Clear();
		StockInsumoController^ SICtrl = gcnew StockInsumoController();
		for each (Almacen ^ a in lista) {
			dataGridView1->Rows->Add(
				Convert::ToString(a->Id),
				a->Nombre,
				a->Ubicacion,
				Convert::ToString(SICtrl->cantidadInsumosEnAlmacen(a->Id))
			);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmNuevoAlmacen^ frmNA = gcnew frmNuevoAlmacen();
		frmNA->ShowDialog();
		button4_Click(nullptr, nullptr); // Refrescar tras cerrar
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para agregar insumos.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		int idAlmacen = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
		frmAgregarInsumoToAlmacen^ frm = gcnew frmAgregarInsumoToAlmacen(idAlmacen);
		frm->ShowDialog();
		button4_Click(nullptr, nullptr); // Refrescar tras cerrar
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para ver el stock.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		int idAlmacen = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
		AlmacenController^ almCtrl = gcnew AlmacenController();
		Almacen^ almacen = almCtrl->buscarPorId(idAlmacen);
		StockInsumoController^ stockCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ stocks = stockCtrl->buscarPorIdAlmacen(idAlmacen);
		frmPaintStockPorAlmacen^ frm = gcnew frmPaintStockPorAlmacen(almacen, stocks);
		frm->ShowDialog();
	}
	};
}