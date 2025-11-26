#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	public ref class frmOrdenesAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmOrdenesAlimentacion(void)
		{
			InitializeComponent();
			this->almacenController = gcnew AlmacenController();

			// APLICAR ESTILO, ESCALADO Y FUENTES GRANDES
			AplicarEstiloProfesional();
		}

	protected:
		~frmOrdenesAlimentacion()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnExportar;
	private: AlmacenController^ almacenController;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnExportar = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();

			// dataGridView1
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(6) {
				this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(16, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->TabIndex = 0;

			// Columnas
			this->Column1->HeaderText = L"ID Orden";
			this->Column1->Visible = false;
			this->Column2->HeaderText = L"ID Dieta";
			this->Column3->HeaderText = L"Robot";
			this->Column4->HeaderText = L"Fecha";
			this->Column5->HeaderText = L"Ruta";
			this->Column6->HeaderText = L"Prioridad";

			// groupBox1
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(26, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(929, 295);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Órdenes pendientes:";

			// btnExportar
			this->btnExportar->Location = System::Drawing::Point(775, 320);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(180, 45); // Un poco más alto para la letra grande
			this->btnExportar->TabIndex = 2;
			this->btnExportar->Text = L"Exportar Reporte";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &frmOrdenesAlimentacion::btnExportar_Click);

			// frmOrdenesAlimentacion
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 380);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmOrdenesAlimentacion";
			this->Text = L"Reportes - Órdenes de alimentación";
			this->Load += gcnew System::EventHandler(this, &frmOrdenesAlimentacion::frmOrdenesAlimentacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

		// =========================================================
		// LÓGICA DE ESTILO PROFESIONAL (LETRAS GRANDES Y TABLA ESCALADA)
		// =========================================================
		void AplicarEstiloProfesional() {
			// 1. COLORES
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(238, 245, 233);
			System::Drawing::Color colorVerde = System::Drawing::Color::FromArgb(67, 160, 71);
			System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(30, 60, 30);
			System::Drawing::Color colorSeleccion = System::Drawing::Color::FromArgb(180, 220, 180);

			// 2. DEFINICIÓN DE FUENTES (MÁS GRANDES PARA PANTALLA COMPLETA)
			// Fuente Base: 12pt (Antes era 8 o 10)
			System::Drawing::Font^ fuenteBase = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Regular);
			// Fuente Títulos/Botones: 12pt Bold
			System::Drawing::Font^ fuenteBold = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
			// Fuente Cabecera Tabla: 11pt Bold
			System::Drawing::Font^ fuenteHeader = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
			// Fuente Título Grupo: 14pt Bold
			System::Drawing::Font^ fuenteTituloGrupo = gcnew System::Drawing::Font("Segoe UI", 14, FontStyle::Bold);

			// 3. CONFIGURACIÓN VENTANA
			this->BackColor = colorFondo;
			this->Font = fuenteBase; // La fuente por defecto del formulario crece
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->AutoSize = false;
			this->Dock = DockStyle::Fill;

			// 4. GROUPBOX (CONTENEDOR)
			int margenH = 20;
			int espacioBoton = 70; // Más espacio abajo para el botón grande

			this->groupBox1->Left = margenH;
			this->groupBox1->Top = 20;
			this->groupBox1->Width = this->ClientSize.Width - (margenH * 2);
			this->groupBox1->Height = this->ClientSize.Height - espacioBoton - 20;
			this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->ForeColor = colorTexto;
			this->groupBox1->Font = fuenteTituloGrupo; // Título grande

			// 5. DATAGRIDVIEW (TABLA)
			this->dataGridView1->Dock = DockStyle::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView1->EnableHeadersVisualStyles = false;

			// --- AJUSTE DE TAMAÑO DE CELDAS PARA TEXTO GRANDE ---
			// Altura de Cabecera
			this->dataGridView1->ColumnHeadersHeight = 50;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorVerde;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = fuenteHeader;
			this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None;

			// Altura de Filas (Importante para que no se corte la letra 12pt)
			this->dataGridView1->RowTemplate->Height = 40;

			// Estilo de Celdas
			this->dataGridView1->DefaultCellStyle->SelectionBackColor = colorSeleccion;
			this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView1->DefaultCellStyle->Font = fuenteBase; // Aplicar fuente 12pt a datos
			this->dataGridView1->DefaultCellStyle->ForeColor = colorTexto;

			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			// 6. BOTÓN EXPORTAR
			this->btnExportar->Size = System::Drawing::Size(200, 45); // Botón más grande
			this->btnExportar->Left = this->ClientSize.Width - this->btnExportar->Width - margenH;
			this->btnExportar->Top = this->ClientSize.Height - this->btnExportar->Height - 20;
			this->btnExportar->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Right);

			this->btnExportar->BackColor = colorVerde;
			this->btnExportar->ForeColor = System::Drawing::Color::White;
			this->btnExportar->FlatStyle = FlatStyle::Flat;
			this->btnExportar->FlatAppearance->BorderSize = 0;
			this->btnExportar->Font = fuenteBold;
			this->btnExportar->Cursor = Cursors::Hand;
		}

	private: System::Void frmOrdenesAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		this->mostrarGrilla(this->almacenController->listarOrdenes());
		this->dataGridView1->ClearSelection();
	}

	public: void mostrarGrilla(List<OrdenDistribucion^>^ listaOrdenes)
	{
		this->dataGridView1->Rows->Clear();

		for (int i = 0; i < listaOrdenes->Count; i++)
		{
			OrdenDistribucion^ orden = listaOrdenes[i];
			array<String^>^ filaGrilla = gcnew array<String^>(6);
			filaGrilla[0] = Convert::ToString(orden->Id);
			filaGrilla[1] = Convert::ToString(orden->IdDieta);
			filaGrilla[2] = orden->RobotAsignado;
			filaGrilla[3] = orden->FechaHoraEntrega;
			filaGrilla[4] = orden->Ruta;
			filaGrilla[5] = orden->Prioridad;

			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		// (Mismo código de exportación previo, no cambia)
		try {
			List<OrdenDistribucion^>^ lista = this->almacenController->listarOrdenes();
			if (lista->Count == 0) {
				MessageBox::Show("No hay órdenes para exportar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Reporte de Texto|*.txt";
			saveDialog->FileName = "Reporte_Ordenes_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				StreamWriter^ writer = gcnew StreamWriter(saveDialog->FileName, false, System::Text::Encoding::UTF8);
				writer->WriteLine("AGROROBOT - REPORTE DE ÓRDENES");
				writer->WriteLine("Fecha: " + DateTime::Now.ToString("g"));
				writer->WriteLine("----------------------------------------------------------------------");
				writer->WriteLine(String::Format("{0,-10} | {1,-15} | {2,-20} | {3,-10}", "ID DIETA", "ROBOT", "FECHA", "RUTA"));
				writer->WriteLine("----------------------------------------------------------------------");
				for each (OrdenDistribucion ^ o in lista) {
					writer->WriteLine(String::Format("{0,-10} | {1,-15} | {2,-20} | {3,-10}",
						o->IdDieta, (o->RobotAsignado->Length > 15 ? o->RobotAsignado->Substring(0, 12) + "..." : o->RobotAsignado),
						o->FechaHoraEntrega, o->Ruta));
				}
				writer->Close();
				MessageBox::Show("Reporte exportado correctamente.");
			}
		}
		catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
	}
	};
}