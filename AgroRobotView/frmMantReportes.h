#pragma once
#include "frmEditarReporte.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; //Para List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel; // Referencia al proyecto AgroRobotModel
	using namespace AgroRobotController; // Referencia al proyecto AgroRobotController

	/// <summary>
	/// Resumen de frmMantReportes
	/// </summary>
	public ref class frmMantReportes : public System::Windows::Forms::Form
	{
	public:
		frmMantReportes(void)
		{
			InitializeComponent();
			this->reporteController = gcnew ReporteController();
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &frmMantReportes::dataGridView1_SelectionChanged);
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReportes::button4_Click);
			hayCambiosPendientes = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantReportes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Impacto;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: UsuarioController^ usuarioController;
	private: ReporteController^ reporteController;
















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMantReportes::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Impacto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(28, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(283, 228);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de búsqueda";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 145);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Tipo de Análisis:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Todos", L"Análisis de Heces", L"Hemograma", L"Análisis Completo" });
			this->comboBox2->Location = System::Drawing::Point(136, 142);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 7;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMantReportes::comboBox2_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Fecha Fin:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(136, 106);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 20);
			this->dateTimePicker2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Estado de salud:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Fecha Inicio:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Todos", L"Excelente", L"Bueno", L"Regular", L"Crítico" });
			this->comboBox1->Location = System::Drawing::Point(136, 180);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(136, 68);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 20);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->Value = System::DateTime(2025, 9, 30, 0, 0, 0, 0);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID Animal:";
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::Color::Gray;
			this->textBox1->Location = System::Drawing::Point(136, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Ej: VAC-001";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmMantReportes::textBox1_TextChanged);
			this->textBox1->Enter += gcnew System::EventHandler(this, &frmMantReportes::textBox1_Enter);
			this->textBox1->Leave += gcnew System::EventHandler(this, &frmMantReportes::textBox1_Leave);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->progressBar1);
			this->groupBox2->Controls->Add(this->comboBox3);
			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(367, 65);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(296, 171);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Monitoreo de Salud";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(250, 117);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"0%";
			this->label7->Click += gcnew System::EventHandler(this, &frmMantReportes::label7_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(147, 114);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(97, 20);
			this->textBox2->TabIndex = 4;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(147, 84);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(121, 23);
			this->progressBar1->TabIndex = 3;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Excelente", L"Bueno", L"Regular", L"Crítico" });
			this->comboBox3->Location = System::Drawing::Point(147, 29);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(29, 84);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Estado de salud:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column6,
					this->Column1, this->Column2, this->Column3, this->Column4, this->Column7, this->Column5, this->Impacto
			});
			this->dataGridView1->Location = System::Drawing::Point(28, 283);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(720, 150);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantReportes::dataGridView1_CellContentClick);
			// 
			// Column6
			// 
			this->Column6->FillWeight = 81.21828F;
			this->Column6->HeaderText = L"";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column1
			// 
			this->Column1->FillWeight = 102.6831F;
			this->Column1->HeaderText = L"ID Reporte";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->FillWeight = 102.6831F;
			this->Column2->HeaderText = L"Tipo";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->FillWeight = 102.6831F;
			this->Column3->HeaderText = L"Animal ID";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->FillWeight = 102.6831F;
			this->Column4->HeaderText = L"Fecha de Generación";
			this->Column4->Name = L"Column4";
			// 
			// Column7
			// 
			this->Column7->FillWeight = 102.6831F;
			this->Column7->HeaderText = L"Estado";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->FillWeight = 102.6831F;
			this->Column5->HeaderText = L"Impacto";
			this->Column5->Name = L"Column5";
			// 
			// Impacto
			// 
			this->Impacto->FillWeight = 102.6831F;
			this->Impacto->HeaderText = L"Atención";
			this->Impacto->Name = L"Impacto";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(583, 455);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Cancelar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReportes::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(416, 455);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Programar tarea";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(255, 455);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Editar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReportes::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 455);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReportes::button1_Click);
			// 
			// frmMantReportes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 523);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantReportes";
			this->Text = L"Gestión de Reportes - Administrador";
			this->Load += gcnew System::EventHandler(this, &frmMantReportes::frmMantReportes_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantReportes_Load(System::Object^ sender, System::EventArgs^ e) {
		// Inicializar el controlador
		reporteController = gcnew AgroRobotController::ReporteController();

		// Configurar fechas por defecto (últimos 30 días)
		dateTimePicker1->Value = DateTime::Today.AddDays(-30);
		dateTimePicker2->Value = DateTime::Today;

		// Cargar datos iniciales
		CargarDatosIniciales();
	}

	private: void CargarDatosIniciales() {
		// Obtener todos los reportes para mostrar al iniciar
		List<AgroRobotModel::Reporte^>^ reportes = reporteController->ObtenerTodosReportes();
		LlenarDataGridView(reportes);
	}

	private: void LlenarDataGridView(List<AgroRobotModel::Reporte^>^ reportes) {
		// Limpiar datos existentes
		dataGridView1->Rows->Clear();

		for each (AgroRobotModel::Reporte ^ reporte in reportes) {
			// Agregar fila al DataGridView
			int rowIndex = dataGridView1->Rows->Add();
			DataGridViewRow^ row = dataGridView1->Rows[rowIndex];

			// Llenar las celdas
			row->Cells["Column1"]->Value = "REP-" + reporte->getIdReporte().ToString("D3");
			row->Cells["Column2"]->Value = reporte->getTipo();
			row->Cells["Column3"]->Value = reporte->getAnimalAlias();
			row->Cells["Column4"]->Value = reporte->getFechaGeneracion().ToString("dd/MM/yyyy");
			row->Cells["Column7"]->Value = reporte->getEstadoSaludImpacto();
			row->Cells["Column5"]->Value = ObtenerImpactoDesdeEstado(reporte->getEstadoSaludImpacto());
			row->Cells["Impacto"]->Value = reporte->getEstadoGestion();

			// Opcional: Configurar colores según el estado
			ConfigurarColorFila(row, reporte->getEstadoSaludImpacto());
		}
	}

private: String^ ObtenerImpactoDesdeEstado(String^ estado) {
	if (estado == "Crítico") return "Urgente";
	if (estado == "Regular") return "Alto";
	if (estado == "Bueno") return "Medio";
	if (estado == "Excelente") return "Bajo";
	return "Desconocido";
}

private: void ConfigurarColorFila(DataGridViewRow^ row, String^ estado) {
	if (estado == "Crítico") {
		row->DefaultCellStyle->BackColor = Color::LightPink;
		row->DefaultCellStyle->ForeColor = Color::DarkRed;
	}
	else if (estado == "Regular") {
		row->DefaultCellStyle->BackColor = Color::LightYellow;
		row->DefaultCellStyle->ForeColor = Color::DarkOrange;
	}
	else if (estado == "Bueno") {
		row->DefaultCellStyle->BackColor = Color::LightBlue;
		row->DefaultCellStyle->ForeColor = Color::DarkBlue;
	}
	else if (estado == "Excelente") {
		row->DefaultCellStyle->BackColor = Color::LightGreen;
		row->DefaultCellStyle->ForeColor = Color::DarkGreen;
	}
}

	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "Ej: VAC-001") {
		textBox1->Text = "";
		textBox1->ForeColor = System::Drawing::Color::Black;
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "") {
		textBox1->Text = "Ej: VAC-001";
		textBox1->ForeColor = System::Drawing::Color::Gray;
	}
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1. OBTENER VALORES DE LOS FILTROS

		// ID Animal (texto, no número)
		String^ animalAlias = "";
		if (textBox1->Text != "Ej: VAC-001" && !String::IsNullOrWhiteSpace(textBox1->Text)) {
			animalAlias = textBox1->Text->Trim();
		}

		// Fechas
		DateTime fechaInicio = dateTimePicker1->Value;
		DateTime fechaFin = dateTimePicker2->Value;

		// Ajustar fechaFin para incluir todo el día
		fechaFin = fechaFin.Date.AddDays(1).AddSeconds(-1);

		// Validar rango de fechas
		if (fechaInicio > fechaFin) {
			MessageBox::Show("La fecha de inicio no puede ser mayor que la fecha fin.",
				"Error en fechas",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}

		// Tipo de Análisis
		String^ tipoAnalisis = "";
		if (comboBox2->SelectedItem != nullptr && comboBox2->Text != "Todos") {
			tipoAnalisis = comboBox2->Text;
		}

		// Estado de Salud
		String^ estadoSalud = "";
		if (comboBox1->SelectedItem != nullptr && comboBox1->Text != "Todos") {
			estadoSalud = comboBox1->Text;
		}

		// 2. EJECUTAR LA BÚSQUEDA
		List<AgroRobotModel::Reporte^>^ resultados =
			reporteController->ConsultarReportesPorFiltros(
				animalAlias,
				fechaInicio,
				fechaFin,
				tipoAnalisis,
				estadoSalud
			);

		// 3. MOSTRAR RESULTADOS
		LlenarDataGridView(resultados);

		// 4. MOSTRAR FEEDBACK AL USUARIO
		String^ mensaje = String::Format("Se encontraron {0} reportes con los criterios seleccionados.",
			resultados->Count);

		if (resultados->Count == 0) {
			MessageBox::Show("No se encontraron reportes con los criterios especificados.",
				"Búsqueda sin resultados",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
		else {
			// Opcional: Mostrar mensaje en una etiqueta de status en lugar de MessageBox
			// statusLabel->Text = mensaje;
		}

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al realizar la búsqueda: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}

	private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

			// Actualizar panel de monitoreo con el reporte seleccionado
			if (selectedRow->Cells["Column7"]->Value != nullptr) {
				String^ estado = selectedRow->Cells["Column7"]->Value->ToString();
				comboBox3->SelectedItem = estado;

				// También actualizar el TextBox y ProgressBar
				ActualizarPanelMonitoreo(estado);
			}
		}
	}

private: void ActualizarPanelMonitoreo(String^ estado) {
	if (estado == "Excelente") {
		progressBar1->Value = 90;
		textBox2->Text = "Óptimo";
		textBox2->ForeColor = Color::Green;
	}
	else if (estado == "Bueno") {
		progressBar1->Value = 70;
		textBox2->Text = "Adecuado";
		textBox2->ForeColor = Color::Blue;
	}
	else if (estado == "Regular") {
		progressBar1->Value = 50;
		textBox2->Text = "Requiere atención";
		textBox2->ForeColor = Color::Orange;
	}
	else if (estado == "Crítico") {
		progressBar1->Value = 20;
		textBox2->Text = "URGENTE";
		textBox2->ForeColor = Color::Red;
	}

	// Actualizar el porcentaje en el label
	label7->Text = progressBar1->Value.ToString() + "%";
}


private:
	bool hayCambiosPendientes = false; // Variable para rastrear cambios

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	CerrarFormulario();

}

private: void CerrarFormulario() {
	// Verificar si hay cambios pendientes
	if (hayCambiosPendientes) {
		System::Windows::Forms::DialogResult resultado = MessageBox::Show(
			"Tiene cambios sin guardar. ¿Está seguro que desea salir?\n\nLos cambios se perderán.",
			"Cambios sin guardar",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning,
			MessageBoxDefaultButton::Button2  // No por defecto
		);

		if (resultado == System::Windows::Forms::DialogResult::No) { // <-- Usar el namespace completo
			return; // No cerrar el formulario
		}
	}
	else {
		// Si no hay cambios, preguntar confirmación normal
		System::Windows::Forms::DialogResult resultado = MessageBox::Show(
			"¿Está seguro que desea salir de la gestión de reportes?",
			"Confirmar salida",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (resultado == System::Windows::Forms::DialogResult::No) { // <-- Usar el namespace completo
			return;
		}
	}

	// Proceder con el cierre
	this->Close();
}

	   // Método para marcar cuando hay cambios (lo usarás más adelante con Editar)
private: void MarcarCambiosPendientes(bool hayCambios) {
	hayCambiosPendientes = hayCambios;

	// Opcional: Cambiar el texto del formulario para indicar cambios
	if (hayCambios) {
		this->Text = "Gestión de Reportes - Administrador *";
	}
	else {
		this->Text = "Gestión de Reportes - Administrador";
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (dataGridView1->SelectedRows->Count > 0) {
		try {
			// Obtener el ID del reporte seleccionado
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
			String^ idReporteStr = selectedRow->Cells["Column1"]->Value->ToString();
			int idReporte = Convert::ToInt32(idReporteStr->Replace("REP-", ""));

			// Buscar el reporte en la lista
			AgroRobotModel::Reporte^ reporteSeleccionado = reporteController->ConsultarReportePorId(idReporte);

			if (reporteSeleccionado != nullptr) {
				// Abrir formulario de edición
				frmEditarReporte^ formEdicion = gcnew frmEditarReporte(reporteController, reporteSeleccionado);
				formEdicion->ShowDialog();

				// Recargar datos después de editar
				button1_Click(sender, e); // Ejecutar búsqueda nuevamente
			}
			else {
				MessageBox::Show("No se pudo encontrar el reporte seleccionado.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al abrir el editor: " + ex->Message,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}
	else {
		MessageBox::Show("Por favor, seleccione un reporte para editar.",
			"Selección requerida",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
	}

}
};
}
