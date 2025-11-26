#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class frmMantReporteDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantReporteDiagnostico(void)
		{
			InitializeComponent();
			this->reporteController = gcnew ReporteDiagnosticoController();
			this->pdfExportController = gcnew PdfExportServiceController();
			this->reporteActual = nullptr;

			// EVENTOS
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button1_Click);
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button3_Click);
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button2_Click);
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button4_Click);
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button5_Click);
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioMensual_CheckedChanged);
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioRango_CheckedChanged);

			// CONFIGURACIÓN
			ConfigurarControlesIniciales();
			ConfigurarCharts();
			ConfigurarToolTips();

			// ESTILO PROFESIONAL (Sutil: 10pt)
			AplicarEstiloProfesional();
		}

	protected:
		~frmMantReporteDiagnostico()
		{
			if (reporteController != nullptr) delete reporteController;
			if (pdfExportController != nullptr) delete pdfExportController;
			if (reporteActual != nullptr) delete reporteActual;
			if (components) delete components;
		}

	private:
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TabControl^ tabControl1;
		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::TabPage^ tabPage3;
		System::Windows::Forms::GroupBox^ groupBox3;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button2;

		ReporteDiagnosticoController^ reporteController;
		PdfExportServiceController^ pdfExportController;
		ReporteDiagnosticoResult^ reporteActual;
		Chart^ chartTipoAnalisis;
		Chart^ chartEstadoSalud;
		System::Windows::Forms::DataGridView^ dataGridEstadisticas;
		System::Windows::Forms::DataGridView^ dataGridDetalle;
		System::Windows::Forms::ComboBox^ comboAnio;
		System::Windows::Forms::ComboBox^ comboMes;
		System::Windows::Forms::RadioButton^ radioMensual;
		System::Windows::Forms::RadioButton^ radioRango;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->chartTipoAnalisis = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartEstadoSalud = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioMensual = (gcnew System::Windows::Forms::RadioButton());
			this->radioRango = (gcnew System::Windows::Forms::RadioButton());
			this->comboAnio = (gcnew System::Windows::Forms::ComboBox());
			this->comboMes = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridEstadisticas = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// chartTipoAnalisis
			this->chartTipoAnalisis->Location = System::Drawing::Point(10, 10);
			this->chartTipoAnalisis->Name = L"chartTipoAnalisis";
			this->chartTipoAnalisis->Size = System::Drawing::Size(380, 140);
			this->chartTipoAnalisis->TabIndex = 0;
			// chartEstadoSalud
			this->chartEstadoSalud->Location = System::Drawing::Point(10, 160);
			this->chartEstadoSalud->Name = L"chartEstadoSalud";
			this->chartEstadoSalud->Size = System::Drawing::Size(380, 130);
			this->chartEstadoSalud->TabIndex = 1;
			// groupBox1
			this->groupBox1->Controls->Add(this->radioMensual);
			this->groupBox1->Controls->Add(this->radioRango);
			this->groupBox1->Controls->Add(this->comboAnio);
			this->groupBox1->Controls->Add(this->comboMes);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Location = System::Drawing::Point(35, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(408, 134);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de búsqueda";
			// radioMensual
			this->radioMensual->AutoSize = true;
			this->radioMensual->Location = System::Drawing::Point(24, 60);
			this->radioMensual->Name = L"radioMensual";
			this->radioMensual->Size = System::Drawing::Size(71, 19);
			this->radioMensual->TabIndex = 14;
			this->radioMensual->TabStop = true;
			this->radioMensual->Text = L"Mensual";
			this->radioMensual->UseVisualStyleBackColor = true;
			// radioRango
			this->radioRango->AutoSize = true;
			this->radioRango->Location = System::Drawing::Point(24, 35);
			this->radioRango->Name = L"radioRango";
			this->radioRango->Size = System::Drawing::Size(59, 19);
			this->radioRango->TabIndex = 15;
			this->radioRango->Text = L"Rango";
			this->radioRango->UseVisualStyleBackColor = true;
			// comboAnio
			this->comboAnio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboAnio->FormattingEnabled = true;
			this->comboAnio->Location = System::Drawing::Point(104, 58);
			this->comboAnio->Name = L"comboAnio";
			this->comboAnio->Size = System::Drawing::Size(70, 23);
			this->comboAnio->TabIndex = 16;
			// comboMes
			this->comboMes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboMes->FormattingEnabled = true;
			this->comboMes->Location = System::Drawing::Point(184, 58);
			this->comboMes->Name = L"comboMes";
			this->comboMes->Size = System::Drawing::Size(100, 23);
			this->comboMes->TabIndex = 17;
			// button3
			this->button3->Location = System::Drawing::Point(214, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Limpiar";
			this->button3->UseVisualStyleBackColor = true;
			// button1
			this->button1->Location = System::Drawing::Point(108, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			// label5
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(231, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 15);
			this->label5->TabIndex = 8;
			this->label5->Text = L"a";
			// label4
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 15);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Rango:";
			// dateTimePicker2
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(261, 33);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker2->TabIndex = 6;
			// dateTimePicker1
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(91, 33);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker1->TabIndex = 2;
			// groupBox2
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(35, 177);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(408, 116);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Resumen Ejecutivo";
			// textBoxes
			this->textBox4->Location = System::Drawing::Point(327, 75); this->textBox4->ReadOnly = true; this->textBox4->Size = System::Drawing::Size(56, 22);
			this->textBox3->Location = System::Drawing::Point(230, 75); this->textBox3->ReadOnly = true; this->textBox3->Size = System::Drawing::Size(56, 22);
			this->textBox1->Location = System::Drawing::Point(130, 75); this->textBox1->ReadOnly = true; this->textBox1->Size = System::Drawing::Size(58, 22);
			this->textBox2->Location = System::Drawing::Point(27, 75); this->textBox2->ReadOnly = true; this->textBox2->Size = System::Drawing::Size(55, 22);
			// labels
			this->label3->AutoSize = true; this->label3->Location = System::Drawing::Point(324, 45); this->label3->Text = L"Heces";
			this->label2->AutoSize = true; this->label2->Location = System::Drawing::Point(227, 45); this->label2->Text = L"Sangre";
			this->label1->AutoSize = true; this->label1->Location = System::Drawing::Point(127, 28); this->label1->Text = L"Animales\r\nÚnicos";
			this->label6->AutoSize = true; this->label6->Location = System::Drawing::Point(24, 28); this->label6->Text = L"Total\r\nMuestras";
			// tabControl1
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(470, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(408, 363);
			this->tabControl1->TabIndex = 5;
			// tabPage1
			this->tabPage1->Controls->Add(this->chartTipoAnalisis);
			this->tabPage1->Controls->Add(this->chartEstadoSalud);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(400, 335);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Gráficos";
			this->tabPage1->UseVisualStyleBackColor = true;
			// tabPage2
			this->tabPage2->Controls->Add(this->dataGridEstadisticas);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(400, 335);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Estadísticas";
			this->tabPage2->UseVisualStyleBackColor = true;
			// dataGridEstadisticas
			this->dataGridEstadisticas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridEstadisticas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridEstadisticas->Location = System::Drawing::Point(3, 3);
			this->dataGridEstadisticas->Name = L"dataGridEstadisticas";
			this->dataGridEstadisticas->Size = System::Drawing::Size(394, 329);
			this->dataGridEstadisticas->TabIndex = 0;
			// tabPage3
			this->tabPage3->Controls->Add(this->dataGridDetalle);
			this->tabPage3->Location = System::Drawing::Point(4, 24);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(400, 335);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Detalle";
			this->tabPage3->UseVisualStyleBackColor = true;
			// dataGridDetalle
			this->dataGridDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridDetalle->Location = System::Drawing::Point(0, 0);
			this->dataGridDetalle->Name = L"dataGridDetalle";
			this->dataGridDetalle->Size = System::Drawing::Size(400, 335);
			this->dataGridDetalle->TabIndex = 0;
			// groupBox3
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Location = System::Drawing::Point(35, 314);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(408, 73);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Exportar a:";
			// button5
			this->button5->Location = System::Drawing::Point(298, 29);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 23);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			// button4
			this->button4->Location = System::Drawing::Point(172, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Excel";
			this->button4->UseVisualStyleBackColor = true;
			// button2
			this->button2->Location = System::Drawing::Point(40, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"TXT";
			this->button2->UseVisualStyleBackColor = true;

			// frmMantReporteDiagnostico
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 413);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantReporteDiagnostico";
			this->Text = L"Reporte de Diagnóstico Médico";
			this->Load += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::frmMantReporteDiagnostico_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

		// EVENTOS
		System::Void frmMantReporteDiagnostico_Load(System::Object^ sender, System::EventArgs^ e) {}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { GenerarReporte(); }
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { LimpiarControles(); }
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { ExportarPDF(); }
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { ExportarExcel(); }
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { this->Close(); }
		System::Void radioMensual_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { HabilitarControlesMensual(); }
		System::Void radioRango_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { HabilitarControlesRango(); }

		// LÓGICA
		void ConfigurarControlesIniciales() {
			comboAnio->Items->Clear();
			for (int i = 2022; i <= 2026; i++) comboAnio->Items->Add(i.ToString());
			comboAnio->SelectedItem = "2025";
			comboMes->Items->Clear();
			array<String^>^ meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
			comboMes->Items->AddRange(meses);
			comboMes->SelectedIndex = 9;
			dateTimePicker1->Value = DateTime(2025, 10, 1);
			dateTimePicker2->Value = DateTime(2025, 10, 31);
			radioMensual->Checked = true;
			HabilitarControlesMensual();
		}
		void HabilitarControlesMensual() {
			comboAnio->Enabled = true; comboMes->Enabled = true;
			dateTimePicker1->Enabled = false; dateTimePicker2->Enabled = false;
		}
		void HabilitarControlesRango() {
			comboAnio->Enabled = false; comboMes->Enabled = false;
			dateTimePicker1->Enabled = true; dateTimePicker2->Enabled = true;
		}

		void ConfigurarCharts() {
			// GRÁFICO 1: TIPOS DE ANÁLISIS
			if (chartTipoAnalisis != nullptr) {
				chartTipoAnalisis->ChartAreas->Clear(); chartTipoAnalisis->Series->Clear(); chartTipoAnalisis->Titles->Clear();
				ChartArea^ area = gcnew ChartArea("AreaTipos");
				area->AxisX->Title = "Tipo de Análisis";
				area->AxisX->TitleFont = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold); // Fuente Segoe UI
				area->AxisX->Interval = 1;
				area->BackColor = System::Drawing::Color::White;
				chartTipoAnalisis->ChartAreas->Add(area);

				Title^ titulo = gcnew Title("Distribución por Tipo");
				titulo->Font = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
				chartTipoAnalisis->Titles->Add(titulo);
			}
			// GRÁFICO 2: ESTADO DE SALUD
			if (chartEstadoSalud != nullptr) {
				chartEstadoSalud->ChartAreas->Clear(); chartEstadoSalud->Series->Clear(); chartEstadoSalud->Titles->Clear();
				ChartArea^ area = gcnew ChartArea("AreaSalud");
				area->Area3DStyle->Enable3D = false;
				area->BackColor = System::Drawing::Color::White;
				chartEstadoSalud->ChartAreas->Add(area);

				Title^ titulo = gcnew Title("Estado de Salud General");
				titulo->Font = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
				chartEstadoSalud->Titles->Add(titulo);
			}
		}

		void GenerarReporte() {
			try {
				if (!radioMensual->Checked && !radioRango->Checked) return;
				if (radioMensual->Checked) {
					int año = Convert::ToInt32(comboAnio->SelectedItem);
					int mes = comboMes->SelectedIndex + 1;
					reporteActual = reporteController->GenerarReporteMensual(año, mes);
				}
				else {
					String^ fi = dateTimePicker1->Value.ToString("yyyy-MM-dd");
					String^ ff = dateTimePicker2->Value.ToString("yyyy-MM-dd");
					reporteActual = reporteController->GenerarReportePorRangoFechas(fi, ff);
				}
				if (reporteActual != nullptr && reporteActual->TotalMuestras == 0)
					MessageBox::Show("No se encontraron muestras.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);

				ActualizarResumen(); ActualizarGraficos(); ActualizarEstadisticas(); ActualizarDetalle();
			}
			catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
		}

		void ActualizarResumen() {
			if (reporteActual == nullptr) return;
			textBox2->Text = reporteActual->TotalMuestras.ToString();
			textBox1->Text = reporteActual->TotalAnimales.ToString();
			int sangre = 0, heces = 0;
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				if (stat->Categoria == "Sangre") sangre = stat->Cantidad;
				else if (stat->Categoria == "Heces") heces = stat->Cantidad;
			}
			textBox3->Text = sangre.ToString(); textBox4->Text = heces.ToString();
		}

		void ActualizarGraficos() {
			if (reporteActual == nullptr) return;
			try {
				// 1. Barras
				chartTipoAnalisis->Series->Clear();
				if (reporteActual->PorTipoAnalisis->Count > 0) {
					Series^ s = gcnew Series("TiposAnalisis");
					s->ChartType = SeriesChartType::Column;
					s->Color = System::Drawing::Color::FromArgb(67, 160, 71); // Verde
					s->IsValueShownAsLabel = true;
					s->LabelForeColor = System::Drawing::Color::Black; // Negro Visible
					s->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
					chartTipoAnalisis->Series->Add(s);
					for each (auto stat in reporteActual->PorTipoAnalisis) {
						DataPoint^ p = gcnew DataPoint();
						p->SetValueXY(stat->Categoria, stat->Cantidad);
						chartTipoAnalisis->Series[0]->Points->Add(p);
					}
				}
				// 2. Pastel
				chartEstadoSalud->Series->Clear();
				if (reporteActual->PorEstadoSalud->Count > 0) {
					Series^ s2 = gcnew Series("EstadosSalud");
					s2->ChartType = SeriesChartType::Pie;
					s2->Label = "#AXISLABEL";
					s2->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
					s2->SetCustomProperty("PieLabelStyle", "Outside");
					s2->SetCustomProperty("PieLineColor", "Black");
					s2->LegendText = "#AXISLABEL (#PERCENT)";
					chartEstadoSalud->Series->Add(s2);
					for each (auto stat in reporteActual->PorEstadoSalud) {
						DataPoint^ p = gcnew DataPoint();
						p->SetValueXY(stat->Categoria, stat->Cantidad);
						p->AxisLabel = stat->Categoria;
						chartEstadoSalud->Series[0]->Points->Add(p);
					}
				}
			}
			catch (...) {}
		}

		void ActualizarEstadisticas() {
			if (reporteActual == nullptr) return;
			dataGridEstadisticas->Rows->Clear(); dataGridEstadisticas->Columns->Clear();
			dataGridEstadisticas->Columns->Add("Cat", "Categoría");
			dataGridEstadisticas->Columns->Add("Cant", "Cantidad");
			dataGridEstadisticas->Columns->Add("Porc", "Porcentaje");
			dataGridEstadisticas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			for each (auto stat in reporteActual->PorTipoAnalisis)
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
			for each (auto stat in reporteActual->PorEstadoSalud)
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
		}
		void ActualizarDetalle() {
			if (reporteActual == nullptr) return;
			dataGridDetalle->Rows->Clear(); dataGridDetalle->Columns->Clear();
			dataGridDetalle->Columns->Add("Num", "N°");
			dataGridDetalle->Columns->Add("Det", "Detalle");
			dataGridDetalle->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridDetalle->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			for (int i = 0; i < reporteActual->MuestrasResumen->Count; i++)
				dataGridDetalle->Rows->Add((i + 1).ToString(), reporteActual->MuestrasResumen[i]);
		}
		void LimpiarControles() {
			textBox2->Text = ""; textBox1->Text = ""; textBox3->Text = ""; textBox4->Text = "";
			chartTipoAnalisis->Series->Clear(); chartEstadoSalud->Series->Clear();
			dataGridEstadisticas->Rows->Clear(); dataGridDetalle->Rows->Clear();
			reporteActual = nullptr;
		}
		void ExportarPDF() {
			if (reporteActual == nullptr) return;
			SaveFileDialog^ sd = gcnew SaveFileDialog();
			sd->Filter = "Texto|*.txt";
			sd->FileName = "Reporte_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".txt";
			if (sd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				pdfExportController->ExportarReporteDiagnosticoPDF(reporteActual, sd->FileName);
		}
		void ExportarExcel() {
			if (reporteActual == nullptr) return;
			SaveFileDialog^ sd = gcnew SaveFileDialog();
			sd->Filter = "CSV|*.csv";
			sd->FileName = "Data_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".csv";
			if (sd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				pdfExportController->ExportarReporteDiagnosticoExcel(reporteActual, sd->FileName);
		}
		void ConfigurarToolTips() {
			ToolTip^ t = gcnew ToolTip();
			t->SetToolTip(button1, "Generar reporte"); t->SetToolTip(button3, "Limpiar");
			t->SetToolTip(button2, "PDF"); t->SetToolTip(button4, "Excel");
		}

		// =====================================================================
		// ESTILO PROFESIONAL (RESPETANDO PROPORCIONES ORIGINALES)
		// =====================================================================
		void AplicarEstiloProfesional() {
			// 1. FUENTES (Sutilmente más grandes: 10pt)
			System::Drawing::Font^ fuenteBase = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Regular);
			System::Drawing::Font^ fuenteBold = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);

			// 2. COLORES
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(238, 245, 233);
			System::Drawing::Color colorVerde = System::Drawing::Color::FromArgb(67, 160, 71);
			System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(30, 60, 30);

			// 3. VENTANA PRINCIPAL
			this->BackColor = colorFondo;
			this->Font = fuenteBase; // Esto ajusta la fuente base de todo el form a 10pt
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->AutoSize = false;
			this->Dock = DockStyle::Fill;

			// 4. ANCLAJES (Para responsividad, sin mover posiciones iniciales)

			// Paneles Izquierda (Se quedan fijos a la izquierda)
			groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			groupBox3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			// TabControl (Se estira a la derecha y abajo)
			tabControl1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);
			// Grillas (Se estiran dentro del Tab)
			dataGridEstadisticas->Dock = DockStyle::Fill;
			dataGridDetalle->Dock = DockStyle::Fill;
			// Gráficos (Responsive)
			chartTipoAnalisis->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
			chartEstadoSalud->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			// 5. ESTILOS VISUALES DE CONTROLES
			// GroupBoxes
			array<GroupBox^>^ grupos = { groupBox1, groupBox2, groupBox3 };
			for each (GroupBox ^ gb in grupos) {
				gb->BackColor = System::Drawing::Color::White;
				gb->ForeColor = colorTexto;
				gb->Font = fuenteBold;
			}

			// Botones (Estilo Verde y Flat)
			array<Button^>^ botones = { button1, button3, button2, button4, button5 };
			for each (Button ^ btn in botones) {
				btn->BackColor = colorVerde;
				btn->ForeColor = System::Drawing::Color::White;
				btn->FlatStyle = FlatStyle::Flat;
				btn->FlatAppearance->BorderSize = 0;
				btn->Cursor = Cursors::Hand;
				btn->Font = fuenteBold;
			}
			// Cancelar en gris
			button5->BackColor = System::Drawing::Color::FromArgb(200, 200, 200);
			button5->ForeColor = System::Drawing::Color::Black;

			// DataGridViews
			array<DataGridView^>^ grids = { dataGridEstadisticas, dataGridDetalle };
			for each (DataGridView ^ dgv in grids) {
				dgv->BackgroundColor = System::Drawing::Color::White;
				dgv->BorderStyle = BorderStyle::None;
				dgv->ColumnHeadersDefaultCellStyle->BackColor = colorVerde;
				dgv->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
				dgv->ColumnHeadersDefaultCellStyle->Font = fuenteBold;
				dgv->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(180, 220, 180);
				dgv->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
				dgv->EnableHeadersVisualStyles = false;
				dgv->RowHeadersVisible = false;
			}

			// Pestañas
			tabPage1->BackColor = colorFondo;
			tabPage2->BackColor = System::Drawing::Color::White;
			tabPage3->BackColor = System::Drawing::Color::White;

			// Charts (Fondo transparente para integrarse)
			if (chartTipoAnalisis != nullptr) chartTipoAnalisis->BackColor = System::Drawing::Color::White;
			if (chartEstadoSalud != nullptr) chartEstadoSalud->BackColor = System::Drawing::Color::White;
		}
	};
}